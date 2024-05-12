//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2004-2007. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/interprocess/detail/config_begin.hpp>
#include <algorithm>
#include <memory>
#include <deque>
#include <iostream>
#include <functional>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/deque.hpp>
#include <boost/interprocess/indexes/flat_map_index.hpp>
#include "print_container.hpp"
#include "check_equal_containers.hpp"
#include "dummy_test_allocator.hpp"
#include "movable_int.hpp"
#include <boost/interprocess/allocators/allocator.hpp>
#include "allocator_v1.hpp"
#include <boost/interprocess/exceptions.hpp>
#include <boost/interprocess/detail/move_iterator.hpp>
#include <boost/interprocess/detail/move.hpp>
#include <boost/interprocess/detail/mpl.hpp>
#include <boost/interprocess/detail/type_traits.hpp>
#include <string>
#include "get_process_id_name.hpp"

//***************************************************************//
//                                                               //
//  This example repeats the same operations with std::deque and //
//  shmem_deque using the node allocator                         //
//  and compares the values of both containers                   //
//                                                               //
//***************************************************************//

using namespace boost::interprocess;

//Explicit instantiation to detect compilation errors
template class boost::interprocess::deque<test::movable_and_copyable_int, 
   test::dummy_test_allocator<test::movable_and_copyable_int> >;

//Function to check if both sets are equal
template<class V1, class V2>
bool copyable_only(V1 *, V2 *, detail::false_type)
{
   return true;
}

//Function to check if both sets are equal
template<class V1, class V2>
bool copyable_only(V1 *shmdeque, V2 *stddeque, detail::true_type)
{
   typedef typename V1::value_type IntType;
   std::size_t size = shmdeque->size();
   stddeque->insert(stddeque->end(), 50, 1);
   shmdeque->insert(shmdeque->end(), 50, 1);
   if(!test::CheckEqualContainers(shmdeque, stddeque)) return false;
   {
   IntType move_me(1);
   stddeque->insert(stddeque->begin()+size/2, 50, 1);
   shmdeque->insert(shmdeque->begin()+size/2, 50, detail::move_impl(move_me));
   if(!test::CheckEqualContainers(shmdeque, stddeque)) return false;
   }
   {
   IntType move_me(2);
   shmdeque->assign(shmdeque->size()/2, detail::move_impl(move_me));
   stddeque->assign(stddeque->size()/2, 2);
   if(!test::CheckEqualContainers(shmdeque, stddeque)) return false;
   }
   return true;
}

template<class IntType, template<class T, class SegmentManager> class AllocatorType >
bool do_test()
{
   //Customize managed_shared_memory class
   typedef basic_managed_shared_memory
      <char,
      //simple_seq_fit<mutex_family>,
      rbtree_best_fit<mutex_family>,
      //flat_map_index
      iset_index
      > my_managed_shared_memory;

   //Alias AllocatorType type
   typedef AllocatorType<IntType, my_managed_shared_memory::segment_manager>
      shmem_allocator_t;

   //Alias deque types
   typedef deque<IntType, shmem_allocator_t>   MyShmDeque;
   typedef std::deque<int>                     MyStdDeque;
   const int Memsize = 65536;
   const char *const shMemName = test::get_process_id_name();
   const int max = 100;

   try{
      shared_memory_object::remove(shMemName);

      //Create shared memory
      my_managed_shared_memory segment(create_only, shMemName, Memsize);

      segment.reserve_named_objects(100);

      //Shared memory allocator must be always be initialized
      //since it has no default constructor
      MyShmDeque *shmdeque = segment.template construct<MyShmDeque>("MyShmDeque")
                              (segment.get_segment_manager());

      MyStdDeque *stddeque = new MyStdDeque;

      try{
         //Compare several shared memory deque operations with std::deque
         int i;
         for(i = 0; i < max; ++i){
            IntType move_me(i);
            shmdeque->insert(shmdeque->end(), detail::move_impl(move_me));
            stddeque->insert(stddeque->end(), i);
         }
         if(!test::CheckEqualContainers(shmdeque, stddeque)) return 1;

         typename MyShmDeque::iterator it;
         typename MyShmDeque::const_iterator cit = it;

         shmdeque->erase(shmdeque->begin()++);
         stddeque->erase(stddeque->begin()++);
         if(!test::CheckEqualContainers(shmdeque, stddeque)) return 1;

         shmdeque->erase(shmdeque->begin());
         stddeque->erase(stddeque->begin());
         if(!test::CheckEqualContainers(shmdeque, stddeque)) return 1;

         {
            //Initialize values
            IntType aux_vect[50];
            for(int i = 0; i < 50; ++i){
               IntType move_me (-1);
               aux_vect[i] = detail::move_impl(move_me);
            }
            int aux_vect2[50];
            for(int i = 0; i < 50; ++i){
               aux_vect2[i] = -1;
            }

            shmdeque->insert(shmdeque->end()
                              ,detail::make_move_iterator(&aux_vect[0])
                              ,detail::make_move_iterator(aux_vect + 50));
            stddeque->insert(stddeque->end(), aux_vect2, aux_vect2 + 50);
            if(!test::CheckEqualContainers(shmdeque, stddeque)) return false;

            for(int i = 0, j = static_cast<int>(shmdeque->size()); i < j; ++i){
               shmdeque->erase(shmdeque->begin());
               stddeque->erase(stddeque->begin());
            }
            if(!test::CheckEqualContainers(shmdeque, stddeque)) return false;
         }
         {
            IntType aux_vect[50];
            for(int i = 0; i < 50; ++i){
               IntType move_me(-1);
               aux_vect[i] = detail::move_impl(move_me);
            }
            int aux_vect2[50];
            for(int i = 0; i < 50; ++i){
               aux_vect2[i] = -1;
            }
            shmdeque->insert(shmdeque->begin()
                              ,detail::make_move_iterator(&aux_vect[0])
                              ,detail::make_move_iterator(aux_vect + 50));
            stddeque->insert(stddeque->begin(), aux_vect2, aux_vect2 + 50);
            if(!test::CheckEqualContainers(shmdeque, stddeque)) return false;
         }

         if(!copyable_only(shmdeque, stddeque
                        ,detail::bool_<!is_movable<IntType>::value>())){
            return false;
         }

         shmdeque->erase(shmdeque->begin());
         stddeque->erase(stddeque->begin());

         if(!test::CheckEqualContainers(shmdeque, stddeque)) return 1;

         for(i = 0; i < max; ++i){
            IntType move_me(i);
            shmdeque->insert(shmdeque->begin(), detail::move_impl(move_me));
            stddeque->insert(stddeque->begin(), i);
         }
         if(!test::CheckEqualContainers(shmdeque, stddeque)) return 1;

         segment.template destroy<MyShmDeque>("MyShmDeque");
         delete stddeque;
         segment.shrink_to_fit_indexes();

         if(!segment.all_memory_deallocated())
            return 1;
      }
      catch(std::exception &ex){
         std::cout << ex.what() << std::endl;
         return false;
      }
      
      std::cout << std::endl << "Test OK!" << std::endl;
   }
   catch(...){
      shared_memory_object::remove(shMemName);
      throw;
   }
   shared_memory_object::remove(shMemName);
   return true;
}

int main ()
{
   if(!do_test<int, allocator>())
      return 1;

   if(!do_test<test::movable_int, allocator>())
      return 1;

   if(!do_test<int, test::allocator_v1>())
      return 1;

   return 0;
}

#include <boost/interprocess/detail/config_end.hpp>
