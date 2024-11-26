# CMakeList.txt : CMake project for piskvorky, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (piskvorky "src/main.cpp" "lib/hxh.cpp" "lib/checker.cpp" "lib/cJSON.cpp" "lib/leaderboard.cpp" "lib/mylib.cpp" "include/checker.h" "include/cJSON.h" "include/hxh.h" "include/leaderboard.h" "include/mylib.h" )

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8")
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET piskvorky PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
