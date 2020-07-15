# CMakeList.txt: opencvdemo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project ("opencvdemo")
set(CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR D:/lib/opencv/build/x64/vc15/lib)

find_package(OpenCV REQUIRED)
# 将源代码添加到此项目的可执行文件。
add_executable(opencvdemo main.cpp header.h header.h utils.cpp utils.h demo.cpp demo.h)
target_link_libraries(opencvdemo "${OpenCV_LIBS}")
if (MSVC)
    file(GLOB OPENCV_DLLS "D:/lib/opencv/build/x64/vc15/bin/*.dll")
    add_custom_command(TARGET opencvdemo
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${OPENCV_DLLS}
            $<TARGET_FILE_DIR:opencvdemo>)
endif (MSVC)
# TODO: 如有需要，请添加测试并安装目标。

