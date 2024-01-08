cmake_minimum_required(VERSION 3.14.0)
project(IMG_TRANSFORM VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGLIB_FILES img_lib.h img_lib.cpp
            ppm_image.h ppm_image.cpp)

if(CMAKE_SYSTEM_NAME MATCHES "^MINGW")
    set(SYSTEM_LIBS -lstdc++)
else()
    set(SYSTEM_LIBS)
endif()



#add_executable(vmirror vmirr.cpp  ${IMGLIB_FILES})
add_executable(negate negate.cpp ${IMGLIB_FILES})
add_executable(hmirror hmirr.cpp ${IMGLIB_FILES})
#add_executable(sobel sobel.cpp ${IMGLIB_FILES})

#target_link_libraries(vmirror ${SYSTEM_LIBS})
target_link_libraries(negate ${SYSTEM_LIBS})
target_link_libraries(hmirror ${SYSTEM_LIBS})
#target_link_libraries(sobel ${SYSTEM_LIBS})
