/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bulat
 *
 * Created on 13 ноября 2021 г., 19:29
 */
#include "geom.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
using namespace std;
vector<Model> models;

/*
 * 
 */
int main(int argc, char** argv) {
    Camera camera();

    models.push_back(Model(0, 0, 0, 1));
    sf::RenderWindow window(sf::VideoMode(800, 600), "3D!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved) {
                for (int i = 0; i < models.size(); i++) {

                }
            }

        }
        window.clear(sf::Color(0, 0, 0));
        sf::RectangleShape center;
        center.setFillColor(sf::Color(255, 0, 0));
        center.setPosition(400, 300);
        center.setSize(sf::Vector2f(1, 1));
        window.draw(center);
        for (int i = 0; i < models.size(); i++) {
            for (int j = 0; j < models[i].triangles.size(); j++) {
                if (models[i].position.x >= camera.minX && models[i].position.x <= camera.maxX && models[i].position.y >= camera.minY && models[i].position.y <= camera.maxY && models[i].position.z >= camera.minZ && models[i].position.z <= camera.maxZ) {
                    //printf("%f\n", models[i].position.z);
                    /*sf::ConvexShape tri;
                    tri.setPointCount(3);
                    tri.setPoint(0, sf::Vector2f(models[i].triangles[j].v1.position.x * 50, -models[i].triangles[j].v1.position.y * 50));
                    tri.setPoint(1, sf::Vector2f(models[i].triangles[j].v2.position.x * 50, -models[i].triangles[j].v2.position.y * 50));
                    tri.setPoint(2, sf::Vector2f(models[i].triangles[j].v3.position.x * 50, -models[i].triangles[j].v3.position.y * 50));
                    tri.setPosition(400 + models[i].position.x * 50, 300 - models[i].position.y * 50);
                    tri.setFillColor(sf::Color(255, 255, 255));
                    tri.setOutlineThickness(1);
                    tri.setOutlineColor(sf::Color(0, 0, 0));
                    window.draw(tri);*/
                    sf::VertexArray line(sf::LinesStrip, 2);
                    line[0].position = sf::Vector2f(400 + models[i].position.x + models[i].triangles[j].v1.position.x, 300 + -models[i].position.y + -models[i].triangles[j].v1.position.y);
                    line[1].position = sf::Vector2f(400 + models[i].position.x + models[i].triangles[j].v2.position.x, 300 + -models[i].position.y + -models[i].triangles[j].v2.position.y);
                    line[0].color = sf::Color(0, 255, 0);
                    line[1].color = sf::Color(0, 255, 0);

                    sf::VertexArray line1(sf::LinesStrip, 2);
                    line1[0].position = sf::Vector2f(400 + models[i].position.x + models[i].triangles[j].v2.position.x, 300 + -models[i].position.y + -models[i].triangles[j].v2.position.y);
                    line1[1].position = sf::Vector2f(400 + models[i].position.x + models[i].triangles[j].v3.position.x, 300 + -models[i].position.y + -models[i].triangles[j].v3.position.y);
                    line1[0].color = sf::Color(0, 255, 0);
                    line1[1].color = sf::Color(0, 255, 0);

                    sf::VertexArray line2(sf::LinesStrip, 2);
                    line2[0].position = sf::Vector2f(400 + models[i].position.x + models[i].triangles[j].v3.position.x, 300 + -models[i].position.y + -models[i].triangles[j].v3.position.y);
                    line2[1].position = sf::Vector2f(400 + models[i].position.x + models[i].triangles[j].v1.position.x, 300 + -models[i].position.y + -models[i].triangles[j].v1.position.y);
                    line2[0].color = sf::Color(0, 255, 0);
                    line2[1].color = sf::Color(0, 255, 0);

                    window.draw(line);
                    window.draw(line1);
                    window.draw(line2);
                }

            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            models[0].rotateYZ(1);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            models[0].rotateXZ(1);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            models[0].rotateXY(1);

        }
        window.display();
    }

    return 0;
}

