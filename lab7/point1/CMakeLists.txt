project(point1)

set(HEDEAR_FILES Point1.h)
set(SOURCE_FILES Point1.cpp)

add_library(libpoint1 STATIC ${SOURCE_FILES})
target_include_directories(libpoint1 PUBLIC .)

add_executable(point1 ${SOURCE_FILES} main.cpp)

target_link_libraries(point1 libpoint1)

