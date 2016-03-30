#ifndef CORPS_HPP
#define CORPS_HPP




////////////////////////////////////////////////////////////
/// \brief Define the studied object
///
////////////////////////////////////////////////////////////

class Corps
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// \param posX     X position of the body
    /// \param posY     Y position of the body
    /// \param p_posX   Previous X position of the body
    /// \param p_posY   Previous Y position of the body
    /// \param spdX     X speed component of the body
    /// \param spdY     Y speed component of the body
    /// \param p_spdX   Previous X speed of the body
    /// \param p_spdY   Previous Y speed of the body
    /// \param accX     X acceleration component of the body
    /// \param accY     Y acceleration component of the body
    ////////////////////////////////////////////////////////////

    Corps();

    Corps(float, float, float, float, float, float, float, float, float, float);

    ////////////////////////////////////////////////////////////
    /// \brief Updates the position of the body with a given time interval
    ///
    /// \param dt       Time interval
    ////////////////////////////////////////////////////////////

    void updatePos(float dt);

    ////////////////////////////////////////////////////////////
    /// \brief Prints out object parameters on the console
    ///
    ///
    ////////////////////////////////////////////////////////////
    void printStats();

    float getX(){return posX;};
    float getY(){return posY;};
    float getpX(){return p_posX;};
    float getpY(){return p_posY;};

private :
    float       posX;
    float       posY;
    float       spdX;
    float       spdY;
    float       accX;
    float       accY;

    float       p_posX;
    float       p_posY;
    float       p_spdX;
    float       p_spdY;

};

#endif
