#include <time.h>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "string.h"
#include "load_everything.h"


void page0()
{
    rendercpypage0();
    int click_x,click_y;
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    if(SDL_WaitEvent(&ev)==1)
    {
        SDL_GetMouseState(&click_x,&click_y);
        if(ev.type==SDL_QUIT)
        {
            game_running=0;
            return;
        }
        else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
        {
            click_x=ev.button.x;
            click_y=ev.button.y;
            if(click_x>new_game_target.x && click_x<new_game_target.x + new_game_target.w && click_y>new_game_target.y && click_y<new_game_target.y + new_game_target.h)
                pageto1();
            else if(click_x>load_game_target.x  && click_x<load_game_target.x + load_game_target.w  && click_y>load_game_target.y && click_y<load_game_target.y + load_game_target.h)
                pageto2();
            else if(click_x>leaderboard_target.x && click_x<leaderboard_target.x + leaderboard_target.w && click_y>leaderboard_target.y && click_y<leaderboard_target.y + leaderboard_target.h)
            {
                leaderboard_set();
                page=3;
            }
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
            {
                game_running=0;
                return;
            }
        }
        if(click_x>new_game_target.x && click_x<new_game_target.x + new_game_target.w && click_y>new_game_target.y && click_y<new_game_target.y + new_game_target.h)
            size_new_game_x=(int)(327*(float)window_width/1335*1.1),size_new_game_y=(int)(37*(float)window_width/1335*1.1);
        else
            size_new_game_x=327*window_width/1335, size_new_game_y=37*window_width/1335;
        if(click_x>load_game_target.x  && click_x<load_game_target.x + load_game_target.w  && click_y>load_game_target.y && click_y<load_game_target.y + load_game_target.h)
            size_load_game_x=(int)(327*(float)window_width/1335*1.1), size_load_game_y=(int)(37*(float)window_width/1335*1.1);
        else
            size_load_game_x=327*window_width/1335, size_load_game_y=37*window_width/1335;
        if(click_x>leaderboard_target.x && click_x<leaderboard_target.x + leaderboard_target.w && click_y>leaderboard_target.y && click_y<leaderboard_target.y + leaderboard_target.h)
            leaderboard_game_x=(int)(327*(float)window_width/1335*1.1), leaderboard_game_y=(int)(37*(float)window_width/1335*1.1);
        else
            leaderboard_game_x=327*window_width/1335, leaderboard_game_y=37*window_width/1335;
        if(click_x>credits_target.x && click_x<credits_target.x+credits_target.w && click_y>credits_target.y && click_y<credits_target.y+credits_target.h)
            size_credits_x=(int)(163*(float)window_width/1335*1.1), size_credits_y=(int)(37*(float)window_width/1335*1.1);
        else
            size_credits_x=163*window_width/1335, size_credits_y=37*window_width/1335;
    }
}

void page1()
{
    rendercpypage1();
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    SDL_WaitEvent(&ev);
    int click_x,click_y;
    SDL_GetMouseState(&click_x,&click_y);
    if(ev.type==SDL_QUIT)
    {
        game_running=0;
        return;
    }
    if(ev.type==SDL_KEYDOWN && writing_mode_username==1)
    {
        if((ev.key.keysym.sym==SDLK_BACKSPACE || ev.key.keysym.sym==SDLK_DELETE))
        {
            if(size_of_text_username>0)
            {
                size_of_text_username--;
                username_text[size_of_text_username]=' ';
            }
        }
        else if (ev.key.keysym.sym!=SDLK_SPACE)
        {
            char temp[40];
            for(int i=0;i<size_of_text_username+1;i++)
                temp[i]=username_text[i];
            temp[size_of_text_username+1]=(char)ev.key.keysym.sym;
            temp[size_of_text_username+2]='\0';
            TTF_SizeText(details_page_outline, temp, &usernametype_w, &usernametype_w);
            if(usernametype_w<600 * window_width/1920)
            {
                username_text[size_of_text_username]= (char)ev.key.keysym.sym;
                size_of_text_username++;
            }
        }
        TTF_SizeText(details_page,username_text,&usernametype_w,&usernametype_h);
    }
    else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
    {
        writing_mode_username=0;
        click_x=ev.button.x;
        click_y=ev.button.y;
        if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
            soundchange();
        else if(click_x>backbutton_target.x && click_x<backbutton_target.x+backbutton_target.w &&
                click_y<backbutton_target.y+backbutton_target.h && click_y>backbutton_target.y)
            page=0;
        else if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
        && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h && size_of_text_username>0)
            page1to10();
        else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
        {
            game_running=0;
            return;
        }
        else if(click_x>updownbutton_target.x && click_x<updownbutton_target.x + updownbutton_target.w
                && click_y>updownbutton_target.y && click_y<updownbutton_target.y + updownbutton_target.h/2 && number_of_enemies<6)
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

        else if(click_x>updownbutton_thi_target.x && click_x<updownbutton_thi_target.x + updownbutton_thi_target.w
                && click_y>updownbutton_thi_target.y && click_y<updownbutton_thi_target.y + updownbutton_thi_target.h/2)  
                number_of_nomansland++;
        else if(click_x>updownbutton_thi_target.x && click_x<updownbutton_thi_target.x + updownbutton_thi_target.w
                && click_y>updownbutton_thi_target.y + updownbutton_thi_target.h/2 && click_y<updownbutton_thi_target.y + updownbutton_thi_target.h && number_of_nomansland>0)
                number_of_nomansland--;

        else if(click_x>updownbutton_fou_target.x && click_x<updownbutton_fou_target.x + updownbutton_fou_target.w
                && click_y>updownbutton_fou_target.y && click_y<updownbutton_fou_target.y + updownbutton_fou_target.h/2)  
                max_troop_in_someones_land++;
        else if(click_x>updownbutton_fou_target.x && click_x<updownbutton_fou_target.x + updownbutton_fou_target.w
                && click_y>updownbutton_fou_target.y + updownbutton_fou_target.h/2 && click_y<updownbutton_fou_target.y + updownbutton_fou_target.h && max_troop_in_someones_land>0)
                max_troop_in_someones_land--;
   
        else if(click_x>updownbutton_fiv_target.x && click_x<updownbutton_fiv_target.x + updownbutton_fiv_target.w
                && click_y>updownbutton_fiv_target.y && click_y<updownbutton_fiv_target.y + updownbutton_fiv_target.h/2)  
                max_troop_no_mans_land++;
        else if(click_x>updownbutton_fiv_target.x && click_x<updownbutton_fiv_target.x + updownbutton_fiv_target.w
                && click_y>updownbutton_fiv_target.y + updownbutton_fiv_target.h/2 && click_y<updownbutton_fiv_target.y + updownbutton_fiv_target.h && max_troop_no_mans_land>0)
                max_troop_no_mans_land--;

        else if(click_x>updownbutton_six_target.x && click_x<updownbutton_six_target.x + updownbutton_six_target.w
                && click_y>updownbutton_six_target.y && click_y<updownbutton_six_target.y + updownbutton_six_target.h/2)  
                start_troop_in_someones_land++;
        else if(click_x>updownbutton_six_target.x && click_x<updownbutton_six_target.x + updownbutton_six_target.w
                && click_y>updownbutton_six_target.y + updownbutton_six_target.h/2 && click_y<updownbutton_six_target.y + updownbutton_six_target.h && start_troop_in_someones_land>0)
                start_troop_in_someones_land--;
        
        else if(click_x>updownbutton_sev_target.x && click_x<updownbutton_sev_target.x + updownbutton_sev_target.w
                && click_y>updownbutton_sev_target.y && click_y<updownbutton_sev_target.y + updownbutton_sev_target.h/2)  
                number_of_systems_of_the_user++;
        else if(click_x>updownbutton_sev_target.x && click_x<updownbutton_sev_target.x + updownbutton_sev_target.w
                && click_y>updownbutton_sev_target.y + updownbutton_sev_target.h/2 && click_y<updownbutton_sev_target.y + updownbutton_sev_target.h && number_of_systems_of_the_user>0)
                number_of_systems_of_the_user--;

        else if(click_x>updownbutton_eig_target.x && click_x<updownbutton_eig_target.x + updownbutton_eig_target.w
                && click_y>updownbutton_eig_target.y && click_y<updownbutton_eig_target.y + updownbutton_eig_target.h/2 && swap_char<6)
        {
            if(swap_char!=0)
                change_char(main_players_id,swap_char);
            swap_char++;
            change_char(main_players_id,swap_char);
        }
        else if(click_x>updownbutton_eig_target.x && click_x<updownbutton_eig_target.x + updownbutton_eig_target.w
                && click_y>updownbutton_eig_target.y + updownbutton_eig_target.h/2 && click_y<updownbutton_eig_target.y + updownbutton_eig_target.h && swap_char>0)
        {
            if(swap_char!=0)
                change_char(main_players_id,swap_char);
            swap_char--;
            change_char(main_players_id,swap_char);
        }

        else if(click_x>textbox_target.x && click_x<textbox_target.x + textbox_target.w
                && click_y>textbox_target.y && click_y<textbox_target.y + textbox_target.h)
                writing_mode_username=1;
    }
    if(click_x>backbutton_target.x && click_x<backbutton_target.x+backbutton_target.w && 
       click_y<backbutton_target.y+backbutton_target.h && click_y>backbutton_target.y)
        backbutton_x_y=(int)(50 * 1.2);
    else
        backbutton_x_y=50;
    if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
    && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
        start_game_x=(int)(327*(float)window_width/1335 * 1.1), start_game_y= (int)(37*(float)window_width/1335 * 1.1);
    else
        start_game_x=327*window_width/1335, start_game_y= 37*window_width/1335;
}
void page2()
{
    rendercpypage2();
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    SDL_WaitEvent(&ev);
    int click_x,click_y;
    SDL_GetMouseState(&click_x,&click_y);
    if(ev.type==SDL_QUIT)
    {
        game_running=0;
        return;
    }
    if(ev.type==SDL_KEYDOWN && writing_mode_map_select==1)
    {
        if((ev.key.keysym.sym==SDLK_BACKSPACE || ev.key.keysym.sym==SDLK_DELETE))
        {
            if(size_of_text_mapselect>0)
            {
                size_of_text_mapselect--;
                mapselect[size_of_text_mapselect]=' ';
            }
        }
        else if (ev.key.keysym.sym>='0' && ev.key.keysym.sym<='9')
        {
            char temp[40];
            for(int i=0;i<size_of_text_mapselect+1;i++)
                temp[i]=mapselect[i];
            temp[size_of_text_mapselect+1]=(char)ev.key.keysym.sym;
            temp[size_of_text_mapselect+2]='\0';
            TTF_SizeText(details_page_outline, temp, &mapsel_target.w, &mapsel_target.h);
            if(mapsel_target.w<600 * window_width/1920)
            {
                mapselect[size_of_text_mapselect]= (char)ev.key.keysym.sym;
                size_of_text_mapselect++;
            }
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
        {
            game_running=0;
            return;
        }
        else if(click_x>mapsel_target.x && click_x<mapsel_target.x + mapsel_target.w
                && click_y>mapsel_target.y && click_y<mapsel_target.y + mapsel_target.h)
            writing_mode_map_select=1;
        else if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
        && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h && size_of_text_mapselect>0)
            page2to10();   
    }
    if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
        backbutton_x_y=(int)(50 * 1.2);
    else
        backbutton_x_y=50;
    if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
    && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
        start_game_x=(int)(327*(float)window_width/1335 * 1.1), start_game_y= (int)(37*(float)window_width/1335 * 1.1);
    else
        start_game_x=327*window_width/1335, start_game_y= 37*window_width/1335;
}

void page3()
{
    rendercpypage3();
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    SDL_WaitEvent(&ev);
    int click_x,click_y;
    SDL_GetMouseState(&click_x,&click_y);
    if(ev.type==SDL_QUIT)
    {
        game_running=0;
        return;
    }
    if(ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_UP && leaderboard_page_y<-60)
        leaderboard_page_y+=5;
        
    else if(ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_DOWN && leaderboard_page_y>-100-(enemies_target.h*3/2*number_of_leaderboard_users-window_height))
        leaderboard_page_y-=5;
    else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
    {
        click_x=ev.button.x;
        click_y=ev.button.y;
        if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
            soundchange();
        else if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
        {
            page=0;
        }
        else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
        {
            game_running=0;
            return;
        }
    }
    if(click_x>25 && click_x<75 && click_y<75 && click_y>25)
        backbutton_x_y=(int)(50 * 1.2);
    else
        backbutton_x_y=50;
}

void page4()
{
    rendercpypage4();
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    SDL_WaitEvent(&ev);
    int click_x,click_y;
    SDL_GetMouseState(&click_x,&click_y);
    if(ev.type==SDL_QUIT)
    {
        game_running=0;
        return;
    }
    if(ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_UP && credits_text_loc_y<10)
        credits_text_loc_y+=10;
    else if(ev.type==SDL_KEYDOWN && ev.key.keysym.sym==SDLK_DOWN && credits_text_loc_y>15-(credits_text_y-window_height))
        credits_text_loc_y-=10;
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
        backbutton_x_y=(int)(50 * 1.2);
    else
        backbutton_x_y=50;
}


void page10()
{
    rendercpypage10();
    int click_x,click_y;
    SDL_GetMouseState(&click_x,&click_y);
    while(SDL_PollEvent(&ev))
    {
        if(ev.type==SDL_QUIT)
        {
            game_running=0;
            return;
        }
        if(ev.type==SDL_KEYDOWN)
        {
            if(ev.key.keysym.sym==SDLK_ESCAPE)
                is_first_clicked=0;
        }
        else if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
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
            else if (click_x>savebutton_target.x && click_x<savebutton_target.x + savebutton_target.w  
                && click_y>savebutton_target.y && click_y<savebutton_target.y + savebutton_target.h)
            {
                save_the_map();
                savebutton_target.w=(int)(savebutton_target.w*1.2);
                savebutton_target.h=(int)(savebutton_target.h*1.2);
            }
            else if(click_x > closebutton_target.x && click_x < closebutton_target.x + closebutton_target.w 
                    && click_y > closebutton_target.y && click_y < closebutton_target.y + closebutton_target.h)
            {
                game_running=0;
                return;
            }
            else if(click_y>size_of_wall_y && click_y<window_height-size_of_wall_y && is_first_clicked==0)
                is_first_clicked=findclickedcell(click_x,click_y,&first_click,1);
            else if(click_y>size_of_wall_y && click_y<window_height-size_of_wall_y && is_first_clicked==1)
            {
                int temp = findclickedcell(click_x,click_y,&second_click,0);
                if(temp)
                    create_moving_troopers(first_click,second_click);
                is_first_clicked=0;
            }
        }
    }
    create_kyber();
    moving_troopers_update_location();
    update_politic_sides_of_users();
    enemy_ai();
    upboard_setup();
    spell_type_two_endcheck();
    spell_type_three_endcheck();
    spell_type_five();
    if(did_win())
    {   
        did_win_int = 1;
        user_score = read_users_score(1,username_text);
        added_score = calculate_score();
        page=99;  
    }
    if(did_lose())
    {
        did_win_int = -1;
        user_score = read_users_score(1,username_text);
        added_score = calculate_score();
        page=99; 
    }
}
void winpage()
{
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    rendercpywinpage();
    SDL_WaitEvent(&ev);
    int click_x,click_y;
    SDL_GetMouseState(&click_x,&click_y);
    if(ev.type==SDL_QUIT)
    {
        game_running=0;
        return;
    }
    if(ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_LEFT)
    {
        click_x=ev.button.x;
        click_y=ev.button.y;
        if(click_x>5 && click_x<40 && click_y>window_height-40 && click_y<window_height-5)
            soundchange();
        else if(click_x>backbutton_target.x && click_x<backbutton_target.x+backbutton_target.w && click_y<backbutton_target.y+backbutton_target.h && click_y>backbutton_target.y)
        {
            Mix_PausedMusic();
            Mix_PlayMusic(menu_music,-1);
            page=0;
            return;
        }
        else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
        {
            game_running=0;
            return;
        }
    }
    if(click_x>backbutton_target.x && click_x<backbutton_target.x+backbutton_target.w && click_y<backbutton_target.y+backbutton_target.h && click_y>backbutton_target.y)
        backbutton_x_y=(int)(50*1.2);
    else
        backbutton_x_y=50;
}
void page1to10()
{
    time(&game_start_time);
    while(1)
    {
        create_cells();
        if(assign_politic_sides()==1)
            break;
    }

    save_the_map();
    first_user_save();
    Mix_PauseMusic();
    Mix_PlayMusic(game_music,-1);  
    page=10;

}
void page2to10()
{
    time(&game_start_time);
    load_the_map();
    Mix_PausedMusic();
    Mix_PlayMusic(game_music,-1);  
    page=10;
}


void pageto1()
{
    enemies_target.x = loc_number_of_enemies_x;
    enemies_target.y = loc_number_of_enemies_y + number_of_enemies_h + 10;
    enemies_target.w = number_of_enemies_w;
    enemies_target.h = number_of_enemies_h;
    username_target.x = loc_number_of_enemies_x;
    username_target.y = loc_number_of_enemies_y;
    username_target.w = usernametype_w;
    username_target.h = usernametype_h;
    page=1;
    char mapselectcpy[33]= "                                ";
    strcpy(username_text,mapselectcpy);
    size_of_text_username=0;
}

void pageto2()
{
    enemies_target.x = loc_number_of_enemies_x;
    enemies_target.y = loc_number_of_enemies_y;
    page=2;
    char mapselectcpy[33]= "                                ";
    strcpy(mapselect,mapselectcpy);
    size_of_text_mapselect=0;
    findtotalofsaves();
}