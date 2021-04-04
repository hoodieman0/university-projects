class UndoableCommand
  {
    public:
      virtual void Execute()=0;
      virtual void Undo()=0;
  };