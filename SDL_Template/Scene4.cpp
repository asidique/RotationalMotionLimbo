#include <stdio.h>
#include "Scene4.h"
#include "SDL2_gfxprimitives.h"
#include "SDL_draw.h"

using namespace GAME;

Scene4::Scene4(class Window& windowRef) : Scene(windowRef) {

	windowPtr = &windowRef;

}
Scene4::~Scene4() {}

bool Scene4::OnCreate() {
	player = new Player();
	ball = new Object(0, 0);
	background = new Image();
	backgroundMusic = new Music();
	backgroundMusic->Load("Fort.ogg");
	backgroundMusic->SetVolume(128);
	player->setImage(SDL_LoadBMP("Character.bmp"));
	player->setSourceRect(0, 0, 57, 123);
	player->setDestRect(200, 450, 57, 123);
	ball->setImage(SDL_LoadBMP(("Spike2.bmp")));
	ball->setSourceRect(0, 0, 55, 55);
	ball->setDestRect(350, 350, 55, 55);
	ball->anchor.Load(350, 250);
	ball->type = 3;
	background->setImage(SDL_LoadBMP("4.bmp"));
	background->setSourceRect(0, 0, 800, 600);
	background->setDestRect(0, 0, 800, 600);
	//Load background
	//Load Player
	//Load scene music*/
	isSceneRunning = true;
	nextScene = false;
	return true;
}
void Scene4::OnDestroy() {
	delete player;
	delete background;
	delete ball;
	backgroundMusic->Stop();
	backgroundMusic->~Music();
	delete backgroundMusic;
}
void Scene4::Update(const float deltaTime) {
	if (!backgroundMusic->isPlaying()) {
		backgroundMusic->Play(1);
		printf("Music is playing");
	}

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
				ball->stringLength += 4;
				break;
			case SDLK_LEFT:
				player->acceleration.x = -5;
				player->animationState = 2;
				ball->stringLength += 4;
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
				if (ball->stringLength > 100) {
					ball->stringLength -= 1;
				}
				break;
			case SDLK_LEFT:
				player->acceleration.x = 0;
				player->animationState = 0;
				if (ball->stringLength > 100) {
					ball->stringLength -= 1;
				}
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


void Scene4::Render() {
	windowPtr->ClearRenderer();
	background->DrawImage(background->GetImage(), background->GetSourceRect(), windowPtr->GetSurface(), background->GetDestRect());
	ball->DrawImage(ball->GetImage(), ball->GetSourceRect(), windowPtr->GetSurface(), ball->GetDestRect());
	player->DrawSprite(player->GetImage(), player->GetSourceRect(), windowPtr->GetSurface(), player->GetDestRect());
	//draw here
	//SDL_RenderPresent(windowPtr->GetRenderer());
};

