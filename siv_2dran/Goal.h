﻿#pragma once
#include"volume.h"
class Goal
{
public:
	RectF rect;
	double x;
	double y;
	double w;
	double h;
	Goal(double _x, double _y, double _x1, double _y1)
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
	void scroll()
	{
		x -= Vscroll * Scene::DeltaTime();
		//x1 -= Vscroll * Scene::DeltaTime();
	}
	void scrollY(double _y)
	{
		y += _y;
	}
	void draw()
	{
		rect = RectF{ x, y, w, h }.draw(ColorF(0.0, 1.0, 1.0, 0.5));
	}
	
};
