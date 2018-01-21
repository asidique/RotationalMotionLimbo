#include <stdio.h>
#include "Scene2.h"
#include "SDL2_gfxprimitives.h"
using namespace GAME;

Scene2::Scene2(class Window& windowRef) : Scene(windowRef) {

	windowPtr = &windowRef;

}
Scene2::~Scene2() {}

bool Scene2::OnCreate() {
	player = new Player();
	ball = new Object(0, 100);
	background = new Image();
	//backgroundMusic = new Music();
	//backgroundMusic->Load("Fort.ogg");
	//backgroundMusic->SetVolume(128);
	player->setImage(SDL_LoadBMP("Character.bmp"));
	player->setSourceRect(0, 0, 57, 123);
	player->setDestRect(200, 450, 57, 123);
	ball->setImage(SDL_LoadBMP(("spikes.bmp")));
	ball->setSourceRect(0, 0, 55, 55);
	ball->setDestRect(450, 450, 55, 55);
	ball->type = 1;
	background->setImage(SDL_LoadBMP("2.bmp"));
	background->setSourceRect(0, 0, 800, 600);
	background->setDestRect(0, 0, 800, 600);
	//Load background
	//Load Player
	//Load scene music*/
	isSceneRunning = true;
	nextScene = false;
	return true;
}
void Scene2::OnDestroy() {
	delete player;
	delete ball;
	delete background;
}
void Scene2::Update(const float deltaTime) {
	//if (!backgroundMusic->isPlaying()) {
	//	backgroundMusic->Play(1);
	//	printf("Music is playing");
	//}

	ball->Update(deltaTime);

	SDL_Event SDLEvent;

	while (SDL_PollEvent(&SDLEvent)) {
		switch (SDLEvent.type) {
		case SDL_EventType::SDL_QUIT:
			OnDestroy();
			SDL_Quit();
			return;
		case SDL_KEYDOWN:
			switch (SDLEvent.key.keysym.sym) {
			case SDLK_RIGHT:
				player->acceleration.x = 5;
				player->animationState = 1;
				ball->torque = 200;
				break;
			case SDLK_LEFT:
				player->acceleration.x = -5;
				player->animationState = 2;
				ball->torque = -200;
				break;
			case SDLK_UP:
				player->force.y = -400;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (SDLEvent.key.keysym.sym) {
			case SDLK_RIGHT:
				player->acceleration.x = 0;
				player->animationState = 0;
				ball->angularAcceleration = 0;
				ball->initialAngularVelocity *= 0.5f;
				break;
			case SDLK_LEFT:
				player->acceleration.x = 0;
				player->animationState = 0;
				ball->angularAcceleration = 0;
				ball->initialAngularVelocity *= 0.5f;
				break;
			case SDLK_SPACE:
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	player->UpdateSprite(8, 57, 2);
	player->Update(deltaTime);
	if (player->destRect.x < 20) {
		nextScene = false;
		isSceneRunning = false;
	}
	if (player->destRect.x > 801) {
		nextScene = true;
		isSceneRunning = false;
	}

	if (Collision(*player->GetDestRect(), *ball->GetDestRect())) {
		nextScene = false;
		isSceneRunning = false;
	}
}

void Scene2::Render() {
	windowPtr->ClearRenderer();
	background->DrawImage(background->GetImage(), background->GetSourceRect(), windowPtr->GetSurface(), background->GetDestRect());
	ball->DrawImage(ball->finalImage, ball->GetSourceRect(), windowPtr->GetSurface(), &ball->rec);
	player->DrawSprite(player->GetImage(), player->GetSourceRect(), windowPtr->GetSurface(), player->GetDestRect());
	//draw here
	//SDL_RenderPresent(windowPtr->GetRenderer());
};