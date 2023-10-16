#pragma once
class Player
{
public:
	Vec2 pos;
	int32 hp;
	const Texture pic = {};
	double Gs;
	RectF karip{pos.x-10, pos.y-30, 20, 30};
	Player()
	{
		pos = { 0,300 };
		hp = 3;
		Gs = 0;
	}
	void janp()
	{
		if(Gs > 0)
		Gs = 0;
		Gs -= 0.2;
	}
	void draw()
	{
		pic.draw(pos);
		karip.draw(Palette::Darkblue);
	}
	void grav()
	{
		pos.y += 9.8 * Gs * Scene::DeltaTime() * 1000;
		Gs += Scene::DeltaTime();
	}
};

