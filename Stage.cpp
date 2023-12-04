#include "Stage.h"

void Stage::Initialize()
{
	// シーン番号初期化
	SceneNo_ = STAGE;

	// 入力管理クラスインスタンス生成
	handler_ = std::make_unique<InputHandler>();

	handler_->AssignMoveLeftCommand2PressKeyA();
	handler_->AssignMoveLeftCommand2PressKeyD();

	// プレイヤー初期化
	player_ = std::make_unique<Player>();
	player_->Initialize();
	// 弾初期化
	bullet_ = std::make_unique<Bullet>();
	bullet_->Initialize();

	// 敵初期化
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void Stage::Update()
{
	// コマンド取得
	command_ = handler_->HandleInput();

	if (command_) {
		command_->Exec(*player_.get());
	}

	// プレイヤー更新
	player_->Update(bullet_.get());
	// 弾更新
	bullet_->Update();

	// 敵更新
	enemy_->Update();

	// 敵と弾の距離を求める
	Vector2 e2b = {
		enemy_->position_.x - bullet_->position_.x,
		enemy_->position_.y - bullet_->position_.y
	};

	float distance = (float)sqrt(pow(e2b.x, 2) + pow(e2b.y, 2));

	// 衝突判定
	if (distance < enemy_->size_.x / 2 + bullet_->size_.x / 2)
		enemy_->isHit_ = true;

	if (enemy_->isDead_)
		SceneNo_ = CLEAR;
}

void Stage::Draw()
{
	// 背景描画
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000FF, kFillModeSolid);

	// プレイヤー描画
	player_->Draw();
	// 弾描画
	bullet_->Draw();
	// 敵描画
	enemy_->Draw();
}
