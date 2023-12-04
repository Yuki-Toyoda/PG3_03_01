#include "Player.h"

void Player::Initialize()
{
	// 座標初期化
	position_ = { 640.0f, 600.0f };
	// 大きさ初期化
	size_ = { 64.0f, 64.0f };
	
	// テクスチャ読み込み
	textureHandle_ = Novice::LoadTexture("./Resources/Player.png");
}

void Player::Update(Bullet* bullet)
{
	if (MyInput::GetKeybordState(DIK_SPACE, Trigger))
		bullet->position_ = position_;
}

void Player::Draw()
{
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

void Player::MoveRight()
{
	if (position_.x >= 1280.0f - 32.0f)
		position_.x = 1280.0f - 32.0f;
	else
		position_.x += 5.0f;
}

void Player::MoveLeft()
{
	if (position_.x <= 32.0f)
			position_.x = 32.0f;
		else
			position_.x -= 5.0f;
}
