/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Simulation implementation
 */

#include "../include/simulation.hpp"
#include "../include/structures.hpp"

void run_simulation(Dynamissa* dyn)
{
	if (!dyn->simulation->run)
	{
		return;
	}

	for (auto& object : dyn->objects)
	{
		object.x += object.velocity;
	}
}
