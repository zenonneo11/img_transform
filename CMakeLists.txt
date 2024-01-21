cmake_minimum_required(VERSION 3.14.0)
project(IMG_TRANSFORM VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(CMAKE_SYSTEM_NAME MATCHES "^MINGW")
    set(SYSTEM_LIBS -lstdc++)
else()
    set(SYSTEM_LIBS)
endif()

add_subdirectory(ImgLib)


add_executable(negate negate.cpp)
add_executable(hmirror hmirr.cpp)
add_executable(vmirror vmirr.cpp)
add_executable(sobel sobel.cpp)

target_include_directories(negate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ImgLib)
target_include_directories(hmirror PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ImgLib)
target_include_directories(vmirror PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ImgLib)
target_include_directories(sobel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ImgLib)



target_link_libraries(negate ImgLib ${SYSTEM_LIBS})
target_link_libraries(hmirror ImgLib ${SYSTEM_LIBS})
target_link_libraries(vmirror ImgLib ${SYSTEM_LIBS})
target_link_libraries(sobel ImgLib ${SYSTEM_LIBS})
