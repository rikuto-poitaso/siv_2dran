#pragma once
#include "volume.h"
class Damage
{
public:
	RectF rect;
	double x;
	double y;
	double w;
	double h;
	Damage(double _x, double _y, double _x1, double _y1)
	{
		rect = RectF{ _x, _y, _x1, _y1 };

		x = _x;
		y = _y;
		w = _x1;
		h = _y1;
	}
	bool isHit(double x, double y, double wh, double hg)
	{
		if (rect.intersects(RectF(x, y, wh, hg)))
		{
			return true;
		}
		return false;
	}
	void scrollX(double _x)
	{
		x += _x;
	}
	void scrollY(double _y)
	{
		y += _y;
	}
	void draw()
	{
		rect = RectF{ x, y, w, h }.draw(ColorF(0.8, 0, 0, 0.5));
	}
};
