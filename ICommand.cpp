#include "ICommand.h"

void MoveLeftCommand::Exec(Player& player)
{
	// 左に移動したコマンド呼び出し
	player.MoveLeft();
}

void MoveRightCommand::Exec(Player& player)
{
	// 右に移動したコマンド呼び出し
	player.MoveRight();
}
