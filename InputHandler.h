#pragma once
#include "ICommand.h"

/// <summary>
/// 入力管理クラス
/// </summary>
class InputHandler
{
public: // メンバ関数

	ICommand* HandleInput();

	/// <summary>
	/// Aキーを押したときのコマンド
	/// </summary>
	void AssignMoveLeftCommand2PressKeyA();

	/// <summary>
	/// Aキーを押したときのコマンド
	/// </summary>
	void AssignMoveLeftCommand2PressKeyD();

private: // メンバ変数

	// Aキーを押したときのコマンド
	ICommand* PressKeyA_;
	// Dキーを押したときのコマンド
	ICommand* PressKeyD_;

};

