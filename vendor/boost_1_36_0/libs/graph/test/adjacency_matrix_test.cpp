/* adjacency_matrix_test.cpp source file
 *
 * Copyright Cromwell D. Enage 2004
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

/*
 * Defines the std::ios class and std::cout, its global output instance.
 */
#include <iostream>

/*
 * Defines the boost::property_map class template and the boost::get and
 * boost::put function templates.
 */
#include <boost/property_map.hpp>

/*
 * Defines the boost::graph_traits class template.
 */
#include <boost/graph/graph_traits.hpp>

/*
 * Defines the vertex and edge property tags.
 */
#include <boost/graph/properties.hpp>

/*
 * Defines the boost::adjacency_list class template and its associated
 * non-member function templates.
 */
#include <boost/graph/adjacency_list.hpp>

/*
 * Defines the boost::adjacency_matrix class template and its associated
 * non-member function templates.
 */
#include <boost/graph/adjacency_matrix.hpp>

#include <boost/test/minimal.hpp>

template<typename Graph1, typename Graph2>
void run_test()
{
   typedef typename boost::property_map<Graph1, boost::vertex_index_t>::type
           IndexMap1;
   typedef typename boost::property_map<Graph2, boost::vertex_index_t>::type
           IndexMap2;

   Graph1 g1(24);
   Graph2 g2(24);

   boost::add_edge(boost::vertex(0, g1), boost::vertex(7, g1), g1);
   boost::add_edge(boost::vertex(0, g2), boost::vertex(7, g2), g2);
   boost::add_edge(boost::vertex(1, g1), boost::vertex(2, g1), g1);
   boost::add_edge(boost::vertex(1, g2), boost::vertex(2, g2), g2);
   boost::add_edge(boost::vertex(2, g1), boost::vertex(10, g1), g1);
   boost::add_edge(boost::vertex(2, g2), boost::vertex(10, g2), g2);
   boost::add_edge(boost::vertex(2, g1), boost::vertex(5, g1), g1);
   boost::add_edge(boost::vertex(2, g2), boost::vertex(5, g2), g2);
   boost::add_edge(boost::vertex(3, g1), boost::vertex(10, g1), g1);
   boost::add_edge(boost::vertex(3, g2), boost::vertex(10, g2), g2);
   boost::add_edge(boost::vertex(3, g1), boost::vertex(0, g1), g1);
   boost::add_edge(boost::vertex(3, g2), boost::vertex(0, g2), g2);
   boost::add_edge(boost::vertex(4, g1), boost::vertex(5, g1), g1);
   boost::add_edge(boost::vertex(4, g2), boost::vertex(5, g2), g2);
   boost::add_edge(boost::vertex(4, g1), boost::vertex(0, g1), g1);
   boost::add_edge(boost::vertex(4, g2), boost::vertex(0, g2), g2);
   boost::add_edge(boost::vertex(5, g1), boost::vertex(14, g1), g1);
   boost::add_edge(boost::vertex(5, g2), boost::vertex(14, g2), g2);
   boost::add_edge(boost::vertex(6, g1), boost::vertex(3, g1), g1);
   boost::add_edge(boost::vertex(6, g2), boost::vertex(3, g2), g2);
   boost::add_edge(boost::vertex(7, g1), boost::vertex(17, g1), g1);
   boost::add_edge(boost::vertex(7, g2), boost::vertex(17, g2), g2);
   boost::add_edge(boost::vertex(7, g1), boost::vertex(11, g1), g1);
   boost::add_edge(boost::vertex(7, g2), boost::vertex(11, g2), g2);
   boost::add_edge(boost::vertex(8, g1), boost::vertex(17, g1), g1);
   boost::add_edge(boost::vertex(8, g2), boost::vertex(17, g2), g2);
   boost::add_edge(boost::vertex(8, g1), boost::vertex(1, g1), g1);
   boost::add_edge(boost::vertex(8, g2), boost::vertex(1, g2), g2);
   boost::add_edge(boost::vertex(9, g1), boost::vertex(11, g1), g1);
   boost::add_edge(boost::vertex(9, g2), boost::vertex(11, g2), g2);
   boost::add_edge(boost::vertex(9, g1), boost::vertex(1, g1), g1);
   boost::add_edge(boost::vertex(9, g2), boost::vertex(1, g2), g2);
   boost::add_edge(boost::vertex(10, g1), boost::vertex(19, g1), g1);
   boost::add_edge(boost::vertex(10, g2), boost::vertex(19, g2), g2);
   boost::add_edge(boost::vertex(10, g1), boost::vertex(15, g1), g1);
   boost::add_edge(boost::vertex(10, g2), boost::vertex(15, g2), g2);
   boost::add_edge(boost::vertex(10, g1), boost::vertex(8, g1), g1);
   boost::add_edge(boost::vertex(10, g2), boost::vertex(8, g2), g2);
   boost::add_edge(boost::vertex(11, g1), boost::vertex(19, g1), g1);
   boost::add_edge(boost::vertex(11, g2), boost::vertex(19, g2), g2);
   boost::add_edge(boost::vertex(11, g1), boost::vertex(15, g1), g1);
   boost::add_edge(boost::vertex(11, g2), boost::vertex(15, g2), g2);
   boost::add_edge(boost::vertex(11, g1), boost::vertex(4, g1), g1);
   boost::add_edge(boost::vertex(11, g2), boost::vertex(4, g2), g2);
   boost::add_edge(boost::vertex(12, g1), boost::vertex(19, g1), g1);
   boost::add_edge(boost::vertex(12, g2), boost::vertex(19, g2), g2);
   boost::add_edge(boost::vertex(12, g1), boost::vertex(8, g1), g1);
   boost::add_edge(boost::vertex(12, g2), boost::vertex(8, g2), g2);
   boost::add_edge(boost::vertex(12, g1), boost::vertex(4, g1), g1);
   boost::add_edge(boost::vertex(12, g2), boost::vertex(4, g2), g2);
   boost::add_edge(boost::vertex(13, g1), boost::vertex(15, g1), g1);
   boost::add_edge(boost::vertex(13, g2), boost::vertex(15, g2), g2);
   boost::add_edge(boost::vertex(13, g1), boost::vertex(8, g1), g1);
   boost::add_edge(boost::vertex(13, g2), boost::vertex(8, g2), g2);
   boost::add_edge(boost::vertex(13, g1), boost::vertex(4, g1), g1);
   boost::add_edge(boost::vertex(13, g2), boost::vertex(4, g2), g2);
   boost::add_edge(boost::vertex(14, g1), boost::vertex(22, g1), g1);
   boost::add_edge(boost::vertex(14, g2), boost::vertex(22, g2), g2);
   boost::add_edge(boost::vertex(14, g1), boost::vertex(12, g1), g1);
   boost::add_edge(boost::vertex(14, g2), boost::vertex(12, g2), g2);
   boost::add_edge(boost::vertex(15, g1), boost::vertex(22, g1), g1);
   boost::add_edge(boost::vertex(15, g2), boost::vertex(22, g2), g2);
   boost::add_edge(boost::vertex(15, g1), boost::vertex(6, g1), g1);
   boost::add_edge(boost::vertex(15, g2), boost::vertex(6, g2), g2);
   boost::add_edge(boost::vertex(16, g1), boost::vertex(12, g1), g1);
   boost::add_edge(boost::vertex(16, g2), boost::vertex(12, g2), g2);
   boost::add_edge(boost::vertex(16, g1), boost::vertex(6, g1), g1);
   boost::add_edge(boost::vertex(16, g2), boost::vertex(6, g2), g2);
   boost::add_edge(boost::vertex(17, g1), boost::vertex(20, g1), g1);
   boost::add_edge(boost::vertex(17, g2), boost::vertex(20, g2), g2);
   boost::add_edge(boost::vertex(18, g1), boost::vertex(9, g1), g1);
   boost::add_edge(boost::vertex(18, g2), boost::vertex(9, g2), g2);
   boost::add_edge(boost::vertex(19, g1), boost::vertex(23, g1), g1);
   boost::add_edge(boost::vertex(19, g2), boost::vertex(23, g2), g2);
   boost::add_edge(boost::vertex(19, g1), boost::vertex(18, g1), g1);
   boost::add_edge(boost::vertex(19, g2), boost::vertex(18, g2), g2);
   boost::add_edge(boost::vertex(20, g1), boost::vertex(23, g1), g1);
   boost::add_edge(boost::vertex(20, g2), boost::vertex(23, g2), g2);
   boost::add_edge(boost::vertex(20, g1), boost::vertex(13, g1), g1);
   boost::add_edge(boost::vertex(20, g2), boost::vertex(13, g2), g2);
   boost::add_edge(boost::vertex(21, g1), boost::vertex(18, g1), g1);
   boost::add_edge(boost::vertex(21, g2), boost::vertex(18, g2), g2);
   boost::add_edge(boost::vertex(21, g1), boost::vertex(13, g1), g1);
   boost::add_edge(boost::vertex(21, g2), boost::vertex(13, g2), g2);
   boost::add_edge(boost::vertex(22, g1), boost::vertex(21, g1), g1);
   boost::add_edge(boost::vertex(22, g2), boost::vertex(21, g2), g2);
   boost::add_edge(boost::vertex(23, g1), boost::vertex(16, g1), g1);
   boost::add_edge(boost::vertex(23, g2), boost::vertex(16, g2), g2);

   IndexMap1 index_map1 = boost::get(boost::vertex_index_t(), g1);
   IndexMap2 index_map2 = boost::get(boost::vertex_index_t(), g2);
   typename boost::graph_traits<Graph1>::vertex_iterator vi1, vend1;
   typename boost::graph_traits<Graph2>::vertex_iterator vi2, vend2;

   typename boost::graph_traits<Graph1>::adjacency_iterator ai1, aend1;
   typename boost::graph_traits<Graph2>::adjacency_iterator ai2, aend2;

   for (boost::tie(vi1, vend1) = boost::vertices(g1), boost::tie(vi2, vend2) =boost::vertices(g2); vi1 != vend1; ++vi1, ++vi2)
   {
      BOOST_CHECK(boost::get(index_map1, *vi1) == boost::get(index_map2, *vi2));

      for (boost::tie(ai1, aend1) = boost::adjacent_vertices(*vi1, g1),
             boost::tie(ai2, aend2) = boost::adjacent_vertices(*vi2, g2);
           ai1 != aend1;
           ++ai1, ++ai2)
      {
        BOOST_CHECK(boost::get(index_map1, *ai1) == boost::get(index_map2, *ai2));
      }
   }

   typename boost::graph_traits<Graph1>::out_edge_iterator ei1, eend1;
   typename boost::graph_traits<Graph2>::out_edge_iterator ei2, eend2;

   for (boost::tie(vi1, vend1) = boost::vertices(g1),
          boost::tie(vi2, vend2) = boost::vertices(g2); vi1 != vend1; ++vi1, ++vi2)
   {
      BOOST_CHECK(boost::get(index_map1, *vi1) == boost::get(index_map2, *vi2));

      for (boost::tie(ei1, eend1) = boost::out_edges(*vi1, g1), 
             boost::tie(ei2, eend2) = boost::out_edges(*vi2, g2);
           ei1 != eend1;
           ++ei1, ++ei2)
      {
        BOOST_CHECK(boost::get(index_map1, boost::target(*ei1, g1)) == boost::get(index_map2, boost::target(*ei2, g2)));
      }
   }

   typename boost::graph_traits<Graph1>::in_edge_iterator iei1, ieend1;
   typename boost::graph_traits<Graph2>::in_edge_iterator iei2, ieend2;

   for (boost::tie(vi1, vend1) = boost::vertices(g1),
          boost::tie(vi2, vend2) = boost::vertices(g2); vi1 != vend1; ++vi1, ++vi2)
   {
      BOOST_CHECK(boost::get(index_map1, *vi1) == boost::get(index_map2, *vi2));

      for (boost::tie(iei1, ieend1) = boost::in_edges(*vi1, g1), 
             boost::tie(iei2, ieend2) = boost::in_edges(*vi2, g2);
           iei1 != ieend1;
           ++iei1, ++iei2)
      {
        BOOST_CHECK(boost::get(index_map1, boost::target(*iei1, g1)) == boost::get(index_map2, boost::target(*iei2, g2)));
      }
   }
}

int test_main(int, char*[])
{
    // Use setS to keep out edges in order, so they match the adjacency_matrix. 
   typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS>
           UGraph1;
   typedef boost::adjacency_matrix<boost::undirectedS>
           UGraph2;
   run_test<UGraph1, UGraph2>();

    // Use setS to keep out edges in order, so they match the adjacency_matrix. 
   typedef boost::adjacency_list<boost::setS, boost::vecS, 
                                 boost::bidirectionalS>
           BGraph1;
   typedef boost::adjacency_matrix<boost::directedS>
           BGraph2;
   run_test<BGraph1, BGraph2>();

   return 0;
}

