# CMakeLists.txt for event package. It creates a library with dictionary and a main program
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(HistMaps)

# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist Tree Net)

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})

ROOT_GENERATE_DICTIONARY(G__MpdCent 
HistMaps.h
LINKDEF HistMaps.LinkDef.h)

#---Create a shared library with geneated dictionary
add_library(HistMap SHARED 
HistMaps.cxx 
G__MpdCent.cxx)
target_link_libraries(HistMap ${ROOT_LIBRARIES})

#---Create  a main program using the library
add_executable(Main HistMapsMain.cxx)
target_link_libraries(Main HistMap)
