#pragma once 
#ifdef MATRIX4F_H
#define MATRIX4F_H
#endif
#include "libs.h"
using namespace std;
class Matrix4f { 
        public: 
            float mat[4][4];
            Matrix4f() {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        this->mat[i][j] = 0.0f;
                    }
                }
            }

            inline void transpose() {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        this->mat[i][j] = this->mat[j][i];
                    }
                }
            }

            float getVal(int row, int col) {
                return this->mat[row][col];
            }


            inline void setScaleFAC(float scalefac) {
                this->mat[0][0] = scalefac;
                this->mat[1][1] = scalefac;
                this->mat[2][2] = scalefac;
                this->mat[3][3] = scalefac;
            }

            inline void transScale(Matrix4f scale) {
                for(int i = 0; i < 4; i++) {
                    for(int j =  0; j < 4; j++) {
                        this->mat[i][j] = this->mat[i][j] *2;
                    }

                }
            }

            void setVectorRows(int row, Vector3 vec) {
                if(row <= 0 || row >= 4) {
                    std::invalid_argument("Spot for placement is invalid.");
                }
                setVal(row, 0, vec.initx);
                setVal(row, 1, vec.inity);
                setVal(row, 2, vec.initz);
            }

            inline void lookAt(Matrix4f view, Matrix4f model) {
                this->mat[0][0] = view.mat[0][0];
                this->mat[0][1] = view.mat[0][1];
                this->mat[0][2] = view.mat[0][2];
                this->mat[1][0] = view.mat[1][0];
                this->mat[1][1] = view.mat[1][1];
            }
        
            void setVal(int row, int col, float val) {
                if(row <= 0 || row >= 4) {
                    std::invalid_argument("Spot for val placement is too big, fix");
                }
                if(col <= 0 || col >= 0) {
                    std::invalid_argument("Col spot too small");
                }
                this->mat[row][col] = val;
            }

            Matrix4f operator+(const Matrix4f& b) {
                Matrix4f c;
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        c.mat[i][j] = b.mat[i][j] + this->mat[i][j];
                    }
                }
                return c;
            }

            Matrix4f operator*(const Matrix4f& b) {
                Matrix4f c;
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        c.mat[i][j] = b.mat[i][j] * this->mat[i][j];
                    }
                }
                return c;
            }
            
            inline void identity() {
                this->mat[0][0] = 1.0f;
                this->mat[1][1] = 1.0f;
                this->mat[2][2] = 1.0f;
                this->mat[3][3] = 1.0f;
            }

            inline void print() {
                for(int i = 0; i < 4; i++) {
                    cout << '\n';
                    for(int j = 0; j < 4; j++) {
                        cout << this->mat[i][j];
                    }
                    cout << '\n';
                }
            }

            void rotateMat(float angle, int axis) {
                rotate(angle, axis);
            }

            inline void rotate(float angle, int axis) {
                if(axis == 1) {
                    this->mat[0][0] = 1;
                    this->mat[0][1] = 0;
                    this->mat[0][2] = 0;
                    this->mat[0][3] = 0;
                    this->mat[1][1] = cosf(angle);
                    this->mat[1][2] = sinf(angle);
                    this->mat[1][3] = 0;
                    this->mat[2][1] = sinf(angle);
                    this->mat[2][2] = cosf(angle);
                    this->mat[2][3] = 0;
                }
            }

            void scaleMat(float scalex, float scaley, float scalez) {
                scale(Vector3(scalex, scaley, scalez));
            }

            inline void scale(Vector3 scaler) {
                this->mat[0][0] = getVal(0, 0) * scaler.initx;
                this->mat[1][1] = getVal(1, 1) * scaler.inity;
                this->mat[2][2] = getVal(2, 2) * scaler.initz;
            }

            void translateMat(float x, float y, float z) {
                translate(Vector3(x, y, z));
            }

            inline void translate(Vector3 x) {
                this->mat[0][3] = x.initx;
                this->mat[1][3] = x.inity;
            }
};

