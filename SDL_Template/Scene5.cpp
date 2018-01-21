#include <stdio.h>
#include "Scene5.h"
#include "SDL2_gfxprimitives.h"
#include "SDL_draw.h"

using namespace GAME;

Scene5::Scene5(class Window& windowRef) : Scene(windowRef) {

	windowPtr = &windowRef;

}
Scene5::~Scene5() {}

bool Scene5::OnCreate() {
	player = new Player();
//	ball = new Object(0, 0);
	background = new Image();
	backgroundMusic = new Music();
	backgroundMusic->Load("Limbo.ogg");
	backgroundMusic->SetVolume(128);
	player->setImage(SDL_LoadBMP("Character.bmp"));
	player->setSourceRect(0, 0, 57, 123);
	player->setDestRect(200, 450, 57, 123);
	//ball->setImage(SDL_LoadBMP(("spikes.bmp")));
	//ball->setSourceRect(0, 0, 55, 55);
	//ball->setDestRect(350, 350, 55, 55);
	//ball->type = 3;
	background->setImage(SDL_LoadBMP("End.bmp"));
	background->setSourceRect(0, 0, 800, 600);
	background->setDestRect(0, 0, 800, 600);
	//Load background
	//Load Player
	//Load scene music*/
	isSceneRunning = true;
	nextScene = false;
	return true;
}
void Scene5::OnDestroy() {
	delete player;
	delete background;
	backgroundMusic->Stop();
	backgroundMusic->~Music();
	delete backgroundMusic;
	//delete ball;
}
void Scene5::Update(const float deltaTime) {
	if (!backgroundMusic->isPlaying()) {
		backgroundMusic->Play(1);
		printf("Music is playing");
	}

	//ball->Update(deltaTime);

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
				break;
			case SDLK_LEFT:
				player->acceleration.x = -5;
				player->animationState = 2;
				break;
			case SDLK_UP:
				player->force.y = -400;
				break;
			case SDLK_SPACE:
				nextScene = true;
				isSceneRunning = false;
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

}


void Scene5::Render() {
	windowPtr->ClearRenderer();
	background->DrawImage(background->GetImage(), background->GetSourceRect(), windowPtr->GetSurface(), background->GetDestRect());
	//ball->DrawImage(ball->GetImage(), ball->GetSourceRect(), windowPtr->GetSurface(), ball->GetDestRect());
	player->DrawSprite(player->GetImage(), player->GetSourceRect(), windowPtr->GetSurface(), player->GetDestRect());
	//draw here
	//SDL_RenderPresent(windowPtr->GetRenderer());
};

