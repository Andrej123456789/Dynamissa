/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main logic
 */

#if defined _WIN32 || defined _WIN64
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#include "../include/dynamissa.hpp"
#include "../include/renderer.hpp"
#include "../include/simulation.hpp"
#include "../include/structures.hpp"
#include "../include/ui.hpp"

void dynamissa(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer)
{
    int width = 0;
    int height = 0;

    SDL_GetWindowSize(window, &width, &height);

    DynamissaEditor dynamissa_editor(0, 0, 0.3 * width, height, dyn);
    dynamissa_editor.dynamissa_editor();

    dynamissa_renderer(dyn, window, renderer);
    run_simulation(dyn);
}
