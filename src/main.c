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
#include "math.h"



int main() 
{
    srand(time(NULL));
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0,&DM);
    TTF_Init();
    number_of_soldiers = TTF_OpenFont("assets/EPISODE1.TTF",14);
    details_page = TTF_OpenFont("assets/Starjedi.ttf",40);
    details_page_outline = TTF_OpenFont("assets/Starjedi.ttf",40);
    TTF_SetFontOutline(details_page_outline,1);
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("State.io: A Star Wars Story", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    load_variables();
    loadimages();
    int begining_of_time = SDL_GetTicks();
    TTF_SizeText(details_page,"number of enemies: 00",&number_of_enemies_w,&number_of_enemies_h);
    TTF_SizeText(details_page,"number of systems per player: 00",&per_user_w,&per_user_h);
    TTF_SizeText(details_page,"there are 00 maps. select one of them:",&mapsel_w,&mapsel_h);
    TTF_SizeText(details_page,"............................",&mapseltype_w,&mapseltype_h);
    TTF_SizeText(details_page,"............................",&usernametype_w,&usernametype_h);
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
    int gamerunning=1;
    while (1) 
    {
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
            rendercpypage0(new_game_target,load_game_target,leaderboard_target,sound_target,credits_target,closebutton_target);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(SDL_WaitEvent(&ev)==1)
            {
                if(ev.type==SDL_QUIT)
                    break;
                else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
                {
                        click_x=ev.button.x;
                        click_y=ev.button.y;
                        if(click_x>window_width/2 - size_new_game_x/2 && click_x<window_width/2 + size_new_game_x/2 && click_y>window_height/2 + window_height/2*160/300 && click_y<window_height/2 + window_height/2*160/300 + size_new_game_y)
                            page=1;
                        else if(click_x>window_width/2 - size_load_game_x/2  && click_x<window_width/2 + size_load_game_x/2  && click_y>window_height/2 + window_height/2*205/300 && click_y<window_height/2 + window_height/2*205/300 + size_load_game_y)
                        {
                            page=2;
                            char mapselect[33] = "............................";
                            size_of_text_mapselect=0;
                            findtotalofsaves();
                        }
                        else if(click_x>window_width/2 - leaderboard_game_x/2 && click_x<window_width/2 + leaderboard_game_x/2 && click_y>window_height/2 + window_height/2*250/300 && click_y<window_height/2 + window_height/2*250/300 + leaderboard_game_y)
                            page=3;
                        else if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                            soundchange();
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
            }
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

        }
        else if(page==1)
        {
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect start_game_target = {window_width - 150*window_width/1335 -start_game_x/2 , window_height - 50*window_height/801 - start_game_y/2, start_game_x, start_game_y};
            SDL_Rect enemies_target = {loc_number_of_enemies_x, loc_number_of_enemies_y, number_of_enemies_w, number_of_enemies_h};
            SDL_Rect per_user_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + number_of_enemies_h + 10, per_user_w, per_user_h};
            SDL_Rect username_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + 2* (number_of_enemies_h + 10), usernametype_w, usernametype_h};
            rendercpypage1(test3, per_user_target,username_target,backbutton_target,start_game_target,enemies_target,sound_target,closebutton_target,updownbutton_target,updownbutton_sec_target);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(SDL_WaitEvent(&ev)==1)
            {
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
                    TTF_SizeText(details_page,test3,&usernametype_w,&usernametype_h);
                }
                else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
                {
                    writing_mode_username=0;
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                        soundchange();
                    else if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                        page=0;
                    else if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
                    && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                    {
                        size_of_politic_sides=0;
                        FILE *mapsave = fopen("assets/save/files_details.txt", "r+");
                        int mapnum=0;
                        while(1)
                            if(fscanf(mapsave,"assets/save/maps/map%d.txt\n",&mapnum)==EOF)
                                break;
                        mapnum++;
                        fprintf(mapsave, "assets/save/maps/map%d.txt\n", mapnum);
                        fclose(mapsave);
                        char path[100] = "assets/save/maps/map";
                        if(mapnum<10)
                        {
                            path[20]= mapnum+ '0';
                            path[21] = '\0';
                        }
                        else
                        {
                            path[20] = mapnum/10 + '0';
                            path[21] = mapnum%10 + '0';
                            path[22] = '\0';
                        }
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
                                // cells[i][j].photo = SDL_LoadBMP("assets/metal.bmp");
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
                                        // temp_photo = SDL_LoadBMP("assets/metal.bmp");
                                        politic_sides[size_of_politic_sides].player_id=10;
                                        // politic_sides[size_of_politic_sides].leader_face=SDL_LoadBMP("assets/faces/r2d2.bmp");
                                    }
                                    else if(i==0)
                                    {
                                        // temp_photo = SDL_LoadBMP("assets/planet_death_star.bmp");
                                        politic_sides[size_of_politic_sides].leader_face=faces[0];
                                        politic_sides[size_of_politic_sides].trooper=troopers[0];
                                        politic_sides[size_of_politic_sides].player_id=0;
                                    }
                                    else
                                    {
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
                                        politic_sides[size_of_politic_sides].player_id=temp_id;
                                        politic_sides[size_of_politic_sides].leader_face=faces[temp_rand];
                                        politic_sides[size_of_politic_sides].trooper = troopers[temp_rand];
                                        temp_photo = planets_photos[temp_rand];
                                        planets[temp_rand]=1;
                                    }
                                    politic_sides[size_of_politic_sides].number_of_troopers=10;
                                    politic_sides[size_of_politic_sides].size_of_cells=1;
                                    politic_sides[size_of_politic_sides].cells_x[0] = temp_x, politic_sides[size_of_politic_sides].cells_y[0] = temp_y;
                                    cells[temp_x][temp_y].photo=temp_photo;
                                    cells[temp_x][temp_y].id=size_of_politic_sides;
                                    cells[temp_x][temp_y].does_it_have_military=1;
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
                        FILE *mapwrite = fopen(path, "w");
                        fprintf(mapwrite, "%d\n%d\n%d\n", number_of_enemies,number_of_politic_sides_per_user,size_of_politic_sides);
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
                        fclose(mapwrite);
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
            }
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
            && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                start_game_x=327*window_width/1335 * 1.1, start_game_y= 37*window_height/801 * 1.1;
            else
                start_game_x=327*window_width/1335, start_game_y= 37*window_height/801;
        }
        else if(page==2)
        {
            SDL_WaitEvent(&ev);
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect enemies_target = {loc_number_of_enemies_x, loc_number_of_enemies_y, mapsel_w, mapsel_h};
            SDL_Rect start_game_target = {window_width - 150*window_width/1335 -start_game_x/2 , window_height - 50*window_height/801 - start_game_y/2, start_game_x, start_game_y};
            SDL_Rect username_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + 2* (number_of_enemies_h + 10), mapseltype_w, mapseltype_h};
            rendercpypage2(mapselect,start_game_target,backbutton_target,enemies_target,username_target,sound_target,closebutton_target);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(ev.type==SDL_QUIT)
                break;
            else if(ev.type==SDL_KEYDOWN && writing_mode_map_select==1)
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
                TTF_SizeText(details_page,mapselect,&mapseltype_w,&mapseltype_h);
            }
            else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
            {
                writing_mode_map_select=0;
                click_x=ev.button.x;
                click_y=ev.button.y;
                if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                    soundchange();
                else if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                    page=0;
                else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                        && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                    break;
                else if(click_x>username_target.x && click_x<username_target.x + username_target.w
                        && click_y>username_target.y + username_target.h/2 && click_y<username_target.y + username_target.h)
                        writing_mode_map_select=1;
                else if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
                && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                {
                    // char* buffer = malloc(sizeof(char) * 50);
                    // sprintf(buffer, "%s %d\n", mapselect, size_of_text_mapselect);
                    // printf("%s", buffer);
                    int mapseltonum=0;
                    for(int i =0;i<size_of_text_mapselect;i++)
                        mapseltonum= mapseltonum *10 + mapselect[i] - '0'; 
                    char path[100] = "assets/save/maps/map";
                    if(mapseltonum<10)
                    {
                        path[20]= mapseltonum+ '0';
                        path[21] = '\0';
                    }
                    else
                    {
                        path[20] = mapseltonum/10 + '0';
                        path[21] = mapseltonum%10 + '0';
                        path[22] = '\0';
                    }
                    FILE *loadedmap = fopen(path, "r");
                    fscanf(loadedmap, "%d %d %d", &number_of_enemies, &number_of_politic_sides_per_user, &size_of_politic_sides);
                    for(int j = 0;j<number_of_cells_y;j++)
                        for(int i=0;i<number_of_cells_x;i++)
                            fscanf(loadedmap,"%d %d %d %d %d %d",&cells[i][j].x, &cells[i][j].y, &cells[i][j].is_territoy, &cells[i][j].id, &cells[i][j].does_it_have_military, &cells[i][j].is_occupied);
                    for(int i=0;i<=size_of_politic_sides;i++)
                    {
                        fscanf(loadedmap,"%d %d %d\n", &politic_sides[i].player_id, &politic_sides[i].size_of_cells, &politic_sides[i].number_of_troopers);
                        for(int j=0;j<politic_sides[i].size_of_cells;j++)
                            fscanf(loadedmap,"%d %d\n", &politic_sides[i].cells_x[j], &politic_sides[i].cells_y[j]);
                    }
                    fclose(loadedmap);
                    Mix_PauseMusic();
                    Mix_PlayMusic(game_music,-1);  
                    page=10;
                }
            }
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
            && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                start_game_x=327*window_width/1335 * 1.1, start_game_y= 37*window_height/801 * 1.1;
            else
                start_game_x=327*window_width/1335, start_game_y= 37*window_height/801;
        }
        else if(page==4)
        {
            SDL_WaitEvent(&ev);
            int click_x,click_y;
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
                        soundchange();
                    else if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                        page=0;
            }
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
            SDL_Rect credits_text_target = {window_width/2 - credits_text_x/2 , credits_text_loc_y, credits_text_x, credits_text_y};
            rendercpypage4(backbutton_target,credits_text_target,sound_target);
        }
        else if (page==10)
        {   
            rendercpypage10(wall_target,wallflipped_target,backtomenu_target,sound_target,closebutton_target,time_now,start_time);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            // char* buffer = malloc(sizeof(char) * 50);
            //             sprintf(buffer, "%d %d %d %d\n",click_x,click_y ,second_click_x, second_click_y);
            //             printf("%s", buffer);
            //             stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
            if(SDL_WaitEventTimeout(&ev, 50)==1)
            {
                
                if(ev.type==SDL_QUIT)
                    break;
                if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
                {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                        soundchange();
                    else if (click_x>backtomenu_target.x && click_x<backtomenu_target.x + backtomenu_target.w  
                        && click_y>backtomenu_target.y && click_y<backtomenu_target.y + backtomenu_target.h)
                    {
                        Mix_PauseMusic();
                        Mix_PlayMusic(menu_music,-1);
                        page=0;
                    }
                    else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                        && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                        break;
                    else if(click_y>40 && click_y<window_height-40 && is_first_clicked==0)
                    {
                        is_first_clicked=findclickedcell(click_x,click_y,&first_click_x,&first_click_y);
                    }
                    else if(click_y>40 && click_y<window_height-40 && is_first_clicked==1)
                    {
                        if(findclickedcell(click_x,click_y,&second_click_x,&second_click_y))
                        {
                            for(int i=0;i<politic_sides[cells[first_click_x][first_click_y].id].number_of_troopers;i++)
                            {

                                moving_troopers[size_of_moving_troopers].did_end=0;
                                moving_troopers[size_of_moving_troopers].did_pass_half=0;
                                moving_troopers[size_of_moving_troopers].current_x=cells[first_click_x][first_click_y].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
                                moving_troopers[size_of_moving_troopers].current_y=cells[first_click_x][first_click_y].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
                                moving_troopers[size_of_moving_troopers].dest_x = cells[second_click_x][second_click_y].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
                                moving_troopers[size_of_moving_troopers].dest_y = cells[second_click_x][second_click_y].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
                                moving_troopers[size_of_moving_troopers].half_dest_x = (moving_troopers[size_of_moving_troopers].dest_x + moving_troopers[size_of_moving_troopers].current_x)/2;
                                moving_troopers[size_of_moving_troopers].half_dest_y = (moving_troopers[size_of_moving_troopers].dest_y + moving_troopers[size_of_moving_troopers].current_y)/2;
                                if(size_of_moving_troopers%3==0)
                                {
                                    moving_troopers[size_of_moving_troopers].half_dest_y += (moving_troopers[size_of_moving_troopers].current_x - moving_troopers[size_of_moving_troopers].dest_x)*dist_from_mid/(moving_troopers[size_of_moving_troopers].dest_y - moving_troopers[size_of_moving_troopers].current_y);
                                    moving_troopers[size_of_moving_troopers].half_dest_x += dist_from_mid;
                                }
                                else if(size_of_moving_troopers%3==2)
                                {
                                    moving_troopers[size_of_moving_troopers].half_dest_y -= (moving_troopers[size_of_moving_troopers].current_x - moving_troopers[size_of_moving_troopers].dest_x)*dist_from_mid/(moving_troopers[size_of_moving_troopers].dest_y - moving_troopers[size_of_moving_troopers].current_y);
                                    moving_troopers[size_of_moving_troopers].half_dest_x -= dist_from_mid;
                                }
                                int m = (moving_troopers[i].half_dest_x - moving_troopers[i].current_x);
                                int n = (moving_troopers[i].half_dest_y - moving_troopers[i].current_y);
                                moving_troopers[size_of_moving_troopers].till_half_a = dist_moving_trooper_per_sec*m/sqrt(m*m+n*n);
                                m= (moving_troopers[i].dest_x - moving_troopers[i].half_dest_x);
                                n= (moving_troopers[i].dest_y - moving_troopers[i].half_dest_y);
                                moving_troopers[size_of_moving_troopers].till_end_a = dist_moving_trooper_per_sec*m/sqrt(m*m+n*n);
                                if(moving_troopers[size_of_moving_troopers].dest_x>moving_troopers[size_of_moving_troopers].current_x)
                                    moving_troopers[size_of_moving_troopers].is_dest_right=1;
                                else
                                    moving_troopers[size_of_moving_troopers].is_dest_right=0;
                                moving_troopers[size_of_moving_troopers].player_id = politic_sides[cells[first_click_x][first_click_y].id].player_id;
                                size_of_moving_troopers++;
                            }
                            is_first_clicked=0;
                        }
                    }
                }
            }
            if(difftime(time_now,start_time)>=0.1)
            {
                for(int i = 0 ; i<size_of_moving_troopers; i++)
                {
                    if(moving_troopers[i].did_end==1)
                        continue;
                    if(moving_troopers[i].did_pass_half==0)
                    {
                        int a_temp = moving_troopers[i].till_half_a;
                        int x_zero = moving_troopers[i].current_x;
                        int x_one = moving_troopers[i].half_dest_x;
                        int y_zero = moving_troopers[i].current_y;
                        int y_one = moving_troopers[i].half_dest_y;
                        moving_troopers[i].current_y = ((y_one*a_temp) + y_zero*(x_one - x_zero - a_temp))/(x_one-x_zero);
                        moving_troopers[i].current_x += a_temp; 
                        if(abs(moving_troopers[i].current_x - moving_troopers[i].dest_x)<abs(moving_troopers[i].half_dest_x - moving_troopers[i].dest_x))
                            moving_troopers[i].did_pass_half=1;
                    }
                    else
                    {
                        int a_temp = moving_troopers[i].till_end_a;
                        int x_zero = moving_troopers[i].current_x;
                        int x_one = moving_troopers[i].dest_x;
                        int y_zero = moving_troopers[i].current_y;
                        int y_one = moving_troopers[i].dest_y;
                        // char* buffer = malloc(sizeof(char) * 50);
                        // sprintf(buffer, "%d %d %d %d\n",moving_troopers[i].dest_x, moving_troopers[i].dest_y, );
                        // printf("%s", buffer);
                        moving_troopers[i].current_y = ((y_one*a_temp) + y_zero*(x_one - x_zero - a_temp))/(x_one-x_zero);
                        moving_troopers[i].current_x += a_temp; 
                        if(abs(moving_troopers[i].current_x - moving_troopers[i].dest_x)< dist_from_mid)
                            moving_troopers[i].did_end=1;
                    }
                    
                }
            }
        SDL_RenderPresent(renderer);

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
