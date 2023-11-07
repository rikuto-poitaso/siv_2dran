#pragma once
#include "volume.h"
#include "Player.h"
class Block
{
public:
	RectF rect;
	Line linetop;
	Line linebottom;
	Line lineright;
	Line lineleft;
	double x;
	double y;
	double x1;
	double y1;
	Block(double _x, double _y, double _x1, double _y1)
	{
		rect = RectF{ _x, _y, _x1, _y1 };
		linetop = Line{ _x,_y,_x+_x1, _y };
		linebottom = Line{ _x,_y + _y1,_x + _x1,_y+_y1 };
		lineright = Line{ _x + _x1,_y+1,_x + _x1,_y + _y1-1 };
		lineleft = Line{ _x,_y+1,_x,_y + _y1-1 };

		x = _x;
		y = _y;
		x1 = _x + _x1;
		y1 = _y + _y1;
	};
	bool put(double x,double y,double wh,double hg)
	{
		if (linetop.intersects(RectF(x - wh /2,y - hg/2,wh,hg/2)))
		{
			return true;
		}
		return false;
	}
	bool top(double x, double y, double wh, double hg)
	{
		if (linebottom.intersects(RectF(x - wh / 2, y - hg , wh, hg/8)))
		{
			return true;
		}
		return false;
	}
	bool right(double x, double y, double wh, double hg)
	{
		if (lineleft.intersects(RectF(x + wh / 3, y - hg, wh/6, hg)))
		{
			return true;
		}
		return false;
	}
	bool left(double x, double y, double wh, double hg)
	{
		if (lineright.intersects(RectF(x - wh / 2, y - hg, wh / 6, hg)))
		{
			return true;
		}
		return false;
	}
	void scroll()
	{
		x -= Vscroll * Scene::DeltaTime();
	}
	void scrollY(double _y)
	{
		y1 += _y;
		y += _y;
	}
	void draw()
	{
		rect = RectF{ x, y, x1, y1 }.draw();
		linetop = Line{ x,y,x + x1, y };
		linebottom = Line{ x,y + y1,x + x1,y + y1 };
		lineright = Line{ x + x1,y + 1,x + x1,y + y1 - 1 };
		lineleft = Line{ x,y + 1,x,y + y1 - 1 };
	}

};

