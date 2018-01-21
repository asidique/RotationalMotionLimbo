#include "Scene0.h"
#include <stdio.h>


using namespace GAME;

Scene0::Scene0(class Window& windowRef) : Scene(windowRef) {
	isSceneRunning = true;
	windowPtr = &windowRef;
}
Scene0::~Scene0() {}

bool Scene0::OnCreate() {
	isSceneRunning = true;
	background.setImage(SDL_LoadBMP("LimboTitle.bmp"));
	background.setDestRect(0, 0, 800, 600);
	backgroundMusic = new Music();
	backgroundMusic->Load("Menu.ogg");
	backgroundMusic->SetVolume(128);
	startText.setImage(SDL_LoadBMP("LimboStartTitle.bmp"));
	startText.setDestRect(100, 300, 140, 40);


	return true;
}
void Scene0::OnDestroy() {
	backgroundMusic->Stop();
	backgroundMusic->~Music();
	delete backgroundMusic;
}

void Scene0::Update(const float deltaTime) {
	if (!backgroundMusic->isPlaying()) {
		backgroundMusic->Play(1);
		printf("Music is playing");
	}
	
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
				break;
			case SDLK_LEFT:
				break;
			case SDLK_UP:
				break;
			case SDLK_SPACE:
				nextScene = true;
				isSceneRunning = false;
			case SDLK_RETURN:
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
				break;
			case SDLK_LEFT:
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
}

void Scene0::Render() {
	windowPtr->ClearRenderer();
	background.DrawImage(background.GetImage(), NULL, windowPtr->GetSurface(), background.GetDestRect());
	startText.DrawImage(startText.GetImage(), NULL, windowPtr->GetSurface(), startText.GetDestRect());
	//SDL_RenderPresent(windowPtr->GetRenderer());
};