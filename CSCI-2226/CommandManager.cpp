#include "CommandManager.hpp"

void CommandManager::Execute(UndoableCommand* command)
{
    stack.Push(command);
    stack.Top()->Execute();
}

void CommandManager::Undo()
{
    try
    {
        stack.Top()->Undo();
        stack.Pop();
    }
    catch (const char* err)
    {
        std::cerr << err; 
    }
}