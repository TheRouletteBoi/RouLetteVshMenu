///////////////////////////////////////////////////////////////////////////////
// deep_copy.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xpressive/proto/proto.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost;

void foo() {}

void test1()
{
    using namespace proto;

    int i = 42;
    terminal<int &>::type t1 = {i};
    terminal<int>::type r1 = deep_copy(t1);
    BOOST_CHECK_EQUAL(42, arg(r1));

    plus<terminal<int>::type, terminal<int>::type>::type r2 = deep_copy(t1 + 24);
    BOOST_CHECK_EQUAL(42, arg(left(r2)));
    BOOST_CHECK_EQUAL(24, arg(right(r2)));

    char buf[16] = {'\0'};
    terminal<char (&)[16]>::type t3 = {buf};
    terminal<char[16]>::type r3 = deep_copy(t3);

    terminal<void(&)()>::type t4 = {foo};
    plus<terminal<void(&)()>::type, terminal<int>::type>::type r4 = deep_copy(t4 + t1);
    BOOST_CHECK_EQUAL(42, arg(right(r4)));
    BOOST_CHECK_EQUAL(&foo, &arg(left(r4)));
}

using namespace unit_test;
///////////////////////////////////////////////////////////////////////////////
// init_unit_test_suite
//
test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    test_suite *test = BOOST_TEST_SUITE("test deep_copy of proto parse trees");

    test->add(BOOST_TEST_CASE(&test1));

    return test;
}
