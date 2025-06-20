/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Header for various structures
 */

#pragma once

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
    double steps;
};
