/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: UI implementation
 */

#include "../include/ui.hpp"
#include "../include/structures.hpp"

int dynamissa_editor(int x, int y, int width, int height, Dynamissa* dyn)
{
    ImGui::SetNextWindowPos(ImVec2(x, y));
    ImGui::SetNextWindowSize(ImVec2(width, height));

    ImGui::Begin("Dynamissa editor", nullptr);

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Objects");
    ImGui::Text("list of objects...");

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Object creation");
    ImGui::InputInt("X position", &dyn->objects.at(dyn->ui->current_object).x);
    ImGui::InputInt("Y position", &dyn->objects.at(dyn->ui->current_object).y);
    ImGui::InputInt("width", &dyn->objects.at(dyn->ui->current_object).width);
    ImGui::InputInt("height", &dyn->objects.at(dyn->ui->current_object).height);
    ImGui::InputDouble("mass", &dyn->objects.at(dyn->ui->current_object).mass);
    ImGui::InputDouble("velocity", &dyn->objects.at(dyn->ui->current_object).velocity);
    if (ImGui::Button("Spawn", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {

    }

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Force manipulation");
    ImGui::Text("forces...");

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Simulation");
    ImGui::InputInt("duration", &dyn->simulation->duration);
    if (ImGui::Button("Run", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {

    }

    ImGui::End();
    return 0;
}
