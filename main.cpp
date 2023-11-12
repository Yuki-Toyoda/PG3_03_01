#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LE2A_14_トヨダユウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// ゲームマネージャー生成
	GameManager* gameManager_ = new GameManager();

	// ゲーム実行
	gameManager_->Run();

	// インスタンス削除
	delete gameManager_;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
