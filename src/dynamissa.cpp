#include "../include/dynamissa.hpp"
#include <stdio.h>

struct Object* objects[MAX_OBJECTS];
int obj_index = 0;

void Dynamissa(int width, int height, SDL_Renderer* renderer)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(0.3 * width, height));

    ImGui::Begin("Dynamissa editor");

    if (ImGui::Button("Spawn", ImVec2(50, 20)) || (ImGui::IsItemFocused() && ImGui::IsKeyPressed(ImGuiKey_Enter)))
    {
        printf("toni\n");

        objects[obj_index] = new Object{300, 100, 100, 100, 0, 10};
        obj_index++;
    }

    for (int i = 0; i < MAX_OBJECTS; i++)
    {
        if (*(objects+i) == NULL)
        {
            break;
        }

        printf("mint\n");

        SDL_Rect redSquare = { objects[i]->x, objects[i]->y, objects[i]->width, objects[i]->height};      // x, y, w, h
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(renderer, &redSquare);         // Draw filled red square
    }

    ImGui::End();
}
