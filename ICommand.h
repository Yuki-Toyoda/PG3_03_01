#pragma once
#include "Player.h"

// クラスの前方宣言
class Player;

/// <summary>
/// コマンド基底クラス
/// </summary>
class ICommand
{
public: // コンストラクタ等
	// 仮想デストラクタ
	virtual ~ICommand() {};
public: // メンバ関数
	/// <summary>
	/// この関数からコマンドの呼び出しを行う
	/// </summary>
	/// <param name="player">プレイヤー</param>
	virtual void Exec(Player& player) = 0;
};


class MoveRightCommand : public ICommand {
public: // メンバ関数

	/// <summary>
	/// コマンドの呼び出し
	/// </summary>
	/// <param name="player"></param>
	void Exec(Player& player) override;

};

class MoveLeftCommand : public ICommand {
public: // メンバ関数

	/// <summary>
	/// コマンドの呼び出し
	/// </summary>
	/// <param name="player"></param>
	void Exec(Player& player) override;

};
