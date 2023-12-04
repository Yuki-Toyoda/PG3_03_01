#include "InputHandler.h"
#include "MyInput.h"

ICommand* InputHandler::HandleInput()
{
	if (MyInput::GetKeybordState(DIK_A, Press)) {
		return PressKeyA_;
	}
 	if (MyInput::GetKeybordState(DIK_D, Press)) {
		return PressKeyD_;
	}

	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	this->PressKeyA_ = std::move(command);
}

void InputHandler::AssignMoveLeftCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	this->PressKeyD_ = std::move(command);
}
