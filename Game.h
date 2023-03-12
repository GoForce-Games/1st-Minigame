#pragma once

#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib")


#include "Entity.h"
#include "Tablero.h"

#define WINDOW_WIDTH	320
#define WINDOW_HEIGHT	320
#define WINDOW_SCALE	2	// 1 = 320x320, 2 = 640x640, etc.

#define MAX_KEYS		256
#define MAX_FX		200

class Game
{
public:
	Game();
	~Game();

	bool Init();
	bool LoadImages();
	void Release();
	
	bool Input();
	bool Update();
	void Draw();

	void ProcessAudio();
	bool PlayMusic(const char* path, float fade_time);

private:
	SDL_Window *Window;
	SDL_Renderer *Renderer;
	SDL_Texture *img_background, *img_player, *img_shot;

	Tablero tablero;

	Entity Player, Scene;

	enum KEY_STATE { KEY_IDLE, KEY_DOWN, KEY_REPEAT, KEY_UP	};
	KEY_STATE keys[MAX_KEYS]; 


	Mix_Music* music;
	Mix_Chunk* fx[MAX_FX];

};
