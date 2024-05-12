//  Boost operations_test.cpp  -----------------------------------------------//

//  Copyright Beman Dawes 2002.

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/filesystem

#include <boost/config/warning_disable.hpp>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/cerrno.hpp>
namespace fs = boost::filesystem;

#include <boost/config.hpp>
#include <boost/test/minimal.hpp>
//#include <boost/concept_check.hpp>

using boost::system::error_code;
using boost::system::system_category;
using boost::system::system_error;

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> // for system()

#ifndef BOOST_FILESYSTEM_NARROW_ONLY
# define BOOST_BND(BOOST_FUNC_TO_DO) BOOST_FUNC_TO_DO<fs::path>
#else
# define BOOST_BND(BOOST_FUNC_TO_DO) BOOST_FUNC_TO_DO
#endif

// VC++ 7.0 and earlier has a serious namespace bug that causes a clash
// between boost::filesystem::is_empty and the unrelated type trait
// boost::is_empty.
#if !defined( BOOST_MSVC ) || BOOST_MSVC > 1300
# define BOOST_FS_IS_EMPTY fs::is_empty
#else
# define BOOST_FS_IS_EMPTY fs::_is_empty
#endif

# ifdef BOOST_NO_STDC_NAMESPACE
    namespace std { using ::asctime; using ::gmtime; using ::localtime;
    using ::difftime; using ::time; using ::tm; using ::mktime; using ::system; }
# endif

#ifdef BOOST_WINDOWS_API
# include <windows.h>
#endif

#define CHECK_EXCEPTION(Functor,Expect) throws_fs_error(Functor,Expect,__LINE__)

namespace
{
  typedef int errno_t;
  std::string platform( BOOST_PLATFORM );
  bool report_throws;
  fs::directory_iterator end_itr;

  unsigned short language_id;  // 0 except for Windows

  const char * temp_dir_name = "temp_fs_test_dir";

  void create_file( const fs::path & ph, const std::string & contents )
  {
    std::ofstream f( ph.file_string().c_str() );
    if ( !f )
      throw fs::filesystem_error( "operations_test create_file",
      ph, error_code(errno, system_category) );
    if ( !contents.empty() ) f << contents;
  }

  void verify_file( const fs::path & ph, const std::string & expected )
  {
    std::ifstream f( ph.file_string().c_str() );
    if ( !f )
      throw fs::filesystem_error( "operations_test verify_file",
        ph, error_code(errno, system_category) );
    std::string contents;
    f >> contents;
    if ( contents != expected )
      throw fs::filesystem_error( "operations_test verify_file contents \""
        + contents  + "\" != \"" + expected + "\"", ph, error_code() );
  }

  template< typename F >
    bool throws_fs_error( F func, errno_t en, int line )
  {
    try { func(); }

    catch ( const fs::filesystem_error & ex )
    {
      if ( report_throws )
      {
        // use the what() convenience function to display exceptions
        std::cout << "\n" << ex.what() << "\n";
      }
      if ( en == 0
        || en == ex.code().default_error_condition().value() ) return true;
      std::cout
        << "\nWarning: line " << line
        << " exception reports default_error_condition().value() " << ex.code().default_error_condition().value()
        << ", should be " << en
        << "\n value() is " << ex.code().value()
        << std::endl;
      return true;
    }
    return false;
  }

  // compile-only two argument "do-the-right-thing" tests
  //   verifies that all overload combinations compile without error
  void do_not_call()
  {
    fs::path p;
    std::string s;
    const char * a = 0;
    fs::copy_file( p, p );
    fs::copy_file( s, p );
    fs::copy_file( a, p );
    fs::copy_file( p, s );
    fs::copy_file( p, a );
    fs::copy_file( s, s );
    fs::copy_file( a, s );
    fs::copy_file( s, a );
    fs::copy_file( a, a );
  }

  void exception_tests()
  {
    bool exception_thrown;
    exception_thrown = false;
    try
    {
      fs::create_directory( "no-such-dir/foo/bar" );
    }
    catch ( std::runtime_error x )
    {
      exception_thrown = true;
      if ( report_throws ) std::cout << x.what() << std::endl;
      if ( platform == "Windows" && language_id == 0x0409 ) // English (United States)
        BOOST_CHECK( std::strcmp( x.what(),
          "boost::filesystem::create_directory" ) == 0 );
    }
    BOOST_CHECK( exception_thrown );

    exception_thrown = false;
    try
    {
      fs::create_directory( "no-such-dir/foo/bar" );
    }
    catch ( system_error x )
    {
      exception_thrown = true;
      if ( report_throws ) std::cout << x.what() << std::endl;
      if ( platform == "Windows" && language_id == 0x0409 ) // English (United States)
        BOOST_CHECK( std::strcmp( x.what(),
          "boost::filesystem::create_directory: The system cannot find the path specified" ) == 0 );
    }
    BOOST_CHECK( exception_thrown );

    exception_thrown = false;
    try
    {
      fs::create_directory( "no-such-dir/foo/bar" );
    }
    catch ( fs::filesystem_error x )
    {
      exception_thrown = true;
      if ( report_throws ) std::cout << x.what() << std::endl;
      if ( platform == "Windows" && language_id == 0x0409 ) // English (United States)
      {
        bool ok ( std::strcmp( x.what(),
          "boost::filesystem::create_directory: The system cannot find the path specified: \"no-such-dir\\foo\\bar\"" ) == 0 );
        BOOST_CHECK( ok );
        if ( !ok )
        {
          std::cout << "what returns \"" << x.what() << "\"" << std::endl;
        }
      }
    }
    BOOST_CHECK( exception_thrown );

    exception_thrown = false;
    try
    {
      fs::create_directory( "no-such-dir/foo/bar" );
    }
    catch ( const fs::filesystem_error & x )
    {
      exception_thrown = true;
      if ( report_throws ) std::cout << x.what() << std::endl;
      if ( platform == "Windows" && language_id == 0x0409 ) // English (United States)
      {
        bool ok ( std::strcmp( x.what(),
          "boost::filesystem::create_directory: The system cannot find the path specified: \"no-such-dir\\foo\\bar\"" ) == 0 );
        BOOST_CHECK( ok );
        if ( !ok )
        {
          std::cout << "what returns \"" << x.what() << "\"" << std::endl;
        }
      }
    }
    BOOST_CHECK( exception_thrown );
  }

  void bad_file_size()
  {
    fs::file_size( " No way, Jose" );
  }
  
  void bad_directory_size()
  {
    fs::file_size( fs::current_path() );
  }
  
  fs::path bad_create_directory_path;
  void bad_create_directory()
  {
    fs::create_directory( bad_create_directory_path );
  }
  
  void bad_equivalent()
  {
    fs::equivalent( "no-such-path", "another-not-present-path" );
  }

  fs::path bad_remove_dir;
  void bad_remove()
  {
    fs::remove( bad_remove_dir );
  }

  class renamer
  {
  public:
    renamer( const fs::path & p1, const fs::path & p2 )
      : from(p1), to(p2) {}
    void operator()()
    {
      fs::rename( from, to );
    }
  private:
    fs::path from;
    fs::path to;
  };
  
} // unnamed namespace

//  test_main  ---------------------------------------------------------------//

int test_main( int argc, char * argv[] )
{
  if ( argc > 1 && *argv[1]=='-' && *(argv[1]+1)=='t' ) report_throws = true;

  // The choice of platform is make at runtime rather than compile-time
  // so that compile errors for all platforms will be detected even though
  // only the current platform is runtime tested.
# if defined( BOOST_POSIX_API )
    platform = "POSIX";
# elif defined( BOOST_WINDOWS_API )
    platform = "Windows";
#   if !defined(__MINGW32__) && !defined(__CYGWIN__)
      language_id = ::GetUserDefaultUILanguage();
#   else
      language_id = 0x0409; // Assume US English
#   endif
# else
    platform = ( platform == "Win32" || platform == "Win64" || platform == "Cygwin" )
               ? "Windows"
               : "POSIX";
# endif
  std::cout << "API is " << platform << std::endl;

  exception_tests();

  std::cout << "\ninitial_path<path>().string() is\n  \""
    << fs::initial_path<fs::path>().string()
            << "\"\n";
  std::cout << "\ninitial_path<fs::path>().file_string() is\n  \""
            << fs::initial_path<fs::path>().file_string()
            << "\"\n\n";
  BOOST_CHECK( fs::initial_path<fs::path>().is_complete() );
  BOOST_CHECK( fs::current_path<fs::path>().is_complete() );
  BOOST_CHECK( fs::initial_path<fs::path>().string()
    == fs::current_path<fs::path>().string() );

  BOOST_CHECK( fs::complete( "" ).empty() );
  BOOST_CHECK( fs::complete( "/" ).string() == fs::initial_path<fs::path>().root_path().string() );
  BOOST_CHECK( fs::complete( "foo" ).string() == fs::initial_path<fs::path>().string()+"/foo" );
  BOOST_CHECK( fs::complete( "/foo" ).string() == fs::initial_path<fs::path>().root_path().string()+"foo" );
  BOOST_CHECK( fs::complete( "foo", fs::path( "//net/bar" ) ).string()
      ==  "//net/bar/foo" );

  // predicate and status tests
  fs::path ng( " no-way, Jose" );
  BOOST_CHECK( !fs::exists( ng ) );
  BOOST_CHECK( !fs::is_directory( ng ) );
  BOOST_CHECK( !fs::is_regular_file( ng ) );
  BOOST_CHECK( !fs::is_regular( ng ) );  // verify deprecated name still works
  BOOST_CHECK( !fs::is_symlink( ng ) );
  fs::file_status stat( fs::status( ng ) );
  BOOST_CHECK( fs::status_known( stat ) );
  BOOST_CHECK( !fs::exists( stat ) );
  BOOST_CHECK( !fs::is_directory( stat ) );
  BOOST_CHECK( !fs::is_regular_file( stat ) );
  BOOST_CHECK( !fs::is_other( stat ) );
  BOOST_CHECK( !fs::is_symlink( stat ) );
  stat = fs::status( "" );
  BOOST_CHECK( fs::status_known( stat ) );
  BOOST_CHECK( !fs::exists( stat ) );
  BOOST_CHECK( !fs::is_directory( stat ) );
  BOOST_CHECK( !fs::is_regular_file( stat ) );
  BOOST_CHECK( !fs::is_other( stat ) );
  BOOST_CHECK( !fs::is_symlink( stat ) );

  fs::path dir(  fs::initial_path<fs::path>() / temp_dir_name );
  
  // Windows only tests
  if ( platform == "Windows" )
  {
    BOOST_CHECK( !fs::exists( fs::path( "//share-not" ) ) );
    BOOST_CHECK( !fs::exists( fs::path( "//share-not/" ) ) );
    BOOST_CHECK( !fs::exists( fs::path( "//share-not/foo" ) ) );
    BOOST_CHECK( !fs::exists( "tools/jam/src/:sys:stat.h" ) ); // !exists() if ERROR_INVALID_NAME
    BOOST_CHECK( !fs::exists( ":sys:stat.h" ) ); // !exists() if ERROR_INVALID_PARAMETER
    BOOST_CHECK( dir.string().size() > 1
      && dir.string()[1] == ':' ); // verify path includes drive

    BOOST_CHECK( fs::system_complete( "" ).empty() );
    BOOST_CHECK( fs::system_complete( "/" ).string()
      == fs::initial_path<fs::path>().root_path().string() );
    BOOST_CHECK( fs::system_complete( "foo" ).string()
      == fs::initial_path<fs::path>().string()+"/foo" );
    BOOST_CHECK( fs::system_complete( "/foo" ).string()
      == fs::initial_path<fs::path>().root_path().string()+"foo" );
    BOOST_CHECK( fs::complete( fs::path( "c:/" ) ).string()
      == "c:/" );
    BOOST_CHECK( fs::complete( fs::path( "c:/foo" ) ).string()
      ==  "c:/foo" );

    BOOST_CHECK( fs::system_complete( fs::path( fs::initial_path<fs::path>().root_name() ) ).string() == fs::initial_path<fs::path>().string() );
    BOOST_CHECK( fs::system_complete( fs::path( fs::initial_path<fs::path>().root_name()
      + "foo" ) ).string() == fs::initial_path<fs::path>().string()+"/foo" );
    BOOST_CHECK( fs::system_complete( fs::path( "c:/" ) ).string()
      == "c:/" );
    BOOST_CHECK( fs::system_complete( fs::path( "c:/foo" ) ).string()
      ==  "c:/foo" );
    BOOST_CHECK( fs::system_complete( fs::path( "//share" ) ).string()
      ==  "//share" );
  } // Windows

  else if ( platform == "POSIX" )
  {
    BOOST_CHECK( fs::system_complete( "" ).empty() );
    BOOST_CHECK( fs::initial_path<fs::path>().root_path().string() == "/" );
    BOOST_CHECK( fs::system_complete( "/" ).string() == "/" );
    BOOST_CHECK( fs::system_complete( "foo" ).string()
      == fs::initial_path<fs::path>().string()+"/foo" );
    BOOST_CHECK( fs::system_complete( "/foo" ).string()
      == fs::initial_path<fs::path>().root_path().string()+"foo" );
  } // POSIX

  fs::remove_all( dir );  // in case residue from prior failed tests
  BOOST_CHECK( !fs::exists( dir ) );

  // the bound functions should throw, so CHECK_EXCEPTION() should return true
  BOOST_CHECK( CHECK_EXCEPTION( bad_file_size, ENOENT ) );

  // test path::exception members
  try { fs::file_size( ng ); } // will throw

  catch ( const fs::filesystem_error & ex )
  {
    BOOST_CHECK( ex.path1().string() == " no-way, Jose" );
  }
  // several functions give unreasonable results if uintmax_t isn't 64-bits
  std::cout << "sizeof(boost::uintmax_t) = " << sizeof(boost::uintmax_t) << '\n';
  BOOST_CHECK( sizeof( boost::uintmax_t ) >= 8 );

  // create a directory, then check it for consistency
  BOOST_CHECK( fs::create_directory( dir ) );

  BOOST_CHECK( fs::exists( dir ) );
  BOOST_CHECK( BOOST_FS_IS_EMPTY( dir ) );
  BOOST_CHECK( fs::is_directory( dir ) );
  BOOST_CHECK( !fs::is_regular_file( dir ) );
  BOOST_CHECK( !fs::is_other( dir ) );
  BOOST_CHECK( !fs::is_symlink( dir ) );
  stat = fs::status( dir );
  BOOST_CHECK( fs::exists( stat ) );
  BOOST_CHECK( fs::is_directory( stat ) );
  BOOST_CHECK( !fs::is_regular_file( stat ) );
  BOOST_CHECK( !fs::is_other( stat ) );
  BOOST_CHECK( !fs::is_symlink( stat ) );

  // set the current directory, then check it for consistency
  fs::path original_dir = fs::current_path<fs::path>();
  BOOST_CHECK( dir != original_dir );
  fs::current_path( dir );
  BOOST_CHECK( fs::current_path<fs::path>() == dir );
  BOOST_CHECK( fs::current_path<fs::path>() != original_dir );
  fs::current_path( original_dir );
  BOOST_CHECK( fs::current_path<fs::path>() == original_dir );
  BOOST_CHECK( fs::current_path<fs::path>() != dir );
  // make sure the overloads work
  fs::current_path( dir.string().c_str() );
  BOOST_CHECK( fs::current_path<fs::path>() == dir );
  BOOST_CHECK( fs::current_path<fs::path>() != original_dir );
  fs::current_path( original_dir.string() );
  BOOST_CHECK( fs::current_path<fs::path>() == original_dir );
  BOOST_CHECK( fs::current_path<fs::path>() != dir );

  // make some reasonable assuptions for testing purposes
  fs::space_info spi( fs::space( dir ) );
  BOOST_CHECK( spi.capacity > 1000000 );
  BOOST_CHECK( spi.free > 1000 );
  BOOST_CHECK( spi.capacity > spi.free );
  BOOST_CHECK( spi.free >= spi.available );

  // it is convenient to display space, but older VC++ versions choke 
# if !defined(BOOST_MSVC) || _MSC_VER >= 1300  // 1300 == VC++ 7.0
    std::cout << " capacity = " << spi.capacity << '\n';
    std::cout << "     free = " << spi.free << '\n';
    std::cout << "available = " << spi.available << '\n';
# endif

  if ( platform == "Windows" )
    BOOST_CHECK( CHECK_EXCEPTION( bad_directory_size, ENOENT ) );
  else
    BOOST_CHECK( CHECK_EXCEPTION( bad_directory_size, 0 ) );
  BOOST_CHECK( !fs::create_directory( dir ) );

  BOOST_CHECK( !fs::is_symlink( dir ) );
  BOOST_CHECK( !fs::is_symlink( "nosuchfileordirectory" ) );

  BOOST_CHECK( !fs::symbolic_link_exists( dir ) );
  BOOST_CHECK( !fs::symbolic_link_exists( "nosuchfileordirectory" ) );

  fs::path d1( dir / "d1" );
  BOOST_CHECK( fs::create_directory( d1 ) );
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( fs::is_directory( d1 ) );
  BOOST_CHECK( BOOST_FS_IS_EMPTY( d1 ) );

//  boost::function_requires< boost::InputIteratorConcept< fs::directory_iterator > >();

  bool dir_itr_exception(false);
  try { fs::directory_iterator it( "" ); }
  catch ( const fs::filesystem_error & ) { dir_itr_exception = true; }
  BOOST_CHECK( dir_itr_exception );

  dir_itr_exception = false;
  try { fs::directory_iterator it( "nosuchdirectory" ); }
  catch ( const fs::filesystem_error & ) { dir_itr_exception = true; }
  BOOST_CHECK( dir_itr_exception );

  dir_itr_exception = false;
  try
  {
    error_code ec;
    fs::directory_iterator it( "nosuchdirectory", ec );
    BOOST_CHECK( ec );
    BOOST_CHECK( ec == fs::detail::not_found_error() );
  }
  catch ( const fs::filesystem_error & ) { dir_itr_exception = true; }
  BOOST_CHECK( !dir_itr_exception );
  
  {
    // probe query function overloads
    fs::directory_iterator dir_itr( dir );
    BOOST_CHECK( fs::is_directory( *dir_itr ) );
    BOOST_CHECK( fs::is_directory( dir_itr->status() ) );
    BOOST_CHECK( fs::is_directory( fs::symlink_status(*dir_itr) ) );
    BOOST_CHECK( fs::is_directory( dir_itr->symlink_status() ) );
    BOOST_CHECK( dir_itr->filename() == "d1" );
  }

  // create a second directory named d2
  fs::path d2( dir / "d2" );
  fs::create_directory(d2 );
  BOOST_CHECK( fs::exists( d2 ) );
  BOOST_CHECK( fs::is_directory( d2 ) );

  // test the basic operation of directory_iterators, and test that
  // stepping one iterator doesn't affect a different iterator.
  {
    fs::directory_iterator dir_itr( dir );
    BOOST_CHECK( fs::exists(dir_itr->status()) );
    BOOST_CHECK( fs::is_directory(dir_itr->status()) );
    BOOST_CHECK( !fs::is_regular_file(dir_itr->status()) );
    BOOST_CHECK( !fs::is_other(dir_itr->status()) );
    BOOST_CHECK( !fs::is_symlink(dir_itr->status()) );

    fs::directory_iterator dir_itr2( dir );
    BOOST_CHECK( dir_itr->filename() == "d1"
      || dir_itr->filename() == "d2" );
    BOOST_CHECK( dir_itr2->filename() == "d1" || dir_itr2->filename() == "d2" );
    if ( dir_itr->filename() == "d1" )
    {
      BOOST_CHECK( (++dir_itr)->filename() == "d2" );
      BOOST_CHECK( dir_itr2->filename() == "d1" );
      BOOST_CHECK( (++dir_itr2)->filename() == "d2" );
    }
    else
    {
      BOOST_CHECK( dir_itr->filename() == "d2" );
      BOOST_CHECK( (++dir_itr)->filename() == "d1" );
      BOOST_CHECK( (dir_itr2)->filename() == "d2" );
      BOOST_CHECK( (++dir_itr2)->filename() == "d1" );
    }
    BOOST_CHECK( ++dir_itr == fs::directory_iterator() );
    BOOST_CHECK( dir_itr2 != fs::directory_iterator() );
    BOOST_CHECK( ++dir_itr2 == fs::directory_iterator() );
  }

  { // *i++ must work to meet the standard's InputIterator requirements
    fs::directory_iterator dir_itr( dir );
    BOOST_CHECK( dir_itr->filename() == "d1"
      || dir_itr->filename() == "d2" );
    if ( dir_itr->filename() == "d1" )
    {
      BOOST_CHECK( (*dir_itr++).filename() == "d1" );
      BOOST_CHECK( dir_itr->filename() == "d2" );
    }
    else
    {
      // Check C++98 input iterator requirements
      BOOST_CHECK( (*dir_itr++).filename() == "d2" );
      // input iterator requirements in the current WP would require this check:
      // BOOST_CHECK( implicit_cast<std::string const&>(*dir_itr++).filename() == "d1" );

      BOOST_CHECK( dir_itr->filename() == "d1" );
    }

    // test case reported in comment to SourceForge bug tracker [937606]
    fs::directory_iterator it( dir );
    const fs::path p1 = *it++;
    BOOST_CHECK( it != fs::directory_iterator() );
    const fs::path p2 = *it++;
    BOOST_CHECK( p1 != p2 );
    BOOST_CHECK( it == fs::directory_iterator() );
  }

  //  Windows has a tricky special case when just the root-name is given,
  //  causing the rest of the path to default to the current directory.
  //  Reported as S/F bug [ 1259176 ]
  if ( platform == "Windows" )
  {
    fs::path root_name_path( fs::current_path<fs::path>().root_name() );
    fs::directory_iterator it( root_name_path );
    BOOST_CHECK( it != fs::directory_iterator() );
    BOOST_CHECK( fs::exists( *it ) );
    BOOST_CHECK( it->path().parent_path() == root_name_path );
    bool found(false);
    do
    {
      if ( it->filename() == temp_dir_name ) found = true;
    } while ( ++it != fs::directory_iterator() );
    BOOST_CHECK( found );
  }

  // create an empty file named "f0"
  fs::path file_ph( dir / "f0");
  create_file( file_ph, "" );
  BOOST_CHECK( fs::exists( file_ph ) );
  BOOST_CHECK( !fs::is_directory( file_ph ) );
  BOOST_CHECK( fs::is_regular_file( file_ph ) );
  BOOST_CHECK( BOOST_FS_IS_EMPTY( file_ph ) );
  BOOST_CHECK( fs::file_size( file_ph ) == 0 );
  bad_create_directory_path = file_ph;
  BOOST_CHECK( CHECK_EXCEPTION( bad_create_directory, EEXIST ) );
  stat = fs::status( file_ph );
  BOOST_CHECK( fs::status_known( stat ) );
  BOOST_CHECK( fs::exists( stat ) );
  BOOST_CHECK( !fs::is_directory( stat ) );
  BOOST_CHECK( fs::is_regular_file( stat ) );
  BOOST_CHECK( !fs::is_other( stat ) );
  BOOST_CHECK( !fs::is_symlink( stat ) );

  // create a file named "f1"
  file_ph = dir / "f1";
  create_file( file_ph, "foobar1" );

  BOOST_CHECK( fs::exists( file_ph ) );
  BOOST_CHECK( !fs::is_directory( file_ph ) );
  BOOST_CHECK( fs::is_regular_file( file_ph ) );
  BOOST_CHECK( fs::file_size( file_ph ) == 7 );
  verify_file( file_ph, "foobar1" );

  // equivalence tests
  BOOST_CHECK( CHECK_EXCEPTION( bad_equivalent, ENOENT ) );
  BOOST_CHECK( fs::equivalent( file_ph, dir / "f1" ) );
  BOOST_CHECK( fs::equivalent( dir, d1 / ".." ) );
  BOOST_CHECK( !fs::equivalent( file_ph, dir ) );
  BOOST_CHECK( !fs::equivalent( dir, file_ph ) );
  BOOST_CHECK( !fs::equivalent( d1, d2 ) );
  BOOST_CHECK( !fs::equivalent( dir, ng ) );
  BOOST_CHECK( !fs::equivalent( ng, dir ) );
  BOOST_CHECK( !fs::equivalent( file_ph, ng ) );
  BOOST_CHECK( !fs::equivalent( ng, file_ph ) );
  
  // hard link tests
  fs::path from_ph( dir / "f3" );
  BOOST_CHECK( !fs::exists( from_ph ) );
  BOOST_CHECK( fs::exists( file_ph ) );
  bool create_hard_link_ok(true);
  try { fs::create_hard_link( file_ph, from_ph ); }
  catch ( const fs::filesystem_error & ex )
  {
    create_hard_link_ok = false;
    std::cout
      << "create_hard_link() attempt failed\n"
      << "filesystem_error.what() reports: " << ex.what() << '\n'
      << "create_hard_link() may not be supported on this file system\n";
  }

  if ( create_hard_link_ok )
  {
    std::cout << "create_hard_link() succeeded\n";
    BOOST_CHECK( fs::exists( from_ph ) );
    BOOST_CHECK( fs::exists( file_ph ) );
    BOOST_CHECK( fs::equivalent( from_ph, file_ph ) );
  }

  error_code ec;
  BOOST_CHECK( fs::create_hard_link( fs::path("doesnotexist"),
    fs::path("shouldnotwork"), ec ) );
  BOOST_CHECK( ec );

  // symbolic link tests
  from_ph = dir / "f4";
  BOOST_CHECK( !fs::exists( from_ph ) );
  BOOST_CHECK( fs::exists( file_ph ) );
  bool create_symlink_ok(true);
  try { fs::create_symlink( file_ph, from_ph ); }
  catch ( const fs::filesystem_error & ex )
  {
    create_symlink_ok = false;
    std::cout
      << "create_symlink() attempt failed\n"
      << "filesystem_error.what() reports: " << ex.what() << '\n'
      << "create_symlink() may not be supported on this file system\n";
  }

  if ( create_symlink_ok )
  {
    std::cout << "create_symlink() succeeded\n";
    BOOST_CHECK( fs::exists( from_ph ) );
    BOOST_CHECK( fs::is_symlink( from_ph ) );
    BOOST_CHECK( fs::exists( file_ph ) );
    BOOST_CHECK( fs::equivalent( from_ph, file_ph ) );
    stat = fs::symlink_status( from_ph );
    BOOST_CHECK( fs::exists( stat ) );
    BOOST_CHECK( !fs::is_directory( stat ) );
    BOOST_CHECK( !fs::is_regular_file( stat ) );
    BOOST_CHECK( !fs::is_other( stat ) );
    BOOST_CHECK( fs::is_symlink( stat ) );
  }

  ec = error_code();
  BOOST_CHECK( fs::create_symlink( "doesnotexist", "", ec ) );
  BOOST_CHECK( ec );

  // there was an inital bug in directory_iterator that caused premature
  // close of an OS handle. This block will detect regression.
  {
    fs::directory_iterator di;
    { di = fs::directory_iterator( dir ); }
    BOOST_CHECK( ++di != fs::directory_iterator() );
  }

  // copy_file() tests
  std::cout << "begin copy_file test..." << std::endl;
  fs::copy_file( file_ph, d1 / "f2" );
  std::cout << "copying complete" << std::endl;
  BOOST_CHECK( fs::exists( file_ph ) );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  BOOST_CHECK( !fs::is_directory( d1 / "f2" ) );
  verify_file( d1 / "f2", "foobar1" );
  std::cout << "copy_file test complete" << std::endl;

  // rename() test case numbers refer to operations.htm#rename table

  // [case 1] make sure can't rename() a non-existent file
  BOOST_CHECK( !fs::exists( d1 / "f99" ) );
  BOOST_CHECK( !fs::exists( d1 / "f98" ) );
  renamer n1a( d1 / "f99", d1 / "f98" );
  BOOST_CHECK( CHECK_EXCEPTION( n1a, ENOENT ) );
  renamer n1b( fs::path(""), d1 / "f98" );
  BOOST_CHECK( CHECK_EXCEPTION( n1b, ENOENT ) );

  // [case 2] rename() target.empty()
  renamer n2( file_ph, "" );
  BOOST_CHECK( CHECK_EXCEPTION( n2, ENOENT ) );

  // [case 3] make sure can't rename() to an existent file or directory
  BOOST_CHECK( fs::exists( dir / "f1" ) );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  renamer n3a( dir / "f1", d1 / "f2" );
  BOOST_CHECK( CHECK_EXCEPTION( n3a, EEXIST ) );
  // several POSIX implementations (cygwin, openBSD) report ENOENT instead of EEXIST,
  // so we don't verify error type on the above test.
  renamer n3b( dir, d1 );
  BOOST_CHECK( CHECK_EXCEPTION( n3b, 0 ) );

  // [case 4A] can't rename() file to a nonexistent parent directory
  BOOST_CHECK( !fs::is_directory( dir / "f1" ) );
  BOOST_CHECK( !fs::exists( dir / "d3/f3" ) );
  renamer n4a( dir / "f1", dir / "d3/f3" );
  BOOST_CHECK( CHECK_EXCEPTION( n4a, ENOENT ) );

  // [case 4B] rename() file in same directory
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  BOOST_CHECK( !fs::exists( d1 / "f50" ) );
  fs::rename( d1 / "f2", d1 / "f50" );
  BOOST_CHECK( !fs::exists( d1 / "f2" ) );
  BOOST_CHECK( fs::exists( d1 / "f50" ) );
  fs::rename( d1 / "f50", d1 / "f2" );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  BOOST_CHECK( !fs::exists( d1 / "f50" ) );

  // [case 4C] rename() file d1/f2 to d2/f3
  fs::rename( d1 / "f2", d2 / "f3" );
  BOOST_CHECK( !fs::exists( d1 / "f2" ) );
  BOOST_CHECK( !fs::exists( d2 / "f2" ) );
  BOOST_CHECK( fs::exists( d2 / "f3" ) );
  BOOST_CHECK( !fs::is_directory( d2 / "f3" ) );
  verify_file( d2 / "f3", "foobar1" );
  fs::rename( d2 / "f3", d1 / "f2" );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );

  // [case 5A] rename() directory to nonexistent parent directory
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( !fs::exists( dir / "d3/d5" ) );
  BOOST_CHECK( !fs::exists( dir / "d3" ) );
  renamer n5a( d1, dir / "d3/d5" );
  BOOST_CHECK( CHECK_EXCEPTION( n5a, ENOENT ) );

  // [case 5B] rename() on directory
  fs::path d3( dir / "d3" );
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  BOOST_CHECK( !fs::exists( d3 ) );
  fs::rename( d1, d3 );
  BOOST_CHECK( !fs::exists( d1 ) );
  BOOST_CHECK( fs::exists( d3 ) );
  BOOST_CHECK( fs::is_directory( d3 ) );
  BOOST_CHECK( !fs::exists( d1 / "f2" ) );
  BOOST_CHECK( fs::exists( d3 / "f2" ) );
  fs::rename( d3, d1 );
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  BOOST_CHECK( !fs::exists( d3 ) );

  // [case 5C] rename() rename and move d1 to d2 / "d20"
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( !fs::exists( d2 / "d20" ) );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );
  fs::rename( d1, d2 / "d20" );
  BOOST_CHECK( !fs::exists( d1 ) );
  BOOST_CHECK( fs::exists( d2 / "d20" ) );
  BOOST_CHECK( fs::exists( d2 / "d20" / "f2" ) );
  fs::rename( d2 / "d20", d1 );
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( !fs::exists( d2 / "d20" ) );
  BOOST_CHECK( fs::exists( d1 / "f2" ) );

  // remove() file
  file_ph = dir / "shortlife";
  BOOST_CHECK( !fs::exists( file_ph ) );
  create_file( file_ph, "" );
  BOOST_CHECK( fs::exists( file_ph ) );
  BOOST_CHECK( !fs::is_directory( file_ph ) );
  fs::remove( file_ph );
  BOOST_CHECK( !fs::exists( file_ph ) );
  fs::remove( "no-such-file" );
  fs::remove( "no-such-directory/no-such-file" );

  // remove() directory
  d1 = dir / "shortlife_dir";
  BOOST_CHECK( !fs::exists( d1 ) );
  fs::create_directory( d1 );
  BOOST_CHECK( fs::exists( d1 ) );
  BOOST_CHECK( fs::is_directory( d1 ) );
  BOOST_CHECK( BOOST_FS_IS_EMPTY( d1 ) );
  bad_remove_dir = dir;
  BOOST_CHECK( CHECK_EXCEPTION( bad_remove, ENOTEMPTY ) );
  fs::remove( d1 );
  BOOST_CHECK( !fs::exists( d1 ) );

  if ( create_symlink_ok )  // only if symlinks supported
  {
    // remove() dangling symbolic link
    fs::path link( "dangling_link" );
    fs::remove( link );
    BOOST_CHECK( !fs::is_symlink( link ) );
    BOOST_CHECK( !fs::exists( link ) );
    fs::create_symlink( "nowhere", link );
    BOOST_CHECK( !fs::exists( link ) );
    BOOST_CHECK( fs::is_symlink( link ) );
    fs::remove( link );
    BOOST_CHECK( !fs::is_symlink( link ) );

    // remove() self-refering symbolic link
    link = "link_to_self";
    fs::remove( link );
    BOOST_CHECK( !fs::is_symlink( link ) );
    BOOST_CHECK( !fs::exists( link ) );
    fs::create_symlink( link, link );
    fs::remove( link );
    BOOST_CHECK( !fs::exists( link ) );
    BOOST_CHECK( !fs::is_symlink( link ) );

    // remove() cyclic symbolic link
    link = "link_to_a";
    fs::path link2( "link_to_b" );
    fs::remove( link );
    fs::remove( link2 );
    BOOST_CHECK( !fs::is_symlink( link ) );
    BOOST_CHECK( !fs::exists( link ) );
    fs::create_symlink( link, link2 );
    fs::create_symlink( link2, link );
    fs::remove( link );
    fs::remove( link2 );
    BOOST_CHECK( !fs::exists( link ) );
    BOOST_CHECK( !fs::exists( link2 ) );
    BOOST_CHECK( !fs::is_symlink( link ) );

    // remove() symbolic link to file
    file_ph = "link_target";
    fs::remove( file_ph );
    BOOST_CHECK( !fs::exists( file_ph ) );
    create_file( file_ph, "" );
    BOOST_CHECK( fs::exists( file_ph ) );
    BOOST_CHECK( !fs::is_directory( file_ph ) );
    BOOST_CHECK( fs::is_regular_file( file_ph ) );
    link = "non_dangling_link";
    fs::create_symlink( file_ph, link );
    BOOST_CHECK( fs::exists( link ) );
    BOOST_CHECK( !fs::is_directory( link ) );
    BOOST_CHECK( fs::is_regular_file( link ) );
    BOOST_CHECK( fs::is_symlink( link ) );
    fs::remove( link );
    BOOST_CHECK( fs::exists( file_ph ) );
    BOOST_CHECK( !fs::exists( link ) );
    BOOST_CHECK( !fs::is_symlink( link ) );
    fs::remove( file_ph );
    BOOST_CHECK( !fs::exists( file_ph ) );
  }

  // write time tests

  file_ph = dir / "foobar2";
  create_file( file_ph, "foobar2" );
  BOOST_CHECK( fs::exists( file_ph ) );
  BOOST_CHECK( !fs::is_directory( file_ph ) );
  BOOST_CHECK( fs::is_regular_file( file_ph ) );
  BOOST_CHECK( fs::file_size( file_ph ) == 7 );
  verify_file( file_ph, "foobar2" );

  // Some file system report last write time as local (FAT), while
  // others (NTFS) report it as UTC. The C standard does not specify
  // if time_t is local or UTC. 

  std::time_t ft = fs::last_write_time( file_ph );
  std::cout << "\nUTC last_write_time() for a file just created is "
    << std::asctime(std::gmtime(&ft)) << std::endl;

  std::tm * tmp = std::localtime( &ft );
  std::cout << "\nYear is " << tmp->tm_year << std::endl;
  --tmp->tm_year;
  std::cout << "Change year to " << tmp->tm_year << std::endl;
  fs::last_write_time( file_ph, std::mktime( tmp ) );
  std::time_t ft2 = fs::last_write_time( file_ph );
  std::cout << "last_write_time() for the file is now "
    << std::asctime(std::gmtime(&ft2)) << std::endl;
  BOOST_CHECK( ft != fs::last_write_time( file_ph ) );


  std::cout << "\nReset to current time" << std::endl;
  fs::last_write_time( file_ph, ft );
  double time_diff = std::difftime( ft, fs::last_write_time( file_ph ) );
  std::cout 
    << "original last_write_time() - current last_write_time() is "
    << time_diff << " seconds" << std::endl;
  BOOST_CHECK( time_diff >= -60.0 && time_diff <= 60.0 );

  // post-test cleanup
  BOOST_CHECK( fs::remove_all( dir ) != 0 );
  // above was added just to simplify testing, but it ended up detecting
  // a bug (failure to close an internal search handle). 
  BOOST_CHECK( !fs::exists( dir ) );
  BOOST_CHECK( fs::remove_all( dir ) == 0 );
  return 0;
} // main

