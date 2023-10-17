# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "Player.h"
#include "Block.h"
void Main()
{
	Window::Resize(1080, 820);


	Player player = Player();
	Array<Block> block;
	block << Block(0, 700, 300, 80);
	block << Block(500, 700, 1200, 80);
	while (System::Update())
	{
		if (KeyA.pressed() && !KeyD.pressed())
			player.movex(-player.xsp);
		else if (KeyD.pressed() && !KeyA.pressed())
			player.movex(player.xsp);

		if (KeySpace.down())
			player.janp();

		for (auto& Block : block)
		{
			Block.draw();
			if (Block.put(player.pos.x, player.pos.y, player.wh, player.hg))
			{
				player.put(Block.y);
			}
			if (Block.top(player.pos.x, player.pos.y, player.wh, player.hg))
			{
				player.top(Block.y1);
			}
			if (Block.right(player.pos.x, player.pos.y, player.wh, player.hg))
			{
				player.right(Block.x);
			}
			if (Block.left(player.pos.x, player.pos.y, player.wh, player.hg))
			{
				player.left(Block.x1);
			}
			Block.scroll();
		}

		player.scroll();

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
