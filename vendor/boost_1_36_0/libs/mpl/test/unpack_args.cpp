
// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source$
// $Date: 2004-09-02 11:41:37 -0400 (Thu, 02 Sep 2004) $
// $Revision: 24874 $

#include <boost/mpl/unpack_args.hpp>

#include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/aux_/test.hpp>
#include <boost/type_traits/is_same.hpp>

MPL_TEST_CASE()
{
    MPL_ASSERT(( apply1< 
          unpack_args< is_same<_1,_2> >
        , vector2<int,int>
        > ));
}
