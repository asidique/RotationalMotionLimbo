#ifndef Scene2_H
#define Scene2_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"
#include "Player.h"
#include "Object.h"

namespace GAME {
	class Scene2 : public Scene {
	public:
		explicit Scene2(Window& windowRef);
		virtual ~Scene2();


		/// Get rid of these
		Scene2(const Scene2&) = delete;
		Scene2(Scene2 &&) = delete;
		Scene2& operator=(const Scene2 &) = delete;
		Scene2& operator=(Scene2 &&) = delete;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render();

		Image *background;
		Music *backgroundMusic;
		Player *player;
		Object *ball;

	};
}

#endif