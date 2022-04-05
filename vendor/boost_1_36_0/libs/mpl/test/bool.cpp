
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License,Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source$
// $Date: 2006-02-20 10:45:40 -0500 (Mon, 20 Feb 2006) $
// $Revision: 33026 $

#include <boost/mpl/bool.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <cassert>

#define BOOL_TEST(c) \
    { MPL_ASSERT(( is_same< bool_<c>::value_type, bool > )); } \
    { MPL_ASSERT(( is_same< bool_<c>, c##_ > )); } \
    { MPL_ASSERT(( is_same< bool_<c>::type, bool_<c> > )); } \
    { MPL_ASSERT_RELATION( bool_<c>::value, ==, c ); } \
    BOOST_TEST( bool_<c>() == c ); \
/**/

MPL_TEST_CASE()
{
    BOOL_TEST(true)
    BOOL_TEST(false)
}
