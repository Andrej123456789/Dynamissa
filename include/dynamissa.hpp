/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main header
 */

#pragma once

#define NAME "Dynamissa"

struct Dynamissa;
struct Renderer;
struct SimulationEngine;
struct SDL_Window;
struct SDL_Renderer;

/**
 * @brief Program's main logic
 * 
 * @param dyn Dynamissa struct
 * @param renderer_class Renderer class
 * @param SimulationEngine SimulationEngine class
 * @param window SDL2 window
 * @param renderer SDL2 renderer
 */
void dynamissa(Dynamissa* dyn, Renderer* renderer_class,
    SimulationEngine* simulation_engine,
    SDL_Window* window, SDL_Renderer* renderer);
