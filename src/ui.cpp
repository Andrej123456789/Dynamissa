/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: UI implementation
 */

#include "../include/ui.hpp"

int dynamissa_editor(int x, int y, int width, int height, Object* object, Simulation* simulation)
{
    ImGui::SetNextWindowPos(ImVec2(x, y));
    ImGui::SetNextWindowSize(ImVec2(width, height));

    ImGui::Begin("Dynamissa editor", nullptr);

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Objects");
    ImGui::Text("list of objects...");

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Object creation");
    ImGui::InputInt("X position", &object->x);
    ImGui::InputInt("Y position", &object->y);
    ImGui::InputInt("width", &object->width);
    ImGui::InputInt("height", &object->height);
    ImGui::InputDouble("mass", &object->mass);
    ImGui::InputDouble("velocity", &object->velocity);
    if (ImGui::Button("Spawn", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {

    }

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Force manipulation");
    ImGui::Text("forces...");

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Simulation");
    ImGui::InputInt("duration", &simulation->duration);
    ImGui::InputDouble("steps", &simulation->steps);
    if (ImGui::Button("Run", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {

    }

    ImGui::End();
    return 0;
}
