
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License,Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source$
// $Date: 2004-09-02 11:41:37 -0400 (Thu, 02 Sep 2004) $
// $Revision: 24874 $

#include <boost/mpl/insert.hpp>

#include <boost/mpl/find.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef vector_c<int,0,1,3,4,5,6,7,8,9> numbers;
    typedef find< numbers,integral_c<int,3> >::type pos;
    typedef insert< numbers,pos,integral_c<int,2> >::type range;
    
    MPL_ASSERT_RELATION( size<range>::value, ==, 10 );
    MPL_ASSERT(( equal< range,range_c<int,0,10> > ));
}
