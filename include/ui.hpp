/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: Dynamissa
 * LICENSE: MIT license
 * DESCRIPTION: UI header
 */

#pragma once

struct Dynamissa;

/**
 * @brief Class for Dynamissa editor window
 */
class DynamissaEditor
{
public:
	/**
	 * @brief Initialize the class
	 *
	 * @param x x position of the window
	 * @param y y position of the window
	 * @param width width of the window
	 * @param height height of the window
	 * @param dyn struct containing everything we might need
	 */
	DynamissaEditor(int x, int y, int width, int height, Dynamissa* dyn);
	~DynamissaEditor();

	/**
	 * @brief Code for `Dynamissa editor` window
	 */
	void dynamissa_editor();

private:
	/**
	 * @brief UI for managing objects
	 */
	void objects_ui();

	/**
	 * @brief UI for creating an object
	 */
	void object_creation_ui();

	/**
	 * @brief UI for managing forces on the objects
	 */
	void forces_ui();

	/**
	 * @brief UI for managing and running the simulation
	 */
	void simulation_ui();

private:
	int x;
	int y;
	int width;
	int height;

	Dynamissa* dyn;
};
