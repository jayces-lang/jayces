cmake_minimum_required(VERSION 3.16.0)

# Config Version
set(JAYCES_VERSION_MAJOR 0)
set(JAYCES_VERSION_MINOR 1)
set(JAYCES_VERSION_PATCH 0)
set(JAYCES_VERSION "${JAYCES_VERSION_MAJOR}.${JAYCES_VERSION_MINOR}.${JAYCES_VERSION_PATCH}")

project(jayces VERSION ${JAYCES_VERSION})

# compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# Config C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# C++ Compiler options
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-pedantic)
add_compile_options(-Wno-unused-parameter)
add_compile_options(-Wno-uninitialized)
add_compile_options(-Wno-missing-field-initializers)

# executable
file(GLOB source_files CONFIGURE_DEPENDS
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

add_executable(${PROJECT_NAME} ${source_files})

#target_link_libraries(${PROJECT_NAME} PRIVATE unofficial::sqlite3::sqlite3)

file(GLOB V_GLOB LIST_DIRECTORIES true "lib/**")
foreach(item ${V_GLOB})
  if(IS_DIRECTORY ${item})
	message(STATUS "[+] ${item}")
	include_directories("${item}/include/")
	link_directories("${item}/lib/")
  endif()
endforeach()


