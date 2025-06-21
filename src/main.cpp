/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's entry point
 */

#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_sdl2.h"
#include "../imgui/imgui_impl_sdlrenderer2.h"

#if defined _WIN32 || defined _WIN64
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#include "../include/dynamissa.hpp"
#include "../include/structures.hpp"

/**
 * @brief Entry point of the program
 * 
 * Initialize SDL2, Dear ImGui and all Dynamissa structures.
 * Continue program's logic in `Dynamissa` function.
 */
int main(int argc, char* argv[]) 
{
    /* --------------------------------------------------------------------- */
    /*                          SDL initialization                           */
    /* --------------------------------------------------------------------- */

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();

        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    /* --------------------------------------------------------------------- */
    /*                      Dear ImGui initialization                        */
    /* --------------------------------------------------------------------- */

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    /* --------------------------------------------------------------------- */
    /*                      Dynamissa initialization                         */
    /* --------------------------------------------------------------------- */

    Simulation simulation = {
        0, // duration
        false, // run
    };

    Dynamissa* dyn = new Dynamissa{};
    dyn->temp_object = { 300, 100, 100, 100, 0.0, 0.0 };

    dyn->simulation = &simulation;

    /* --------------------------------------------------------------------- */
    /*                              Main loop                                */
    /* --------------------------------------------------------------------- */
    int running = 1;
    SDL_Event event;

    while (running)
    {
        // Handle events
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }

        // Start ImGui
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Clear screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Run Dynamissa
        dynamissa(dyn, window, renderer);

        // Present on screen
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

        SDL_RenderPresent(renderer);
    }

    /* --------------------------------------------------------------------- */
    /*                              Cleanup                                  */
    /* --------------------------------------------------------------------- */

    delete dyn;

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
