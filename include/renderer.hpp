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
 * @brief Class for renderer
 */
class Renderer
{
public:
	/**
	 * @brief Initialize the class
	 *
	 * @param dyn Dynamissa struct
	 * @param window SDL2 window
	 * @param renderer SDL2 renderer
	 */
	Renderer(Dynamissa* dyn, SDL_Window* window, SDL_Renderer* renderer);
	~Renderer();

public:
	/**
	 * Render all objects to the screen.
	 */
	void dynamissa_renderer();

private:
	Dynamissa* dyn;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
