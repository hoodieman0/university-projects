#include "Stack.hpp"
#include "UndoableCommand.hpp"

class CommandManager
    {
      private:
          Stack<UndoableCommand*> stack; 

      public:
          CommandManager() :stack{ Stack<UndoableCommand*>()} {}
          void Execute(UndoableCommand* command);
          void Undo();
    };