/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: Header for various structures
 */

#pragma once

#include <array>
#include <chrono>
#include <vector>

/**
 * @brief Structure containing force information
 * @param angle vector's orientation in degrees, measured clockwise
 * @param magnitude
 */
struct Force
{
    int angle;
    double magnitude;
};

 /**
  * @brief Structure containing object information
  *
  * @param x
  * @param y
  * @param width
  * @param height
  * @param mass in kg
  * @param velocity in m/s
  * @param color represented in ImGui way (0.0 - 1.0), array of size 4
  */
struct Object
{
    int x;
    int y;
    int width;
    int height;

    double mass;
    double velocity;

    std::array<float, 4> color;
};

/**
 * @brief Structure containing simulation information
 *
 * @param start time when simulation started
 * @param duration duration of simulation in seconds
 * @param run is simulation active
 */
struct SimulationData
{
    std::chrono::steady_clock::time_point start;
    std::chrono::duration<double> duration;
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

    SimulationData* simulation;
};
