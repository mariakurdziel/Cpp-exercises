project(figury)

set(HEDEAR_FILES Figury.h)
set(SOURCE_FILES Figury.cpp)

add_library(libfigury STATIC ${SOURCE_FILES})
target_include_directories(libfigury PUBLIC .)

add_executable(figury ${SOURCE_FILES} main.cpp)

target_link_libraries(figury libfigury)

