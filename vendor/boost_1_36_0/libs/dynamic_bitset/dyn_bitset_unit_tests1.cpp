// --------------------------------------------------------
//        (C) Copyright Jeremy Siek   2001.
//        (C) Copyright Gennaro Prota 2003 - 2006.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// -----------------------------------------------------------
//
// $Id: dyn_bitset_unit_tests1.cpp 41370 2007-11-25 18:38:02Z bemandawes $

#include "bitset_test.hpp"
#include "boost/dynamic_bitset/dynamic_bitset.hpp"
#include "boost/limits.hpp"
#include "boost/config.hpp"

#include "boost/detail/workaround.hpp"

#define BOOST_BITSET_TEST_COUNT_OF(x) (sizeof(x)/sizeof(x[0]))


// Codewarrior 8.3 for Win fails without this.
// Thanks Howard Hinnant ;)
#if defined __MWERKS__ && BOOST_WORKAROUND(__MWERKS__, <= 0x3003) // 8.x
# pragma parse_func_templ off
#endif


template <typename Tests, typename String>
void run_string_tests(const String& s
                      BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tests)
                     )
{

  const std::size_t len = s.length();
  const std::size_t step = len/4 ? len/4 : 1;

  // bitset length determined by the string-related arguments
  std::size_t i;
  for (i = 0; i <= len/2 ; i += step) {
    Tests::from_string(s, i, len/2);     // len/2 - i bits
    Tests::from_string(s, i, len);       // len - i   bits
    Tests::from_string(s, i, 1 + len*2); // len - i   bits
  }

  // bitset length explicitly specified
  for (i = 0; i <= len/2; i += step) {
    for (std::size_t sz = 0; sz <= len*4; sz+= step*2) {
      Tests::from_string(s, i, len/2, sz);
      Tests::from_string(s, i, len,   sz);
      Tests::from_string(s, i, 1 + len*2, sz);

      }
  }

}

template <typename Block>
void run_test_cases( BOOST_EXPLICIT_TEMPLATE_TYPE(Block) )
{
  typedef boost::dynamic_bitset<Block> bitset_type;
  typedef bitset_test<bitset_type> Tests;
  const int bits_per_block = bitset_type::bits_per_block;

  const std::string long_string = get_long_string();
  const Block all_1s = static_cast<Block>(-1);

  //=====================================================================
  // Test construction from unsigned long
  {
    typedef unsigned long source_type;
    const std::size_t source_width = std::numeric_limits<source_type>::digits;
    const source_type source_max =(std::numeric_limits<source_type>::max)();

    source_type numbers[] = { 0, 1, 40247, source_max >> 1, source_max };
    std::size_t sizes[] =
    { 0, 7 * source_width / 10, source_width, 13 * source_width / 10,
         7 * bits_per_block / 10, bits_per_block, 13 * bits_per_block / 10,
         3 * bits_per_block };

    const std::size_t value_count = BOOST_BITSET_TEST_COUNT_OF(numbers);
    const std::size_t size_count = BOOST_BITSET_TEST_COUNT_OF(sizes);

    for (std::size_t v = 0; v < value_count; ++v) {
      for (std::size_t s = 0; s < size_count; ++s) {
        Tests::from_unsigned_long(sizes[s], numbers[v]);
      }
    }
  }
  //=====================================================================
  // Test construction from a string
  {

    run_string_tests<Tests>(std::string("")); // empty string
    run_string_tests<Tests>(std::string("1"));

    run_string_tests<Tests>(long_string);

# if !defined BOOST_NO_STD_WSTRING
    // I need to decide what to do for non "C" locales here. On
    // one hand I should have better tests. On the other one
    // I don't want tests for dynamic_bitset to cope with locales,
    // ctype::widen, etc. (but that's what you deserve when you
    // don't separate concerns at the library level)
    //
    run_string_tests<Tests>(
        std::wstring(L"11111000000111111111010101010101010101010111111"));
# endif

    // Note that these are _valid_ arguments
    Tests::from_string(std::string("x11y"), 1, 2);
    Tests::from_string(std::string("x11"), 1, 10);
    Tests::from_string(std::string("x11"), 1, 10, 10);

  }
  //=====================================================================
  // test from_block_range
  {
    std::vector<Block> blocks;
    Tests::from_block_range(blocks);
  }
  {
    std::vector<Block> blocks(3);
    blocks[0] = static_cast<Block>(0);
    blocks[1] = static_cast<Block>(1);
    blocks[2] = all_1s;
    Tests::from_block_range(blocks);
  }
  {
    const unsigned int n = (std::numeric_limits<unsigned char>::max)();
    std::vector<Block> blocks(n);
    for (typename std::vector<Block>::size_type i = 0; i < n; ++i)
      blocks[i] = static_cast<Block>(i);
    Tests::from_block_range(blocks);
  }
  //=====================================================================
  // test to_block_range
  {
    bitset_type b;
    Tests::to_block_range(b);
  }
  {
    bitset_type b(1, 1ul);
    Tests::to_block_range(b);
  }
  {
    bitset_type b(long_string);
    Tests::to_block_range(b);
  }

  //=====================================================================
  // Test copy constructor
  {
    boost::dynamic_bitset<Block> b;
    Tests::copy_constructor(b);
  }
  {
    boost::dynamic_bitset<Block> b(std::string("0"));
    Tests::copy_constructor(b);
  }
  {
    boost::dynamic_bitset<Block> b(long_string);
    Tests::copy_constructor(b);
  }
  //=====================================================================
  // Test assignment operator
  {
    bitset_type a, b;
    Tests::assignment_operator(a, b);
  }
  {
    bitset_type a(std::string("1")), b(std::string("0"));
    Tests::assignment_operator(a, b);
  }
  {
    bitset_type a(long_string), b(long_string);
    Tests::assignment_operator(a, b);
  }
  {
    bitset_type a;
    bitset_type b(long_string); // b greater than a, a empty
    Tests::assignment_operator(a, b);
  }
  {
    bitset_type a(std::string("0"));
    bitset_type b(long_string); // b greater than a
    Tests::assignment_operator(a, b);
  }
  //=====================================================================
  // Test swap
  {
    bitset_type a;
    bitset_type b(std::string("1"));
    Tests::swap(a, b);
    Tests::swap(b, a);
    Tests::swap(a, a);
  }
  {
    bitset_type a;
    bitset_type b(long_string);
    Tests::swap(a, b);
    Tests::swap(b, a);
  }
  {
    bitset_type a(std::string("0"));
    bitset_type b(long_string);
    Tests::swap(a, b);
    Tests::swap(b, a);
    Tests::swap(a, a);
    Tests::swap(b, b);
  }
  //=====================================================================
  // Test resize
  {
    boost::dynamic_bitset<Block> a;
    Tests::resize(a);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("0"));
    Tests::resize(a);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("1"));
    Tests::resize(a);
  }
  {
    boost::dynamic_bitset<Block> a(long_string);
    Tests::resize(a);
  }
  //=====================================================================
  // Test clear
  {
    boost::dynamic_bitset<Block> a;
    Tests::clear(a);
  }
  {
    boost::dynamic_bitset<Block> a(long_string);
    Tests::clear(a);
  }
  //=====================================================================
  // Test append bit
  {
    boost::dynamic_bitset<Block> a;
    Tests::append_bit(a);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("0"));
    Tests::append_bit(a);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("1"));
    Tests::append_bit(a);
  }
  {
    const int size_to_fill_all_blocks = 4 * bits_per_block;
    boost::dynamic_bitset<Block> a(size_to_fill_all_blocks, 255ul);
    Tests::append_bit(a);
  }
  {
    boost::dynamic_bitset<Block> a(long_string);
    Tests::append_bit(a);
  }
  //=====================================================================
  // Test append block
  {
    boost::dynamic_bitset<Block> a;
    Tests::append_block(a);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("0"));
    Tests::append_block(a);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("1"));
    Tests::append_block(a);
  }
  {
    const int size_to_fill_all_blocks = 4 * bits_per_block;
    boost::dynamic_bitset<Block> a(size_to_fill_all_blocks, 15ul);
    Tests::append_block(a);
  }
  {
    boost::dynamic_bitset<Block> a(long_string);
    Tests::append_block(a);
  }
  //=====================================================================
  // Test append block range
  {
    boost::dynamic_bitset<Block> a;
    std::vector<Block> blocks;
    Tests::append_block_range(a, blocks);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("0"));
    std::vector<Block> blocks(3);
    blocks[0] = static_cast<Block>(0);
    blocks[1] = static_cast<Block>(1);
    blocks[2] = all_1s;
    Tests::append_block_range(a, blocks);
  }
  {
    boost::dynamic_bitset<Block> a(std::string("1"));
    const unsigned int n = (std::numeric_limits<unsigned char>::max)();
    std::vector<Block> blocks(n);
    for (typename std::vector<Block>::size_type i = 0; i < n; ++i)
      blocks[i] = static_cast<Block>(i);
    Tests::append_block_range(a, blocks);
  }
  {
    boost::dynamic_bitset<Block> a;
    a.append(Block(1));
    a.append(Block(2));
    Block x[] = {3, 4, 5};
    std::size_t sz = sizeof(x) / sizeof(x[0]);
    std::vector<Block> blocks(x, x + sz);
    Tests::append_block_range(a, blocks);
  }
  {
    boost::dynamic_bitset<Block> a(long_string);
    std::vector<Block> blocks(3);
    blocks[0] = static_cast<Block>(0);
    blocks[1] = static_cast<Block>(1);
    blocks[2] = all_1s;
    Tests::append_block_range(a, blocks);
  }
  //=====================================================================
  // Test bracket operator
  {
    boost::dynamic_bitset<Block> b1;
    std::vector<bool> bitvec1;
    Tests::operator_bracket(b1, bitvec1);
  }
  {
    boost::dynamic_bitset<Block> b(std::string("1"));
    std::vector<bool> bit_vec(1, true);
    Tests::operator_bracket(b, bit_vec);
  }
  {
    boost::dynamic_bitset<Block> b(long_string);
    std::size_t n = long_string.size();
    std::vector<bool> bit_vec(n);
    for (std::size_t i = 0; i < n; ++i)
      bit_vec[i] = long_string[n - 1 - i] == '0' ? 0 : 1;
    Tests::operator_bracket(b, bit_vec);
  }
}

int
test_main(int, char*[])
{
  run_test_cases<unsigned char>();
  run_test_cases<unsigned short>();
  run_test_cases<unsigned int>();
  run_test_cases<unsigned long>();
# ifdef BOOST_HAS_LONG_LONG
  run_test_cases< ::boost::ulong_long_type>();
# endif

  return 0;
}
