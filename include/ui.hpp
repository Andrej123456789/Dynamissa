/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: UI header
 */

#pragma once

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_sdl2.h"
#include "../imgui/imgui_impl_sdlrenderer2.h"

#include "../include/structures.hpp"

/**
 * @brief Code for `Dynamissa editor` window
 * 
 * @param x x position of the window
 * @param y y position of the window
 * @param width width of the window
 * @param height height of the window
 * @param object struct containing object's information
 * @param simulation struct containing information about simulation
 */
int dynamissa_editor(int x, int y, int width, int height, Object* object, Simulation* simulation);
