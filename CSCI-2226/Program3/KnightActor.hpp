#pragma once

#include "Actor.hpp"

class KnightActor : public Actor
{
    public:
        KnightActor();
        void Hit(int damage);
        void Heal(int amount);
};