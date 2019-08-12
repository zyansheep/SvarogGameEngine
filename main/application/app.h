#pragma once 
#ifndef APP_H
#define APP_H
#include <glad/glad.h>
#include "main/window/window.h"
#include "main/materials/material.h"
#include "core/ds-classes/ArrayList.h"
#include "main/shapes/shape.h"
#include "macrodefs.h"
#include <bits/stdc++.h>
class Application {
    public: 
        Window winA;
        bool engineState;
        Shape drawer;
        GLFWwindow* appWindow;
        Application(){};
        Application(Window w, bool eState) {
            winA = w;
            engineState = eState;
        }

        Application(GLFWwindow* window, bool eState) {
            appWindow = window;
            engineState = eState;
        }
        // getters
        Window getWindow() const;
        bool getLoopState() const;
        // setters
        void ChangeCurrWindow(Window win);
        void ChangeLoopState(bool newState);
        // window context
        void createWindowContext();
        void SvarogAppLoop();
};
#endif