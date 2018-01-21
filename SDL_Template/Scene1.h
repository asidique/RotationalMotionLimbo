#ifndef Scene1_H
#define Scene1_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"
#include "Player.h"
#include "Object.h"

namespace GAME {
	class Scene1 : public Scene {
	public:
		explicit Scene1(Window& windowRef);
		virtual ~Scene1();


		/// Get rid of these
		Scene1(const Scene1&) = delete;
		Scene1(Scene1 &&) = delete;
		Scene1& operator=(const Scene1 &) = delete;
		Scene1& operator=(Scene1 &&) = delete;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render();



		Image *background;
		Music *backgroundMusic;
		Image startText;
		Player *player;
		Object *ball;
	
	};
}

#endif