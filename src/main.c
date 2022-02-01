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
#include <sys/timeb.h>

int main() 
{
    srand(time(NULL));
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0,&DM);
    TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("State.io: A Star Wars Story", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    load_variables();
    loadimages();
    int begining_of_time = SDL_GetTicks();
    SDL_Rect closebutton_target = {window_width - 10 - size_of_closebutton_x_y, 25 - size_of_closebutton_x_y, size_of_closebutton_x_y, size_of_closebutton_x_y};

    SDL_Rect updownbutton_target = {loc_number_of_enemies_x + number_of_enemies_w + 10*window_width/1920, loc_number_of_enemies_y, 40*window_width/1920, 60*window_width/1920};
    SDL_Rect updownbutton_sec_target = {loc_number_of_enemies_x + per_user_w + 10*window_width/1920, loc_number_of_enemies_y + per_user_h + 10*window_width/1920, 40*window_width/1920, 60*window_width/1920};

    SDL_Rect wall_target = {0, window_height - size_of_wall_y, window_width, size_of_wall_y};
    SDL_Rect wallflipped_target = {0, 0, window_width, size_of_wall_y};
    SDL_Rect backtomenu_target = {60, window_height - 35, 60, 30};
    SDL_Rect sound_target = {5 , window_height-40, 35, 35};

    time_t t;
    srand((unsigned) time(&t));
   
    time_t start_time_troop;
    time(&start_time);
    time(&start_time_troop);

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *menu_music = Mix_LoadMUS("assets/menu.mp3");
    Mix_Music *game_music = Mix_LoadMUS("assets/Anakins_Symphony.mp3");

    Mix_PlayMusic(menu_music,-1);

    SDL_Rect new_game_target = {window_width/2 - size_new_game_x/2 , window_height/2 + window_height/2*160/300 - size_new_game_y/2, size_new_game_x, size_new_game_y};
    SDL_Rect load_game_target = {window_width/2 - size_load_game_x/2 , window_height/2 + window_height/2*205/300 - size_load_game_y/2, size_load_game_x, size_load_game_y};
    SDL_Rect leaderboard_target = {window_width/2 - leaderboard_game_x/2 , window_height/2 + window_height/2*250/300 - leaderboard_game_y/2, leaderboard_game_x, leaderboard_game_y};
    SDL_Rect credits_target = {180*window_width/1335- size_credits_x/2, window_height -50*window_width/1335 - size_credits_y/2, size_credits_x, size_credits_y};
    SDL_Rect start_game_target = {window_width - 150*window_width/1335 -start_game_x/2 , window_height - 50*window_width/1335 - start_game_y/2, start_game_x, start_game_y};
    SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
    SDL_Rect enemies_target = {loc_number_of_enemies_x, loc_number_of_enemies_y, number_of_enemies_w, number_of_enemies_h};
    SDL_Rect per_user_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + number_of_enemies_h + 10, per_user_w, per_user_h};
    SDL_Rect username_target = {loc_number_of_enemies_x, loc_number_of_enemies_y + 2* (number_of_enemies_h + 10), usernametype_w, usernametype_h};
    time_t temp_now;
    time(&temp_now);
    while (1) 
    {
        start_ticks = SDL_GetTicks();
        time(&time_now);
        if(page==0)
        {
            rendercpypage0(new_game_target,load_game_target,leaderboard_target,sound_target,credits_target,closebutton_target);
            int click_x,click_y;
            SDL_PumpEvents();
            SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
            if(SDL_WaitEvent(&ev)==1)
            {
                SDL_GetMouseState(&click_x,&click_y);
                if(ev.type==SDL_QUIT)
                    break;
                else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
                {
                    click_x=ev.button.x;
                    click_y=ev.button.y;
                    if(click_x>new_game_target.x && click_x<new_game_target.x + new_game_target.w && click_y>new_game_target.y && click_y<new_game_target.y + new_game_target.h)
                        page=1;
                    else if(click_x>load_game_target.x  && click_x<load_game_target.x + load_game_target.w  && click_y>load_game_target.y && click_y<load_game_target.y + load_game_target.h)
                    {
                        page=2;
                        char mapselect[33] = "............................";
                        size_of_text_mapselect=0;
                        findtotalofsaves();
                    }
                    else if(click_x>leaderboard_target.x && click_x<leaderboard_target.x + leaderboard_target.w && click_y>leaderboard_target.y && click_y<leaderboard_target.y + leaderboard_target.h)
                        page=3;
                    else if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
                        soundchange();
                    else if(click_x>credits_target.x && click_x<credits_target.x+credits_target.w &&
                            click_y>credits_target.y && click_y<credits_target.y+credits_target.h)
                    {
                        credits_text_loc_y=5;
                        page=4;
                    }
                    else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                        && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
                        break;
                }
                if(click_x>new_game_target.x && click_x<new_game_target.x + new_game_target.w && click_y>new_game_target.y && click_y<new_game_target.y + new_game_target.h)
                    size_new_game_x=327*window_width/1335*1.1,size_new_game_y=37*window_width/1335*1.1;
                else
                    size_new_game_x=327*window_width/1335, size_new_game_y=37*window_width/1335;
                if(click_x>load_game_target.x  && click_x<load_game_target.x + load_game_target.w  && click_y>load_game_target.y && click_y<load_game_target.y + load_game_target.h)
                    size_load_game_x=327*window_width/1335*1.1, size_load_game_y=37*window_width/1335*1.1;
                else
                    size_load_game_x=327*window_width/1335, size_load_game_y=37*window_width/1335;
                if(click_x>leaderboard_target.x && click_x<leaderboard_target.x + leaderboard_target.w && click_y>leaderboard_target.y && click_y<leaderboard_target.y + leaderboard_target.h)
                    leaderboard_game_x=327*window_width/1335*1.1, leaderboard_game_y=37*window_width/1335*1.1;
                else
                    leaderboard_game_x=327*window_width/1335, leaderboard_game_y=37*window_width/1335;
                if(click_x>credits_target.x && click_x<credits_target.x+credits_target.w && click_y>credits_target.y && click_y<credits_target.y+credits_target.h)
                    size_credits_x=163*window_width/1335*1.1, size_credits_y=37*window_width/1335*1.1;
                else
                    size_credits_x=163*window_width/1335, size_credits_y=37*window_width/1335;
            }
        }
        else if(page==1)
        {
            SDL_PumpEvents();
            SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
            SDL_WaitEvent(&ev);
            rendercpypage1(test3, per_user_target,username_target,backbutton_target,start_game_target,enemies_target,sound_target,closebutton_target,updownbutton_target,updownbutton_sec_target);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
            if(ev.type==SDL_QUIT)
                break;
            if(ev.type==SDL_KEYDOWN && writing_mode_username==1)
            {
                if((ev.key.keysym.sym==SDLK_BACKSPACE || ev.key.keysym.sym==SDLK_DELETE) && size_of_text_username>0)
                {
                    size_of_text_username--;
                    test3[size_of_text_username]='.';
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
                    create_cells();
                    assign_politic_sides();
                    save_the_map();
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
            if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
                backbutton_x_y=50 * 1.2;
            else
                backbutton_x_y=50;
            if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
            && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
                start_game_x=327*window_width/1335 * 1.1, start_game_y= 37*window_width/1335 * 1.1;
            else
                start_game_x=327*window_width/1335, start_game_y= 37*window_width/1335;
        }
        else if(page==2)
        {
            SDL_PumpEvents();
            SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
            SDL_WaitEvent(&ev);
            rendercpypage2(mapselect,start_game_target,backbutton_target,enemies_target,username_target,sound_target,closebutton_target);
            int click_x,click_y;
            SDL_GetMouseState(&click_x,&click_y);
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
                    load_the_map();
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
                start_game_x=327*window_width/1335 * 1.1, start_game_y= 37*window_width/1335 * 1.1;
            else
                start_game_x=327*window_width/1335, start_game_y= 37*window_width/1335;
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
            rendercpypage4(sound_target);
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
            // SDL_PumpEvents();
            // SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
            // SDL_Delay(5);
            while(SDL_PollEvent(&ev))
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
                    else if(click_x > closebutton_target.x && click_x < closebutton_target.x + closebutton_target.w 
                         && click_y > closebutton_target.y && click_y < closebutton_target.y + closebutton_target.h)
                    {
                        game_running=0;
                        break;
                    }
                    else if(click_y>40 && click_y<window_height-40 && is_first_clicked==0)
                    {
                        is_first_clicked=findclickedcell(click_x,click_y,&first_click_x,&first_click_y,1);
                            //                     char* buffer = malloc(sizeof(char) * 50);
                            // sprintf(buffer, "first%d\n",is_first_clicked);
                            // printf("%s", buffer);
                        // stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
                    }
                    else if(click_y>40 && click_y<window_height-40 && is_first_clicked==1)
                    {
                        // char* buffer = malloc(sizeof(char) * 50);
                        //     sprintf(buffer, "%d\n",is_first_clicked);
                        //     printf("%s", buffer);
                        if(findclickedcell(click_x,click_y,&second_click_x,&second_click_y,0))
                        { 
                            char* buffer = malloc(sizeof(char) * 50);
                            sprintf(buffer, "%d\n",is_first_clicked);
                            printf("%s", buffer);
                            stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
                            free(buffer);
                            politic_sides[cells[first_click_x][first_click_y].politic_side_number].is_sending_troopers=1;
                            create_moving_troopers();
                        }
                    }
                }
                // char* buffer = malloc(sizeof(char) * 50);
                // sprintf(buffer, "%d %lf\n",is_first_clicked,difftime(time_now,temp_now));
                // printf("%s", buffer);
                // stringRGBA(renderer, 5, 5, buffer, 0, 0, 200, 255);
                // free(buffer);
            }
            if(game_running==0)
                break;
            moving_troopers_update_location();
            SDL_RenderPresent(renderer);
        }
        SDL_RenderClear(renderer);
        if(difftime(time_now,start_time_troop)>=0.3)
            time(&start_time_troop);
        if(difftime(time_now,start_time)>=1)
            time(&start_time);
        while (SDL_GetTicks() - start_ticks < 1000 / FPS);
    }
    Mix_FreeMusic(menu_music);
    Mix_FreeMusic(game_music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
    return 0;
}
