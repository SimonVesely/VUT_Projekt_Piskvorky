# CMake generated Testfile for 
# Source directory: /Users/simonvesely/Neovim/C/Quiz/cjson
# Build directory: /Users/simonvesely/Neovim/C/Quiz/cjson/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "/Users/simonvesely/Neovim/C/Quiz/cjson/build/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/simonvesely/Neovim/C/Quiz/cjson/CMakeLists.txt;252;add_test;/Users/simonvesely/Neovim/C/Quiz/cjson/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
