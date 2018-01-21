#include "Scene.h"

using namespace GAME;

Scene::Scene(Window& windowRef) : windowPtr(&windowRef) {

}


Scene::~Scene() {

}

bool Scene::Collision(SDL_Rect a, SDL_Rect b) {
	if (a.x < b.x + b.w &&
		a.x + a.w > b.x &&
		a.y < b.y + b.h &&
		a.y + a.h > b.y) {
		return true;
	}
	else {
		return false;
	}
}