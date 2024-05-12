
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source$
// $Date: 2004-09-02 11:41:37 -0400 (Thu, 02 Sep 2004) $
// $Revision: 24874 $

#include <boost/mpl/aux_/largest_int.hpp>
#include <boost/mpl/aux_/test.hpp>


MPL_TEST_CASE()
{
    MPL_ASSERT(( is_same< mpl::aux::largest_int<bool,bool>::type, bool > ));
    MPL_ASSERT(( is_same< mpl::aux::largest_int<bool,char>::type, char > ));
    MPL_ASSERT(( is_same< mpl::aux::largest_int<char,bool>::type, char > ));
    MPL_ASSERT(( is_same< mpl::aux::largest_int<int,unsigned>::type, unsigned > ));
    MPL_ASSERT(( is_same< mpl::aux::largest_int<unsigned,long>::type, long > ));
}
