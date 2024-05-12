//  Copyright (c) 2001-2008 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  The main purpose of this example is to show the uniform and easy way of
//  output formatting for different container types. 
//
//  Since the 'stream' primitive used below uses the streaming operator defined 
//  for the container value_type, you must make sure to have a corresponding
//  operator<<() available for this contained data type. OTOH this means, that
//  the format descriptions used below will be usable for any contained type as
//  long as this type has an associated streaming operator defined.

//  use a larger value for the alignment field width (default is 10)
#define BOOST_KARMA_DEFAULT_FIELD_LENGTH 25

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/karma_stream.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib> 

#include <boost/range.hpp>
#include <boost/date_time//gregorian/gregorian.hpp>

using namespace boost::spirit;
using namespace boost::spirit::ascii;
namespace karma = boost::spirit::karma;

///////////////////////////////////////////////////////////////////////////////
// Output the given containers in list format
// Note: the format description does not depend on the type of the sequence
//       nor does it depend on the type of the elements contained in the 
//       sequence
///////////////////////////////////////////////////////////////////////////////
template <typename Container>
void output_container(std::ostream& os, Container const& c)
{
    // output the container as a space separated sequence
    os << 
        karma::format_delimited(
            *stream,                              // format description
            c,                                    // data
            space                                 // delimiter
        ) << std::endl << std::endl;

    os << 
        karma::format_delimited(
            '[' << *stream << ']',                // format description
            c,                                    // data
            space                                 // delimiter
        ) << std::endl << std::endl;

    // output the container as a comma separated list
    os << 
        karma::format(
            stream % ", ",                        // format description
            c                                     // data
        ) << std::endl << std::endl;

    os << 
        karma::format(
            '[' << (stream % ", ") << ']',        // format description
            c                                     // data
        ) << std::endl << std::endl;

    // output the container as a comma separated list of items enclosed in '()'
    os << 
        karma::format(
            ('(' << stream << ')') % ", ",        // format description
            c                                     // data
        ) << std::endl << std::endl;

    os << 
        karma::format(
            '[' << (  
                ('(' << stream << ')') % ", "
             )  << ']',                           // format description
            c                                     // data
        ) << std::endl << std::endl;
        
    // output the container as a HTML list
    os << 
        karma::format_delimited(
            "<ol>" << 
                *verbatim["<li>" << stream << "</li>"]
            << "</ol>",                           // format description
            c,                                    // data
            '\n'                                  // delimiter
        ) << std::endl;

    // output the container as right aligned column
    os << 
        karma::format_delimited(
           *verbatim[
                "|" << right_align[stream] << "|"
            ],                                    // format description
            c,                                    // data
            '\n'                                  // delimiter
        ) << std::endl;

    os << std::endl;
}

int main()
{
    ///////////////////////////////////////////////////////////////////////////
    // vector
    std::vector<int> v (8);
    std::generate(v.begin(), v.end(), std::rand); // randomly fill the vector

    std::cout << "-------------------------------------------------------------" 
              << std::endl;
    std::cout << "std::vector<int>" << std::endl;
    output_container(std::cout, v);
        
    ///////////////////////////////////////////////////////////////////////////
    // list
    std::list<char> l;
    l.push_back('A');
    l.push_back('B');
    l.push_back('C');

    std::cout << "-------------------------------------------------------------" 
              << std::endl;
    std::cout << "std::list<char>" << std::endl;
    output_container(std::cout, l);

    ///////////////////////////////////////////////////////////////////////////
    // C-style array
    int i[4] = { 3, 6, 9, 12 };
    
    std::cout << "-------------------------------------------------------------" 
              << std::endl;
    std::cout << "int i[]" << std::endl;
    output_container(std::cout, boost::make_iterator_range(i, i+4));
    
    ///////////////////////////////////////////////////////////////////////////
    // strings
    std::string str("Hello world!");

    std::cout << "-------------------------------------------------------------" 
              << std::endl;
    std::cout << "std::string" << std::endl;
    output_container(std::cout, str);
        
    ///////////////////////////////////////////////////////////////////////////
    //  vector of boost::date objects
    //  Note: any registered facets get used!
    using namespace boost::gregorian;
    std::vector<date> dates;
    dates.push_back(date(2005, Jun, 25));
    dates.push_back(date(2006, Jan, 13));
    dates.push_back(date(2007, May, 03));

    date_facet* facet(new date_facet("%A %B %d, %Y"));
    std::cout.imbue(std::locale(std::cout.getloc(), facet));

    std::cout << "-------------------------------------------------------------" 
              << std::endl;
    std::cout << "std::vector<boost::date>" << std::endl;
    output_container(std::cout, dates);
    
    return 0;
}

