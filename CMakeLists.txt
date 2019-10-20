cmake_minimum_required(VERSION 3.15)
project(uzduotis_2)

set(CMAKE_CXX_STANDARD 20)
add_executable(uzduotis_2 main.cpp classes/hash.cpp classes/hash.h classes/user.cpp classes/user.h classes/transaction.h classes/transaction.cpp classes/data.cpp classes/data.h classes/block.cpp classes/block.h classes/block_header.cpp classes/block_header.h classes/block_body.cpp classes/block_body.h)