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
#include <vector>
#include <iostream>
#include <functional>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include "allocator_v1.hpp"
#include "check_equal_containers.hpp"
#include "movable_int.hpp"
#include "expand_bwd_test_allocator.hpp"
#include "expand_bwd_test_template.hpp"
#include "dummy_test_allocator.hpp"
#include "vector_test.hpp"

using namespace boost::interprocess;

//Explicit instantiation to detect compilation errors
template class boost::interprocess::vector<test::movable_and_copyable_int, 
   test::dummy_test_allocator<test::movable_and_copyable_int> >;

int test_expand_bwd()
{
   //Now test all back insertion possibilities

   //First raw ints
   typedef test::expand_bwd_test_allocator<int>
      int_allocator_type;
   typedef vector<int, int_allocator_type>
      int_vector;

   if(!test::test_all_expand_bwd<int_vector>())
      return 1;
/*
   //First raw volatile ints
   typedef test::expand_bwd_test_allocator<volatile int>
      volatile_int_allocator_type;
   typedef vector<volatile int, volatile_int_allocator_type>
      volatile_int_vector;

   if(!test::test_all_expand_bwd<volatile_int_vector>())
      return 1;
*/
   //Now user defined wrapped int
   typedef test::expand_bwd_test_allocator<test::int_holder>
      int_holder_allocator_type;
   typedef vector<test::int_holder, int_holder_allocator_type>
      int_holder_vector;

   if(!test::test_all_expand_bwd<int_holder_vector>())
      return 1;

   //Now user defined bigger wrapped int
   typedef test::expand_bwd_test_allocator<test::triple_int_holder>
      triple_int_holder_allocator_type;

   typedef vector<test::triple_int_holder, triple_int_holder_allocator_type>
      triple_int_holder_vector;

   if(!test::test_all_expand_bwd<triple_int_holder_vector>())
      return 1;

   return 0;
}

int main()
{
   typedef allocator<int, managed_shared_memory::segment_manager> ShmemAllocator;
   typedef vector<int, ShmemAllocator> MyVector;

   //typedef allocator<volatile int, managed_shared_memory::segment_manager> ShmemVolatileAllocator;
   //typedef vector<volatile int, ShmemVolatileAllocator> MyVolatileVector;

   typedef allocator<test::movable_int, managed_shared_memory::segment_manager> ShmemMoveAllocator;
   typedef vector<test::movable_int, ShmemMoveAllocator> MyMoveVector;

   typedef allocator<test::movable_and_copyable_int, managed_shared_memory::segment_manager> ShmemCopyMoveAllocator;
   typedef vector<test::movable_and_copyable_int, ShmemCopyMoveAllocator> MyCopyMoveVector;

   if(test::vector_test<managed_shared_memory, MyVector>())
      return 1;

   //if(test::vector_test<managed_shared_memory, MyVolatileVector>())
      //return 1;

   if(test::vector_test<managed_shared_memory, MyMoveVector>())
      return 1;

   if(test::vector_test<managed_shared_memory, MyCopyMoveVector>())
      return 1;

   if(test_expand_bwd())
      return 1;

   return 0;
}

#include <boost/interprocess/detail/config_end.hpp>
