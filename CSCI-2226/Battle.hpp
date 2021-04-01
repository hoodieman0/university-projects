class Battle
  {
    private:
      CommandManager undoManager;
      Actor* player1; 
      Actor* player2; 

    public:
      Battle(ActorType actor1, ActorType actor2) {
        player1 = ActorFactory::CreateActor(actor1);
        player2 = ActorFactory::CreateActor(actor2);
      }

      void Start();
      bool PlayerTurn();
      void NpcTurn();
  };