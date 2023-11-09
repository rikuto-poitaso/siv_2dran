#pragma once
#include "Block.h"
class Player
{
public:
	Vec2 pos;
	int32 hp;
	double ghosttime;
	const double wh = 90 * Pscale;
	const double hg = 180 * Pscale;
	const double xsp = 2000;
	const Texture pic{ U"example/sukebo.png" };
	int32 now;
	double Gs;
	double Gx;
	double a;
	//RectF karip;
	Player()
	{
		pos = Vec2{ 100.0,300.0 };
		hp = 3;
		now = 0;
		Gs = 0;
		Gx = 0;
		ghosttime = 0;
		a = 1;
	}
	void movex(double _x)
	{
		//pos.x += _x * Scene::DeltaTime();
		Gx += _x * Scene::DeltaTime();
	}
	void put(double _y)
	{
		pos.y = _y;
		Gs = 0;
	}
	void top(double _y1)
	{
		pos.y =_y1 + hg+1;
		Gs = 0;
	}
	void right(double _x)
	{
		pos.x = _x - wh/1.0  - 1;
		Gx = 0;
	}
	void left(double _x1)
	{
		pos.x = _x1 + wh/1.0 +1;
		Gx = 0;
	}
	void janp()
	{
		if(Gs > 0)
		Gs = 0;
		Gs -= 0.2;
		--pos.y;
	}
	void draw()
	{
		pic(now * 500, 0,500, 206).scaled(Pscale).draw(pos.x - (250 * Pscale), pos.y - (193 * Pscale));
		//RectF{ pos.x - wh / 2, pos.y - hg, wh , hg }.draw(Palette::White);
	}
	void damage()
	{
		if (ghosttime < 0)
		{
			--hp;
			ghosttime = 3;
		}
	}
	void goal()
	{
		
	}
	void grav()
	{
		if (Gs > 0.001)
			now = 2;
		else if (Gs < -0.001)
			now = 1;
		else
			now = 0;
		pos.y += 9.8 * Gs * Scene::DeltaTime() * 1000;
		if (Gs < 2)
		Gs += Scene::DeltaTime();

		pos.x += Gx * Scene::DeltaTime();
		Gx /= 1.01;

		ghosttime -= Scene::DeltaTime();
	}
	void scroll()
	{
		pos.x -= Vscroll * Scene::DeltaTime();
	}
	double checkScrollY()
	{
		if (pos.y < 150)
		{
			//pos.y += 100 * Scene::DeltaTime();
			return -pos.y+150;
		}
		if (pos.y > 700)
		{
			//pos.y -= 100 * Scene::DeltaTime();
			return -pos.y + 700;
		}
		return 0;
	}
	void scrollY(double _y)
	{
		pos.y += _y;
	}
	
};

