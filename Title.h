#pragma once
#include "Iscene.h"

/// <summary>
/// タイトルシーン
/// </summary>
class Title : public Iscene
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

	// テクスチャ読み込み
	int textureHandle_;

};

