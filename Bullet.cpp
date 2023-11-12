#include "Bullet.h"
#include "Enemy.h"

void Bullet::Initialize()
{
	// 座標初期化
	position_ = { 10000.0f, 10000.0f };
	// 大きさ初期化
	size_ = { 32.0f, 32.0f };

	// テクスチャ読み込み
	textureHandle_ = Novice::LoadTexture("./Resources/Bullet.png");
}

void Bullet::Update()
{
	// 弾を前進
	position_.y -= 10.0f;
}

void Bullet::Draw()
{
	Novice::DrawQuad(
		(int)(position_.x - size_.x / 2.0f), (int)(position_.y - size_.y / 2.0f),
		(int)(position_.x + size_.x / 2.0f), (int)(position_.y - size_.y / 2.0f),
		(int)(position_.x - size_.x / 2.0f), (int)(position_.y + size_.y / 2.0f),
		(int)(position_.x + size_.x / 2.0f), (int)(position_.y + size_.y / 2.0f),
		0, 0,
		64, 64,
		textureHandle_,
		0xFFFFFFFF
	);
}
