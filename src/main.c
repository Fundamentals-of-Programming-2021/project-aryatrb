#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
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
//int size_of_each_cell=20, number_of_cells=window_width/size_of_each_cell;
int main() {
    double snake_x = 100;
    double snake_y = 100;
    SDL_Color white= {255,255,255,255};
    SDL_Color black = {0,0,0,0};
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("State.io", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int begining_of_time = SDL_GetTicks();
    const double FPS = 30;
    SDL_Surface *startbackground = SDL_LoadBMP("assets/background.bmp");
    SDL_Surface *new_game_background = SDL_LoadBMP("assets/newgame_background.bmp");

    SDL_Surface *new_game = SDL_LoadBMP("assets/new_game.bmp");
    int size_new_game_x = 327,size_new_game_y=37;
    int size_load_game_x = 327,size_load_game_y=37;
    int leaderboard_game_x = 327,leaderboard_game_y=37;

    SDL_Surface *load_game = SDL_LoadBMP("assets/load_game.bmp");
    SDL_Rect load_game_target = {window_width/2 - size_new_game_x/2 , window_height/2 + 205, size_new_game_x, size_new_game_y};

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    SDL_Surface *leaderboard = SDL_LoadBMP("assets/leaderboard.bmp");
    
    Mix_Music *menu_music = Mix_LoadMUS("assets/menu.mp3");


    SDL_Event ev;
    int page=0;
    struct cell cells[10000];
    Mix_PlayMusic(menu_music,-1);

    while (1) {
        int start_ticks = SDL_GetTicks();
        if (handleEvents(&snake_x, &snake_y) == EXIT)
            break;
        SDL_RenderClear(renderer);
        if(page==0)
        {
            SDL_Rect new_game_target = {window_width/2 - size_new_game_x/2 , window_height/2 + 160, size_new_game_x, size_new_game_y};
            SDL_Rect load_game_target = {window_width/2 - size_load_game_x/2 , window_height/2 + 205, size_load_game_x, size_load_game_y};
            SDL_Rect leaderboard_target = {window_width/2 - leaderboard_game_x/2 , window_height/2 + 250, leaderboard_game_x, leaderboard_game_y};

            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, startbackground);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
            SDL_Texture *newgame_texture = SDL_CreateTextureFromSurface(renderer, new_game);
            SDL_RenderCopy(renderer, newgame_texture, NULL, &new_game_target);
            SDL_Texture *loadgame_texture = SDL_CreateTextureFromSurface(renderer, load_game);
            SDL_RenderCopy(renderer, loadgame_texture, NULL, &load_game_target);
            SDL_Texture *leaderboard_texture = SDL_CreateTextureFromSurface(renderer, leaderboard);
            SDL_RenderCopy(renderer, leaderboard_texture, NULL, &leaderboard_target);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>465 && click_y<490)
                size_new_game_x=327*1.1,size_new_game_y=37*1.1;
            else
                size_new_game_x=327, size_new_game_y=37;
            if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>510 && click_y<535)
                size_load_game_x=327*1.1, size_load_game_y=37*1.1;
            else
                size_load_game_x=327, size_load_game_y=37;
            if(click_x>window_width/2 - 130 && click_x<window_width/2 + 130 && click_y>555 && click_y<580)
                leaderboard_game_x=327*1.1, leaderboard_game_y=37*1.1;
            else
                leaderboard_game_x=327, leaderboard_game_y=37;
            SDL_WaitEvent(&ev);
            if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>465 && click_y<490)
                        page=1;
                    else if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>510 && click_y<535)
                        page=2;
                    else if(click_x>window_width/2 - 130 && click_x<window_width/2 + 130 && click_y>555 && click_y<580)
                        page=3;
            }
            char* buffer = malloc(sizeof(char) * 50);
            sprintf(buffer, "sfff %d %d %d %d %d\n", click_x, click_y,page,ev.button.x,ev.button.y);
            printf("%s", buffer);
            stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
            SDL_RenderPresent(renderer);
            // SDL_DestroyTexture(ttfTexture_menu_main);
            // SDL_DestroyTexture(ttfTexture_menu_main_stroke);
            SDL_DestroyTexture(startscreentexture);
            SDL_DestroyTexture(newgame_texture);
            SDL_DestroyTexture(loadgame_texture);
            SDL_DestroyTexture(leaderboard_texture);
        }
        else if(page==1)
        {
            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, new_game_background);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
            char* buffer = malloc(sizeof(char) * 50);
            sprintf(buffer, "HEEEER-\n");
            printf("%s", buffer);
            stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);

            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(startscreentexture);
        }
        while (SDL_GetTicks() - start_ticks < 1000 / FPS);
    }
    Mix_FreeMusic(menu_music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
    return 0;
}
