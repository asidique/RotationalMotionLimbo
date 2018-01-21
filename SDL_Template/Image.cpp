#include "Image.h"
#include "SDL2_rotozoom.h"

Image::Image() {}

void Image::DrawImage(SDL_Surface *source, SDL_Rect* sourceRect, SDL_Surface *surface, SDL_Rect* destRect) {

	SDL_BlitSurface(source, sourceRect, surface, destRect);
}

void Image::DrawSprite(SDL_Surface *source, SDL_Rect* sourceRect, SDL_Surface *surface, SDL_Rect* destRect) {
	SDL_BlitSurface(source, sourceRect, surface, destRect);
}

void Image::setImage(SDL_Surface *img) {
	image = img;
}

SDL_Surface * Image::GetImage() {
	return image;
}

SDL_Rect * Image::GetDestRect() {
	return &destRect;
}

SDL_Rect * Image::GetSourceRect() {
	return &sourceRect;
}

void Image::setSourceRect(float x, float y, float w, float h) {
	SDL_Rect tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.w = w;
	tmp.h = h;
	sourceRect = tmp;
}

void Image::setDestRect(float x, float y, float w, float h) {
	SDL_Rect tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.h = h;
	tmp.w = w;
	destRect = tmp;
}

void Image::UpdateSprite(int maxTime, int framexsize, int numberofframes) {
	int move = 0;
	bool right = true;
	bool left = false;
	if (timer < maxTime) {
		timer++;
	} else {
		if (sourceRect.x >= framexsize * numberofframes) {
			sourceRect.x = 0;
		}
		else {
			sourceRect.x += framexsize;
		}
		timer = 0;
	}
}
