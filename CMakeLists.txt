# Copyright 2023 the JayCeS authors. All rights reserved.
#
# MIT license.

cmake_minimum_required(VERSION 3.16.0)

project("jayces"
  VERSION 0.1.0
  LANGUAGES CXX)

# compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# Config C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# C++ Compiler options
add_compile_options(-Wall)
add_compile_options(-pedantic)

# vcpkg (preparation)
if (DEFINED ENV{GITHUB_WORKSPACE})
  message("set ---- GitHub Actions")
  if (WIN32)
	include(C:/vcpkg/scripts/buildsystems/vcpkg.cmake)
  elseif (APPLE)
	include(/usr/local/share/scripts/buildsystems/vcpkg.cmake)
  elseif (UNIX)
	include(/usr/local/share/scripts/buildsystems/vcpkg.cmake)
  endif ()
else ()
  include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
endif ()

# vcpkg
find_package(CLI11 CONFIG REQUIRED)

# source files
file(GLOB source_files CONFIGURE_DEPENDS
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

# executable
add_executable(${PROJECT_NAME} ${source_files})

# include and static link
file(GLOB V_GLOB LIST_DIRECTORIES true "lib/**")
foreach(item ${V_GLOB})
  if(IS_DIRECTORY ${item})
	message(STATUS "[+] ${item}")
	include_directories("${item}/include/")
	link_directories("${item}/lib/")
  endif()
endforeach()

# link
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)
