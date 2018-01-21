#include "Music.h"
#include <SDL_mixer.h>
#include "Debug.h"

using namespace GAME;

Music::Music() :MixMusic(nullptr) {
	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

bool Music::isPlaying() {
	int a = Mix_PlayingMusic();

	if (a == 1) {
		return true;
	}
	else if(a==0){
		return false;
	}
}

Music::~Music() {
	Destroy();
}

bool Music::Load(const char *FileName) {
	Destroy();
	MixMusic = Mix_LoadMUS(FileName);

	if (!MixMusic) {
		Debug::Log(EMessageType::ERROR, "Music Class", "Load", "Error loading", true);
		return false;
	}

	Debug::Log(EMessageType::INFO, "Music Class", "Load", "Loading succeeded", true);
	return true;
}

void Music::Play(const int LoopCount) const {
	Stop();
	if (Mix_PlayMusic(MixMusic, LoopCount) != 0) {
		Mix_VolumeMusic(127);
		Debug::Log(EMessageType::INFO, "Music Class", "Load", "Playing music", true);
	}
}

void Music::SetVolume(const int musicVolume) const {
	Mix_VolumeMusic(musicVolume);
}

void Music::Destroy() {
	Mix_FreeMusic(MixMusic);
	MixMusic = nullptr;
}

void Music::Stop() const {
	if (Mix_PlayingMusic()) {
		Mix_HaltMusic();
	}
}

void Music::Pause() const {
	Mix_PauseMusic();
}

void Music::Resume() const {
	Mix_ResumeMusic();
}

void Music::TogglePause() const {
	if (Mix_PausedMusic()) {
		Mix_ResumeMusic();
	}
	else {
		Mix_PauseMusic();
	}
}