/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   geom.h
 * Author: bulat
 *
 * Created on 13 ноября 2021 г., 19:30
 */

#include <SFML/System.hpp>
#include <vector>
#ifndef GEOM_H
#define GEOM_H

class Camera {
public:
    sf::Vector3f position;
    sf::Vector3f rotation;
    int minX = -400, maxX = 400; //минимальная и максимальная границы X
    int minY = -300, maxY = 300; //мин. и макс. границы Y
    int minZ = position.z, maxZ = 200; //мин. и макс. границы Z
    Camera();
};

class Vector {
public:
    sf::Vector3f position;

    Vector(float x, float y, float z);
    Vector();

};

class Line {
public:
    Vector start;
    Vector end;
    Line(Vector s, Vector e);
    Line();
};

class Triangle {
public:
    Vector v1;
    Vector v2;
    Vector v3;
    Triangle(sf::Vector3f ve1, sf::Vector3f ve2, sf::Vector3f ve3);
};

class Model {
public:
    sf::Vector3f position;
    sf::Vector3f rotation;
    std::vector<Triangle> triangles;
    Model(float x, float y, float z, std::vector<Triangle> tris);

    Model(float x, float y, float z, int type);

    void rotateXY(float angle);
    void rotateYZ(float angle);
    void rotateXZ(float angle);
};

Vector AddVectorToVector(Vector v1, Vector v2);
Vector SubtractVectorFromVector(Vector v1, Vector v2);

Vector XYMatrixRotation(Vector v, float angle);
Vector YZMatrixRotation(Vector v, float angle);
Vector XZMatrixRotation(Vector v, float angle);

Vector Scale_(Vector v, Vector s);
#endif /* GEOM_H */

