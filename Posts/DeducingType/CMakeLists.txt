
#cmake_minimum_required(VERSION 3.7)

project(langsCpp)

#add_compile_options(-std=c++11 -g -Wall -Wextra -Werror)
add_compile_options(-std=c++11 -g -Wall -Wextra)

add_executable(deducingType.exe deducingType.cpp)
#target_link_libraries(deducingType.exe boost_system)

#add_executable(compilerDiagnostics compilerDiagnostics.cpp)
