project(palindrome)

set(HEDEAR_FILES Palindrome.h Show.h)
set(SOURCE_FILES Palindrome.cpp Show.h)

add_library(libpalindrome STATIC ${SOURCE_FILES})
target_include_directories(libpalindrome PUBLIC .)

add_executable(palindrome ${SOURCE_FILES} main.cpp Palindrome.cpp Show.h)

target_link_libraries(palindrome libpalindrome)
