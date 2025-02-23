#pragma once
#ifndef WINDOWINPUT_H
#define WINDOWINPUT_H
#include "keyboard.h"
#include "macrodefs.h"

class WindowInput : public Keyboard{
    private: 
        static WindowInput* InputManager;
    public: 
        static WindowInput* getSingleton();
        WindowInput() : Keyboard() {}
    protected: 
        virtual bool checkKeyPressed(int keycode) override;
        virtual bool checkKeyReleased(int keycode) override;
        virtual bool checkKeyHeld(int keycode) override;
        virtual bool checkKeyRepeat(int keycode) override;
};
#endif