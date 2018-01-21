#include <stdio.h>
#include "Scene1.h"
using namespace GAME;

Scene1::Scene1(class Window& windowRef) : Scene(windowRef) {
	windowPtr = &windowRef;

}
Scene1::~Scene1() {}

bool Scene1::OnCreate() {
	player = new Player();
	ball = new Object(0, 10);
	background = new Image();
	isSceneRunning = true;
	//backgroundMusic = new Music();
	//backgroundMusic->Load("Fort.ogg");
	//backgroundMusic->SetVolume(128);
	player->setImage(SDL_LoadBMP("Character.bmp"));
	player->setSourceRect(0, 0, 57, 123);
	player->setDestRect(200, 200, 57, 123);
	ball->setImage(SDL_LoadBMP(("Spike2.bmp")));
	ball->setSourceRect(0, 0, 55, 55);
	ball->setDestRect(450, 450, 55, 55);
	ball->type = 0;
	background->setImage(SDL_LoadBMP("1.bmp"));
	background->setSourceRect(0, 0, 800, 600);
	background->setDestRect(0, 0, 800, 600);
	//Load background
	//Load Player
	//Load scene music
	return true;
}
void Scene1::OnDestroy() {
	delete player;
	delete background;
	delete ball;
} 

void Scene1::Update(const float deltaTime) {
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
				ball->equilibrium.x = 500;
				player->animationState = 1;
				break;
			case SDLK_LEFT:
				player->acceleration.x = -5;
				player->animationState = 2;
				break;
			case SDLK_UP:
				player->initialVelocity.y = -400;
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
				break;
			case SDLK_LEFT:
				player->acceleration.x = 0;
				player->animationState = 0;
				break;
			case SDLK_UP:
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

void Scene1::Render() {
	windowPtr->ClearRenderer();
	background->DrawImage(background->GetImage(), background->GetSourceRect(), windowPtr->GetSurface(), background->GetDestRect());
	ball->DrawImage(ball->GetImage(), ball->GetSourceRect(), windowPtr->GetSurface(), ball->GetDestRect());
	player->DrawSprite(player->GetImage(), player->GetSourceRect(), windowPtr->GetSurface(), player->GetDestRect());

	//draw here
	//SDL_RenderPresent(windowPtr->GetRenderer());
};