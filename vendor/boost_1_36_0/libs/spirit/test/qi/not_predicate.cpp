/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/spirit/include/qi_operator.hpp>
#include <boost/spirit/include/qi_numeric.hpp>
#include <boost/spirit/include/phoenix_core.hpp>

#include <iostream>
#include "test.hpp"

int
main()
{
    using spirit_test::test;
    using namespace boost::spirit;

    {
        BOOST_TEST((!test("1234", !int_)));
        BOOST_TEST((test("abcd", !int_, false)));
    }

    return boost::report_errors();
}
