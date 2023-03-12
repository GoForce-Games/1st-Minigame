#include "SDL/include/SDL.h"

//SDL_AudioSpec audioSpec;
//SDL_AudioDeviceID audioDevice;
//
//void initAudio() 
//{
//    SDL_Init(SDL_INIT_AUDIO);
//    audioSpec.freq = 44100;
//    audioSpec.format = AUDIO_S16SYS;
//    audioSpec.channels = 2;
//    audioSpec.samples = 1024;
//    audioSpec.callback = NULL;
//    audioDevice = SDL_OpenAudioDevice(NULL, 0, &audioSpec, NULL, 0);
//    SDL_PauseAudioDevice(audioDevice, 0);
//}
//int main() 
//{
//    initAudio();
//    // Resto del código aquí
//    return 0;
//}
//
////const int BUFFER_SIZE = 4096;
////Uint32 audioLength = 300600;
////Uint8 * audioBuffer = new Uint8[BUFFER_SIZE];
////SDL_QueueAudio(audioDevice, audioBuffer, audioLength);
