# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mikey\CLionProjects\ASD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mikey\CLionProjects\ASD\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\ASD.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ASD.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ASD.dir\flags.make

CMakeFiles\ASD.dir\insertionSort.cpp.obj: CMakeFiles\ASD.dir\flags.make
CMakeFiles\ASD.dir\insertionSort.cpp.obj: ..\insertionSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mikey\CLionProjects\ASD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ASD.dir/insertionSort.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ASD.dir\insertionSort.cpp.obj /FdCMakeFiles\ASD.dir\ /FS -c C:\Users\mikey\CLionProjects\ASD\insertionSort.cpp
<<

CMakeFiles\ASD.dir\insertionSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ASD.dir/insertionSort.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ASD.dir\insertionSort.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mikey\CLionProjects\ASD\insertionSort.cpp
<<

CMakeFiles\ASD.dir\insertionSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ASD.dir/insertionSort.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ASD.dir\insertionSort.cpp.s /c C:\Users\mikey\CLionProjects\ASD\insertionSort.cpp
<<

# Object files for target ASD
ASD_OBJECTS = \
"CMakeFiles\ASD.dir\insertionSort.cpp.obj"

# External object files for target ASD
ASD_EXTERNAL_OBJECTS =

ASD.exe: CMakeFiles\ASD.dir\insertionSort.cpp.obj
ASD.exe: CMakeFiles\ASD.dir\build.make
ASD.exe: CMakeFiles\ASD.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mikey\CLionProjects\ASD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ASD.exe"
	"C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ASD.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ASD.dir\objects1.rsp @<<
 /out:ASD.exe /implib:ASD.lib /pdb:C:\Users\mikey\CLionProjects\ASD\cmake-build-debug\ASD.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ASD.dir\build: ASD.exe

.PHONY : CMakeFiles\ASD.dir\build

CMakeFiles\ASD.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ASD.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ASD.dir\clean

CMakeFiles\ASD.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\mikey\CLionProjects\ASD C:\Users\mikey\CLionProjects\ASD C:\Users\mikey\CLionProjects\ASD\cmake-build-debug C:\Users\mikey\CLionProjects\ASD\cmake-build-debug C:\Users\mikey\CLionProjects\ASD\cmake-build-debug\CMakeFiles\ASD.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ASD.dir\depend
