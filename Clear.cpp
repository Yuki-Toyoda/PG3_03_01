#include "Clear.h"

void Clear::Initialize()
{
	// シーン番号初期化
	SceneNo_ = CLEAR;
	// テクスチャ読み込み
	textureHandle_ = Novice::LoadTexture("./Resources/Clear.png");
}

void Clear::Update()
{
	// スペースキーを押すとシーン遷移
	if (MyInput::GetKeybordState(DIK_SPACE, Trigger))
		SceneNo_ = TITLE;
}

void Clear::Draw()
{
	// 描画
	Novice::DrawSprite(0, 0, textureHandle_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
