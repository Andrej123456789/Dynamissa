/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Simulation implementation
 */

#include "../include/simulation.hpp"
#include "../include/structures.hpp"

SimulationEngine::SimulationEngine(Dynamissa* dyn, int window_width, int window_height)
{
	this->dyn = dyn;
	this->window_width = window_width;
	this->window_height = window_height;
}

SimulationEngine::~SimulationEngine()
{

}

void SimulationEngine::run_simulation()
{
	if (!dyn->simulation->run)
	{
		return;
	}

	for (auto& object : dyn->objects)
	{
		object.x += object.velocity;

		// Window bounds
		if (object.x <= 0 || object.x + object.width >= window_width)
		{
			object.velocity = -object.velocity;
		}
	}
}
