//
//  shared_ptr_move_test.cpp
//
//  Copyright (c) 2007 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//

#include <boost/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

struct X
{
    static long instances;

    X()
    {
        ++instances;
    }

    ~X()
    {
        --instances;
    }

private:

    X( X const & );
    X & operator=( X const & );
};

long X::instances = 0;

int main()
{
    BOOST_TEST( X::instances == 0 );

    {
        boost::shared_ptr<X> p( new X );
        BOOST_TEST( X::instances == 1 );

        boost::shared_ptr<X> p2( static_cast< boost::shared_ptr<X> && >( p ) );
        BOOST_TEST( X::instances == 1 );
        BOOST_TEST( p.get() == 0 );

        boost::shared_ptr<void> p3( static_cast< boost::shared_ptr<X> && >( p2 ) );
        BOOST_TEST( X::instances == 1 );
        BOOST_TEST( p2.get() == 0 );

        p3.reset();
        BOOST_TEST( X::instances == 0 );
    }

    {
        boost::shared_ptr<X> p( new X );
        BOOST_TEST( X::instances == 1 );

        boost::shared_ptr<X> p2;
        p2 = static_cast< boost::shared_ptr<X> && >( p );
        BOOST_TEST( X::instances == 1 );
        BOOST_TEST( p.get() == 0 );

        boost::shared_ptr<void> p3;
        p3 = static_cast< boost::shared_ptr<X> && >( p2 );
        BOOST_TEST( X::instances == 1 );
        BOOST_TEST( p2.get() == 0 );

        p3.reset();
        BOOST_TEST( X::instances == 0 );
    }

    {
        boost::shared_ptr<X> p( new X );
        BOOST_TEST( X::instances == 1 );

        boost::shared_ptr<X> p2( new X );
        BOOST_TEST( X::instances == 2 );
        p2 = static_cast< boost::shared_ptr<X> && >( p );
        BOOST_TEST( X::instances == 1 );
        BOOST_TEST( p.get() == 0 );

        boost::shared_ptr<void> p3( new X );
        BOOST_TEST( X::instances == 2 );
        p3 = static_cast< boost::shared_ptr<X> && >( p2 );
        BOOST_TEST( X::instances == 1 );
        BOOST_TEST( p2.get() == 0 );

        p3.reset();
        BOOST_TEST( X::instances == 0 );
    }

    return boost::report_errors();
}
