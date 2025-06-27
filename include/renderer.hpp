/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Renderer header
 */

#pragma once

struct Dynamissa;
struct SDL_Window;
struct SDL_Renderer;

/**
 * @brief Entry point of Dynamissa's renderer
 *
 * Render all objects to the screen.
 * 
 * @param dyn Dynamissa struct
 * @param window SDL2 window
 * @param renderer SDL2 renderer
 */
void dynamissa_renderer(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer);
