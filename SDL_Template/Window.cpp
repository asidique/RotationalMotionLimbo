#include "Window.h"
#include <sstream>
#include "Debug.h"

using namespace GAME;

Window::Window() :SDLWindow(nullptr), SDLRenderer(nullptr), SDLSurface(nullptr), winRect(), isInitialized(false), isFullScreen(false) {
	Debug::Log(EMessageType::INFO, "Entering Window constructor", __FILE__, "Contents", false);
}

Window::~Window() {
	Shutdown();
}

bool Window::Initialize() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Debug::Log(EMessageType::FATAL_ERROR, (SDL_GetError()), __FILE__, "Contents", false);
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		Debug::Log(EMessageType::WARNING, "Linear texture filtering is not enabled.", __FILE__, "Contents", false);
	}

	SDLWindow = SDL_CreateWindow("SDL Game Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winRect.w, winRect.h, SDL_WINDOW_SHOWN);
	if (!SDLWindow) {
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to create a window!", __FILE__, "Contents", false);
		Shutdown();
		return false;
	}

	SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

	if (!SDLRenderer) {
		Debug::Log(EMessageType::FATAL_ERROR, (SDL_GetError()), __FILE__, "Contents", false);
		Shutdown();
		return false;
	}

	SDL_SetRenderDrawColor(SDLRenderer, 100, 100, 100, 255);
	SDL_RenderFillRect(SDLRenderer, &winRect);
	SDL_RenderPresent(SDLRenderer);
	SDLSurface = SDL_GetWindowSurface(SDLWindow);
	isInitialized = true;
	return true;
}

void Window::Shutdown() {
	SDL_FreeSurface(SDLSurface);
	SDLSurface = nullptr;
	SDL_DestroyRenderer(SDLRenderer);
	SDLRenderer = nullptr;
	SDL_DestroyWindow(SDLWindow);
	SDLWindow = nullptr;
	isInitialized = false;
}

void Window::SetWindowSize(const int width_, const int height_) {
	winRect.w = width_;
	winRect.h = height_;
}

void Window::ClearRenderer() const {
	SDL_SetRenderDrawColor(SDLRenderer, 255, 255, 255, 255);
	SDL_RenderClear(SDLRenderer);
}

void Window::ToggleFullScreen() {
	isFullScreen = !isFullScreen;
	SDL_SetWindowFullscreen(SDLWindow, (isFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
}

SDL_Surface* Window::GetSurface() const{
	return SDLSurface;
}

SDL_Renderer* Window::GetRenderer() const {
	return SDLRenderer;
}

SDL_Window* Window::GetWindow() const {
	return SDLWindow;
}


int Window::GetWidth() const {
	return winRect.w;
}

int Window::GetHeight() const {
	return winRect.h;
}