#include "Object.h"
#include "SDL2_rotozoom.h"
#include <string>

using namespace std;

Object::Object(float dampening, float springConst) {
	equilibrium.Load(450, 300);
	springConstant = springConst;
	dampenConst = dampening;
	angle = 30;
	anchor.Load(250, 250);
	stringLength = 100;
	torque = 100;
}

void Object::Update(float time) {

	if (type == 0) { //SPRINGS
		distanceFromEquilibriumY = destRect.y - equilibrium.y;
		acceleration.y = springConstant*distanceFromEquilibriumY*-1;// -dampenConst*finalVelocity.y;
		finalVelocity.y = initialVelocity.y + acceleration.y*time;
		position.y = (initialVelocity.y * time) + (0.5*acceleration.y*time*time);
		destRect.y += position.y + (0.5*acceleration.y*time*time); //VERLET INTEG
		initialVelocity = finalVelocity;

		distanceFromEquilibriumX = destRect.x - equilibrium.x;
		acceleration.x = springConstant*distanceFromEquilibriumX*-1;// -dampenConst*finalVelocity.x;
		finalVelocity.x = initialVelocity.x + acceleration.x*time;
		position.x = (initialVelocity.x * time) + (0.5*acceleration.x*time*time);
		destRect.x += position.x + (0.5*acceleration.x*time*time);
		initialVelocity = finalVelocity;

	}
	else if (type == 1) { //ROTATIONL MOTION (CONSTANT ACC)
		angularAcceleration = torque;
		finalAngularVelocity = initialAngularVelocity + angularAcceleration*time;
		angleDisplacement += initialAngularVelocity * time + (0.5*angularAcceleration*time*time);
		initialAngularVelocity = finalAngularVelocity;
		finalImage = rotozoomSurface(image, angleDisplacement, 1, 0);
		rec = { 450, 450, 0, 0 };
		rec.x -= finalImage->w / 2 - image->w / 2;
		rec.y -= finalImage->h / 2 - image->h / 2;
	}
	else if (type == 2) { //DAMPED SPRING
		distanceFromEquilibriumY = destRect.y - equilibrium.y;
		acceleration.y = (springConstant*distanceFromEquilibriumY*-1)  - (initialVelocity.y);// -dampenConst*finalVelocity.y;
		finalVelocity.y = initialVelocity.y + acceleration.y*time;
		position.y = (initialVelocity.y * time) + (0.5*acceleration.y*time*time);
		destRect.y += position.y + (0.5*acceleration.y*time*time); //VERLET INTEG
		initialVelocity = finalVelocity;

		distanceFromEquilibriumX = destRect.x - equilibrium.x;
		acceleration.x = springConstant*distanceFromEquilibriumX*-1 - (initialVelocity.x);// -dampenConst*finalVelocity.x;
		finalVelocity.x = initialVelocity.x + acceleration.x*time;
		position.x = (initialVelocity.x * time) + (0.5*acceleration.x*time*time);
		destRect.x += position.x + (0.5*acceleration.x*time*time);
		initialVelocity = finalVelocity;
	}
	else if (type == 3) {
		angularAcceleration = (980 / stringLength) * sin(angle);
		initialAngularVelocity += angularAcceleration * time;
		angle += initialAngularVelocity * time;
		destRect.x = anchor.x + (int)(sin(angle) * stringLength);
		destRect.y = (anchor.y - (int)(cos(angle) * stringLength));
			}
}
