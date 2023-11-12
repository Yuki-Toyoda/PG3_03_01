#include "Title.h"

void Title::Initialize()
{
	// シーン番号初期化
	SceneNo_ = TITLE;

	// テクスチャ読み込み
	textureHandle_ = Novice::LoadTexture("./Resources/Title.png");
}

void Title::Update()
{
	// スペースキーを押すとシーン遷移
	if (MyInput::GetKeybordState(DIK_SPACE, Trigger))
		SceneNo_ = STAGE;
}

void Title::Draw()
{
	// 描画
	Novice::DrawSprite(0, 0, textureHandle_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
