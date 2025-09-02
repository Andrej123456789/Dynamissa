/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: UI implementation
 */

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_sdl2.h"
#include "../imgui/imgui_impl_sdlrenderer2.h"

#include <format>
#include <string>

#include <stdint.h>

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
    for (size_t i = 0; i < dyn->objects.size(); i++)
    {
        std::string label = std::format("* Object {} {{X: {}, Y: {}, \nwidth: {}, height: {}, \
            \nmass: {:.2f} kg, \nvelocity: {:f} m/s, \
            \ncolor: ({}, {}, {}, {})}}",
            i,
            dyn->objects[i].x,
            dyn->objects[i].y,
            dyn->objects[i].width,
            dyn->objects[i].height,
            dyn->objects[i].mass,
            dyn->objects[i].velocity,
            (uint8_t)(dyn->objects[i].color[0] * 255),
            (uint8_t)(dyn->objects[i].color[1] * 255),
            (uint8_t)(dyn->objects[i].color[2] * 255),
            (uint8_t)(dyn->objects[i].color[3] * 255)
        );

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0)); // normal
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1, 1, 1, 0.1f)); // slight highlight on hover
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1, 1, 1, 0.2f)); // slight highlight on click
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f); // no border

        if (ImGui::Button(label.c_str()))
        {
            dyn->objects.erase(dyn->objects.begin() + i);

            ImGui::PopStyleVar();
            ImGui::PopStyleColor(3);

            continue; // don't increment because other objects shifted to the left
        }

        if (ImGui::IsItemHovered())
        {
            ImGui::SetTooltip("Click to destroy an object");
        }

        ImGui::PopStyleVar();
        ImGui::PopStyleColor(3);
    }
}

void DynamissaEditor::object_creation_ui()
{
    ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x * 0.6f);

    ImGui::InputInt("X position", &dyn->temp_object.x);
    ImGui::InputInt("Y position", &dyn->temp_object.y);
    ImGui::InputInt("width", &dyn->temp_object.width);
    ImGui::InputInt("height", &dyn->temp_object.height);
    ImGui::InputDouble("mass (kg)", &dyn->temp_object.mass, 0.1);
    ImGui::InputDouble("velocity (m/s)", &dyn->temp_object.velocity, 0.1);
    ImGui::ColorEdit4("color", dyn->temp_object.color.data());

    if (ImGui::Button("Spawn", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        dyn->objects.push_back(dyn->temp_object);
    }

    ImGui::PopItemWidth();
}

void DynamissaEditor::forces_ui()
{
    ImGui::Text("forces...");
}

void DynamissaEditor::simulation_ui()
{
    ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x * 0.65f);

    double duration = dyn->simulation->duration.count();
    if (ImGui::InputDouble("duration (s)", &duration, 0.1))
    {
        dyn->simulation->duration = std::chrono::duration<double>(duration);
    }

    if (ImGui::Button("Run", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        dyn->simulation->start = std::chrono::steady_clock::now();
        dyn->simulation->run = true;
    }

    if (ImGui::Button("Stop", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        dyn->simulation->run = false;
    }

    ImGui::PopItemWidth();
}
