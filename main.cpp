#include <stdio.h>

#include "Corps.hpp"
#include "Calcul.hpp"
#include <iostream>
#include "mainheader.hpp"
#include <math.h>


using namespace std;

int main()
{

    sf::Uint8 *pixels = new sf::Uint8[LENGTH*HEIGHT*4];
    /* Création de la fenêtre */
    sf::RenderWindow window(sf::VideoMode(LENGTH, HEIGHT), "SFML works!");

    /* Création des deux corps */
    sf::CircleShape soleil(sRadius);
    soleil.setFillColor(sf::Color::Yellow);
    soleil.setPosition(xSoleil,ySoleil);
    // Centre soleil : (xSoleil+sRadius/2,ySoleil+sRadius/2)
    sf::CircleShape terre(tRadius);
    terre.setFillColor(sf::Color::Blue);
    terre.setPosition(xTerre,yTerre);
    // Centre soleil : (xTerre+tradius/2,500+tradius/2)

    /* Création du corps étudié de masse négligeable devant les deux autres */
    /* Prototype : Corps(float pX = 0.f, float pY = 0.f, float ppX = 0.f, float ppY = 0.f, float sX = 500.f, float sY = 500.f, float psX = 500.f, float psY = 500.f, float aX = 0.f, float aY = 0.f) */
    /* (pX,pY)=current position */
    /* (ppX,ppY)=previous position */
    /* (sX,sY)=current speed */
    /* (psX,psY)=previous speed */
    /* (aX,aY)=current acceleration */
    /* all floats. */
    Corps *corps = new Corps(0,0,600,500,0,0,0,-200,0,0);


    sf::CircleShape corps_screen(5.f);
    corps_screen.setFillColor(sf::Color::Red);


    /* Boucle permettant d'actualiser la position du corps de masse négligeable */
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Texture texture;
        texture.create(LENGTH,HEIGHT);
        sf::Sprite sprite;
        sprite.setTexture(texture);

        /* Calcul des nouvelles coordonnées */
 //       corps->updatePos(0.01);
        /* Affichage console des paramètres */
 //       corps->printStats();

        /* Actualisation de la position sur l'écran */
 //       corps_screen.setPosition(corps->getX(),corps->getY());

        updatePixels(pixels);

        texture.update(pixels);
        window.clear();
        window.draw(sprite);
        window.draw(soleil);
        window.draw(terre);
        window.display();
    }


    return 0;
}


