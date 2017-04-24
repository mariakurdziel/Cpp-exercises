project(figury)

set(HEDEAR_FILES Geometry.h)
set(SOURCE_FILES Geometry.cpp)

add_library(libsquares STATIC ${SOURCE_FILES})
target_include_directories(libsquares PUBLIC .)

add_executable(squares ${SOURCE_FILES} Geometry.cpp main.cpp)

target_link_libraries(squares libsquares)