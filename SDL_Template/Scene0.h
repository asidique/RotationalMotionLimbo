#ifndef Scene0_H
#define Scene0_H

#include "Scene.h"
#include "Image.h"
#include "Music.h"

namespace GAME {
	class Scene0 : public Scene {
	public:
		explicit Scene0(Window& windowRef);
		virtual ~Scene0();


		/// Get rid of these
		Scene0(const Scene0&) = delete;
		Scene0(Scene0 &&) = delete;
		Scene0& operator=(const Scene0 &) = delete;
		Scene0& operator=(Scene0 &&) = delete;



		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render();

		Image background;
		Music *backgroundMusic;
		Image startText;

	};
}
#endif