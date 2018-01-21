#pragma once
#include "Image.h"
#include "Vector.h"

using namespace MATH;

class Object : public Image
{

public:
	Object(float dampening, float springConst);
	Vec2 position;
	Vec2 initialVelocity;
	Vec2 finalVelocity;
	Vec2 acceleration;
	Vec2 equilibrium;
	Vec2 oldPosition;

	float springConstant;
	float distanceFromEquilibriumY;
	float distanceFromEquilibriumX;
	int a;
	float accumilativeTime = 0;

	float angle;
	float stringLength;
	Vec2 anchor;

	float angularAcceleration, torque, finalAngularVelocity, initialAngularVelocity, angleDisplacement;
	float dampenConst;
	SDL_Rect rec;
	SDL_Surface * finalImage;

	void Update(float time);
	int type;

};
