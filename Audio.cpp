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
    SDL_Delay(300600); // Espera 5 segundos para que se reproduzca el sonido
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}