cmake_minimum_required(VERSION 3.9)
project(ImageBinarization)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(
        ImageBinarization
        main.cpp
        Binarizer.h Binarizer.cpp
)

target_link_libraries(ImageBinarization ${OpenCV_LIBS})