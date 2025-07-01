/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Simulation header
 */

#pragma once

struct Dynamissa;

/**
 * @brief Class for simulation engine
 */
class SimulationEngine
{
public:
	/**
	 * @brief Initialize the class
	 *
	 * @param dyn Dynamissa struct
	 * @param window_width SDL2 window width
	 * @param window_height SDL2 window height
	 */
	SimulationEngine(Dynamissa* dyn, int window_width, int window_height);
	~SimulationEngine();

public:
	/**
	 * @brief Run the simulation, move objects.
	 */
	void run_simulation();


	/**
	 * @brief Update the SDL2 window size
	 *
	 * @param window_width SDL2 window width
	 * @param window_height SDL2 window height
	 */
	void update_window(int window_width, int window_height);

private:
	Dynamissa* dyn;
	int window_width;
	int window_height;
};
