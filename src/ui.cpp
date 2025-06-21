/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: UI implementation
 */

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_sdl2.h"
#include "../imgui/imgui_impl_sdlrenderer2.h"

#include "../include/structures.hpp"
#include "../include/ui.hpp"

DynamissaEditor::DynamissaEditor(int x, int y, int width, int height, Dynamissa* dyn)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->dyn = dyn;
}

DynamissaEditor::~DynamissaEditor()
{

}

void DynamissaEditor::dynamissa_editor()
{
    ImGui::SetNextWindowPos(ImVec2(x, y));
    ImGui::SetNextWindowSize(ImVec2(width, height));

    ImGui::Begin("Dynamissa editor", nullptr);

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Objects");
    objects_ui();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Object creation");
    object_creation_ui();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Force manipulation");
    forces_ui();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Simulation");
    simulation_ui();

    ImGui::End();
}

void DynamissaEditor::objects_ui()
{
    ImGui::Text("list of objects...");
}

void DynamissaEditor::object_creation_ui()
{
    ImGui::InputInt("X position", &dyn->temp_object.x);
    ImGui::InputInt("Y position", &dyn->temp_object.y);
    ImGui::InputInt("width", &dyn->temp_object.width);
    ImGui::InputInt("height", &dyn->temp_object.height);
    ImGui::InputDouble("mass", &dyn->temp_object.mass);
    ImGui::InputDouble("velocity", &dyn->temp_object.velocity);
    if (ImGui::Button("Spawn", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        dyn->objects.push_back(dyn->temp_object);
    }
}

void DynamissaEditor::forces_ui()
{
    ImGui::Text("forces...");
}

void DynamissaEditor::simulation_ui()
{
    ImGui::InputInt("duration", &dyn->simulation->duration);
    if (ImGui::Button("Run", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        dyn->simulation->run = true;
    }

    if (ImGui::Button("Stop", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        dyn->simulation->run = false;
    }
}
