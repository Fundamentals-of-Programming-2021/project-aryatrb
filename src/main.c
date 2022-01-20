#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#define window_width 1000
#define window_height 600
struct cell{
    int x;
    int y;
    int is_territoy;
};
const int EXIT = 12345;
int handleEvents(double* snake_x, double* snake_y) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return EXIT;
    }
}
int size_of_each_cell=20, number_of_cells=window_width/size_of_each_cell;
int main() {
    double snake_x = 100;
    double snake_y = 100;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("State.io", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int begining_of_time = SDL_GetTicks();
    const double FPS = 30;
    SDL_Surface *startbackground = SDL_LoadBMP("assets/background.bmp");
    SDL_Surface *new_game_background = SDL_LoadBMP("assets/newgame_background.bmp");
    SDL_Event ev;
    int page=0;
    struct cell cells[10000];
    while (1) {
        int start_ticks = SDL_GetTicks();
        if (handleEvents(&snake_x, &snake_y) == EXIT)
            break;
        SDL_RenderClear(renderer);
        if(page==0)
        {
            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, startbackground);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            SDL_PollEvent(&ev);
            if(ev.type==SDL_MOUSEBUTTONDOWN)
            {
                if(ev.button.button==SDL_BUTTON_LEFT)
                {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>465 && click_y<490)
                        page=1;
                    else if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>510 && click_y<535)
                        page=2;
                    else if(click_x>window_width/2 - 80 && click_x<window_width/2 + 80 && click_y>555 && click_y<580)
                        page=3;
                }
            }
            char* buffer = malloc(sizeof(char) * 50);
            sprintf(buffer, "sfff %d %d %d %d %d\n", click_x, click_y,page,ev.button.x,ev.button.y);
            printf("%s", buffer);
            stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(startscreentexture);
        }
        else if(page==1)
        {
            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, new_game_background);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);


            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(startscreentexture);
        }
        while (SDL_GetTicks() - start_ticks < 500 / FPS);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
