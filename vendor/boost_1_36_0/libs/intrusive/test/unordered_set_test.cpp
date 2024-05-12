/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Olaf Krzikalla 2004-2006.
// (C) Copyright Ion Gaztanaga  2006-2007.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////
#include <boost/intrusive/detail/config_begin.hpp>
#include <boost/intrusive/unordered_set.hpp>
#include <boost/intrusive/detail/pointer_to_other.hpp>
#include "itestvalue.hpp"
#include "smart_ptr.hpp"
#include "common_functors.hpp"
#include <vector>
#include <set>
#include <boost/detail/lightweight_test.hpp>
#include "test_macros.hpp"
#include "test_container.hpp"

using namespace boost::intrusive;

static const std::size_t BucketSize = 11;

template<class ValueTraits, bool CacheBegin, bool CompareHash>
struct test_unordered_set 
{
   typedef typename ValueTraits::value_type value_type;
   static void test_all(std::vector<value_type>& values);
   static void test_sort(std::vector<value_type>& values);
   static void test_insert(std::vector<value_type>& values);
   static void test_swap(std::vector<value_type>& values);
   static void test_rehash(std::vector<value_type>& values);
   static void test_find(std::vector<value_type>& values);
   static void test_impl();
   static void test_clone(std::vector<value_type>& values);
};

template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_all(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;
   {
      typename unordered_set_type::bucket_type buckets [BucketSize];
      unordered_set_type testset(bucket_traits(buckets, BucketSize));
      testset.insert(values.begin(), values.end());
      test::test_container(testset);
      testset.clear();
      testset.insert(values.begin(), values.end());
      test::test_common_unordered_and_associative_container(testset, values);
      testset.clear();
      testset.insert(values.begin(), values.end());
      test::test_unordered_associative_container(testset, values);
      testset.clear();
      testset.insert(values.begin(), values.end());
      test::test_unique_container(testset, values);
   }
   test_sort(values);
   test_insert(values);
   test_swap(values);
   test_rehash(values);
   test_find(values);
   test_impl();
   test_clone(values);
}

//test case due to an error in tree implementation:
template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_impl()
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;

   std::vector<value_type> values (5);
   for (int i = 0; i < 5; ++i)
      values[i].value_ = i; 

   typename unordered_set_type::bucket_type buckets [BucketSize];
   unordered_set_type testset(bucket_traits(buckets, BucketSize));
   for (int i = 0; i < 5; ++i)
      testset.insert (values[i]);

   testset.erase (testset.iterator_to (values[0]));
   testset.erase (testset.iterator_to (values[1]));
   testset.insert (values[1]);
   testset.erase (testset.iterator_to (values[2]));
   testset.erase (testset.iterator_to (values[3]));
}

//test: constructor, iterator, clear, reverse_iterator, front, back, size:
template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_sort(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;

   typename unordered_set_type::bucket_type buckets [BucketSize];
   unordered_set_type testset1(values.begin(), values.end(), bucket_traits(buckets, BucketSize));
   
   BOOST_TEST (5 == std::distance(testset1.begin(), testset1.end()));
   {  int init_values [] = { 1, 2, 3, 4, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }
    
   testset1.clear();
   BOOST_TEST (testset1.empty());
}  
  
//test: insert, const_iterator, const_reverse_iterator, erase, iterator_to:
template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_insert(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;

   typename unordered_set_type::bucket_type buckets [BucketSize];
   unordered_set_type testset(bucket_traits(buckets, BucketSize));
   testset.insert(&values[0] + 2, &values[0] + 5);

   const unordered_set_type& const_testset = testset;
   {  int init_values [] = { 1, 4, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, const_testset.begin() );  }

   typename unordered_set_type::iterator i = testset.begin();
   BOOST_TEST (i->value_ == 1);

   i = testset.insert(values[0]).first;
   BOOST_TEST (&*i == &values[0]);

   i = testset.iterator_to (values[2]);
   BOOST_TEST (&*i == &values[2]);

   testset.erase (i);

   {  int init_values [] = { 1, 3, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, const_testset.begin() );  }
}  

//test: insert (seq-version), swap, erase (seq-version), size:
template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_swap(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;

   typename unordered_set_type::bucket_type buckets1 [BucketSize];
   typename unordered_set_type::bucket_type buckets2 [BucketSize];
   unordered_set_type testset1(&values[0], &values[0] + 2, bucket_traits(buckets1, BucketSize));
   unordered_set_type testset2(bucket_traits(buckets2, BucketSize));

   testset2.insert (&values[0] + 2, &values[0] + 6);
   testset1.swap (testset2);

   {  int init_values [] = { 1, 2, 4, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }
   {  int init_values [] = { 2, 3 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset2.begin() );  }

   testset1.erase (testset1.iterator_to(values[5]), testset1.end());
   BOOST_TEST (testset1.size() == 1);
   //  BOOST_TEST (&testset1.front() == &values[3]);
   BOOST_TEST (&*testset1.begin() == &values[3]);
}  

//test: rehash:
template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_rehash(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;

   typename unordered_set_type::bucket_type buckets1 [BucketSize];
   typename unordered_set_type::bucket_type buckets2 [2];
   typename unordered_set_type::bucket_type buckets3 [BucketSize*2];

   unordered_set_type testset1(&values[0], &values[0] + 6, bucket_traits(buckets1, BucketSize));
   BOOST_TEST (testset1.size() == 5);
   {  int init_values [] = { 1, 2, 3, 4, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }

   testset1.rehash(bucket_traits(buckets2, 2));
   BOOST_TEST (testset1.size() == 5);
   {  int init_values [] = { 4, 2, 5, 3, 1 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }

   testset1.rehash(bucket_traits(buckets3, BucketSize*2));
   BOOST_TEST (testset1.size() == 5);
   {  int init_values [] = { 1, 2, 3, 4, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }

   //Now rehash reducing the buckets
   testset1.rehash(bucket_traits(buckets3, 2));
   BOOST_TEST (testset1.size() == 5);
   {  int init_values [] = { 4, 2, 5, 3, 1 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }

   //Now rehash increasing the buckets
   testset1.rehash(bucket_traits(buckets3, BucketSize*2));
   BOOST_TEST (testset1.size() == 5);
   {  int init_values [] = { 1, 2, 3, 4, 5 };
      TEST_INTRUSIVE_SEQUENCE( init_values, testset1.begin() );  }
}  


//test: find, equal_range (lower_bound, upper_bound):
template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>::test_find(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;

   typename unordered_set_type::bucket_type buckets [BucketSize];
   unordered_set_type testset (values.begin(), values.end(), bucket_traits(buckets, BucketSize));
   typedef typename unordered_set_type::iterator iterator;

   value_type cmp_val;
   cmp_val.value_ = 2;
   iterator i = testset.find (cmp_val);
   BOOST_TEST (i->value_ == 2);
   BOOST_TEST ((++i)->value_ != 2);
   std::pair<iterator,iterator> range = testset.equal_range (cmp_val);
     
   BOOST_TEST (range.first->value_ == 2);
   BOOST_TEST (range.second->value_ == 3);
   BOOST_TEST (std::distance (range.first, range.second) == 1);

   cmp_val.value_ = 7;
   BOOST_TEST (testset.find (cmp_val) == testset.end());
}

template<class ValueTraits, bool CacheBegin, bool CompareHash>
void test_unordered_set<ValueTraits, CacheBegin, CompareHash>
   ::test_clone(std::vector<typename ValueTraits::value_type>& values)
{
   typedef typename ValueTraits::value_type value_type;
   typedef unordered_set
      <value_type
      , value_traits<ValueTraits>
      , constant_time_size<value_type::constant_time_size>
      , cache_begin<CacheBegin>
      , compare_hash<CompareHash>
      > unordered_set_type;
   typedef typename unordered_set_type::bucket_traits bucket_traits;
   {
      //Test with equal bucket arrays
      typename unordered_set_type::bucket_type buckets1 [BucketSize];
      typename unordered_set_type::bucket_type buckets2 [BucketSize];
      unordered_set_type testset1 (values.begin(), values.end(), bucket_traits(buckets1, BucketSize));
      unordered_set_type testset2 (bucket_traits(buckets2, BucketSize));

      testset2.clone_from(testset1, test::new_cloner<value_type>(), test::delete_disposer<value_type>());
      //Ordering is not guarantee in the cloning so insert data in a set and test
      std::set<typename ValueTraits::value_type>
         src(testset1.begin(), testset1.end());
      std::set<typename ValueTraits::value_type>
         dst(testset2.begin(), testset2.end());
      BOOST_TEST (src.size() == dst.size() && std::equal(src.begin(), src.end(), dst.begin()));
      testset2.clear_and_dispose(test::delete_disposer<value_type>());
      BOOST_TEST (testset2.empty());
   }
   {
      //Test with bigger source bucket arrays
      typename unordered_set_type::bucket_type buckets1 [BucketSize*2];
      typename unordered_set_type::bucket_type buckets2 [BucketSize];
      unordered_set_type testset1 (values.begin(), values.end(), bucket_traits(buckets1, BucketSize*2));
      unordered_set_type testset2 (bucket_traits(buckets2, BucketSize));

      testset2.clone_from(testset1, test::new_cloner<value_type>(), test::delete_disposer<value_type>());
      //Ordering is not guarantee in the cloning so insert data in a set and test
      std::set<typename ValueTraits::value_type>
         src(testset1.begin(), testset1.end());
      std::set<typename ValueTraits::value_type>
         dst(testset2.begin(), testset2.end());
      BOOST_TEST (src.size() == dst.size() && std::equal(src.begin(), src.end(), dst.begin()));
      testset2.clear_and_dispose(test::delete_disposer<value_type>());
      BOOST_TEST (testset2.empty());
   }
   {
      //Test with smaller source bucket arrays
      typename unordered_set_type::bucket_type buckets1 [BucketSize];
      typename unordered_set_type::bucket_type buckets2 [BucketSize*2];
      unordered_set_type testset1 (values.begin(), values.end(), bucket_traits(buckets1, BucketSize));
      unordered_set_type testset2 (bucket_traits(buckets2, BucketSize*2));

      testset2.clone_from(testset1, test::new_cloner<value_type>(), test::delete_disposer<value_type>());
      //Ordering is not guarantee in the cloning so insert data in a set and test
      std::set<typename ValueTraits::value_type>
         src(testset1.begin(), testset1.end());
      std::set<typename ValueTraits::value_type>
         dst(testset2.begin(), testset2.end());
      BOOST_TEST (src.size() == dst.size() && std::equal(src.begin(), src.end(), dst.begin()));
      testset2.clear_and_dispose(test::delete_disposer<value_type>());
      BOOST_TEST (testset2.empty());
   }
}

template<class VoidPointer, bool constant_time_size>
class test_main_template
{
   public:
   int operator()()
   {
      typedef testvalue<VoidPointer, constant_time_size> value_type;
      static const int random_init[6] = { 3, 2, 4, 1, 5, 2 };
      std::vector<testvalue<VoidPointer, constant_time_size> > data (6);
      for (int i = 0; i < 6; ++i)
         data[i].value_ = random_init[i]; 

      test_unordered_set < typename detail::get_base_value_traits
                  < value_type
                  , typename value_type::unordered_set_base_hook_t
                  >::type
                , true
                , false
                >::test_all(data);
      test_unordered_set < typename detail::get_member_value_traits
                  < value_type
                  , member_hook< value_type
                               , typename value_type::unordered_set_member_hook_t
                               , &value_type::unordered_set_node_
                               >
                  >::type
                , false
                , false
                >::test_all(data);

      return 0;
   }
};

template<class VoidPointer>
class test_main_template<VoidPointer, false>
{
   public:
   int operator()()
   {
      typedef testvalue<VoidPointer, false> value_type;
      static const int random_init[6] = { 3, 2, 4, 1, 5, 2 };
      std::vector<testvalue<VoidPointer, false> > data (6);
      for (int i = 0; i < 6; ++i)
         data[i].value_ = random_init[i]; 

      test_unordered_set < typename detail::get_base_value_traits
                  < value_type
                  , typename value_type::unordered_set_base_hook_t
                  >::type
                , true
                , false
                >::test_all(data);

      test_unordered_set < typename detail::get_member_value_traits
                  < value_type
                  , member_hook< value_type
                               , typename value_type::unordered_set_member_hook_t
                               , &value_type::unordered_set_node_
                               >
                  >::type
                , false
                , false
                >::test_all(data);

      test_unordered_set < typename detail::get_base_value_traits
                  < value_type
                  , typename value_type::unordered_set_auto_base_hook_t
                  >::type
                , true
                , true
                >::test_all(data);

      test_unordered_set < typename detail::get_member_value_traits
                  < value_type
                  , member_hook< value_type
                               , typename value_type::unordered_set_auto_member_hook_t
                               , &value_type::unordered_set_auto_node_
                               >
                  >::type
                , false
                , true
                >::test_all(data);
      return 0;
   }
};

int main( int, char* [] ) 
{
   test_main_template<void*, false>()();
   test_main_template<smart_ptr<void>, false>()();
   test_main_template<void*, true>()();
   test_main_template<smart_ptr<void>, true>()();
   return boost::report_errors();
}
#include <boost/intrusive/detail/config_end.hpp>
