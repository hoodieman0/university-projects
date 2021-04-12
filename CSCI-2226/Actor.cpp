#include "Actor.hpp"

std::ostream& operator<<(std::ostream& out, const Actor& actor) //I never use this, prints memory address
{
    out << actor.type;
}