#pragma once
#include <SDL.h>

class Image {
public:
	Image();
	SDL_Rect destRect;
	SDL_Rect sourceRect;
	SDL_Surface *image;
	void DrawImage(SDL_Surface *source, SDL_Rect* sourceRect, SDL_Surface *surface, SDL_Rect* destRect);
	void DrawSprite(SDL_Surface *source, SDL_Rect* sourceRect, SDL_Surface *surface, SDL_Rect* destRect);
	void UpdateSprite(int maxTime, int framexsize, int numberofframes);
	void setDestRect(float x, float y, float w, float h);
	void setSourceRect(float x, float y, float w, float h);
	SDL_Surface * GetImage();
	SDL_Rect * GetDestRect();
	SDL_Rect * GetSourceRect();
	void setImage(SDL_Surface *img);
	float timer;
};