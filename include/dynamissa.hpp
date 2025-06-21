/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main header
 */

#pragma once

#define NAME "Dynamissa"

struct Dynamissa;
struct SDL_Window;
struct SDL_Renderer;

/**
 * @brief Program's main logic
 * 
 * @param window SDL2 window
 * @param renderer SDL2 renderer
 */
void dynamissa(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer);
