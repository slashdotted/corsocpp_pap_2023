set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(S8multipleinheritance main.cpp lecturer.cpp researcher.cpp employee.cpp lecturerresearcher.cpp)
add_executable(S8casts casts.cpp lecturer.cpp researcher.cpp employee.cpp lecturerresearcher.cpp)
