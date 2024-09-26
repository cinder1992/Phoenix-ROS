cmake_minimum_required(VERSION 3.20...3.30)
set(PHOENIX_TARGET "x86_64" CACHE STRING "Default build target")
set(PHOENIX_BINARY "elf" CACHE STRING "Default binary filetype") 
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/target/${PHOENIX_TARGET}-${PHOENIX_BINARY}.cmake")
project(phoenix-kernel
	VERSION 0.1
	LANGUAGES C ASM)

add_executable(kernel.elf)
target_include_directories(kernel.elf PRIVATE include)
add_subdirectory(include/platform/${PHOENIX_TARGET})
add_subdirectory(src)
