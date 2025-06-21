/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Header for various structures
 */

#pragma once

#include <vector>

 /**
  * @brief Structure containing object information
  *
  * @param x
  * @param y
  * @param width
  * @param height
  * @param mass in kg
  * @param velocity in m/s
  */
struct Object
{
    int x;
    int y;
    int width;
    int height;

    double mass;
    double velocity;
};

/**
 * @brief Structure containing simulation information
 *
 * @param duration duration of simulation in seconds
 * @param run is simulation active
 */
struct Simulation
{
    int duration;
    bool run;
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
    Object temp_object;

    Simulation* simulation;
};
