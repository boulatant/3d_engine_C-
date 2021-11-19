/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "geom.h"
#include <cmath>

Camera::Camera() {
    position.x = 0;
    position.y = 0;
    position.z = 0;
    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;
}

Vector::Vector(float x, float y, float z) {
    position.x = x;
    position.y = y;
    position.z = z;
}

Vector::Vector() {

}

Line::Line(Vector s, Vector e) {
    start = s;
    end = e;
}

Line::Line() {
}

Triangle::Triangle(sf::Vector3f ve1, sf::Vector3f ve2, sf::Vector3f ve3) {
    v1.position = ve1;
    v2.position = ve2;
    v3.position = ve3;
}

Model::Model(float x, float y, float z, std::vector<Triangle> tris) {
    position.x = x;
    position.y = y;
    position.z = z;
    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;
    triangles = tris;
}

Model::Model(float x, float y, float z, int type) {
    position.x = x;
    position.y = y;
    position.z = z;
    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;
    switch (type) {
        case 1:
            triangles.push_back(Triangle(sf::Vector3f(-50, -50, 50), sf::Vector3f(50, -50, 50), sf::Vector3f(0, 50, 0)));
            triangles.push_back(Triangle(sf::Vector3f(-50, -50, -50), sf::Vector3f(50, -50, -50), sf::Vector3f(0, 50, 0)));
            triangles.push_back(Triangle(sf::Vector3f(-50, -50, 50), sf::Vector3f(-50, -50, -50), sf::Vector3f(0, 50, 0)));
            triangles.push_back(Triangle(sf::Vector3f(50, -50, 50), sf::Vector3f(50, -50, -50), sf::Vector3f(0, 50, 0)));
            triangles.push_back(Triangle(sf::Vector3f(-50, -50, 50), sf::Vector3f(-50, -50, -50), sf::Vector3f(50, -50, -50)));
            triangles.push_back(Triangle(sf::Vector3f(-50, -50, 50), sf::Vector3f(50, -50, 50), sf::Vector3f(50, -50, -50)));
            break;
    }
}

void Model::rotateXY(float angle) {
    for (int i = 0; i < triangles.size(); i++) {
        triangles[i].v1 = XYMatrixRotation(triangles[i].v1, angle);
        triangles[i].v2 = XYMatrixRotation(triangles[i].v2, angle);
        triangles[i].v3 = XYMatrixRotation(triangles[i].v3, angle);
    }
}

void Model::rotateXZ(float angle) {
    for (int i = 0; i < triangles.size(); i++) {
        triangles[i].v1 = XZMatrixRotation(triangles[i].v1, angle);
        triangles[i].v2 = XZMatrixRotation(triangles[i].v2, angle);
        triangles[i].v3 = XZMatrixRotation(triangles[i].v3, angle);
    }
}

void Model::rotateYZ(float angle) {
    for (int i = 0; i < triangles.size(); i++) {
        triangles[i].v1 = YZMatrixRotation(triangles[i].v1, angle);
        triangles[i].v2 = YZMatrixRotation(triangles[i].v2, angle);
        triangles[i].v3 = YZMatrixRotation(triangles[i].v3, angle);
    }
}

Vector AddVectorToVector(Vector v1, Vector v2) {
    Vector result;
    result.position.x = v1.position.x + v2.position.x;
    result.position.y = v1.position.y + v2.position.y;
    result.position.z = v1.position.z + v2.position.z;

    return result;
}

Vector SubtractVectorFromVector(Vector v1, Vector v2) {
    Vector result;
    result.position.x = v1.position.x - v2.position.x;
    result.position.y = v1.position.y - v2.position.y;
    result.position.z = v1.position.z - v2.position.z;

    return result;
}

Vector XYMatrixRotation(Vector v, float angle) {
    Vector result;
    float deg_angle = angle / (180 / M_PI);
    result.position.x = cos(deg_angle) * (v.position.x) + -sin(deg_angle) * (v.position.y);
    result.position.y = sin(deg_angle) * (v.position.x) + cos(deg_angle) * (v.position.y);
    result.position.z = v.position.z;
    return result;
}

Vector XZMatrixRotation(Vector v, float angle) {
    Vector result;
    float deg_angle = angle / (180 / M_PI);
    result.position.x = cos(deg_angle) * (v.position.x) + sin(deg_angle) * (v.position.z);
    result.position.y = v.position.y;
    result.position.z = -sin(deg_angle) * (v.position.x) + cos(deg_angle) * (v.position.z);
    return result;
}

Vector YZMatrixRotation(Vector v, float angle) {
    Vector result;
    float deg_angle = angle / (180 / M_PI);
    result.position.x = v.position.x;
    result.position.y = cos(deg_angle) * (v.position.y) + -sin(deg_angle) * (v.position.z);
    result.position.z = sin(deg_angle) * (v.position.y) + cos(deg_angle) * (v.position.z);
    return result;
}

Vector Scale_(Vector v, Vector s) {
    Vector result;
    result.position.x = v.position.x * s.position.x;
    result.position.y = v.position.y * s.position.y;
    result.position.z = v.position.z * s.position.z;
    return result;
}
