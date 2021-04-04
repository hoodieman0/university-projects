#include "Actor.hpp"

Actor::Actor()
{
    health = 0;
    type = "Knight";
}

Actor::Actor(int h, std::string t)
{
    type = t;
    health = h;
}