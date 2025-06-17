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
#define MAX_OBJECTS 10

struct Object
{
	int x;
	int y;
	int width;
	int height;

	int velocity;
	int mass;
};

void Dynamissa(int width, int height, SDL_Renderer* renderer);
