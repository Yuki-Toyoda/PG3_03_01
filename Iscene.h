#pragma once
#include <memory>
#include <Novice.h>
#include "MyInput.h"

enum SCENE
{
	TITLE,
	STAGE,
	CLEAR
};

/// <summary>
/// シーン基底クラス
/// </summary>
class Iscene
{
public: // コンストラクタ等

	// 仮想デストラクタ
	virtual ~Iscene();

public: // 純粋仮想関数

	/// <summary>
	/// 初期化関数
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() = 0;

public: // アクセッサ等

	int GetSceneNo() { return SceneNo_; };

protected: // 静的なメンバ変数

	// 現在のシーン番号
 	static int SceneNo_;

};

