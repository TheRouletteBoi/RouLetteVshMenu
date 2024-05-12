//  Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/distributions/non_central_beta.hpp>
// #includes all the files that it needs to.
//
// In order to pass our conceptual tests, we need to forward declare
// those functoins that the non-central beta (deliberately) doesn't 
// implement.  These declarations have to appear *before* the
// non central beta is defined, otherwise two-phase lookup
// won't find them :-(
// 
#include <boost/math/distributions/fwd.hpp>

namespace boost{ namespace math{

template <class T, class Policy>
T mean(const non_central_beta_distribution<T, Policy>&);

template <class T, class Policy>
T variance(const non_central_beta_distribution<T, Policy>&);

template <class T, class Policy>
T skewness(const non_central_beta_distribution<T, Policy>&);

template <class T, class Policy>
T kurtosis(const non_central_beta_distribution<T, Policy>&);

template <class T, class Policy>
T kurtosis_excess(const non_central_beta_distribution<T, Policy>&);

}}

#include <boost/math/distributions/non_central_beta.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

void check()
{
   TEST_DIST_FUNC(non_central_beta)
}

template class boost::math::non_central_beta_distribution<float, boost::math::policies::policy<> >;
template class boost::math::non_central_beta_distribution<double, boost::math::policies::policy<> >;
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
template class boost::math::non_central_beta_distribution<long double, boost::math::policies::policy<> >;
#endif
