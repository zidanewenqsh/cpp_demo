# CMakeList.txt: libtorchdemo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project ("libtorchdemo")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH D:/lib/libtorch)
find_package(Torch REQUIRED)
# 将源代码添加到此项目的可执行文件。
add_executable (libtorchdemo main.cpp header.h utils.cpp utils.h)
target_link_libraries(libtorchdemo "${TORCH_LIBRARIES}")
if (MSVC)
    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    add_custom_command(TARGET libtorchdemo
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${TORCH_DLLS}
            $<TARGET_FILE_DIR:libtorchdemo>)
endif (MSVC)
# TODO: 如有需要，请添加测试并安装目标。

