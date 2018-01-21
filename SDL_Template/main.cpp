
#include "Main.h"
#include "Image.h"
#include <thread>

using namespace GAME;
GameSceneManager *gsm = GameSceneManager::getInstance();

void LoadingScreen() {
	gsm->Load();
}

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	gsm->Initialize();
	std::thread loadThread(LoadingScreen);
	loadThread.detach();
	gsm->LoadAssets();
	gsm->Run();
	return 0;
}