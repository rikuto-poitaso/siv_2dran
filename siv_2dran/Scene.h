#pragma once
#include "volume.h"
#include "Player.h"
#include "Block.h"
#include "damage.h"
#include "Goal.h"
using App = SceneManager<String, GameData>;
class Game : public App::Scene
{
public:
	Player player = Player();
	Array<Block> block;
	Array<Goal> goal;
	Array<Damage> damageA;
	Game(const InitData& init)
		: IScene{ init }
	{
		block << Block(0, 700, 300, 80);//左上のｘ、左上のｙ、安全良し。
		block << Block(500, 700, 1200, 80);
		block << Block(400, 300, 600, 20);
		block << Block(0, 20, 1300, 20);
		block << Block(1620, -1080, 80, 1800);
		block << Block(1220, -1680, 80, 1700);
		/*block << Block();
		block << Block();*/

		goal << Goal(1620, 300, 200, 300);

		damageA << Damage(0, 800, 3000, 1000);
	}
	void update()override
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

		for (auto& Goal : goal)
		{
			if (Goal.isHit(player.pos.x, player.pos.y, player.wh, player.hg))
				changeScene(U"Clear");
			Goal.draw();
			Goal.scroll();
			Goal.scrollY(player.checkScrollY());
		}

		player.scroll();
		player.scrollY(player.checkScrollY());

		player.draw();
		player.grav();
	}
	void draw() const override
	{

	}
};

class Clear : public App::Scene
{
public:
	
	Clear(const InitData& init)
		: IScene{ init }
	{

	}
	void update()override
	{

	}
	void draw()const override
	{

	}
};
