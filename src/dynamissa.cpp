/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main logic
 */

#include "../include/dynamissa.hpp"
#include "../include/ui.hpp"
#include "../include/structures.hpp"

void Dynamissa(SDL_Window* window, SDL_Renderer* renderer)
{
    int width = 0;
    int height = 0;

    Object* object = new Object{300, 100, 100, 100, 0.0, 0.0};
    Simulation* simulation = new Simulation{0, 0.0};

    SDL_GetWindowSize(window, &width, &height);
    dynamissa_editor(0, 0, 0.3 * width, height, object, simulation);

    delete object;
    delete simulation;
}
