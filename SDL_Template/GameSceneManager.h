#pragma once

#include <memory>
#include <thread>
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "Scene5.h"
#include "Scene6.h"
#include "Image.h"

namespace GAME {
	class GameSceneManager {
	private:
		GameSceneManager();
		~GameSceneManager();
		static GameSceneManager* instance;
		bool isRunning;
		unsigned int fps;
		friend std::default_delete<GameSceneManager>;
		Scene *currentScene;
		Scene *scenes[7];
		Image *dancingBear = new Image();
		Image *borat = new Image();
		Image *loading = new Image();

	public:
		bool isLoading = false;
		void LoadAssets();
		void Load();
		Window windowInstance;
		void Run();
		bool Initialize();
		void deleteInstance();
		void Update(const float deltaTime);
		void Render();
		int playState = 0;
		int sceneNumber;
		static GameSceneManager* getInstance();
		GameSceneManager(const GameSceneManager&) = delete;
		GameSceneManager(GameSceneManager&&) = delete;
		GameSceneManager& operator =(const GameSceneManager&) = delete;
		GameSceneManager& operator=(GameSceneManager&&) = delete;
	};

}

