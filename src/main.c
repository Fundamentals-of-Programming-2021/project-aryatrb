#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "variables.h"



int main() 
{
    srand(time(NULL));
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0,&DM);
    TTF_Init();
    window = SDL_CreateWindow("State.io: A Star Wars Story", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    number_of_soldiers = TTF_OpenFont("assets/EPISODE1.TTF",14);
    details_page = TTF_OpenFont("assets/Starjedi.ttf",40);
    details_page_outline = TTF_OpenFont("assets/Starjedi.ttf",40);
    TTF_SetFontOutline(details_page_outline,1);
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("State.io: A Star Wars Story", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_GetRendererOutputSize(renderer,&window_width,&window_height);
    load_variables();
    loadimages();
    int begining_of_time = SDL_GetTicks();
    TTF_SizeText(details_page,"number of enemies: 00",&number_of_enemies_w,&number_of_enemies_h);
    TTF_SizeText(details_page,"number of systems per player: 00",&per_user_w,&per_user_h);
    TTF_SizeText(details_page,"there are 00 maps. select one of them:",&mapsel_w,&mapsel_h);
    SDL_Rect load_game_target = {window_width/2 - size_new_game_x/2 , window_height/2 + 205, size_new_game_x, size_new_game_y};

    SDL_Rect closebutton_target = {window_width - 10 - size_of_closebutton_x_y, 10, size_of_closebutton_x_y, size_of_closebutton_x_y};


    SDL_Rect updownbutton_target = {loc_number_of_enemies_x + number_of_enemies_w + 10, loc_number_of_enemies_y, 40, 60};
    SDL_Rect updownbutton_sec_target = {loc_number_of_enemies_x + per_user_w + 10, loc_number_of_enemies_y + per_user_h + 10, 40, 60};


    SDL_Rect wall_target = {0, window_height - 40, window_width, 40};
    SDL_Rect wallflipped_target = {0, 0, window_width, size_of_each_cell_y/2};
    SDL_Rect backtomenu_target = {60, window_height - 35, 60, 30};
    SDL_Rect sound_target = {5 , window_height-40, 35, 35};

    time_t t;
    srand((unsigned) time(&t));
    time_t start_time;
    time(&start_time);


    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *menu_music = Mix_LoadMUS("assets/menu.mp3");
    Mix_Music *game_music = Mix_LoadMUS("assets/Anakins_Symphony.mp3");

    Mix_PlayMusic(menu_music,-1);
    char test3[33] = "............................";
    char mapselect[33] = "............................";
    while (1) {
        int start_ticks = SDL_GetTicks();
        SDL_RenderClear(renderer);
        time_t time_now;
        time(&time_now);
        if(page==0)
        {

            SDL_Rect new_game_target = {window_width/2 - size_new_game_x/2 , window_height/2 + window_height/2*160/300, size_new_game_x, size_new_game_y};
            SDL_Rect load_game_target = {window_width/2 - size_load_game_x/2 , window_height/2 + window_height/2*205/300, size_load_game_x, size_load_game_y};
            SDL_Rect leaderboard_target = {window_width/2 - leaderboard_game_x/2 , window_height/2 + window_height/2*250/300, leaderboard_game_x, leaderboard_game_y};
            SDL_Rect credits_target = {180- size_credits_x/2, window_height -50 - size_credits_y/2, size_credits_x, size_credits_y};


            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(click_x>window_width/2 - size_new_game_x/2 && click_x<window_width/2 + size_new_game_x/2 && click_y>window_height/2 + window_height/2*160/300 && click_y<window_height/2 + window_height/2*160/300 + size_new_game_y)
                size_new_game_x=327*window_width/1335*1.1,size_new_game_y=37*window_height/801*1.1;
            else
                size_new_game_x=327*window_width/1335, size_new_game_y=37*window_height/801;
            if(click_x>window_width/2 - size_load_game_x/2  && click_x<window_width/2 + size_load_game_x/2  && click_y>window_height/2 + window_height/2*205/300 && click_y<window_height/2 + window_height/2*205/300 + size_load_game_y)
                size_load_game_x=327*window_width/1335*1.1, size_load_game_y=37*window_height/801*1.1;
            else
                size_load_game_x=327*window_width/1335, size_load_game_y=37*window_height/801;
            if(click_x>window_width/2 - leaderboard_game_x/2 && click_x<window_width/2 + leaderboard_game_x/2 && click_y>window_height/2 + window_height/2*250/300 && click_y<window_height/2 + window_height/2*250/300 + leaderboard_game_y)
                leaderboard_game_x=327*window_width/1335*1.1, leaderboard_game_y=37*window_height/801*1.1;
            else
                leaderboard_game_x=327*window_width/1335, leaderboard_game_y=37*window_height/801;
            if(click_x>credits_target.x+60 && click_x<credits_target.x+credits_target.w - 60 && click_y>credits_target.y && click_y<credits_target.y+credits_target.h)
                size_credits_x=327*window_width/1335*1.1, size_credits_y=37*window_height/801*1.1;
            else
                size_credits_x=327*window_width/1335, size_credits_y=37*window_height/801;
            SDL_WaitEvent(&ev);
            if(ev.type==SDL_QUIT)
                break;
            if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>window_width/2 - size_new_game_x/2 && click_x<window_width/2 + size_new_game_x/2 && click_y>window_height/2 + window_height/2*160/300 && click_y<window_height/2 + window_height/2*160/300 + size_new_game_y)
                        page=1;
                    else if(click_x>window_width/2 - size_load_game_x/2  && click_x<window_width/2 + size_load_game_x/2  && click_y>window_height/2 + window_height/2*205/300 && click_y<window_height/2 + window_height/2*205/300 + size_load_game_y)
                    {
                        page=2;
                        char teemp[1000];
                        FILE *mapsave = fopen("assets/save/files_details.txt", "r+");
                        while(1)
                            if(fscanf(mapsave,"assets/save/maps/map%d.txt\n",&mapnumsel)==EOF)
                                break;
                        fclose(mapsave);
                    }
                    else if(click_x>window_width/2 - leaderboard_game_x/2 && click_x<window_width/2 + leaderboard_game_x/2 && click_y>window_height/2 + window_height/2*250/300 && click_y<window_height/2 + window_height/2*250/300 + leaderboard_game_y)
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
                    else if(click_x>credits_target.x+60 && click_x<credits_target.x+credits_target.w - 60 &&
                            click_y>credits_target.y && click_y<credits_target.y+credits_target.h)
                    {
                        credits_text_loc_y=5;
                        page=4;
                    }
                    else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                         && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                        break;
            }
            rendercpypage0(renderer,new_game_target,load_game_target,leaderboard_target,sound_target,credits_target,closebutton_target);

        }
        else if(page==1)
        {
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect start_game_target = {window_width - 150*window_width/1335 -start_game_x/2 , window_height - 50*window_height/801 - start_game_y/2, start_game_x, start_game_y};
            SDL_Rect enemies_target = {loc_number_of_enemies_x, loc_number_of_enemies_y, number_of_enemies_w, number_of_enemies_h};
            SDL_Rect per_user_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + number_of_enemies_h + 10, per_user_w, per_user_h};
            SDL_Rect username_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + 2* (number_of_enemies_h + 10), per_user_w, per_user_h};

            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
            && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                start_game_x=327*window_width/1335 * 1.1, start_game_y= 37*window_height/801 * 1.1;
            else
                start_game_x=327*window_width/1335, start_game_y= 37*window_height/801;
            SDL_WaitEvent(&ev);
            if(ev.type==SDL_QUIT)
                break;
            if(ev.type==SDL_KEYDOWN && writing_mode_username==1)
            {
                if((ev.key.keysym.sym==SDLK_BACKSPACE || ev.key.keysym.sym==SDLK_DELETE))
                {
                    if(size_of_text_username>0)
                    {
                        size_of_text_username--;
                        test3[size_of_text_username]='.';
                    } 
                }
                else
                {
                    test3[size_of_text_username]= ev.key.keysym.sym;
                    size_of_text_username++;
                }
            }
            else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                writing_mode_username=0;
                click_x=ev.button.x;
                click_y=ev.button.y;
                if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
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
                else if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
                && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                {
                    char teemp[1000];
                    FILE *mapsave = fopen("assets/save/files_details.txt", "r+");
                    int mapnum=0;
                    while(1)
                    {
                        if(fscanf(mapsave,"assets/save/maps/map%d.txt\n",&mapnum)==EOF)
                        break;
                    }
                    mapnum++;
                    fprintf(mapsave, "assets/save/maps/map%d.txt\n", mapnum);
                    fclose(mapsave);
                    char path[100] = "assets/save/maps/map";
                    if(mapnum<10)
                    path[20]= mapnum+ '0';
                    else
                    {
                        path[20] = mapnum/10 + '0';
                        path[21] = mapnum%10 + '0';
                    }
                    FILE *mapwrite = fopen(path, "w");
                    fprintf(mapwrite, "%d\n%d\n", number_of_enemies,number_of_politic_sides_per_user);
                    for(int j = 0;j<number_of_cells_y;j++)
                    {
                        for(int i=0;i<number_of_cells_x;i++)
                        {
                            if(j%2==0)
                                cells[i][j].x=(i)*size_of_each_cell_x*3/2;
                            else
                                cells[i][j].x=(i-1)*size_of_each_cell_x*3/2+ size_of_each_cell_x*3/4;
                            if((j%2==1 && i==0)|| (j%2==0 && i==number_of_cells_x-1) || rand()%2==0)
                                cells[i][j].is_territoy=0;
                            else
                                cells[i][j].is_territoy=1;
                            cells[i][j].y=(j+1)*size_of_each_cell_y/2;
                            cells[i][j].photo = SDL_LoadBMP("assets/metal.bmp");
                        }
                    }
                    int planets[5] = {0};
                    planets[0]=1;
                    int politic_sides_of_user=0;
                    for(int i=0;i<=number_of_enemies*number_of_politic_sides_per_user*3;i++)
                    {
                        politic_sides_of_user=0;
                        int temp_id;
                        while(politic_sides_of_user<number_of_politic_sides_per_user)
                        {
                            int temp_x = rand()%number_of_cells_x;
                            int temp_y = rand()%number_of_cells_y;
                            if(cells[temp_x][temp_y].is_territoy==1 && cells[temp_x][temp_y].is_occupied!=1)
                            {
                                cells[temp_x][temp_y].is_occupied=1;
                                SDL_Surface *temp_photo;
                                if(i>number_of_enemies)
                                {
                                    if(politic_sides_of_user==1)
                                        break;
                                    temp_photo = SDL_LoadBMP("assets/metal.bmp");
                                    politic_sides[size_of_politic_sides].player_id=-1;
                                    politic_sides[size_of_politic_sides].leader_face=SDL_LoadBMP("assets/faces/r2d2.bmp");
                                }
                                else if(i==0)
                                {
                                    temp_photo = SDL_LoadBMP("assets/planet_death_star.bmp");
                                    politic_sides[size_of_politic_sides].leader_face=faces[0];
                                    politic_sides[size_of_politic_sides].trooper=troopers[0];
                                    politic_sides[size_of_politic_sides].player_id=0;
                                }
                                else
                                {
                                    politic_sides[size_of_politic_sides].player_id=i;
                                    int temp_rand;
                                    if(politic_sides_of_user!=0)
                                        temp_rand=temp_id;
                                    else
                                    {
                                        temp_rand=rand()%5;
                                        while(planets[temp_rand]==1)
                                            temp_rand=rand()%5;
                                        temp_id=temp_rand;
                                    }
                                    politic_sides[size_of_politic_sides].leader_face=faces[temp_rand];
                                    politic_sides[size_of_politic_sides].trooper = troopers[temp_rand];
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
                                politic_sides[size_of_politic_sides].number_of_troopers=10;
                                politic_sides[size_of_politic_sides].size_of_cells=1;
                                politic_sides[size_of_politic_sides].cells_x[0] = temp_x, politic_sides[size_of_politic_sides].cells_y[0] = temp_y;
                                cells[temp_x][temp_y].photo=temp_photo;
                                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,0,1);
                                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,0,-1);
                                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,0,2);
                                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,0,-2);
                                if(temp_y%2==1)
                                {
                                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,-1,+1);
                                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,-1,1);
                                }
                                else
                                {
                                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,+1,+1);
                                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,temp_photo,+1,1);
                                }
                                size_of_politic_sides++;
                                politic_sides_of_user++;
                            }
                        }
                    }
                    for(int j = 0;j<number_of_cells_y;j++)
                        for(int i=0;i<number_of_cells_x;i++)
                            fprintf(mapwrite,"%d %d %d %d %d %d\n",cells[i][j].x, cells[i][j].y, cells[i][j].is_territoy, cells[i][j].id,cells[i][j].does_it_have_military,cells[i][j].is_occupied);
                    fprintf(mapwrite,"\n");
                    for(int i=0;i<=size_of_politic_sides;i++)
                    {
                            fprintf(mapwrite,"%d %d %d\n", politic_sides[i].player_id,politic_sides[i].size_of_cells,politic_sides[i].number_of_troopers);
                            for(int j=0;j<politic_sides[i].size_of_cells;j++)
                                fprintf(mapwrite,"%d %d\n",politic_sides[i].cells_x[j],politic_sides[i].cells_y[j]);
                            fprintf(mapwrite,"\n");
                    }
                    Mix_PauseMusic();
                    Mix_PlayMusic(game_music,-1);  
                    page=10;
                }
                else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                        && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                    break;
                else if(click_x>updownbutton_target.x && click_x<updownbutton_target.x + updownbutton_target.w
                        && click_y>updownbutton_target.y && click_y<updownbutton_target.y + updownbutton_target.h/2)
                        number_of_enemies++;
                else if(click_x>updownbutton_target.x && click_x<updownbutton_target.x + updownbutton_target.w
                        && click_y>updownbutton_target.y + updownbutton_target.h/2 && click_y<updownbutton_target.y + updownbutton_target.h && number_of_enemies>1)
                        number_of_enemies--;
                else if(click_x>updownbutton_sec_target.x && click_x<updownbutton_sec_target.x + updownbutton_sec_target.w
                        && click_y>updownbutton_sec_target.y && click_y<updownbutton_sec_target.y + updownbutton_sec_target.h/2)
                        number_of_politic_sides_per_user++;
                else if(click_x>updownbutton_sec_target.x && click_x<updownbutton_sec_target.x + updownbutton_sec_target.w
                        && click_y>updownbutton_sec_target.y + updownbutton_sec_target.h/2 && click_y<updownbutton_sec_target.y + updownbutton_sec_target.h && number_of_politic_sides_per_user>1)
                        number_of_politic_sides_per_user--;
                else if(click_x>username_target.x && click_x<username_target.x + username_target.w
                        && click_y>username_target.y + username_target.h/2 && click_y<username_target.y + username_target.h)
                        writing_mode_username=1;
            }
            rendercpypage1(test3,renderer,per_user_target,username_target,backbutton_target,start_game_target,enemies_target,sound_target,closebutton_target,updownbutton_target,updownbutton_sec_target);
        }
        else if(page==2)
        {
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect enemies_target = {loc_number_of_enemies_x, loc_number_of_enemies_y, mapsel_w, mapsel_h};
            SDL_Rect username_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + 2* (number_of_enemies_h + 10), per_user_w, per_user_h};

            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            SDL_WaitEvent(&ev);
            if(ev.type==SDL_QUIT)
                break;
            if(ev.type==SDL_KEYDOWN && writing_mode_map_select==1)
            {
                if((ev.key.keysym.sym==SDLK_BACKSPACE || ev.key.keysym.sym==SDLK_DELETE))
                {
                    if(size_of_text_mapselect>0)
                    {
                        size_of_text_mapselect--;
                        mapselect[size_of_text_mapselect]='.';
                    }
                }
                else if (ev.key.keysym.sym>='0' && ev.key.keysym.sym<='9')
                {
                    mapselect[size_of_text_mapselect]= ev.key.keysym.sym;
                    size_of_text_mapselect++;
                }
            }
            else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                writing_mode_map_select=0;
                click_x=ev.button.x;
                click_y=ev.button.y;
                if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
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
                else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                        && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                    break;
                else if(click_x>username_target.x && click_x<username_target.x + username_target.w
                        && click_y>username_target.y + username_target.h/2 && click_y<username_target.y + username_target.h)
                        writing_mode_map_select=1;
            }
            rendercpypage2(renderer,mapselect,backbutton_target,enemies_target,username_target,sound_target,closebutton_target);
        }
        else if(page==4)
        {
            int click_x,click_y;
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            
            SDL_WaitEvent(&ev);
            if(ev.type==SDL_QUIT)
                break;
            if(ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_UP && credits_text_loc_y<5)
                credits_text_loc_y+=5;
            else if(ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_DOWN && credits_text_loc_y>5-(credits_text_y-window_height))
                credits_text_loc_y-=5;
            else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
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
            }
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect credits_text_target = {window_width/2 - credits_text_x/2 , credits_text_loc_y, credits_text_x, credits_text_y};
            rendercpypage4(backbutton_target,credits_text_target,sound_target);
        }
        else if (page==10)
        {   
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            SDL_Delay(100);
            SDL_PollEvent(&ev);
            if(ev.type==SDL_QUIT)
                break;
            if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                click_x=ev.button.x;
                click_y=ev.button.y;
                if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
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
                else if (click_x>backtomenu_target.x && click_x<backtomenu_target.x + backtomenu_target.w  && click_y>backtomenu_target.y && click_y<backtomenu_target.y + backtomenu_target.h)
                {
                    Mix_PauseMusic();
                    Mix_PlayMusic(menu_music,-1);
                    page=0;
                }
                else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                        break;
            }

            SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, starsbackground);
            SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
            SDL_Texture *walltexture = SDL_CreateTextureFromSurface(renderer, wall);
            SDL_RenderCopy(renderer, walltexture, NULL, &wall_target);
            SDL_Texture *wallflippedtexture = SDL_CreateTextureFromSurface(renderer, wallflipped);
            SDL_RenderCopy(renderer, wallflippedtexture, NULL, &wallflipped_target);
            SDL_Texture *backtomenutexture = SDL_CreateTextureFromSurface(renderer, backtomenu);
            SDL_RenderCopy(renderer, backtomenutexture, NULL, &backtomenu_target);
            SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
            SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
            SDL_Texture *closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
            SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);



            SDL_Texture *startgametexture[100][100];
            SDL_Texture *leaders_faces_texture[100];
            SDL_Texture *temp_troopers_textures[200];
            SDL_GetMouseState(&click_x,&click_y);
            for(int i=0;i<size_of_politic_sides;i++)
            {
                for(int j=0;j<politic_sides[i].size_of_cells;j++)
                {
                    int x = politic_sides[i].cells_x[j], y = politic_sides[i].cells_y[j];
                    SDL_Rect cell_target = {cells[x][y].x , cells[x][y].y, size_of_each_cell_x, size_of_each_cell_y};
                    startgametexture[x][y] = SDL_CreateTextureFromSurface(renderer, cells[x][y].photo);
                    SDL_RenderCopy(renderer, startgametexture[x][y], NULL, &cell_target);
                    if(j==0)
                    {
                        SDL_Rect leader_target = {cells[x][y].x+ size_of_each_cell_x/2 - size_of_leaders_x_y/2, cells[x][y].y + size_of_each_cell_y*1/10, size_of_leaders_x_y, size_of_leaders_x_y};
                        leaders_faces_texture[i] = SDL_CreateTextureFromSurface(renderer, politic_sides[i].leader_face);
                        SDL_RenderCopy(renderer, leaders_faces_texture[i], NULL, &leader_target);
                        SDL_Rect temp_trooper_target = leader_target;
                        temp_troopers_textures[i] = SDL_CreateTextureFromSurface(renderer, politic_sides[i].trooper);
                        temp_trooper_target.w = temp_trooper_target.h = size_of_troopers_x_y;
                        temp_trooper_target.x -=5;
                        SDL_RenderCopy(renderer, temp_troopers_textures[i], NULL, &temp_trooper_target);
                        temp_trooper_target.x+=leader_target.w - temp_trooper_target.w + 10;
                        SDL_RenderCopy(renderer, temp_troopers_textures[i], NULL, &temp_trooper_target);
                        SDL_Color white = {255,255,255,255};
                        int w,h;
                        TTF_SizeText(number_of_soldiers,"100",&w,&h);
                        if(difftime(time_now,start_time)>=1)
                        {
                            politic_sides[i].number_of_troopers+=difftime(time_now,start_time);
                        }
                        char test[4];
                        test[0]=politic_sides[i].number_of_troopers/100 + '0';
                        test[1]=(politic_sides[i].number_of_troopers/10)%10 + '0';
                        test[2]=politic_sides[i].number_of_troopers%10 + '0';
                        test[3]= '\0';
                        leader_target.h = h;
                        leader_target.w = w;
                        leader_target.x += size_of_leaders_x_y/2 - w/2;
                        leader_target.y += size_of_leaders_x_y-5;
                        SDL_Surface *textsurface = TTF_RenderText_Solid(number_of_soldiers,test, white);
                        SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
                        SDL_RenderCopy(renderer,text_texture,NULL,&leader_target);
                        SDL_DestroyTexture(text_texture);
                        char* buffer = malloc(sizeof(char) * 50);
                        sprintf(buffer, "%s\n", test);
                        printf("%s", buffer);
                        stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
                    }
                }   
            }
            int rand_to_do_kyber = rand()%150;
            if(rand_to_do_kyber==0)
            {
                int rand_two_side_first = rand()%size_of_politic_sides;
                while(politic_sides[rand_two_side_first].number_of_troopers==-1)
                    rand_two_side_first = rand()%size_of_politic_sides;
                int rand_two_side_second = rand()%size_of_politic_sides;
                while(rand_two_side_first==rand_two_side_second || politic_sides[rand_two_side_second].player_id==-1)
                    rand_two_side_second = rand()%size_of_politic_sides;
                int first_center_x = cells[politic_sides[rand_two_side_first].cells_x[0]][politic_sides[rand_two_side_first].cells_y[0]].x+ size_of_each_cell_x/2 - size_of_kyber_photo_x/2;
                int first_center_y = cells[politic_sides[rand_two_side_first].cells_x[0]][politic_sides[rand_two_side_first].cells_y[0]].y + size_of_each_cell_y/2 - size_of_kyber_photo_y/2;
                int second_center_x = cells[politic_sides[rand_two_side_second].cells_x[0]][politic_sides[rand_two_side_second].cells_y[0]].x + size_of_each_cell_x/2 - size_of_kyber_photo_x/2;
                int second_center_y = cells[politic_sides[rand_two_side_second].cells_x[0]][politic_sides[rand_two_side_second].cells_y[0]].y + size_of_each_cell_y/2 - size_of_kyber_photo_y/2;
                int dist_rand = rand()%70 + 15;
                kybers[size_of_kybers].x = (first_center_x* dist_rand + second_center_x*(100-dist_rand))/100;
                kybers[size_of_kybers].y = (first_center_y* dist_rand + second_center_y*(100-dist_rand))/100;
                kybers[size_of_kybers].kyber_photo = kyber_cristal_photos[rand()%4];
                size_of_kybers++;
            }
            for(int i=0; i<size_of_kybers;i++)
            {
                SDL_Rect kyber_target = {kybers[i].x, kybers[i].y, size_of_kyber_photo_x, size_of_kyber_photo_y};
                SDL_Texture *kybertexture = SDL_CreateTextureFromSurface(renderer, kybers[i].kyber_photo);
                SDL_RenderCopy(renderer, kybertexture, NULL, &kyber_target);
                SDL_DestroyTexture(kybertexture);
            }
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(startscreentexture);
            SDL_DestroyTexture(walltexture);
            SDL_DestroyTexture(wallflippedtexture);
            SDL_DestroyTexture(backtomenutexture);
            SDL_DestroyTexture(soundtexture);
            for(int i=0;i<size_of_politic_sides;i++)
            {
                for(int j=0;j<politic_sides[i].size_of_cells;j++)
                    SDL_DestroyTexture(startgametexture[politic_sides[i].cells_x[j]][politic_sides[i].cells_y[j]]);
                SDL_DestroyTexture(leaders_faces_texture[i]);
                SDL_DestroyTexture(temp_troopers_textures[i]);
            }

        }
        if(difftime(time_now,start_time)>=1)
            time(&start_time);
        frame++;
        while (SDL_GetTicks() - start_ticks < 1000 / FPS);
    }
    Mix_FreeMusic(menu_music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
    return 0;
}
