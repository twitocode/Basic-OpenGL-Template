cmake_minimum_required(VERSION 3.0)
project(graphics-tinkering VERSION 1.0 LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4 # release-1.10.0
  FIND_PACKAGE_ARGS
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_MakeAvailable(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
 endif()

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)

FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_MakeAvailable(glad)
    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
    set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
endif()

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        1.0.1 # release-1.10.0
  FIND_PACKAGE_ARGS
)

FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
    FetchContent_MakeAvailable(glm)
endif()

file(GLOB PROJECT_SHADERS shaders/*.vert shaders/*.frag)
source_group("Shaders" FILES ${PROJECT_SHADERS})

add_executable(${PROJECT_NAME} main.cpp ${PROJECT_SHADERS})


#target_sources(${PROJECT_NAME} PRIVATE src/Shader.cpp src/VBO.cpp src/VAO.cpp src/IBO.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} glfw glad glm)