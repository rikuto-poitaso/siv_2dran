#pragma once
#include "volume.h"
#include "Player.h"
#include "Block.h"
#include "damage.h"
#include "Goal.h"
using App = SceneManager<String, GameData>;
class Title : public App::Scene
{
public:
	Title(const InitData& init) : IScene{ init }
	{

	}
	void update() override
	{
		if (MouseL.down())
			changeScene(U"Game",0.3s);
	}
	void draw() const override
	{

	}
};
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
		block << Block(-500, 700, 800, 80);//左上のｘ、左上のｙ、安全良し。
		block << Block(500, 700, 1200, 80);
		block << Block(400, 300, 600, 20);
		block << Block(-500, 20, 1800, 20);
		block << Block(-500, 40, 80, 660);
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

		player.scrollX(player.checkscroll());
		player.scrollY(player.checkScrollY());
		player.draw();
		player.grav();
		for (auto& Block : block)
		{
			Block.scrollX(player.checkscroll());
			Block.scrollY(player.checkScrollY());
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
			Block.draw();
		}

		for (auto& Damage : damageA)
		{
			if (Damage.isHit(player.pos.x, player.pos.y, player.wh, player.hg))
				player.damage();
			Damage.scrollY(player.checkScrollY());
			Damage.scrollX(player.checkscroll());
			Damage.draw();
			if (player.gethp() <= 0)
				changeScene(U"Gameover");
		}

		for (auto& Goal : goal)
		{
			if (Goal.isHit(player.pos.x, player.pos.y, player.wh, player.hg))
				changeScene(U"Clear", 0.3s);
			Goal.scrollX(player.checkscroll());
			Goal.scrollY(player.checkScrollY());
			Goal.draw();
		}


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
		if (MouseL.down())
			changeScene(U"Title", 0.3s);
	}
	void draw()const override
	{

	}
};
class Gameover : public App::Scene
{
public:

	Gameover(const InitData& init)
		: IScene{ init }
	{

	}
	void update()override
	{
		if (MouseL.down())
			changeScene(U"Title", 0.3s);
	}
	void draw()const override
	{

	}
};
