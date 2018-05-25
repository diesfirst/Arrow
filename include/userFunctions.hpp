//
//  userFunctions.hpp
//  OpenGL
//
//  Created by Michael Buckley on 3/10/18.
//  Copyright © 2018 Michael Buckley. All rights reserved.
//

#ifndef userFunctions_hpp
#define userFunctions_hpp

#include <glad/glad.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* initWindow(int scr_width, int scr_height);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow *window);
int initFail(GLFWwindow* window);

#endif /* userFunctions_hpp */


