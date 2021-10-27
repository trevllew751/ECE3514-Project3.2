cmake_minimum_required(VERSION 3.5)
project(LinkedList CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(STACK_SOURCE
  Stack.hpp)

set(CONVERTER_SOURCE
  ExpConverter.hpp ExpConverter.cpp)
  
set (DRIVER_SOURCE
    ExpConvDriver.cpp)
 
set(TEST_SOURCE
 student_tests.cpp)

set(SOURCE ${STACK_SOURCE} ${CONVERTER_SOURCE})

add_executable(student-tests catch.hpp student_catch.cpp ${SOURCE} ${TEST_SOURCE})
add_executable(conv ${SOURCE} ${DRIVER_SOURCE})
#add_executable(instructor-tests catch.hpp student_catch.cpp ${SOURCE} instructor_tests.cpp)

# REMOVE ALL BELOW FOR GRADER
# some simple tests
enable_testing()
add_test(student-tests student-tests)
#add_test(instructor-tests instructor-tests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
   ExpConverter.cpp ExpConvDriver.cpp student_tests.cpp
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
