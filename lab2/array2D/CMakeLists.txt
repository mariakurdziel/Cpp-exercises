project(array2D)

set(HEDEAR_FILES Array2D.h)
set(SOURCE_FILES Array2D.cpp)

add_library(libarray2D STATIC ${SOURCE_FILES})
target_include_directories(libarray2D PUBLIC .)

add_executable( array2D ${SOURCE_FILES} main.cpp Array2D.cpp)

target_link_libraries(array2D libarray2D)
