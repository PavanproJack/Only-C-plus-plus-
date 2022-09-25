# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(Project)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)


# Add all the source files needed to build the executable
# add_executable(Project src/main.cpp src/helpers/AwesomeHelper.cpp src/helpers/OkHelper.cpp src/models/Person.cpp)
add_executable(Project src/main.cpp
                       src/learnings/literals.cpp
                       src/learnings/test.cpp
                       src/learnings/arrayss.cpp
                       src/learnings/pointerss.cpp

                       )


# Include the directory where MyLibrary project is. Otherwise, we can't use the
# library
# add_subdirectory(lib/MyLibrary)

# Link the executable and the library together
# target_link_libraries(Project MyLibrary)