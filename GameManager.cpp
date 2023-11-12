#include "GameManager.h"

GameManager::GameManager()
{
	// 入力クラス初期化
	MyInput::Initialize();

	// シーンの生成
	sceneArray_[TITLE] = std::make_unique<Title>(); // タイトルシーン
	sceneArray_[STAGE] = std::make_unique<Stage>(); // ゲームシーン
	sceneArray_[CLEAR] = std::make_unique<Clear>(); // クリアシーン

	// 初期シーン番号の設定
	currentSceneNo_ = TITLE;
	sceneArray_[currentSceneNo_]->Initialize();
}

GameManager::~GameManager()
{
	
}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// 入力クラス初期化
		MyInput::Update();

		// シーン番号の取得
		prevSceneNo_ = currentSceneNo_;								  // 前シーン番号
		currentSceneNo_ = sceneArray_[currentSceneNo_]->GetSceneNo(); // 現在シーン番号の取得

		// 前フレームとシーン番号が異なる場合シーン遷移
		if (prevSceneNo_ != currentSceneNo_)
			sceneArray_[currentSceneNo_]->Initialize();

		// 現在シーン更新
		sceneArray_[currentSceneNo_]->Update();

		// 現在シーン描画
		sceneArray_[currentSceneNo_]->Draw();

		// フレーム終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (MyInput::GetKeybordState(DIK_ESCAPE, Trigger)) {
			break;
		}
	}
	return 0;
}
