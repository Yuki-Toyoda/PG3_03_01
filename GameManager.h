#pragma once
#include <memory>
#include "MyInput.h"
#include "Iscene.h"
#include "Title.h"
#include "Stage.h"
#include "Clear.h"

/// <summary>
/// ゲームマネージャー
/// </summary>
class GameManager
{
public: // コンストラクタ等

	// コンストラクタ
	GameManager();
	// デストラクタ
	~GameManager();

public: // メンバ関数

	/// <summary>
	/// メインループ関数
	/// </summary>
	/// <returns></returns>
	int Run();

private: // メンバ変数

	// シーン配列
	std::unique_ptr<Iscene> sceneArray_[3];

	// シーン管理用変数
	int currentSceneNo_; // 現在シーン
	int prevSceneNo_;    // 前シーン

};

