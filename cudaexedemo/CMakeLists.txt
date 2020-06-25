cmake_minimum_required(VERSION 3.16)
project(cudaexedemo CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cudaexedemo main.cu)

set_target_properties(
        cudaexedemo
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)