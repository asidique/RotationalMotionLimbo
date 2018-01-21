#ifndef Scene4_H
#define Scene4_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"
#include "Player.h"
#include "Object.h"

namespace GAME {
	class Scene4 : public Scene {
	public:
		explicit Scene4(Window& windowRef);
		virtual ~Scene4();


		/// Get rid of these
		Scene4(const Scene4&) = delete;
		Scene4(Scene4 &&) = delete;
		Scene4& operator=(const Scene4 &) = delete;
		Scene4& operator=(Scene4 &&) = delete;

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