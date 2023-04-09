#pragma once

#include "MoveType.hpp"

#include <vector>
#include <string>
#include <iostream>

class Actor {
    private:
        std::string type;

    protected:
        int health;
        std::vector<MoveType> moves;

    public:
        Actor(int health, std::string type) :
            health{ health },
            type{ type }
            {}

        virtual void Hit(int damage)=0;
        virtual void Heal(int amount)=0;

        int GetHealth() const
        {
            return health;
        }

        std::string GetType() const
        {
            return type;
        }

        const std::vector<MoveType>& GetMoves() const 
        {
            return moves;
        }

        bool IsDead() {return health <= 0; }
        
        friend std::ostream& operator<<(std::ostream& out, const Actor& actor);
      };