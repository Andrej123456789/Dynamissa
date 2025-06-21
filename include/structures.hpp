/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Header for various structures
 */

#pragma once

#include <vector>

struct Object
{
    int x;
    int y;
    int width;
    int height;

    double mass;
    double velocity;
};

struct Simulation
{
    int duration;
};

struct UI
{
    size_t current_object;
};

/**
 * @brief Structure containing pointers to all Dynamissa structures we might use
 * 
 * @param objects list of objects in simulation
 * @param simulation structure containing simulation settings
 */
struct Dynamissa
{
    std::vector<Object> objects;
    Simulation* simulation;
    UI* ui;
};
