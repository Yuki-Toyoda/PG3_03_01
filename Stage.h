#pragma once
#include "Iscene.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

/// <summary>
/// ステージシーン
/// </summary>
class Stage : public Iscene
{
public: // メンバ関数

	/// <summary>
	/// 初期化関数
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw() override;

private: // メンバ変数

	// プレイヤー
	std::unique_ptr<Player> player_;
	// 弾
	std::unique_ptr<Bullet> bullet_;

	// 敵
	std::unique_ptr<Enemy> enemy_;
};

