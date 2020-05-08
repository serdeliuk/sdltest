#include <SDL2/SDL.h>

int main(int argc, char ** argv)
{
    fprintf(stderr, "SDL event tester: start \n");
    // variables
    bool quit = false;
    SDL_Event event;
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER|SDL_INIT_JOYSTICK) != 0) {
	fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }


    fprintf(stderr, "SDL event tester: please press any keys\n");
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
	    fprintf(stderr, "SDL event type: %s\n",event.type);
	case SDL_USEREVENT:
	    fprintf(stderr,"USEREVENT %s key acting as %s key \n", SDL_GetScancodeName(event.key.keysym.scancode), SDL_GetKeyName(event.key.keysym.sym));
            break;
        case SDL_KEYDOWN:
	    fprintf(stderr,"KEYDOWN %s key acting as %s key \n", SDL_GetScancodeName(event.key.keysym.scancode), SDL_GetKeyName(event.key.keysym.sym));
            break;
        case SDL_KEYUP:
	    fprintf(stderr,"KEYUP %s key acting as %s key \n", SDL_GetScancodeName(event.key.keysym.scancode), SDL_GetKeyName(event.key.keysym.sym));
            break;
	case SDL_MOUSEBUTTONDOWN:
	    fprintf(stderr,"MOUSEBUTTON %s key acting as %s key \n", SDL_GetScancodeName(event.key.keysym.scancode), SDL_GetKeyName(event.key.keysym.sym));
            break;
        case SDL_QUIT:
            quit = true;
            break;

        }
    }

    SDL_Quit();
    return 0;
}
