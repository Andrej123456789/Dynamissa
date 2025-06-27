/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Renderer implementation
 */

#if defined _WIN32 || defined _WIN64
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#include "../include/renderer.hpp"
#include "../include/structures.hpp"

void dynamissa_renderer(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer)
{
    for (auto& object: dyn->objects)
    {
        SDL_Rect square =
        {
            object.x,
            object.y,
            object.width,
            object.height,
        }; // x, y, w, h

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // Red color
        SDL_RenderFillRect(renderer, &square);              // Draw filled red square
    }
}
