set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(S6inheritance main.cpp lecturer.cpp researcher.cpp employee.cpp)
add_executable(S6binding binding.cpp
    printable.h)
add_executable(S6poly polymorphic.cpp)
add_executable(S6team team.cpp)
