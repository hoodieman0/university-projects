
enum MoveType {
    Spell,
    Curse, 
    Sword,
    Melee
  };

class BattleMove : public UndoableCommand {
  public:
      BattleMove(Actor* self, Actor* other)
          :self{ self },
          other{ other }
      {}

  protected:
      Actor* self;
      Actor* other;
  };

  This derives from UndoableCommand which is defined below:
  class UndoableCommand
  {
    public:
      virtual void Execute()=0;
      virtual void Undo()=0;
  };