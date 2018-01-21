#pragma once
#include <SDL.h>
#include "Vector.h"
#include "Image.h"

using namespace MATH;

class Player : public Image
{
	public:
	Player();
	void Update(float time);
	void UpdateSprite(int maxTime, int framexsize, int numberofframes);
	int animationState;
	float angleDisp;
	Vec2 acceleration;
	Vec2 finalVelocity; 
	Vec2 initialVelocity;
	Vec2 gravity;
	Vec2 position;
	Vec2 force;
};
