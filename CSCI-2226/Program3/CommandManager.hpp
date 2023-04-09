#pragma once

#include "Stack.hpp"
#include "UndoableCommand.hpp"

#include <iostream>

class CommandManager
    {
      private:
          Stack<UndoableCommand*> stack; 

      public:
          CommandManager() :stack{ Stack<UndoableCommand*>()} {}
          void Execute(UndoableCommand* command);
          void Undo();
    };