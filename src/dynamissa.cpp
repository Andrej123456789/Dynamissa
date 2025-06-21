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
#include "../include/structures.hpp"
#include "../include/ui.hpp"

void dynamissa(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer)
{
    int width = 0;
    int height = 0;

    SDL_GetWindowSize(window, &width, &height);

    DynamissaEditor dynamissa_editor(0, 0, 0.3 * width, height, dyn);
    dynamissa_editor.dynamissa_editor();

    for (size_t i = 0; i < dyn->objects.size(); i++)
    {
        SDL_Rect redSquare = { 
            dyn->objects[i].x,
            dyn->objects[i].y,
            dyn->objects[i].width,
            dyn->objects[i].height,
        };      // x, y, w, h

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(renderer, &redSquare);         // Draw filled red square
    }

    if (dyn->simulation->run)
    {
        printf("run");
    }
}
