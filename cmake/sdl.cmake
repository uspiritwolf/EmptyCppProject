set(SDL_STATIC ON)
set(SDL_SHARED OFF)

FetchContent_Declare(
    sdl3
    URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.2.26.zip
)
FetchContent_MakeAvailable(sdl3)
