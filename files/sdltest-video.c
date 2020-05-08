#include <SDL2/SDL.h>

int main( int argc, char* args[] )
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
}

SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
if (win == nullptr){
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    SDL_Quit();
    return 1;
}

SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
if (ren == nullptr){
    SDL_DestroyWindow(win);
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    SDL_Quit();
    return 1;
}

SDL_Surface *bmp = SDL_LoadBMP("/usr/share/sdltest/a.bmp");
if (bmp == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    SDL_Quit();
    return 1;
}

SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
SDL_FreeSurface(bmp);
if (tex == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    SDL_Quit();
    return 1;
}

SDL_ShowWindow(win);

SDL_Delay(3000);

//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
for (int i = 0; i < 3; ++i){
    //First clear the renderer
    SDL_RenderClear(ren);
    //Draw the texture
    SDL_RenderCopy(ren, tex, NULL, NULL);
    //Update the screen
    SDL_RenderPresent(ren);
    //Take a quick break after all that hard work
//    SDL_Delay(1000);
}

SDL_Delay(60000);

SDL_DestroyTexture(tex);
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();

}
