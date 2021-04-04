#include "CommandManager.hpp"

CommandManager::CommandManager()
{

}

void CommandManager::Execute(UndoableCommand* command)
{
    stack.Push(command);
    stack.Top()->Execute();
}

void CommandManager::Undo()
{
    stack.Top()->Undo();
    stack.Pop();
}