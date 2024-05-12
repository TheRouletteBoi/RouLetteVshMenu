//  Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0.  (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#define BOOST_MATH_TR1_SOURCE
#include <boost/math/tr1.hpp>
#include <boost/math/special_functions/expm1.hpp>
#include "c_policy.hpp"

extern "C" long double BOOST_MATH_TR1_DECL boost_expm1l BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{
   return c_policies::expm1 BOOST_PREVENT_MACRO_SUBSTITUTION(x);
}
