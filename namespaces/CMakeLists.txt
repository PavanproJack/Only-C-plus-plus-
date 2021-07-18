add_library(namespaces src/name_space.cpp)

message("${CMAKE_CURRENT_SOURCE_DIR} is the current source")

target_include_directories(namespaces PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

