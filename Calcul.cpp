#include "mainheader.hpp"
#include <math.h>
#include "Calcul.hpp"
#include <iostream>

using namespace std;

double calculNorme(int x, int y)
{

    int m1=1, m2=0.1;
    //double a = 40000/pow(d_so,2) + 10000/pow(d_to,2);
    //printf("aX=%lf\taY=%lf\n",aX,aY);
    double omega = sqrt(m1+m2);            // angular velocity of massive bodies

    double r1 = d_so;      // distance from m1 to (x,y)
    double r2 = d_to;      // distance from m2 to (x,y)

    double a = -pow(omega,2)/2*(pow(x,2)+pow(y,2))/10000;
    double b = - 10000*m1/r1;
    double c = - 10000*m2/r2;
    //cout << "\na=" << a << "\tb=" << b << "\tc=" << c ;
    double U = a + b + c;

    return U;
}

void updatePixels(sf::Uint8* pixels)
{
    for(int i=0; i<LENGTH; i++)
        {
            //std::cin.ignore();
            for(int j=0; j<HEIGHT; j++)
            {
                double n=calculNorme(i, j);
                //printf("n=%lf\t",n);
                //std::cin.ignore();


                /*
                pixels[(LENGTH*j+i)*4] = (int)(n)%255; //Rouge
                pixels[(LENGTH*j+i)*4 + 1] = 0; //Vert
                pixels[(LENGTH*j+i)*4 + 2] = 0; //Bleu
                pixels[(LENGTH*j+i)*4 + 3] = 255; //Alpha
                */

                for(double k=-30; k>=-60; k=k-1)
                    if(n<=k+0.1 && n>=k-0.1)
                    {
                        pixels[(LENGTH*j+i)*4] = 0; //Rouge
                        pixels[(LENGTH*j+i)*4 + 1] = 255; //Vert
                        pixels[(LENGTH*j+i)*4 + 2] = 0; //Bleu
                        pixels[(LENGTH*j+i)*4 + 3] = 255; //Alpha
                    }



            }
        }
}
