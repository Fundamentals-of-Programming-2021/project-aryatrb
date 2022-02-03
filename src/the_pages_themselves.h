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
            {
                game_running=0;
                return;
            }
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
        if((ev.key.keysym.sym==SDLK_BACKSPACE || ev.key.keysym.sym==SDLK_DELETE) && size_of_text_username>0)
        {
            size_of_text_username--;
            username_text[size_of_text_username]='.';
        }
        else
        {
            username_text[size_of_text_username]= ev.key.keysym.sym;
            size_of_text_username++;
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
        && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
            page1to10();
        else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
        {
            game_running=0;
            return;
        }
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
    if(click_x>backbutton_target.x && click_x<backbutton_target.x+backbutton_target.w && 
       click_y<backbutton_target.y+backbutton_target.h && click_y>backbutton_target.y)
        backbutton_x_y=50 * 1.2;
    else
        backbutton_x_y=50;
    if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
    && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
        start_game_x=327*window_width/1335 * 1.1, start_game_y= 37*window_width/1335 * 1.1;
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
        {
            game_running=0;
            return;
        }
        else if(click_x>username_target.x && click_x<username_target.x + username_target.w
                && click_y>username_target.y + username_target.h/2 && click_y<username_target.y + username_target.h)
            writing_mode_map_select=1;
        else if(click_x>start_game_target.x && click_x<start_game_target.x + start_game_target.w 
        && click_y>start_game_target.y && click_y<start_game_target.y + start_game_target.h)
        {
            time(&game_start_time);
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
                return;
            }
            else if(click_y>40 && click_y<window_height-40 && is_first_clicked==0)
                is_first_clicked=findclickedcell(click_x,click_y,&first_click,1);
            else if(click_y>40 && click_y<window_height-40 && is_first_clicked==1)
            {
                int temp = findclickedcell(click_x,click_y,&second_click,0);
                if(politic_sides[second_click].number_of_moving_troppers!=0)
                    stop_the_moving_troopers__new_destination(first_click);
                if(temp)
                    create_moving_troopers(first_click,second_click);
            }
        }
    }
    create_kyber();
    moving_troopers_update_location();
    moving_troopers_without_a_home_update_location();
    update_politic_sides_of_users();
    enemy_ai();
    if(did_win()==1)
    {   
        did_win_int = 1;
        user_score = read_users_score(1);
        added_score = calculate_score();
        page=99;  
    }
    if(did_lose())
    {
        did_win_int = -1;
        user_score = read_users_score(1);
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
            page=0;
        else if(click_x>closebutton_target.x && click_x<closebutton_target.x + closebutton_target.w 
                && click_y>closebutton_target.y && click_y<closebutton_target.y + closebutton_target.h)
        {
            game_running=0;
            return;
        }
    }
    if(click_x>backbutton_target.x && click_x<backbutton_target.x+backbutton_target.w && click_y<backbutton_target.y+backbutton_target.h && click_y>backbutton_target.y)
        backbutton_x_y=50*1.2;
    else
        backbutton_x_y=50;
}
void page1to10()
{
    time(&game_start_time);
    create_cells();
    assign_politic_sides();
    save_the_map();
    first_user_save();
    Mix_PauseMusic();
    Mix_PlayMusic(game_music,-1);  
    page=10;
    for(int i=0;i<number_of_enemies+1;i++)
    {
        movingtrooper_texture[i]=SDL_CreateTextureFromSurface(renderer, troopers[i]);
    }    
}

