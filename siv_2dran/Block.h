#pragma once
#include "Player.h"
class Block
{
public:
	RectF rect;
	Line line;
	double x;
	double y;
	Block(double _x, double _y, double _x1, double _y1)
	{
		rect = { _x, _y, _x1, _y1 };
		line = { _x,_y,_x1,_y };
		x = _x;
		y = _y;
	};
	void stop(Player& p)
	{
		if (rect.intersects(p.karip))
		{
			p.pos.y = y;
			p.Gs = 0;
		}
	}
};

