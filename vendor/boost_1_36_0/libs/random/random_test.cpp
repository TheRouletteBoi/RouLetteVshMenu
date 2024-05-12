/* boost random_test.cpp various tests
 *
 * Copyright Jens Maurer 2000
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: random_test.cpp 30670 2005-08-25 16:27:28Z johnmaddock $
 */

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
#pragma warning( disable : 4786 )
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iterator>
#include <vector>
#include <boost/random.hpp>
#include <boost/config.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/included/test_exec_monitor.hpp>

#ifdef BOOST_NO_STDC_NAMESPACE
  namespace std { using ::abs; using ::fabs; using ::pow; }
#endif


/*
 * General portability note:
 * MSVC mis-compiles explicit function template instantiations.
 * For example, f<A>() and f<B>() are both compiled to call f<A>().
 * BCC is unable to implicitly convert a "const char *" to a std::string
 * when using explicit function template instantiations.
 *
 * Therefore, avoid explicit function template instantiations.
 */

/*
 * Validate correct implementation
 */

// own run
bool check(unsigned long x, const boost::mt11213b&) { return x == 3809585648U; }

// validation by experiment from mt19937.c
bool check(unsigned long x, const boost::mt19937&) { return x == 4123659995U; }

// validation values from the publications
bool check(int x, const boost::minstd_rand0&) { return x == 1043618065; }

// validation values from the publications
bool check(int x, const boost::minstd_rand&) { return x == 399268537; }

#if !defined(BOOST_NO_INT64_T) && !defined(BOOST_NO_INTEGRAL_INT64_T)
// by experiment from lrand48()
bool check(unsigned long x, const boost::rand48&) { return x == 1993516219; }
#endif

// ????
bool check(unsigned long x, const boost::taus88&) { return x == 3535848941U; }

// ????
bool check(int x, const boost::ecuyer1988&) { return x == 2060321752; }

// validation by experiment from Harry Erwin's generator.h (private e-mail)
bool check(unsigned int x, const boost::kreutzer1986&) { return x == 139726; }

bool check(double x, const boost::lagged_fibonacci607&) { return std::abs(x-0.401269) < 1e-5; }

// principal operation validated with CLHEP, values by experiment
bool check(unsigned long x, const boost::ranlux3&) { return x == 5957620; }
bool check(unsigned long x, const boost::ranlux4&) { return x == 8587295; }

bool check(float x, const boost::ranlux3_01&)
{ return std::abs(x-5957620/std::pow(2.0f,24)) < 1e-6; }
bool check(float x, const boost::ranlux4_01&)
{ return std::abs(x-8587295/std::pow(2.0f,24)) < 1e-6; }

bool check(double x, const boost::ranlux64_3_01&)
{ return std::abs(x-0.838413) < 1e-6; }
bool check(double x, const boost::ranlux64_4_01&)
{ return std::abs(x-0.59839) < 1e-6; }

template<class PRNG>
void validate(const std::string & name, const PRNG &)
{
  std::cout << "validating " << name << ": ";
  PRNG rng;  // default ctor
  for(int i = 0; i < 9999; i++)
    rng();
  typename PRNG::result_type val = rng();
  // make sure the validation function is a static member
  bool result = check(val, rng);
  
  // allow for a simple eyeball check for MSVC instantiation brokenness
  // (if the numbers for all generators are the same, it's obviously broken)
  std::cout << val << std::endl;
  BOOST_CHECK(result);
}

void validate_all()
{
  using namespace boost;
#if !defined(BOOST_NO_INT64_T) && !defined(BOOST_NO_INTEGRAL_INT64_T)
  validate("rand48", rand48());
#endif
  validate("minstd_rand", minstd_rand());
  validate("minstd_rand0", minstd_rand0());
  validate("ecuyer combined", ecuyer1988());
  validate("mt11213b", mt11213b());
  validate("mt19937", mt19937());
  validate("kreutzer1986", kreutzer1986());
  validate("ranlux3", ranlux3());
  validate("ranlux4", ranlux4());
  validate("ranlux3_01", ranlux3_01());
  validate("ranlux4_01", ranlux4_01());
  validate("ranlux64_3_01", ranlux64_3_01());
  validate("ranlux64_4_01", ranlux64_4_01());
  validate("taus88", taus88());
  validate("lagged_fibonacci607", lagged_fibonacci607());
}


/*
 * Check function signatures
 */

#if BOOST_WORKAROUND( __BORLANDC__, BOOST_TESTED_AT( 0x570) )
#pragma warn -par
#endif
template<class URNG, class Dist>
void instantiate_dist(URNG& urng, const char * name, const Dist& dist)
{
  // this makes a copy of urng
  boost::variate_generator<URNG, Dist> gen(urng, dist);

  // this keeps a reference to urng
  boost::variate_generator<URNG&, Dist> genref(urng, dist);

#ifndef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
  // and here is a pointer to (a copy of) the urng
  URNG copy = urng;
  boost::variate_generator<URNG*, Dist> genptr(&copy, dist);
#endif

  for(int i = 0; i < 1000; ++i) {
    (void) gen();
    (void) genref();
#ifndef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    (void) genptr();
#endif
  }
  typename Dist::result_type g = gen();
  BOOST_CHECK(std::abs(g - genref()) < 1e-6);
#ifndef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
  BOOST_CHECK(std::abs(g - genptr()) < 1e-6);
#endif

  (void) gen.engine();
  gen.distribution().reset();

  Dist d = dist;            // copy ctor
  d = dist;                 // copy assignment

#if !defined(BOOST_NO_OPERATORS_IN_NAMESPACE) && !defined(BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
  {
    std::ostringstream file;
    file << urng << std::endl;
    file << d;
    std::istringstream input(file.str());
    // std::cout << file.str() << std::endl;
    URNG restored_engine;
    input >> restored_engine;
    input >> std::ws;
    Dist restored_dist;
    input >> restored_dist;
#if !defined(BOOST_MSVC) || BOOST_MSVC > 1300 // MSVC brokenness
    boost::variate_generator<URNG, Dist> old(urng, d);
    boost::variate_generator<URNG, Dist> restored(restored_engine, restored_dist);
    // advance some more so that state is exercised
    for(int i = 0; i < 1000; ++i) {
      (void) old();
      (void) restored();
    }
    BOOST_CHECK_MESSAGE((std::abs(old()-restored()) < 0.0001),
                        (std::string(name) + " old == restored_dist"));
#endif // BOOST_MSVC
  }
#endif // BOOST_NO_OPERATORS_IN_NAMESPACE
}

template<class URNG, class RealType>
void instantiate_real_dist(URNG& urng, RealType /* ignored */)
{
  instantiate_dist(urng, "uniform_real",
                   boost::uniform_real<RealType>(0, 2.1));
  instantiate_dist(urng, "triangle_distribution",
                   boost::triangle_distribution<RealType>(1, 1.5, 7));
  instantiate_dist(urng, "exponential_distribution",
                   boost::exponential_distribution<RealType>(5));
  instantiate_dist(urng, "normal_distribution",
                   boost::normal_distribution<RealType>());
  instantiate_dist(urng, "lognormal_distribution",
                   boost::lognormal_distribution<RealType>(1, 1));
  instantiate_dist(urng, "cauchy_distribution",
                   boost::cauchy_distribution<RealType>(1));
  instantiate_dist(urng, "gamma_distribution",
                   boost::gamma_distribution<RealType>(1));
}

template<class URNG, class ResultType>
void instantiate_urng(const std::string & s, const URNG &, const ResultType &)
{
  std::cout << "Basic tests for " << s;
  URNG urng;
  urng.seed();                                  // seed() member function
  int a[URNG::has_fixed_range ? 5 : 10];        // compile-time constant
  (void) a;   // avoid "unused" warning
  typename URNG::result_type x1 = urng();
  ResultType x2 = x1;
  (void) &x2;           // avoid "unused" warning

  URNG urng2 = urng;             // copy constructor
#if !defined(BOOST_MSVC) || BOOST_MSVC > 1300 // MSVC brokenness
  BOOST_CHECK(urng == urng2);     // operator==
  BOOST_CHECK(!(urng != urng2));  // operator!=
  urng();
  urng2 = urng;                  // copy assignment
  BOOST_CHECK(urng == urng2);
#endif // BOOST_MSVC

  const std::vector<int> v(9999u, 0x41);
  std::vector<int>::const_iterator it = v.begin();
  std::vector<int>::const_iterator it_end = v.end();
  URNG urng3(it, it_end);
  BOOST_CHECK(it != v.begin());
  std::cout << "; seeding uses " << (it - v.begin()) << " words" << std::endl;

  bool have_exception = false;
  try {
    // now check that exceptions are thrown
    it = v.end();
    urng3.seed(it, it_end);
  } catch(std::invalid_argument& x) {
    have_exception = true;
  }
  BOOST_CHECK(have_exception);

  // check for min/max members
  ResultType min = (urng3.min)();
  (void) &min;
  ResultType max = (urng3.max)();
  (void) &max;

#if !defined(BOOST_NO_OPERATORS_IN_NAMESPACE) && !defined(BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
  // Streamable concept not supported for broken compilers

  // advance a little so that state is relatively arbitrary
  for(int i = 0; i < 9307; ++i)
    urng();
  urng2 = urng;

  {
    // narrow stream first
    std::ostringstream file;
    file << urng;
    // move forward
    urng();
    // restore old state
    std::istringstream input(file.str());
    input >> urng;
    // std::cout << file.str() << std::endl;
#if !defined(BOOST_MSVC) || BOOST_MSVC > 1300 // MSVC brokenness
    // advance some more so that state is exercised
    for(int i = 0; i < 10000; ++i) {
      urng();
      urng2();
    }
    BOOST_CHECK(urng == urng2);
#endif // BOOST_MSVC
  }
  
  urng2 = urng;
#if !defined(BOOST_NO_STD_WSTREAMBUF) && !defined(BOOST_NO_STD_WSTRING)
  {
    // then wide stream
    std::wostringstream file;
    file << urng;
    // move forward
    urng();
    std::wistringstream input(file.str());
    input >> urng;
#if !defined(BOOST_MSVC) || BOOST_MSVC > 1300 // MSVC brokenness
    // advance some more so that state is exercised
    for(int i = 0; i < 10000; ++i) {
      urng();
      urng2();
    }
    BOOST_CHECK(urng == urng2);
#endif // BOOST_MSVC
  }
#endif // BOOST_NO_STD_WSTREAMBUF, BOOST_NO_STD_WSTRING
#endif // BOOST_NO_OPERATORS_IN_NAMESPACE etc.

  // instantiate various distributions with this URNG
  // instantiate_dist(urng, "uniform_smallint", boost::uniform_smallint(0, 11));
  instantiate_dist(urng, "uniform_int", boost::uniform_int<>(-200, 20000));
  instantiate_dist(urng, "bernoulli_distribution",
                   boost::bernoulli_distribution<>(0.2));
  instantiate_dist(urng, "binomial_distribution",
                   boost::binomial_distribution<>(4, 0.2));
  instantiate_dist(urng, "geometric_distribution",
                   boost::geometric_distribution<>(0.8));
  instantiate_dist(urng, "poisson_distribution",
                   boost::poisson_distribution<>(1));

  instantiate_real_dist(urng, 1.0f);
  instantiate_real_dist(urng, 1.0);
  instantiate_real_dist(urng, 1.0l);

#if 0
  // We cannot compare the outcomes before/after save with std::abs(x-y)
  instantiate_dist("uniform_on_sphere",
                   boost::uniform_on_sphere<URNG>(urng, 2));
#endif
}

void instantiate_all()
{
  using namespace boost;

#if !defined(BOOST_NO_INT64_T) && !defined(BOOST_NO_INTEGRAL_INT64_T)
  instantiate_urng("rand48", rand48(), 0);
  rand48 rnd(boost::int32_t(5));
  rand48 rnd2(boost::uint64_t(0x80000000) * 42);
  rnd.seed(boost::int32_t(17));
  rnd2.seed(boost::uint64_t(0x80000000) * 49);
#endif

  instantiate_urng("minstd_rand0", minstd_rand0(), 0);
  instantiate_urng("minstd_rand", minstd_rand(), 0);
  minstd_rand mstd(42);
  mstd.seed(17);

  instantiate_urng("ecuyer1988", ecuyer1988(), 0);
  instantiate_urng("kreutzer1986", kreutzer1986(), 0);
  instantiate_urng("hellekalek1995", hellekalek1995(), 0);

  instantiate_urng("mt11213b", mt11213b(), 0u);
  instantiate_urng("mt19937", mt19937(), 0u);

  mt19937 mt(boost::uint32_t(17));  // needs to be an exact type match for MSVC
  int i = 42;
  mt.seed(boost::uint32_t(i));
  mt19937 mt2(mstd);
  mt2.seed(mstd);


  random_number_generator<mt19937> std_rng(mt2);
  (void) std_rng(10);

  instantiate_urng("lagged_fibonacci",
                   boost::random::lagged_fibonacci<boost::uint32_t, 24, 607, 273>(),
                   0u);
  instantiate_urng("lagged_fibonacci607", lagged_fibonacci607(), 0.0);

  instantiate_urng("ranlux3", ranlux3(), 0u);
  instantiate_urng("ranlux4", ranlux4(), 0u);

  instantiate_urng("ranlux3_01", ranlux3_01(), 0.0f);
  instantiate_urng("ranlux4_01", ranlux4_01(), 0.0f);

  instantiate_urng("ranlux64_3_01", ranlux64_3_01(), 0.0);
  instantiate_urng("ranlux64_4_01", ranlux64_4_01(), 0.0);

  instantiate_urng("taus88", taus88(), 0u);
}

/*
 * A few equidistribution tests
 */

// yet to come...

template<class Generator>
void check_uniform_int(Generator & gen, int iter)
{
  std::cout << "testing uniform_int(" << (gen.min)() << "," << (gen.max)() 
            << ")" << std::endl;
  int range = (gen.max)()-(gen.min)()+1;
  std::vector<int> bucket(range);
  for(int j = 0; j < iter; j++) {
    int result = gen();
    if(result < (gen.min)() || result > (gen.max)())
      std::cerr << "   ... delivers " << result << std::endl;
    else
      bucket[result-(gen.min)()]++;
  }
  int sum = 0;
  // use a different variable name "k", because MSVC has broken "for" scoping
  for(int k = 0; k < range; k++)
    sum += bucket[k];
  double avg = static_cast<double>(sum)/range;
  double threshold = 2*avg/std::sqrt(static_cast<double>(iter));
  for(int i = 0; i < range; i++) {
    if(std::fabs(bucket[i] - avg) > threshold) {
      // 95% confidence interval
      std::cout << "   ... has bucket[" << i << "] = " << bucket[i] 
                << "  (distance " << (bucket[i] - avg) << ")" 
                << std::endl;
    }
  }
}

template<class Generator>
void test_uniform_int(Generator & gen)
{
  typedef boost::uniform_int<int> int_gen;

  // large range => small range (modulo case)
  typedef boost::variate_generator<Generator&, int_gen> level_one;

  level_one uint12(gen, int_gen(1,2));
  BOOST_CHECK((uint12.distribution().min)() == 1);
  BOOST_CHECK((uint12.distribution().max)() == 2);
  check_uniform_int(uint12, 100000);
  level_one uint16(gen, int_gen(1,6));
  check_uniform_int(uint16, 100000);

  // test chaining to get all cases in operator()

  // identity map
  typedef boost::variate_generator<level_one&, int_gen> level_two;
  level_two uint01(uint12, int_gen(0, 1));
  check_uniform_int(uint01, 100000);

  // small range => larger range
  level_two uint05(uint12, int_gen(-3, 2));
  check_uniform_int(uint05, 100000);

  // larger => small range, rejection case
  typedef boost::variate_generator<level_two&, int_gen> level_three;
  level_three uint1_4(uint05, int_gen(1, 4));
  check_uniform_int(uint1_4, 100000);
}

#if defined(BOOST_MSVC) && _MSC_VER < 1300

// These explicit instantiations are necessary, otherwise MSVC does
// not find the <boost/operators.hpp> inline friends.
// We ease the typing with a suitable preprocessor macro.
#define INSTANT(x) \
template class boost::uniform_smallint<x>; \
template class boost::uniform_int<x>; \
template class boost::uniform_real<x>; \
template class boost::bernoulli_distribution<x>; \
template class boost::geometric_distribution<x>; \
template class boost::triangle_distribution<x>; \
template class boost::exponential_distribution<x>; \
template class boost::normal_distribution<x>; \
template class boost::uniform_on_sphere<x>; \
template class boost::lognormal_distribution<x>;

INSTANT(boost::minstd_rand0)
INSTANT(boost::minstd_rand)
INSTANT(boost::ecuyer1988)
INSTANT(boost::kreutzer1986)
INSTANT(boost::hellekalek1995)
INSTANT(boost::mt19937)
INSTANT(boost::mt11213b)

#undef INSTANT
#endif

#if !defined(BOOST_NO_INT64_T) && !defined(BOOST_NO_INTEGRAL_INT64_T)
// testcase by Mario R�tti
class ruetti_gen
{
public:
  typedef boost::uint64_t result_type;
  result_type min BOOST_PREVENT_MACRO_SUBSTITUTION () const { return 0; }
  result_type max BOOST_PREVENT_MACRO_SUBSTITUTION () const { return std::numeric_limits<result_type>::max BOOST_PREVENT_MACRO_SUBSTITUTION (); }
  result_type operator()() { return (max)()-1; }
};

void test_overflow_range()
{
  ruetti_gen gen;
  boost::variate_generator<ruetti_gen, boost::uniform_int<> >
    rng(gen, boost::uniform_int<>(0, 10));
  for (int i=0;i<10;i++)
    (void) rng();
}
#else
void test_overflow_range()
{ }
#endif

int test_main(int, char*[])
{

#if !defined(__INTEL_COMPILER) || !defined(_MSC_VER) || __INTEL_COMPILER > 700 
  instantiate_all();
  validate_all();
  boost::mt19937 mt;
  test_uniform_int(mt);

  // bug report from Ken Mahler:  This used to lead to an endless loop.
  typedef boost::uniform_int<unsigned int> uint_dist;
  boost::minstd_rand mr;
  boost::variate_generator<boost::minstd_rand, uint_dist> r2(mr,
                                                            uint_dist(0, 0xffffffff));
  r2();
  r2();

  // bug report from Fernando Cacciola:  This used to lead to an endless loop.
  // also from Douglas Gregor
  boost::variate_generator<boost::minstd_rand, boost::uniform_int<> > x(mr, boost::uniform_int<>(0, 8361));
  (void) x();

  // bug report from Alan Stokes and others: this throws an assertion
  boost::variate_generator<boost::minstd_rand, boost::uniform_int<> > y(mr, boost::uniform_int<>(1,1));
  std::cout << "uniform_int(1,1) " << y() << ", " << y() << ", " << y()
            << std::endl;

  test_overflow_range();

  return 0;
#else
  std::cout << "Intel 7.00 on Win32 loops, so the test is disabled\n";
  return 1;
#endif
}
