cmake_minimum_required(VERSION 3.1...3.15)

set(targets "main")
set(objects "hello_glut")
set(proj_name "opengl_gungfu")
set(ver "0.1")

set(lang "CXX")
set(lang_ver "17")

project(${proj_name} VERSION ${ver} LANGUAGES ${lang})

add_executable(${objects} ${targets}.cpp)

target_compile_features(${objects} PUBLIC cxx_std_${lang_ver})
set_target_properties(${objects} PROPERTIES CXX_EXTENSIONS OFF)

list(INSERT CMAKE_FRAMEWORK_PATH 0 /System/Library/Frameworks)
include(CMakePrintHelpers) # macOS has incorrect location property accroding the issue 20184 
cmake_print_properties(TARGETS GLUT::GLUT PROPERTIES INTERFACE_INCLUDE_DIRECTORIES LOCATION) # workaround: https://gitlab.kitware.com/cmake/cmake/-/issues/20184 

find_package(GLUT REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
target_link_libraries(${objects} PRIVATE GLUT::GLUT)
target_link_libraries(${objects} PRIVATE glfw)
target_link_libraries(${objects} PRIVATE GLEW::GLEW)
