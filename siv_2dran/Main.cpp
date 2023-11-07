#include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "Player.h"
#include "Block.h"
#include "damage.h"
void Main()
{
	Window::Resize(1080, 820);


	Player player = Player();

	Array<Block> block;
	block << Block(0, 700, 300, 80);
	block << Block(500, 700, 1200, 80);
	block << Block(400,300,600,20);
	block << Block(0,20,1300,20);
	block << Block(1620,-1080,80,1800);
	block << Block(1220,-1680,80,1700);
	/*block << Block();
	block << Block();*/

	Array<Damage> damageA;
	damageA << Damage(0, 800, 3000, 1000);
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
			Block.scrollY(player.checkScrollY());
			Block.draw();
		}

		for (auto& Damage : damageA)
		{
			if (Damage.isHit(player.pos.x, player.pos.y, player.wh, player.hg))
				player.damage();
			Damage.scrollY(player.checkScrollY());
			Damage.scroll();
			Damage.draw();
		}

		player.scroll();
		player.scrollY(player.checkScrollY());

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
