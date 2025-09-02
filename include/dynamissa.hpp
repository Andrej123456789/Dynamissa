/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main header
 */

#pragma once

#define NAME "Dynamissa"

struct Dynamissa;
struct DynamissaEditor;
struct Renderer;
struct SimulationEngine;

/**
 * @brief Program's main logic
 * 
 * @param width width of the SDL2 window
 * @param height height of the SDL2 window
 * @param dyn Dynamissa struct
 * @param renderer_class Renderer class
 * @param SimulationEngine SimulationEngine class
 */
void dynamissa(int width, int height, Dynamissa* dyn, DynamissaEditor* dyn_editor,
               Renderer* renderer_class, SimulationEngine* simulation_engine);
