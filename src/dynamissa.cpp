/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Program's main logic
 */

#include "../include/dynamissa.hpp"
#include "../include/renderer.hpp"
#include "../include/simulation.hpp"
#include "../include/structures.hpp"
#include "../include/ui.hpp"

void dynamissa(int width, int height, Dynamissa* dyn, DynamissaEditor* dyn_editor,
               Renderer* renderer_class, SimulationEngine* simulation_engine)
{
    dyn_editor->dynamissa_editor();

    renderer_class->dynamissa_renderer();

    simulation_engine->update_window(width, height);
    simulation_engine->run_simulation();
}
