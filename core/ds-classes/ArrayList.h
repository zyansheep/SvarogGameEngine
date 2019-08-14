#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "core/String.h"
#include "core/events/Event.h"
#include<iostream>
#include<vector>
#include<string>
#define ARRAYLIST_TYPE(X)template class ArrayList<X>
template<class T>
class ArrayList {
    private:
        T * itemLI;
        std::vector<T>items;
    public:
        
        void set(int index, T const& item);
        void add(T const& item);
        void clear();
        void remove(int index);
        T get(int index);
        int size();
        bool isEmpty();
        T Max (const T& a, const T& b);
        T Min (const T& a, const T& b);
        T lessThanEqual(const T& a, const T& b);
        T greaterThanEqual(const T& a, const T& b);
};
#endif

