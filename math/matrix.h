#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include "macrodefs.h"
#include "core/Point.h"
#include "core/ds-classes/ArrayList.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// simple matrix row struct
typedef struct {
    float r0, r1, r2;
} matrixRow;

// coordinate matrix struct
typedef struct {
    float xpos, ypos, zpos;
} coordmat;
class Matrix {
    public:
        matrixRow row1, row2, row3;
        Matrix(matrixRow r1, matrixRow r2, matrixRow r3) {
            this->row1 = r1;
            this->row2 = r2;
            this->row3 = r3;
        }
        Matrix(){}

        void setC1Parts(float x0, float x1, float x2);
        void setC2Parts(float y0, float y1, float y2);
        void setC3Parts(float z0, float z1, float z2);

        Matrix operator+(Matrix const& mat4) {
            Matrix a;
            a.row1.r0 = mat4.row1.r0 + this->row1.r0;
            a.row1.r1 = mat4.row1.r1 + this->row1.r1;
            a.row1.r2 = mat4.row2.r2 + this->row2.r2;
            a.row2.r0 = mat4.row2.r0 + this->row2.r0;
            a.row2.r1 = mat4.row2.r1 + this->row2.r1;
            a.row2.r2 = mat4.row2.r2 + this->row2.r2;
            a.row3.r0 = mat4.row3.r0 + this->row3.r0;
            a.row3.r1 = mat4.row3.r1 + this->row3.r1;
            a.row3.r2 = mat4.row3.r2 + this->row3.r2;
            return a;
        }

        Matrix operator-(Matrix const& mat4) {
            Matrix a;
            a.row1.r0 = mat4.row1.r0 - this->row1.r0;
            a.row1.r1 = mat4.row1.r1 - this->row1.r1;
            a.row1.r2 = mat4.row1.r2 - this->row1.r2;
            a.row2.r0 = mat4.row2.r0 - this->row2.r0;
            a.row2.r1 = mat4.row2.r1 - this->row2.r1;
            a.row2.r2 = mat4.row2.r2 - this->row2.r2;
            a.row3.r0 = mat4.row3.r0 - this->row3.r0;
            a.row3.r1 = mat4.row3.r1 - this->row3.r1;
            a.row3.r2 = mat4.row3.r2 - this->row3.r2;
            return a;
        }

        Matrix operator*(Matrix const& mat4) {
            Matrix a;
            a.row1.r0 = mat4.row1.r0 * this->row1.r0;
            a.row1.r1 = mat4.row1.r1 * this->row1.r1;
            a.row1.r2 = mat4.row1.r2 * this->row1.r2;
            a.row2.r0 = mat4.row2.r0 * this->row2.r0;
            a.row2.r1 = mat4.row2.r1 * this->row2.r1;
            a.row2.r2 = mat4.row2.r2 * this->row2.r2;
            a.row3.r0 = mat4.row3.r0 * this->row3.r0;
            a.row3.r1 = mat4.row3.r1 * this->row3.r1;
            a.row3.r2 = mat4.row3.r2 * this->row3.r2;
            return a;
        }

        Matrix operator/(Matrix const& mat4) {
            Matrix a;
            a.row1.r0 = mat4.row1.r0 / this->row1.r0;
            a.row1.r1 = mat4.row1.r1 / this->row1.r1;
            a.row1.r2 = mat4.row1.r2 / this->row1.r2;
            a.row2.r0 = mat4.row2.r0 / this->row2.r0;
            a.row2.r1 = mat4.row2.r1 / this->row2.r1;
            a.row2.r2 = mat4.row2.r2 / this->row2.r2;
            a.row3.r0 = mat4.row3.r0 / this->row3.r0;
            a.row3.r1 = mat4.row3.r1 / this->row3.r1;
            a.row3.r2 = mat4.row3.r2 / this->row3.r2;
            return a;
        };
        // TODO: fix typename error.
        // ArrayList<float>getRow(int row);
        float getValue(int row, int spot);
        ArrayList<float>*getRow(int id) {
            ArrayList<float>*row = new ArrayList<float>();
            if(id == 1) {
                row->add(this->row1.r0);
                row->add(this->row1.r1);
                row->add(this->row1.r2);
            }

            if(id == 2) {
                row->add(this->row2.r0);
                row->add(this->row2.r1);
                row->add(this->row2.r2);
            }

            if(id == 3) {
                row->add(this->row3.r0);
                row->add(this->row3.r1);
                row->add(this->row3.r2);
            }
            return row;
        }
};
#endif