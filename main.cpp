#include "Game.h"
#include "SDL/include/SDL.h"

#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )


int main(int argc, char* args[])
{
    Game game;
    if (!game.Init()) return -1;
    bool end = false; 
    while (!end)
    {
        
        end = game.Update();
        game.Draw(); 
        SDL_Init(SDL_INIT_AUDIO);
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8* wavBuffer;
        SDL_LoadWAV("MusicaFondo.wav", &wavSpec, &wavBuffer, &wavLength);
        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
        SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        SDL_PauseAudioDevice(deviceId, 0);
        while (true) { // Bucle infinito para reproducir la música de fondo continuamente
            SDL_Delay(300600); // Espera 5 segundos antes de cargar de nuevo el archivo
            SDL_ClearQueuedAudio(deviceId); // Limpiar el buffer de audio
            SDL_QueueAudio(deviceId, wavBuffer, wavLength); // Cargar el archivo de audio de nuevo
        }
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();
    }  
    return 0;
}




	