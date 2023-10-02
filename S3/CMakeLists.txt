set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(S3userdef userdefinedtypes.cpp)

add_executable(S3struct main.cpp
    Frazione.h
    Frazione.cpp)

add_executable(S3class main2.cpp Fraction.h Fraction.cpp)
add_executable(S3classinline main3.cpp FractionInline.h)

