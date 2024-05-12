/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2007
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////
#include <boost/intrusive/list.hpp>
#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/set.hpp>
#include <boost/intrusive/unordered_set.hpp>
#include <boost/intrusive/detail/mpl.hpp>
#include "smart_ptr.hpp"
#include <vector>

using namespace boost::intrusive;

class MyClass
:  public make_list_base_hook
   < void_pointer<smart_ptr<void> >, link_mode<normal_link> >::type
,  public make_slist_base_hook
   < void_pointer<smart_ptr<void> >, link_mode<normal_link> >::type
,  public make_set_base_hook
   < void_pointer<smart_ptr<void> >, link_mode<normal_link> >::type
,  public make_unordered_set_base_hook
   < void_pointer<smart_ptr<void> >, link_mode<normal_link> >::type
{
   int int_;

   public:
   MyClass(int i)
      :  int_(i)
   {}

   friend bool operator<(const MyClass &l, const MyClass &r)
   {  return l.int_ < r.int_; }

   friend bool operator==(const MyClass &l, const MyClass &r)
   {  return l.int_ == r.int_; }

   friend std::size_t hash_value(const MyClass &v)
   {  return boost::hash_value(v.int_); }
};

//Define a list that will store MyClass using the public base hook
typedef make_list<MyClass>::type          List;
typedef make_slist<MyClass>::type         Slist;
typedef make_set<MyClass>::type           Set;
typedef make_unordered_set<MyClass>::type USet;

int main()
{
   typedef std::vector<MyClass>::iterator VectIt;
   typedef std::vector<MyClass>::reverse_iterator VectRit;

   //Create several MyClass objects, each one with a different value
   std::vector<MyClass> values;
   for(int i = 0; i < 100; ++i)  values.push_back(MyClass(i));

   USet::bucket_type buckets[100];

   List  my_list;
   Slist my_slist;
   Set   my_set;
   USet  my_uset(USet::bucket_traits(buckets, 100));

   //Now insert them in containers
   for(VectIt it(values.begin()), itend(values.end()); it != itend; ++it){
      my_list.push_front(*it);
      my_slist.push_front(*it);
      my_set.insert(*it);
      my_uset.insert(*it);
   }

   //Now test lists
   {
      List::const_iterator  list_it(my_list.cbegin());
      Slist::const_iterator slist_it(my_slist.cbegin());
      Set::const_reverse_iterator set_rit(my_set.crbegin());
      VectRit vect_it(values.rbegin()), vect_itend(values.rend());

      //Test the objects inserted in the base hook list
      for(; vect_it != vect_itend; ++vect_it, ++list_it, ++slist_it, ++set_rit){
         if(&*list_it  != &*vect_it)   return 1;
         if(&*slist_it != &*vect_it)   return 1;
         if(&*set_rit  != &*vect_it)   return 1;
         if(my_uset.find(*set_rit) == my_uset.cend())  return 1;
      }
   }

   //Check defined types and implicitly defined types are equal
   if(detail::is_same<make_list_base_hook<void_pointer<void*>, link_mode<safe_link> >::type
                     ,make_list_base_hook<>::type
                     >::value == false){
      return 1;
   }

   if(detail::is_same<make_slist_base_hook<void_pointer<void*>, link_mode<safe_link> >::type
                     ,make_slist_base_hook<>::type
                     >::value == false){
      return 1;
   }

   if(detail::is_same<make_set_base_hook<void_pointer<void*>, link_mode<safe_link> >::type
                     ,make_set_base_hook<>::type
                     >::value == false){
      return 1;
   }

   if(detail::is_same<make_unordered_set_base_hook<void_pointer<void*>, link_mode<safe_link> >::type
                     ,make_unordered_set_base_hook<>::type
                     >::value == false){
      return 1;
   }

   //Check defined types and implicitly defined types are unequal
   if(detail::is_same<make_list_base_hook<void_pointer<void*>, link_mode<normal_link> >::type
                     ,make_list_base_hook<>::type
                     >::value == true){
      return 1;
   }

   if(detail::is_same<make_slist_base_hook<void_pointer<void*>, link_mode<normal_link> >::type
                     ,make_slist_base_hook<>::type
                     >::value == true){
      return 1;
   }

   if(detail::is_same<make_set_base_hook<void_pointer<void*>, link_mode<normal_link> >::type
                     ,make_set_base_hook<>::type
                     >::value == true){
      return 1;
   }

   if(detail::is_same<make_unordered_set_base_hook<void_pointer<void*>, link_mode<normal_link> >::type
                     ,make_unordered_set_base_hook<>::type
                     >::value == true){
      return 1;
   }


   return 0;
}
