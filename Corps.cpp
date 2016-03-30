#include "Corps.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>

/* Defines for 1st body/object and 2nd body/object distances */
#define d_so sqrt(pow(this->posX-300,2)+pow(500-this->posY,2))
#define d_to sqrt(pow(this->posX-850,2)+pow(500-this->posY,2))

Corps::Corps()
{
    this->posX = 0;
    this->posY = 0;
    this->p_posX = 0;
    this->p_posY = 0;
    this->spdX = 0;
    this->spdY = 0;
    this->p_spdX = 0;
    this->p_spdY = 0;
    this->accX = 0;
    this->accY = 0;
}



Corps::Corps(float pX = 0.f, float pY = 0.f, float ppX = 0.f, float ppY = 0.f, float sX = 500.f, float sY = 500.f, float psX = 500.f, float psY = 500.f, float aX = 0.f, float aY = 0.f)
{
    this->posX = pX;
    this->posY = pY;
    this->p_posX = ppX;
    this->p_posY = ppY;
    this->spdX = sX;
    this->spdY = sY;
    this->p_spdX = psX;
    this->p_spdY = psY;
    this->accX = aX;
    this->accY = aY;
}

void Corps::updatePos(float dt)
{



    this->accX = - 10000000*(this->posX-300)/pow(d_so,3);// + 1000000*(550-(this->posX-300))/pow(d_to,3);
    this->accY = + 10000000*(500-this->posY)/pow(d_so,3);// + 1000000*(500-this->posY)/pow(d_to,3);



    this->spdX = this->p_spdX + this->accX*dt;
    this->spdY = this->p_spdY + this->accY*dt;

    this->posX = this->p_posX + this->spdX*dt;
    this->posY = this->p_posY + this->spdY*dt;

    this->p_posX = posX;
    this->p_posY = posY;

    this->p_spdX = spdX;
    this->p_spdY = spdY;
}

void Corps::printStats()
{
    printf("accX = %f accY = %f\n",this->accX,this->accY);
    printf("spdX = %f spdY = %f\n",this->spdX,this->spdY);
    printf("d_so = %f\n",d_so);
    printf("d_to = %f\n\n",d_to);
    printf("%f %f\n", this->posX, this->posY);
}
