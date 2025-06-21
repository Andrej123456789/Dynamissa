/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main header
 */

#pragma once

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_sdl2.h"
#include "../imgui/imgui_impl_sdlrenderer2.h"

#if defined _WIN32 || defined _WIN64
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#define NAME "Dynamissa"

struct Dynamissa;

/**
 * @brief Program's main logic
 * 
 * @param window SDL2 window
 * @param renderer SDL2 renderer
 */
void dynamissa(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer);
