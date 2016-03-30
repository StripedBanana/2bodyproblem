#include <SFML/Graphics.hpp>

#define LENGTH 1024
#define HEIGHT 768

/* Defines for 1st body/object and 2nd body/object distances */
#define d_so sqrt(pow(x-(xSoleil+sRadius),2)+pow((ySoleil+sRadius)-y,2))
#define d_to sqrt(pow(x-(xTerre+tRadius),2)+pow((yTerre+tRadius)-y,2))

#define xSoleil 200
#define ySoleil 1050
#define xTerre 800
#define yTerre 1100
#define sRadius 100
#define tRadius 50
