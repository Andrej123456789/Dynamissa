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

Renderer::Renderer(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer)
{
    this->dyn = dyn;
    this->window = window;
    this->renderer = renderer;
}

Renderer::~Renderer()
{

}

void Renderer::dynamissa_renderer()
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

        SDL_SetRenderDrawColor
        (
            renderer, 
            (uint8_t)(object.color[0] * 255),
            (uint8_t)(object.color[1] * 255),
            (uint8_t)(object.color[2] * 255),
            (uint8_t)(object.color[3] * 255)
        );

        SDL_RenderFillRect(renderer, &square);
    }
}
