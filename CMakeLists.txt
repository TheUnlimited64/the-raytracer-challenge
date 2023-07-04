cmake_minimum_required(VERSION 3.25)
project(the_raytracer_challange C)

# Set the path to the Unity source files
set(UNITY_PATH ${CMAKE_SOURCE_DIR}/test)

# Include the Unity headers
include_directories(${UNITY_PATH})

# Add the test target
add_executable(tests
        test/unity.c
        test/src/testTuple.c
        src/helper/tuple.c
        src/helper/tuple.h
        src/color.h
        src/canvas.c src/canvas.h src/helper/defines.h src/filewriter/ppmWriter.c src/filewriter/ppmWriter.h src/filewriter/bmpWriter.c src/filewriter/bmpWriter.h)
add_executable(the_raytracer_challange main.c
        src/helper/tuple.c
        src/helper/tuple.h
        src/helper/floatingpoint.h
        src/color.h
        src/canvas.c src/canvas.h src/helper/defines.h src/filewriter/ppmWriter.c src/filewriter/ppmWriter.h src/filewriter/bmpWriter.c src/filewriter/bmpWriter.h)


# Include the source files directly for the test target
target_sources(tests PRIVATE
        src/helper/tuple.c
        src/helper/tuple.h
        src/helper/floatingpoint.h
        src/color.h
        )

set(CMAKE_C_STANDARD 11)

# Create the main target
target_link_libraries(the_raytracer_challange m)
target_link_libraries(tests m)
