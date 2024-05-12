//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2006-2007. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#include <boost/interprocess/detail/config_begin.hpp>
#include <boost/interprocess/detail/workaround.hpp>
//[doc_private_adaptive_pool
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/private_adaptive_pool.hpp>
#include <cassert>

using namespace boost::interprocess;

int main ()
{
   shared_memory_object::remove("MySharedMemory");

   try{
      //Create shared memory
      managed_shared_memory segment(create_only, 
                                    "MySharedMemory",  //segment name
                                    65536);

      //Create a private_adaptive_pool that allocates ints from the managed segment
      //The number of chunks per segment is the default value
      typedef private_adaptive_pool<int, managed_shared_memory::segment_manager>
            private_adaptive_pool_t;
      private_adaptive_pool_t allocator_instance(segment.get_segment_manager());

      //Create another private_adaptive_pool.
      private_adaptive_pool_t allocator_instance2(segment.get_segment_manager());

      //Although the segment manager address
      //is the same, this private_adaptive_pool will have its own pool so
      //"allocator_instance2" CAN'T deallocate nodes allocated by "allocator_instance".
      //"allocator_instance2" is NOT equal to "allocator_instance"
      assert(allocator_instance != allocator_instance2);   

      //Create another adaptive_pool using copy-constructor.
      private_adaptive_pool_t allocator_instance3(allocator_instance2);

      //This allocator is also unequal to allocator_instance2
      assert(allocator_instance2 != allocator_instance3);

      //Pools are destroyed with the allocators
   }
   catch(...){
      shared_memory_object::remove("MySharedMemory");
      throw;
   }
   shared_memory_object::remove("MySharedMemory");
   return 0;
}
//]
#include <boost/interprocess/detail/config_end.hpp>
