#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <iostream>
#include <string>

#define __triangle__

/* Setup the display and create the window */
extern GLFWwindow* InitDisplay(int width, int height);

/* Terminate the program */
extern void ExitProgram(void);