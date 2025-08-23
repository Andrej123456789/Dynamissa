/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's entry point
 */

#include <array>
#include <chrono>
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
#include "../include/renderer.hpp"
#include "../include/simulation.hpp"
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

    SDL_Window* window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 
                                          800, 600, SDL_WINDOW_RESIZABLE);
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
    /*                    Dynamissa structs initialization                   */
    /* --------------------------------------------------------------------- */

    SimulationData simulation_data = {
        std::chrono::steady_clock::now(), // start
        std::chrono::duration<double>(1.0), // duration
        false, // run
    };

    Dynamissa* dyn = new Dynamissa{};

    std::array<float, 4> default_color = { 1.0f, 0.0f, 0.0f, 1.0f }; // red
    dyn->temp_object = { 300, 100, 100, 100, 0.0, 0.0, default_color };

    dyn->simulation = &simulation_data;

    /* --------------------------------------------------------------------- */
    /*                    Dynamissa classes initialization                   */
    /* --------------------------------------------------------------------- */

    Renderer renderer_class = Renderer(dyn, window, renderer);
    SimulationEngine simulation_engine(dyn, 0, 0);

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

        // Get window size
        int width = 0;
        int height = 0;

        SDL_GetWindowSize(window, &width, &height);

        // Run Dynamissa
        dynamissa(width, height, dyn, &renderer_class, &simulation_engine);

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
