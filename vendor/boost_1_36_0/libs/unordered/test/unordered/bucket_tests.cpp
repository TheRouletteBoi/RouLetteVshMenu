
// Copyright 2006-2008 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include "../helpers/test.hpp"
#include <algorithm>
#include "../objects/test.hpp"
#include "../helpers/random_values.hpp"
#include "../helpers/helpers.hpp"

namespace bucket_tests {

test::seed_t seed(54635);

template <class X>
void tests(X* = 0, test::random_generator generator = test::default_generator)
{
    typedef BOOST_DEDUCED_TYPENAME X::size_type size_type;
    typedef BOOST_DEDUCED_TYPENAME X::const_local_iterator const_local_iterator;
    test::random_values<X> v(1000, generator);

    X x(v.begin(), v.end());

    BOOST_CHECK(x.bucket_count() < x.max_bucket_count());
    std::cerr<<x.bucket_count()<<"<"<<x.max_bucket_count()<<"\n";

    for(BOOST_DEDUCED_TYPENAME test::random_values<X>::const_iterator
            it = v.begin(), end = v.end(); it != end; ++it)
    {
        size_type bucket = x.bucket(test::get_key<X>(*it));

        BOOST_CHECK(bucket < x.bucket_count());
        if(bucket < x.max_bucket_count()) {
            // lit? lend?? I need a new naming scheme.
            const_local_iterator lit = x.begin(bucket), lend = x.end(bucket);
            while(lit != lend && test::get_key<X>(*it) != test::get_key<X>(*lit)) ++lit;
            BOOST_CHECK(lit != lend);
        }
    }

    for(size_type i = 0; i < x.bucket_count(); ++i) {
        BOOST_CHECK(x.bucket_size(i) == (size_type) std::distance(x.begin(i), x.end(i)));
        BOOST_CHECK(x.bucket_size(i) == (size_type) std::distance(x.cbegin(i), x.cend(i)));
        X const& x_ref = x;
        BOOST_CHECK(x.bucket_size(i) == (size_type) std::distance(x_ref.begin(i), x_ref.end(i)));
        BOOST_CHECK(x.bucket_size(i) == (size_type) std::distance(x_ref.cbegin(i), x_ref.cend(i)));
    }
}

boost::unordered_set<test::object, test::hash, test::equal_to, test::allocator<test::object> >* test_set;
boost::unordered_multiset<test::object, test::hash, test::equal_to, test::allocator<test::object> >* test_multiset;
boost::unordered_map<test::object, test::object, test::hash, test::equal_to, test::allocator<test::object> >* test_map;
boost::unordered_multimap<test::object, test::object, test::hash, test::equal_to, test::allocator<test::object> >* test_multimap;

UNORDERED_TEST(tests, ((test_set)(test_multiset)(test_map)(test_multimap)))

}

RUN_TESTS()
