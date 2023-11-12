#pragma once
#include <Novice.h>
#include "Vector2.h"

// クラスの前方宣言
class BaseState;

/// <summary>
/// 敵
/// </summary>
class Enemy
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

public: // アクセッサ等

	/// <summary>
	/// 行動変化関数
	/// </summary>
	/// <param name="nextState">次の行動</param>
	void ChangeState(BaseState* nextState);

public: // パブリックなメンバ変数

	// 座標
	Vector2 position_;
	// 大きさ
	Vector2 size_;

	// 速度
	float velocity_;

	// 命中トリガー
	bool isHit_;
	// 死亡トリガー
	bool isDead_;

private: // メンバ変数

	// 行動関数
	BaseState* state_ = nullptr;

	// テクスチャ
	int textureHandle_;
};

/// <summary>
/// 基底行動
/// </summary>
class BaseState {
public: // 純粋仮想関数

	// 仮想デストラクタ
	virtual ~BaseState() {};

	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵</param>
	virtual void Update(Enemy* enemy) = 0;
};

/// <summary>
/// 移動関数
/// </summary>
class Move : public BaseState {
public: // メンバ関数
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵</param>
	void Update(Enemy* enemy) override;
};

/// <summary>
/// 死亡関数
/// </summary>
class Dead : public BaseState {
public: // メンバ関数
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵</param>
	void Update(Enemy* enemy) override;
};
