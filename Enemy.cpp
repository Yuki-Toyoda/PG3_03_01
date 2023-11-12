#include "Enemy.h"

void Enemy::Initialize()
{
	// 行動初期化
	state_ = new Move();

	// 座標初期化
	position_ = { 640.0f, 200.0f };
	// 速度初期化
	velocity_ = 2.5f;

	// 大きさ初期化
	size_ = { 64.0f, 64.0f };

	// トリガーリセット
	isHit_ = false;
	isDead_ = false;

	// テクスチャ読み込み
	textureHandle_ = Novice::LoadTexture("./Resources/Enemy.png");
}

void Enemy::Update()
{
	// 現在行動を更新
	state_->Update(this);
}

void Enemy::Draw()
{
	if(!isDead_)
		Novice::DrawQuad(
			(int)(position_.x - size_.x / 2.0f), (int)(position_.y - size_.y / 2.0f),
			(int)(position_.x + size_.x / 2.0f), (int)(position_.y - size_.y / 2.0f),
			(int)(position_.x - size_.x / 2.0f), (int)(position_.y + size_.y / 2.0f),
			(int)(position_.x + size_.x / 2.0f), (int)(position_.y + size_.y / 2.0f),
			0, 0,
			256, 256,
			textureHandle_,
			0xFFFFFFFF
		);
}

void Enemy::ChangeState(BaseState* nextState)
{
	// 元のステートを削除
	delete state_;
	// ステートを新規作成
	state_ = new Move();
	// 行動状態セット
	state_ = nextState;
}

void Move::Update(Enemy* enemy) {
	// 移動
	enemy->position_.x += enemy->velocity_;
	// 範囲を超過したら移動を反転
	if (enemy->position_.x >= 1280.0f - 32.0f) {
		enemy->position_.x = 1280.0f - 32.0f;
		enemy->velocity_ *= -1.0f;
	}
	else if (enemy->position_.x <= 32.0f) {
		enemy->position_.x = 32.0f;
		enemy->velocity_ *= -1.0f;
	}
	
	if (enemy->isHit_)
		enemy->ChangeState(new Dead());

}

void Dead::Update(Enemy* enemy) {
	if (enemy->size_.x > 0) {
		enemy->size_.x -= 1.0f;
		enemy->size_.y -= 1.0f;
	}
	else {
		enemy->size_ = { 0.0f, 0.0f };
		enemy->isDead_ = true;
	}
}