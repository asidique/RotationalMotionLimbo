#ifndef Scene6_H
#define Scene6_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"
#include "Player.h"
#include "Object.h"

namespace GAME {
	class Scene6 : public Scene {
	public:
		explicit Scene6(Window& windowRef);
		virtual ~Scene6();


		/// Get rid of these
		Scene6(const Scene6&) = delete;
		Scene6(Scene6 &&) = delete;
		Scene6& operator=(const Scene6 &) = delete;
		Scene6& operator=(Scene6 &&) = delete;

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