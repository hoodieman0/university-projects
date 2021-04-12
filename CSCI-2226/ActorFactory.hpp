#pragma once

#include "Actor.hpp"
#include "ActorType.hpp"
#include "KnightActor.hpp"
#include "GhostActor.hpp"

//teacher provided code

class ActorFactory {
  public:
      static Actor* CreateActor(ActorType actorType) {
          Actor* actor = nullptr;
          switch (actorType) {
          case ActorType::Ghost:
              actor = new GhostActor(); 
              break;
          case ActorType::Knight:
              actor = new KnightActor();
              break;
            default:
                std::cerr << "I shouldn't be here";
                exit(1);
                break;
          }
          return actor; 
      }
  };