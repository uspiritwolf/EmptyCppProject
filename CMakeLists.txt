cmake_minimum_required (VERSION 3.29.2)
project (EmptyCppProject VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
include(cmake/sdl.cmake)

add_subdirectory(app)
