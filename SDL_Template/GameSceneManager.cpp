#include <stdio.h>
#include "GameSceneManager.h"
#include <cassert>
#include "Timer.h"
#include "Debug.h"
#include <thread>

using namespace GAME;

GameSceneManager::GameSceneManager() : windowInstance(), isRunning(false), fps(60) {
	windowInstance.SetWindowSize(800, 600);
	sceneNumber = 0;
}

GameSceneManager::~GameSceneManager() {
	Debug::Log(EMessageType::INFO, "GameSceneManager", "~GameSceneManager()", "Bye from the destructor", true);
	windowInstance.Shutdown();
	isRunning = false;
}

GameSceneManager *GameSceneManager::instance = nullptr;

GameSceneManager *GameSceneManager::getInstance() {
	if (instance == nullptr) {
		Debug::Log(EMessageType::WARNING, "GameSceneManager", "getInstance()", "instance is null, making new gamescenemanager", true);
		instance = new GameSceneManager();
	}
	else {
		Debug::Log(EMessageType::WARNING, "GameSceneManager", "getInstance()", "instance is already made", true);
	}

	return instance;
}


void GameSceneManager::Load() {
		dancingBear->setImage(SDL_LoadBMP("Bear35x40.bmp"));
		loading->setImage(SDL_LoadBMP("Loading.bmp"));
		dancingBear->setSourceRect(0, 0, 35, 40);
		loading->setSourceRect(0, 0, 256, 256);
		dancingBear->setDestRect(windowInstance.GetWidth() / 2 - 30, windowInstance.GetHeight() / 2, 35, 40);
		loading->setDestRect(windowInstance.GetWidth() / 2 - loading->sourceRect.w / 2, windowInstance.GetHeight() / 2 - loading->sourceRect.h / 2 + 100, 256, 256);
		isLoading = true;
		Timer timer;
		timer.Start();
		while (isLoading) {
			//Debug::Log(EMessageType::INFO, "GSM", "LOADASSETS", "PROGRAM IS LOADING", true);
			timer.UpdateFrameTicks();
			Update(timer.GetDeltaTime());
			Render();
			SDL_Delay(timer.GetSleepTime(fps));
		}
}

void GameSceneManager::LoadAssets() {
	SDL_Delay(2000);
	isLoading = false;
}

bool GameSceneManager::Initialize() {
	Debug::Log(EMessageType::INFO, "GameSceneManager", "Initialize()", "Initializing...", true);
	if (!windowInstance.Initialize()) {
		Debug::Log(EMessageType::INFO, "GameSceneManager", "Initialize()", "Failed to initialize", true);
		return false;
	}

	scenes[0] = new Scene0(windowInstance);
	scenes[1] = new Scene6(windowInstance);
	scenes[2] = new Scene1(windowInstance);
	scenes[3] = new Scene2(windowInstance);
	scenes[4] = new Scene3(windowInstance);
	scenes[5] = new Scene4(windowInstance);
	scenes[6] = new Scene5(windowInstance);
	
	if (!isLoading) {
		currentScene = scenes[0];
		currentScene->OnCreate();
		printf("isNotLoading");
	}

	return true;
}


void GameSceneManager::Run() {
	isRunning = true;
	Timer timer;
	timer.Start();
	while(isRunning) {
		//Debug::Log(EMessageType::INFO, "GSM", "RUN", "PROGRAM IS RUNNING", true);
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}
}

void GameSceneManager::Update(const float deltaTime) {
	if (isLoading) {
		dancingBear->UpdateSprite(4, 35, 3);
	}
	else {

		if (!currentScene->isSceneRunning) {
			if (currentScene->nextScene) {
				sceneNumber++;
			}
			else if (!currentScene->nextScene) {
				sceneNumber--;
			}

			if (sceneNumber > 6) {
				sceneNumber = 0;
			}
			currentScene->OnDestroy();
			currentScene = scenes[sceneNumber];
			currentScene->OnCreate();
		}
		else {
			currentScene->Update(deltaTime);
		}
	}
}

void GameSceneManager::deleteInstance() {
	delete &windowInstance;
}

void GameSceneManager::Render() {
	SDL_Surface* surface = windowInstance.GetSurface();
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 20, 5, 5));
	if (currentScene == nullptr) {
		Debug::Log(EMessageType::ERROR, "GameSceneManager", "Render()", "No scene selected", true);
		assert(currentScene);
	}

	if (isLoading) {
		dancingBear->DrawSprite(dancingBear->GetImage(), dancingBear->GetSourceRect(), surface, dancingBear->GetDestRect());
		loading->DrawSprite(loading->GetImage(), loading->GetSourceRect(), surface, loading->GetDestRect());
	}
	else {
		currentScene->Render();
	}
	SDL_UpdateWindowSurface(windowInstance.GetWindow());

}


