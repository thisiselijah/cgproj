# Cmake Version
cmake_minimum_required(VERSION 3.10)
# Set project
project(finalproj)
# Set C/C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Set the source code
set(SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Find library
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

# Set executable file
add_executable(main2 ${SOURCES})

# target_sources(main PRIVATE 
#     ../component/shader.cpp
#     ../component/texture.cpp
#     ../component/controls.cpp)
target_sources(main2 PRIVATE 
    ../component/particlesys.cpp
    ../component/camera.cpp
    ../component/background.cpp
    ../component/shader.cpp
    ../component/texture.cpp
    ../component/stb_image.cpp
    ../component/stb_image_write.cpp
    )

target_include_directories(main2 PUBLIC 
    ../component)
# Linking
target_link_libraries(
    main2
    OpenGL::GL 
    GLEW::GLEW 
    glfw)