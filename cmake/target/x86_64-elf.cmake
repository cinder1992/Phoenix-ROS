set(CMAKE_SYSTEM_NAME           "Generic")
set(CMAKE_SYSTEM_PROCESSOR      "x86_64")
set(triple                      "${CMAKE_SYSTEM_PROCESSOR}-elf")

set(CMAKE_AR                    "llvm-ar${CMAKE_EXECUTABLE_SUFFIX}")
set(CMAKE_ASM_COMPILER          "clang${CMAKE_EXECUTABLE_SUFFIX}")
set(CMAKE_C_COMPILER            "clang${CMAKE_EXECUTABLE_SUFFIX}")
set(CMAKE_CXX_COMPILER          "clang++${CMAKE_EXECUTABLE_SUFFIX}")
set(CMAKE_LINKER                "ld.lld${CMAKE_EXECUTABLE_SUFFIX}")
set(CMAKE_OBJCOPY               "llvm-objcopy${CMAKE_EXECUTABLE_SUFFIX}" CACHE INTERNAL "")
set(CMAKE_RANLIB                "llvm-ranlib${CMAKE_EXECUTABLE_SUFFIX}" CACHE INTERNAL "")
set(CMAKE_SIZE                  "llvm-size${CMAKE_EXECUTABLE_SUFFIX}" CACHE INTERNAL "")
set(CMAKE_STRIP                 "llvm-strip${CMAKE_EXECUTABLE_SUFFIX}" CACHE INTERNAL "")

set(CMAKE_ASM_COMPILER_TARGET   ${triple})
set(CMAKE_C_COMPILER_TARGET     ${triple})
set(CMAKE_CXX_COMPILER_TARGET   ${triple})

set(CMAKE_C_FLAGS               "-ffreestanding -nostdlib -fno-builtin -fno-slp-vectorize -mcmodel=kernel" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS             "${CMAKE_C_FLAGS}"  CACHE INTERNAL "")
set(CMAKE_C_FLAGS_DEBUG         "-Os -g" CACHE INTERNAL "")
set(CMAKE_C_FLAGS_RELEASE       "-Os -DNDEBUG" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_DEBUG       "${CMAKE_C_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELEASE     "${CMAKE_C_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS
	"-fuse-ld=lld -T ${CMAKE_SOURCE_DIR}/src/platform/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_PROCESSOR}-elf.ld"
	CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM     NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY     ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE     ONLY)

set(CMAKE_TRY_COMPILE_TARGET_TYPE         STATIC_LIBRARY)

#set(KERNEL_LINK_FILE "${CMAKE_CURRENT_LIST_DIR}/kernel.ld")
