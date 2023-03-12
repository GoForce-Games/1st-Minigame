#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL.h"
#include "Game.h"

void playMusic()
{
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;
    SDL_LoadWAV("MusicaFondo.wav", &wavSpec, &wavBuffer, &wavLength);
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);

    bool quit = false; // Variable para indicar que el usuario quiere salir
    while (!quit) {
        // Realiza las tareas que quieras mientras la música sigue sonando
        // Puedes utilizar eventos de SDL para detectar cuando el usuario quiere salir
        // Por ejemplo, puedes utilizar SDL_PollEvent para revisar si se ha detectado un evento de salida
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true; // Usuario quiere salir
            }
        }
    }

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);

}