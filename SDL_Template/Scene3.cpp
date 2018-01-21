#include <stdio.h>
#include "Scene3.h"
using namespace GAME;

Scene3::Scene3(class Window& windowRef) : Scene(windowRef) {

	windowPtr = &windowRef;

}
Scene3::~Scene3() {}

bool Scene3::OnCreate() {
	player = new Player();
	ball = new Object(2, 50);
	background = new Image();
	//backgroundMusic = new Music();
	//backgroundMusic->Load("Fort.ogg");
	//backgroundMusic->SetVolume(128);
	player->setImage(SDL_LoadBMP("Character.bmp"));
	player->setSourceRect(0, 0, 57, 123);
	player->setDestRect(200, 450, 57, 123);
	ball->setImage(SDL_LoadBMP(("Spike1.bmp")));
	ball->setSourceRect(0, 0, 55, 55);
	ball->setDestRect(450, 0, 55, 55);
	ball->type = 2;
	background->setImage(SDL_LoadBMP("3.bmp"));
	background->setSourceRect(0, 0, 800, 600);
	background->setDestRect(0, 0, 800, 600);
	//Load background
	//Load Player
	//Load scene music*/
	isSceneRunning = true;
	nextScene = false;
	return true;
}
void Scene3::OnDestroy() {
	delete player;
	delete background;
}
void Scene3::Update(const float deltaTime) {
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
				ball->equilibrium.x = 500;
				break;
			case SDLK_LEFT:
				player->acceleration.x = -5;
				player->animationState = 2;
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
				break;
			case SDLK_LEFT:
				player->acceleration.x = 0;
				player->animationState = 0;
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

void Scene3::Render() {
	windowPtr->ClearRenderer();
	background->DrawImage(background->GetImage(), background->GetSourceRect(), windowPtr->GetSurface(), background->GetDestRect());
	ball->DrawImage(ball->GetImage(), ball->GetSourceRect(), windowPtr->GetSurface(), ball->GetDestRect());
	player->DrawSprite(player->GetImage(), player->GetSourceRect(), windowPtr->GetSurface(), player->GetDestRect());

	//draw here
	//SDL_RenderPresent(windowPtr->GetRenderer());
};