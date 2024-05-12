
# Copyright Aleksey Gurtovoy 2001-2006
#
# Distributed under the Boost Software License, Version 1.0. 
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt)
#
# See http://www.boost.org/libs/mpl for documentation.

# $Source$
# $Date: 2006-11-23 14:57:11 -0500 (Thu, 23 Nov 2006) $
# $Revision: 36168 $

import preprocess
import os.path

preprocess.main(
      [ "plain", "typeof_based", "no_ctps" ]
    , "map"
    , os.path.join( "boost", "mpl", "map", "aux_", "preprocessed" )
    )
