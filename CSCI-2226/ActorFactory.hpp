#include "Actor.hpp"
#include "KnightActor.hpp"
#include "GhostActor.hpp"

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
          }
          return actor; 
      }
  };