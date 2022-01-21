#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
    SDL_Surface *photo;
    int id;
    int does_it_have_military;
    int is_occupied;
};
struct politic_side{
    int cells_x[100];
    int cells_y[100];
    int size_of_cells;
    int player_id;
};
const int EXIT = 12345;
int handleEvents(double* snake_x, double* snake_y) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return EXIT;
    }
}
int main() {
    int number_of_enemies=3;
    srand(time(NULL));
    int size_of_each_cell_x=81,size_of_each_cell_y=70 ,number_of_cells_x=window_width/size_of_each_cell_x*3/4, number_of_cells_y = window_height*2/size_of_each_cell_y - 1;

    double snake_x = 100;
    double snake_y = 100;
    SDL_Color white= {255,255,255,255};
    SDL_Color black = {0,0,0,0};
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("State.io", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int begining_of_time = SDL_GetTicks();
    const double FPS = 30;
    int size_new_game_x = 327,size_new_game_y=37;
    int size_load_game_x = 327,size_load_game_y=37;
    int leaderboard_game_x = 327,leaderboard_game_y=37;
    int backbutton_x_y=50;
    int start_game_x = 327 , start_game_y =37;

    SDL_Surface *startbackground = SDL_LoadBMP("assets/background.bmp");
    SDL_Surface *starsbackground = SDL_LoadBMP("assets/stars.bmp");
    SDL_Surface *load_game = SDL_LoadBMP("assets/load_game.bmp");
    SDL_Surface *leaderboard = SDL_LoadBMP("assets/leaderboard.bmp");
    SDL_Surface *new_game = SDL_LoadBMP("assets/new_game.bmp");
    SDL_Rect load_game_target = {window_width/2 - size_new_game_x/2 , window_height/2 + 205, size_new_game_x, size_new_game_y};

    SDL_Surface *new_game_background = SDL_LoadBMP("assets/newgame_background.bmp");
    SDL_Surface *backbutton = SDL_LoadBMP("assets/backbutton.bmp");
    SDL_Surface *startgame = SDL_LoadBMP("assets/startgame.bmp");


    SDL_Surface *soundonphoto = SDL_LoadBMP("assets/soundon.bmp");
    SDL_Rect sound_target = {5 , window_height-40, 35, 35};


    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *menu_music = Mix_LoadMUS("assets/menu.mp3");
    SDL_Event ev;
    int page=0;
    struct cell cells[100][100];
    struct politic_side politic_sides[100];
    int size_of_politic_sides=0;
    Mix_PlayMusic(menu_music,-1);
    int is_sound_on=1,size_of_cells=0;
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
            SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
            SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
            

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
                    else if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                    {
                        if(is_sound_on==1)
                        {
                            is_sound_on=0;
                            Mix_PauseMusic();
                            soundonphoto = SDL_LoadBMP("assets/soundoff.bmp");
                        }
                        else
                        {
                            is_sound_on=1;
                            Mix_ResumeMusic();
                            soundonphoto = SDL_LoadBMP("assets/soundon.bmp");
                        }
                    }
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
            SDL_DestroyTexture(soundtexture);
        }
        else if(page==1)
        {
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect start_game_target = {window_width - 150 -start_game_x/2 , window_height - 50 - start_game_y/2, start_game_x, start_game_y};
            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, new_game_background);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
            SDL_Texture *backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
            SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
            SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
            SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
            SDL_Texture *startgametexture = SDL_CreateTextureFromSurface(renderer, startgame);
            SDL_RenderCopy(renderer, startgametexture, NULL, &start_game_target);

            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            if(click_x>730 && click_x<970 && click_y<window_height - 50 + start_game_y/2 && click_y>window_height - 50 - start_game_y/2)
                start_game_x=327 * 1.1, start_game_y= 37 * 1.1;
            else
                start_game_x=327, start_game_y= 37;
            
            SDL_WaitEvent(&ev);
            if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    /*if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>465 && click_y<490)
                        page=1;
                    else if(click_x>window_width/2 - 100 && click_x<window_width/2 + 100 && click_y>510 && click_y<535)
                        page=2;
                    else if(click_x>window_width/2 - 130 && click_x<window_width/2 + 130 && click_y>555 && click_y<580)
                        page=3;
                    else */if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                    {
                        if(is_sound_on==1)
                        {
                            is_sound_on=0;
                            Mix_PauseMusic();
                            soundonphoto = SDL_LoadBMP("assets/soundoff.bmp");
                        }
                        else
                        {
                            is_sound_on=1;
                            Mix_ResumeMusic();
                            soundonphoto = SDL_LoadBMP("assets/soundon.bmp");
                        }
                    }
                    else if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                        page=0;
                    else if(click_x>730 && click_x<970 && click_y<window_height - 50 + start_game_y/2 && click_y>window_height - 50 - start_game_y/2)
                    {
                        for(int j = 0;j<number_of_cells_y;j++)
                        {
                            for(int i=0;i<number_of_cells_x;i++)
                            {
                                if(j%2==0)
                                {
                                    cells[i][j].x=(i)*size_of_each_cell_x*3/2;
                                }
                                else
                                {
                                    cells[i][j].x=(i-1)*size_of_each_cell_x*3/2+ size_of_each_cell_x*3/4;
                                }
                                if((j%2==1 && i==0)|| (j%2==0 && i==number_of_cells_x-1) || rand()%2==0)
                                {
                                    cells[i][j].is_territoy=0;
                                    cells[i][j].photo = SDL_LoadBMP("assets/sea.bmp");
                                }
                                else
                                    cells[i][j].is_territoy=1;
                                cells[i][j].y=(j)*size_of_each_cell_y/2;
                                cells[i][j].photo = SDL_LoadBMP("assets/metal.bmp");
                            }
                        }
                        int planets[5] = {0};
                        planets[0]=1;
                        for(int i=0;i<number_of_enemies * 3;i++)
                        {
                            while(1)
                            {
                                int temp_x = rand()%number_of_cells_x;
                                int temp_y = rand()%number_of_cells_y;
                                if(cells[temp_x][temp_y].is_territoy==1 && cells[temp_x][temp_y].is_occupied!=1)
                                {
                                    cells[temp_x][temp_y].is_occupied=1;
                                    SDL_Surface *temp_photo;
                                    if(i>=number_of_enemies)
                                    {
                                        temp_photo = SDL_LoadBMP("assets/metal.bmp");
                                        politic_sides[size_of_politic_sides].player_id=-1;
                                    }
                                    else if(i==0)
                                    {
                                        temp_photo = SDL_LoadBMP("assets/planet_death_star.bmp");
                                        politic_sides[size_of_politic_sides].player_id=0;
                                    }
                                    else
                                    {
                                        politic_sides[size_of_politic_sides].player_id=i;
                                        int temp_rand=rand()%5;
                                        while(planets[temp_rand]==1)
                                            temp_rand=rand()%5;
                                        if(temp_rand==0)
                                            temp_photo = SDL_LoadBMP("assets/planet_death_star.bmp");
                                        if(temp_rand==1)
                                            temp_photo = SDL_LoadBMP("assets/planet_lothal.bmp");
                                        if(temp_rand==2)
                                            temp_photo = SDL_LoadBMP("assets/planet_mustafar.bmp");
                                        if(temp_rand==3)
                                            temp_photo = SDL_LoadBMP("assets/planet_naboo.bmp");
                                        if(temp_rand==4)
                                            temp_photo = SDL_LoadBMP("assets/planet_rodia.bmp");
                                        planets[temp_rand]=1;
                                    }
                                    politic_sides[size_of_politic_sides].size_of_cells=1;
                                    politic_sides[size_of_politic_sides].cells_x[0] = temp_x, politic_sides[size_of_politic_sides].cells_y[0] = temp_y;
                                    cells[temp_x][temp_y].photo=temp_photo;
                                    if(cells[temp_x][temp_y+1].is_territoy==1 && cells[temp_x][temp_y+1].is_occupied!=1)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y+1;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x][temp_y+1].photo = temp_photo;
                                        cells[temp_x][temp_y+1].is_occupied=1;
                                    }
                                    if(cells[temp_x][temp_y-1].is_territoy==1 && cells[temp_x][temp_y-1].is_occupied!=1)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y-1;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x][temp_y-1].photo = temp_photo;
                                        cells[temp_x][temp_y-1].is_occupied=1;
                                    }
                                    if(cells[temp_x][temp_y+2].is_territoy==1 && cells[temp_x][temp_y+2].is_occupied!=1)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y+2;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x][temp_y+2].photo = temp_photo;
                                        cells[temp_x][temp_y+2].is_occupied=1;
                                    }
                                    if(cells[temp_x][temp_y-2].is_territoy==1 && cells[temp_x][temp_y-2].is_occupied!=1)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y-2;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x][temp_y-2].photo = temp_photo;
                                        cells[temp_x][temp_y-2].is_occupied=1;
                                    }
                                    if(cells[temp_x-1][temp_y+1].is_territoy==1 && cells[temp_x-1][temp_y+1].is_occupied!=1 && temp_y%2==1)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x-1;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y+1;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x-1][temp_y+1].photo = temp_photo;
                                        cells[temp_x-1][temp_y+1].is_occupied=1;
                                    }
                                    if(cells[temp_x-1][temp_y-1].is_territoy==1 && cells[temp_x-1][temp_y-1].is_occupied!=1 && temp_y%2==1)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x-1;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y-1;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x-1][temp_y-1].photo = temp_photo;
                                        cells[temp_x-1][temp_y-1].is_occupied=1;
                                    }
                                    if(cells[temp_x+1][temp_y+1].is_territoy==1 && cells[temp_x+1][temp_y+1].is_occupied!=1 && temp_y!=2==0)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x+1;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y+1;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x+1][temp_y+1].photo = temp_photo;
                                        cells[temp_x+1][temp_y+1].is_occupied=1;
                                    }
                                    if(cells[temp_x+1][temp_y-1].is_territoy==1 && cells[temp_x+1][temp_y-1].is_occupied!=1 && temp_y!=2==0)
                                    {
                                        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x+1;
                                        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y-1;
                                        politic_sides[size_of_politic_sides].size_of_cells++;
                                        cells[temp_x+1][temp_y-1].photo = temp_photo;
                                        cells[temp_x+1][temp_y-1].is_occupied=1;
                                    }
                                    size_of_politic_sides++;
                                    break;
                                }
                            }
                        }
                        // for(int j = 0;j<number_of_cells_y;j++)
                        // {
                        //     for(int i=0;i<number_of_cells_x;i++)
                        //     {
                        //         if(cells[i][j].is_territoy==0)
                        //             continue;
                        //         SDL_Surface *temp_photo;
                        //         int temp_rand=rand()%5;
                        //         if(temp_rand==0)
                        //             temp_photo = SDL_LoadBMP("assets/planet_death_star.bmp");
                        //         if(temp_rand==1)
                        //             temp_photo = SDL_LoadBMP("assets/planet_lothal.bmp");
                        //         if(temp_rand==2)
                        //             temp_photo = SDL_LoadBMP("assets/planet_mustafar.bmp");
                        //         if(temp_rand==3)
                        //             temp_photo = SDL_LoadBMP("assets/planet_naboo.bmp");
                        //         if(temp_rand==4)
                        //             temp_photo = SDL_LoadBMP("assets/planet_rodia.bmp");
                        //         politic_sides[size_of_politic_sides].size_of_cells=1;
                        //         politic_sides[size_of_politic_sides].cells_x[0] = i, politic_sides[size_of_politic_sides].cells_y[0] = j;
                        //         if(cells[i][j+1].is_territoy==1)
                        //         {
                        //             politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = i;
                        //             politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = j+1;
                        //             politic_sides[size_of_politic_sides].size_of_cells++;
                        //             cells[i][j].photo = temp_photo;
                        //         }
                        //         if(cells[i][j-1].is_territoy==1)
                        //         {
                        //             politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = i;
                        //             politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = j-1;
                        //             politic_sides[size_of_politic_sides].size_of_cells++;
                        //             cells[i][j].photo = temp_photo;
                        //         }
                        //     }
                        // }
                        page=10;
                    }
            }


            char* buffer = malloc(sizeof(char) * 50);
            sprintf(buffer, "sfff %d %d %d %d %d\n", click_x, click_y,page,ev.button.x,ev.button.y);
            printf("%s", buffer);
            stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
            SDL_RenderPresent(renderer);

            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(startscreentexture);
            SDL_DestroyTexture(soundtexture);
            SDL_DestroyTexture(backbuttontexture);
            SDL_DestroyTexture(startgametexture);
        }
        else if (page==10)
        {
            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, starsbackground);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
            SDL_Texture *startgametexture[100][100];
            // for(int i =0; i<number_of_cells_x;i++)
            // {
            //     for(int j=0;j<number_of_cells_y;j++)
            //     {
            //         if(cells[i][j].is_territoy==1)
            //         {
            //             SDL_Rect cell_target = {cells[i][j].x , cells[i][j].y, size_of_each_cell_x, size_of_each_cell_y};
            //             startgametexture[i][j] = SDL_CreateTextureFromSurface(renderer, cells[i][j].photo);
            //             SDL_RenderCopy(renderer, startgametexture[i][j], NULL, &cell_target);
            //         }
                    
            //     }
            // }
            for(int i=0;i<size_of_politic_sides;i++)
            {
                for(int j=0;j<politic_sides[i].size_of_cells;j++)
                {
                    int x = politic_sides[i].cells_x[j], y = politic_sides[i].cells_y[j];
                    SDL_Rect cell_target = {cells[x][y].x , cells[x][y].y, size_of_each_cell_x, size_of_each_cell_y};
                    startgametexture[x][y] = SDL_CreateTextureFromSurface(renderer, cells[x][y].photo);
                    SDL_RenderCopy(renderer, startgametexture[x][y], NULL, &cell_target);
                }
            }
            SDL_WaitEvent(&ev);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(startscreentexture);
            for(int i=0;i<size_of_politic_sides;i++)
            {
                for(int j=0;j<politic_sides[i].size_of_cells;j++)
                {
                    if(cells[politic_sides[i].cells_x[j]][politic_sides[i].cells_y[j]].is_territoy==1)
                        SDL_DestroyTexture(startgametexture[politic_sides[i].cells_x[j]][politic_sides[i].cells_y[j]]);
                }
            }
            // for(int i =0; i<number_of_cells_x;i++)
            // {
            //     for(int j=0;j<number_of_cells_y;j++)
            //     {
            //         if(cells[i][j].is_territoy==1)
            //         {
            //             SDL_DestroyTexture(startgametexture[i][j]);
            //         }
            //     }
            // }
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
