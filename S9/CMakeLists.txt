set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(S9friend friend.cpp)
add_executable(S9move move.cpp)
add_executable(S9pimpl pimpl.cpp box.h box.cpp)
add_executable(S9lambda lambda.cpp)
add_executable(S9template template.cpp mylist.h mylist.cpp)
