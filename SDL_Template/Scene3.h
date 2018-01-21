#ifndef Scene3_H
#define Scene3_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"
#include "Player.h"
#include "Object.h"

namespace GAME {
	class Scene3 : public Scene {
	public:
		explicit Scene3(Window& windowRef);
		virtual ~Scene3();


		/// Get rid of these
		Scene3(const Scene3&) = delete;
		Scene3(Scene3 &&) = delete;
		Scene3& operator=(const Scene3 &) = delete;
		Scene3& operator=(Scene3 &&) = delete;

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