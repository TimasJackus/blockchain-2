cmake_minimum_required(VERSION 3.15)
project(uzduotis_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lbitcoin -L/home/timas/bitcoin/lib" )

set(ENV{PKG_CONFIG_PATH} "/home/timas/bitcoin/lib/pkgconfig/:$ENV{PKG_CONFIG_PATH}")

#then later..
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIB_BITCOIN REQUIRED libbitcoin)
#then later..
add_executable(uzduotis_2 main.cpp classes/hash.cpp classes/hash.h classes/user.cpp classes/user.h classes/transaction.h classes/transaction.cpp classes/data.cpp classes/data.h classes/block.cpp classes/block.h classes/block_header.cpp classes/block_header.h classes/block_body.cpp classes/block_body.h classes/candidate.cpp classes/candidate.h classes/merkle.cpp classes/merkle.h)


target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_BITCOIN_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${LIB_BITCOIN_INCLUDE_DIRS})
