# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Trevl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Trevl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter\cmake-build-debug"

# Utility rule file for submission.

# Include the progress variables for this target.
include CMakeFiles\submission.dir\progress.make

CMakeFiles\submission:
	cd C:\Users\Trevl\Desktop\Projects\School\ECE351~1\Project3.2\P3263B~1.2-S
	C:\Users\Trevl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E tar cfv "C:/Users/Trevl/Desktop/Projects/School/ECE 3514 - Data Structures and Algorithms/Project3.2/P3.2-starter/cmake-build-debug/submission.zip" --format=zip ExpConverter.cpp ExpConvDriver.cpp student_tests.cpp
	cd C:\Users\Trevl\Desktop\Projects\School\ECE351~1\Project3.2\P3263B~1.2-S\CMAKE-~1

submission: CMakeFiles\submission
submission: CMakeFiles\submission.dir\build.make

.PHONY : submission

# Rule to build all files generated by this target.
CMakeFiles\submission.dir\build: submission

.PHONY : CMakeFiles\submission.dir\build

CMakeFiles\submission.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\submission.dir\cmake_clean.cmake
.PHONY : CMakeFiles\submission.dir\clean

CMakeFiles\submission.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter\cmake-build-debug" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter\cmake-build-debug" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514 - Data Structures and Algorithms\Project3.2\P3.2-starter\cmake-build-debug\CMakeFiles\submission.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\submission.dir\depend

