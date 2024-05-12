#!/usr/bin/python

# Copyright 2003 Dave Abrahams 
# Copyright 2003 Vladimir Prus 
# Distributed under the Boost Software License, Version 1.0. 
# (See accompanying file LICENSE_1_0.txt or http://www.boost.org/LICENSE_1_0.txt) 

# Test the 'symlink' rule

from BoostBuild import Tester, List
import os
t = Tester()

if os.name != 'posix':
    print "The symlink tests can be run on posix only"
    sys.exit(1)

t.write("project-root.jam", "import gcc ;")
t.write("Jamfile", """
exe hello : hello.cpp ;
symlink hello_release : hello/<variant>release ; 
symlink hello_debug : hello/<variant>debug ;
symlink links/hello_release : hello/<variant>release ; 
""")
t.write("hello.cpp", """
int main()
{
    return 0;
}
""")

t.run_build_system()
t.expect_addition(List('hello_debug.exe hello_release.exe links/hello_release.exe'))


t.cleanup()
