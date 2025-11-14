#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

struct AppState {

    SDL_Window* Window = nullptr;

    SDL_Renderer* Renderer = nullptr;

    static AppState* Create(void** ptr) {
        auto state = new AppState{};
        *ptr = state;
        return state;
    }

    static void Destroy(void* ptr) {
        delete Get(ptr);
    }

    static AppState* Get(void* ptr) {
        return reinterpret_cast<AppState*>(ptr);
    }
};

SDL_AppResult SDL_AppInit(void** stateptr, int argc, char* argv[]) {

    SDL_SetAppMetadata("SDL Template", "1.0", "com.uspiritwolf.sdl.template");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    const SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_HIDDEN;

    AppState* appState = AppState::Create(stateptr);

    if (!SDL_CreateWindowAndRenderer("SDL Template", 1920, 1080, flags, &appState->Window, &appState->Renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderLogicalPresentation(appState->Renderer, 1920, 1080, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    SDL_SetWindowPosition(appState->Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(appState->Window);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* stateptr) {

    AppState* state = AppState::Get(stateptr);

    const double now = ((double)SDL_GetTicks()) / 1000.0;
    const float red = (float)(0.5 + 0.5 * SDL_sin(now));
    const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
    SDL_SetRenderDrawColorFloat(state->Renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);

    SDL_RenderClear(state->Renderer);
    SDL_RenderPresent(state->Renderer);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* stateptr, SDL_Event* event) {

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* stateptr, SDL_AppResult result) {
    AppState::Destroy(stateptr);
}

int main(int argc, char* argv[]) {
    return SDL_EnterAppMainCallbacks(argc, argv, SDL_AppInit, SDL_AppIterate, SDL_AppEvent, SDL_AppQuit);
}
