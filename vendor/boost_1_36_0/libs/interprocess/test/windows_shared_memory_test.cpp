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
#include <boost/interprocess/detail/workaround.hpp>

#ifdef BOOST_WINDOWS

#include <boost/interprocess/windows_shared_memory.hpp>
#include <boost/interprocess/detail/managed_open_or_create_impl.hpp>
#include <boost/interprocess/exceptions.hpp>
#include "named_creation_template.hpp"
#include <cstring>   //for strcmp, memset
#include <iostream>  //for cout
#include <string>  //for string
#include "get_process_id_name.hpp"

using namespace boost::interprocess;

static const char *name_initialization_routine()
{
   static std::string process_name;
   test::get_process_id_name(process_name);
   return process_name.c_str();
}

static const std::size_t ShmSize = 1000;

//This wrapper is necessary to have a common constructor
//in generic named_creation_template functions
class shared_memory_creation_test_wrapper
   : public detail::managed_open_or_create_impl
      <windows_shared_memory, false>
{
   typedef detail::managed_open_or_create_impl
      <windows_shared_memory, false> windows_shared_memory_t;

   public:
   shared_memory_creation_test_wrapper(create_only_t)
      :  windows_shared_memory_t(create_only, name_initialization_routine(), ShmSize)
   {}

   shared_memory_creation_test_wrapper(open_only_t)
      :  windows_shared_memory_t(open_only, name_initialization_routine())
   {}

   shared_memory_creation_test_wrapper(open_or_create_t)
      :  windows_shared_memory_t(open_or_create, name_initialization_routine(), ShmSize)
   {}
};


int main ()
{
   typedef detail::managed_open_or_create_impl<windows_shared_memory, false> windows_shared_memory_t;

   try{
      test::test_named_creation<shared_memory_creation_test_wrapper>();
   }
   catch(std::exception &ex){
      std::cout << ex.what() << std::endl;
      return 1;
   }

   return 0;
}

#else

int main()
{
   return 0;
}

#endif   //#ifdef BOOST_WINDOWS

#include <boost/interprocess/detail/config_end.hpp>
