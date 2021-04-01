class CommandManager
    {
      private:
          Stack<UndoableCommand*> stack; 

      public:
          CommandManager() :stack{ Stack<UndoableCommand*>(100) } {}
          void Execute(UndoableCommand* command);
          void Undo();
      };