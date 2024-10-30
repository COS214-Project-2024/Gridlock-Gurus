# CMake generated Testfile for 
# Source directory: /home/hayley/Documents/COS_214/Gridlock-Gurus-dev
# Build directory: /home/hayley/Documents/COS_214/Gridlock-Gurus-dev/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(all_tests "/home/hayley/Documents/COS_214/Gridlock-Gurus-dev/build/tests")
set_tests_properties(all_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/hayley/Documents/COS_214/Gridlock-Gurus-dev/CMakeLists.txt;32;add_test;/home/hayley/Documents/COS_214/Gridlock-Gurus-dev/CMakeLists.txt;0;")
subdirs("googletest")
