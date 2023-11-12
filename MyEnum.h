#pragma once

/// 列挙子管理クラス

// マウス入力検知
enum MouseButton
{
	LeftClick,
	RightClick
};

// 入力状態検知
enum InputState
{
	Null,
	Trigger,
	Press
};

// オブジェクトのタイプ
enum EffectType {
	// タイプなし
	TypeNone
};

// イージングの種類
enum EasingType {
	// ノーマル
	TypeEaseNormal,
	// イーズイン
	TypeEaseIn,
	// イーズアウト
	TypeEaseOut
};

// 銃の種類
enum GunType {
	// デフォルト
	TypeGunDefault,
	// <para>ボルトアクション
	// 射撃毎にコッキング動作が入る
	TypeBoltAction,
	// <para>セミオート
	// コッキング動作がなく連射可能
	TypeSemiAuto,
	// <para>三点バースト
	// 一回のトリガーで複数の弾を発射する
	TypeBurst
};


// 弾の種類
enum BulletType {
	// デフォルト
	TypeBulletDefault,
	// <para>7.62mm
	// 弾速が早く弾道落下が少ない。反動がかなり大き目
	Type7_62mm,
	// <para>5.56mm
	// 反動が小さいかわりに弾速が遅い。
	Type5_56mm,
	// <para>50BMG
	// 対物ライフルの弾
	// 弾速が早く威力がほかの弾と比べて高い。反動が大きく弾道落下もする
	Type50BMG
};

enum MagagineType {
	// デフォルト
	TypeMagazineDefault,
	// <para>ボックスマガジン
	// 箱型マガジン。マガジン交換一回でフル装填
	TypeBox,
	// <para>一発一発込めるタイプ
	// リロードの際は一発ずつ弾を込める
	TypeTube
};