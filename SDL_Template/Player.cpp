#include "Player.h"
#include "SDL2_rotozoom.h"
Player::Player() {
	gravity.Load(0, 9.8f);
	acceleration.Load(0, 0);
	finalVelocity.Load(0, 0);
	initialVelocity.Load(0, 0);
	animationState = 0;
	angleDisp = 10;
}

void Player::Update(float time) {
	destRect.x += acceleration.x;
	acceleration.y = gravity.y + force.y;
	finalVelocity.y = initialVelocity.y + acceleration.y*time;
	position.y += (initialVelocity.y * time) + (0.5*acceleration.y*time*time);
	destRect.y = position.y;
	initialVelocity.y = finalVelocity.y;
	//printf("Gravity: %f\n", gravity.y);
	if (destRect.y < 450) {
		gravity.y = 980.0f;
	}
	else {
		gravity.y = 0;
		destRect.y = 449;
	}



}
void Player::UpdateSprite(int maxTime, int framexsize, int numberofframes) {
	if (animationState == 1) {
		sourceRect.y = 123;
		if (timer < maxTime) {
			timer++;
		}
		else {
			if (sourceRect.x >= framexsize * numberofframes) {
				sourceRect.x = 0;
			}
			else {
				sourceRect.x += framexsize;
			}
			timer = 0;
		}
	} else if (animationState == 2) {
		sourceRect.y = 246;
		if (timer < maxTime) {
			timer++;
		}
		else {
			if (sourceRect.x >= framexsize * numberofframes) {
				sourceRect.x = 0;
			}
			else {
				sourceRect.x += framexsize;
			}
			timer = 0;
		}
	} else if (animationState == 0) {
		sourceRect.x = 0;
		sourceRect.y = 0;
		if (timer < maxTime) {
			timer++;
		}
		else {
			if (sourceRect.x >= framexsize * numberofframes) {
				sourceRect.x = 0;
			}
			else {
				sourceRect.x += framexsize;
			}
			timer = 0;
		}
	}
	
}

