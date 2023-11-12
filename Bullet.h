#pragma once
#include <Novice.h>
#include <cmath>
#include "Vector2.h"

/// <summary>
/// 弾クラス
/// </summary>
class Bullet
{
public: // メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

public: // パブリックなメンバ変数

	// 座標
	Vector2 position_;
	// 大きさ
	Vector2 size_;

private: // メンバ変数

	// テクスチャ
	int textureHandle_;

};

