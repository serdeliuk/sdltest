#include <SDL2/SDL.h>
int i;

int main( int argc, char* args[] )
{
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        //SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }

/* Show the list of available drivers */
SDL_Log("Available audio drivers:");
    for (i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
    SDL_Log("%i: %s", i, SDL_GetAudioDriver(i));
}

// load WAV file
SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8 *wavBuffer;

SDL_LoadWAV("/usr/share/sdltest/a.wav", &wavSpec, &wavBuffer, &wavLength);
/* Start playing */

// open audio device
SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

//SDL_Log("Device id: %s", deviceId);

// play audio
int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
SDL_PauseAudioDevice(deviceId, 0);

//SDL_PauseAudio(0);

SDL_Delay(8000);

// clean up

SDL_CloseAudioDevice(deviceId);
SDL_FreeWAV(wavBuffer);
SDL_Quit();

return 0;
}
