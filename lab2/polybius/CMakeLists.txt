project(polybius)

set(HEDEAR_FILES Polybius.h)
set(SOURCE_FILES Polybius.cpp)

add_library(libpolybius STATIC ${SOURCE_FILES})
target_include_directories(libpolybius PUBLIC .)

add_executable( polybius ${SOURCE_FILES} Polybius.cpp main.cpp)

target_link_libraries(polybius libpolybius)
