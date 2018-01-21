#ifndef Scene5_H
#define Scene5_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"
#include "Player.h"
#include "Object.h"

namespace GAME {
	class Scene5 : public Scene {
	public:
		explicit Scene5(Window& windowRef);
		virtual ~Scene5();


		/// Get rid of these
		Scene5(const Scene5&) = delete;
		Scene5(Scene5 &&) = delete;
		Scene5& operator=(const Scene5 &) = delete;
		Scene5& operator=(Scene5 &&) = delete;

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