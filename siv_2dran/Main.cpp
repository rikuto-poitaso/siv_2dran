# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "Player.h"
#include "Block.h"
void Main()
{
	Player player;
	Block block1(0,550,600,600);
	while (System::Update())
	{
		block1.rect.draw();
		block1.stop(player);
		if (KeySpace.down())
			player.janp();

		player.draw();
		player.grav();
	}

}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
