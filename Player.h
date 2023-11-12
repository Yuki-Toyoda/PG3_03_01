#pragma once
#include <Novice.h>
#include "MyInput.h"
#include "Bullet.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player
{
public: // メンバ関数

	/// <summary>
	/// 初期化関数
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update(Bullet* bullet);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

private: // メンバ変数

	// 座標
	Vector2 position_;
	// 大きさ
	Vector2 size_;

	// テクスチャ
	int textureHandle_;

};

