#pragma once 
#ifndef STACK_H
#define STACK_H
#include "Pair.h"
#include "core/String.h"
#include "ArrayList.h"
#include "core/events/Event.h"
#include "macrodefs.h"

template<class S>
class Stack {
    private: 
        ArrayList<S>stack;
        const int topPiece = stack.size() - 1;
        const int bottomPiece = 0;
    public:
        Stack() {}
        S top();
        bool isEmpty();
        void clear();
        void push(S const& item);
        S pop();
};

TMP_TYPE(Stack, Queue<Event*>);
TMP_TYPE(Stack, Event);
TMP_TYPE(Stack, Event*);
TMP_TYPE(Stack, double);
TMP_TYPE(Stack, float);
TMP_TYPE(Stack, int);
TMP_TYPE(Stack, char);
TMP_TYPE(Stack, short);
TMP_TYPE(Stack, long);
TMP_TYPE(Stack, String);
#endif