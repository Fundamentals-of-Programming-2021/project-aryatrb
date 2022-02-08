
#include "load_everything.h"
#include "time.h"
void rendercpypage0()
{
    new_game_target.x = window_width/2 - size_new_game_x/2;
    new_game_target.y = window_height/2 + window_height/2*160/300 - size_new_game_y/2;
    new_game_target.w = size_new_game_x;
    new_game_target.h = size_new_game_y;
    load_game_target.x = window_width/2 - size_load_game_x/2;
    load_game_target.y = window_height/2 + window_height/2*205/300 - size_load_game_y/2;
    load_game_target.w = size_load_game_x;
    load_game_target.h = size_load_game_y;
    leaderboard_target.x = window_width/2 - leaderboard_game_x/2;
    leaderboard_target.y = window_height/2 + window_height/2*250/300 - leaderboard_game_y/2;
    leaderboard_target.w = leaderboard_game_x;
    leaderboard_target.h = leaderboard_game_y;
    credits_target.x = 180*window_width/1335 - size_credits_x/2;
    credits_target.y = window_height -50*window_width/1335 - size_credits_y/2;
    credits_target.w = size_credits_x;
    credits_target.h = size_credits_y;
    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, startbackground);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, newgame_texture, NULL, &new_game_target);
    SDL_RenderCopy(renderer, loadgame_texture, NULL, &load_game_target);
    SDL_RenderCopy(renderer, leaderboard_texture, NULL, &leaderboard_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_RenderCopy(renderer, creditstexture, NULL, &credits_target);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
}

void rendercpypage1text(char text[],SDL_Surface *textsurface,SDL_Texture *text_texture ,SDL_Rect *target)
{
    TTF_SizeText(details_page_outline, text, &target->w, &target->h);
    textsurface = TTF_RenderText_Solid(details_page_outline,text, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    target->y+=2, target->x+=2;

    TTF_SizeText(details_page, text, &target->w, &target->h);
    textsurface = TTF_RenderText_Solid(details_page,text, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    target->y-=2, target->x-=2;
}
void rendercpypage1()
{
    start_game_target.x = window_width - 150*window_width/1335 -start_game_x/2;
    start_game_target.y = window_height - 50*window_height/801 - start_game_y/2;
    start_game_target.w = start_game_x;
    start_game_target.h = start_game_y;

    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;
    
    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, new_game_background);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_RenderCopy(renderer, startgametexture, NULL, &start_game_target);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_sec_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_thi_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_fou_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_fiv_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_six_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_sev_target);
    SDL_Surface *textsurface;
    SDL_Texture *text_texture;
    char test[100];
    sprintf(test,"number of enemies: %d",number_of_enemies);
    rendercpypage1text(test,textsurface,text_texture,&enemies_target);
    sprintf(test, "number of systems per player: %d",number_of_politic_sides_per_user);
    rendercpypage1text(test,textsurface,text_texture,&per_user_target);
    sprintf(test, "number of no man's land: %d",number_of_nomansland);
    rendercpypage1text(test,textsurface,text_texture,&number_of_nomansland_target);
    sprintf(test, "username: ");
    rendercpypage1text(test,textsurface,text_texture,&username_target);
    int temp_w= username_target.w;
    username_target.x +=temp_w;
    textbox_target = username_target, textbox_target.w = 600 * window_width/1920, textbox_target.h *=1.2, textbox_target.x*=0.97;
    SDL_RenderCopy(renderer, textbox_texture, NULL, &textbox_target);
    rendercpypage1text(username_text,textsurface,text_texture,&username_target);
    username_target.x-=temp_w;
    sprintf(test, "max troopers in a players planet: %d",max_troop_in_someones_land);
    rendercpypage1text(test,textsurface,text_texture,&maxtrooperinplayers_house);
    sprintf(test, "max troopers in no man's land: %d",max_troop_no_mans_land);
    rendercpypage1text(test,textsurface,text_texture,&maxtrooperinnomansland_target);
    sprintf(test, "number of troopers the land has in the beginning: %d",start_troop_in_someones_land);
    rendercpypage1text(test,textsurface,text_texture,&start_troop_insomo_la_target);
    sprintf(test, "number of systems of the main player: %d",number_of_systems_of_the_user);
    rendercpypage1text(test,textsurface,text_texture,&number_of_systems_of_user_target);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
}
void rendercpypage2()
{
    start_game_target.x = window_width - 150*window_width/1335 -start_game_x/2;
    start_game_target.y = window_height - 50*window_height/801 - start_game_y/2;
    start_game_target.w = start_game_x;
    start_game_target.h = start_game_y;

    username_target.x = loc_number_of_enemies_x;
    username_target.y = loc_number_of_enemies_y + 2* (number_of_enemies_h + 10);
    username_target.w = mapseltype_w;
    username_target.h = mapseltype_h;

    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;

    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, padmegrave1);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target); 
    SDL_Texture *startgametexture = SDL_CreateTextureFromSurface(renderer, startgame);
    SDL_RenderCopy(renderer, startgametexture, NULL, &start_game_target);
    SDL_Surface *textsurface;
    SDL_Texture *text_texture;
    char test[60];
    sprintf(test, "there are %d maps. select one of them:", mapnumsel);
    rendercpypage1text(test,textsurface,text_texture,&enemies_target);
    int temp_w= username_target.w;    
    textbox_target = username_target;
    textbox_target.w = 600 * window_width/1920;
    textbox_target.h *=1.2;
    SDL_RenderCopy(renderer, textbox_texture, NULL, &textbox_target);
    mapsel_target=username_target;
    mapsel_target.x*=1.08;
    rendercpypage1text(mapselect,textsurface,text_texture,&mapsel_target);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startgametexture);
    SDL_DestroyTexture(startscreentexture);
}
void rendercpypage3text(char text[],SDL_Surface *textsurface,SDL_Texture *text_texture ,SDL_Rect *target)
{
    textsurface = TTF_RenderText_Solid(details_page_outline,text, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    target->y+=2, target->x+=2;

    TTF_SizeText(details_page, text, &target->w, &target->h);
    textsurface = TTF_RenderText_Solid(details_page,text, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    target->y-=2, target->x-=2;
}
void rendercpypage3()
{
    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;

    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, leaderboardbackground);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target); 
    char test[150];
    SDL_Surface *textsurface;
    SDL_Texture *text_texture;
    for(int i=0;i<number_of_leaderboard_users;i++)
    {
        sprintf(test, "%d. %s",i+1,leaderboard_users[i].name);
        TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);  
        enemies_target.x = window_width*1/10;
        enemies_target.y = enemies_target.h*3/2*(i+1) + leaderboard_page_y;      
        rendercpypage3text(test,textsurface,text_texture,&enemies_target);
    }
    for(int i=0;i<number_of_leaderboard_users;i++)
    {
        sprintf(test, "%d",leaderboard_users[i].score);
        TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);        
        enemies_target.x = window_width*9/10 - enemies_target.w/2;
        enemies_target.y = enemies_target.h*3/2*(i+1) + leaderboard_page_y;
        rendercpypage3text(test,textsurface,text_texture,&enemies_target);
    }
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
}
void rendercpypage4()
{
    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;
    SDL_Rect credits_text_target = {window_width/2 - credits_text_x/2 , credits_text_loc_y, credits_text_x, credits_text_y};
    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, padmegrave2);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_RenderCopy(renderer, creditstext_texture, NULL, &credits_text_target);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
}
void rendercpypage10()
{
    savebutton_target.x = window_width - 60*window_width/1920 - savebutton_target.w;
    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, starsbackground);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, walltexture, NULL, &wall_target);
    SDL_RenderCopy(renderer, wallflippedtexture, NULL, &wallflipped_target);
    SDL_RenderCopy(renderer, backtomenutexture, NULL, &backtomenu_target);
    SDL_RenderCopy(renderer, savebuttontexture, NULL, &savebutton_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_Rect upboard_target = {window_width*0.2, size_of_wall_y*0.1,window_width*0.6,size_of_wall_y*0.8};
    SDL_Rect temp_target = upboard_target;
    temp_target.x = window_width*0.10;
    temp_target.w= upboard_target.x-temp_target.x;
    SDL_RenderCopy(renderer, handletexture, NULL, &temp_target);
    int k=0;
    for(int i=0;i<15;i++)
    {
        upboard_target.x = window_width*0.2 + window_width*0.6*(double)((double)k/(double)total_of_soldiers_in_map);
        k+=upboardwidth[i];
        upboard_target.w= (window_width*0.8) - upboard_target.x;
        SDL_RenderCopy(renderer, upboardcolortexture[i], NULL, &upboard_target);
    }
    for(int i=0;i<size_of_politic_sides;i++)
    {
        for(int j=politic_sides[i].size_of_cells-1;j>=0;j--)
        {
            int x = politic_sides[i].cells_x[j], y = politic_sides[i].cells_y[j];
            SDL_Rect cell_target = {cells[x][y].x , cells[x][y].y, size_of_each_cell_x, size_of_each_cell_y};
            if(i==main_players_id && is_first_clicked==1 && j==0)
            {
                cell_target.w*=1.2;
                cell_target.h*=1.2;
                cell_target.x-=0.1*size_of_each_cell_x;
                cell_target.y-=0.1*size_of_each_cell_y;
            }
            SDL_RenderCopy(renderer, planetphotostexture[politic_sides[i].player_id], NULL, &cell_target);
            if(j==0)
            {
                SDL_Rect leader_target = {cells[x][y].x+ size_of_each_cell_x/2 - size_of_leaders_x_y/2, cells[x][y].y + size_of_each_cell_y*1/10, size_of_leaders_x_y, size_of_leaders_x_y};
                SDL_RenderCopy(renderer, facestexture[politic_sides[i].player_id], NULL, &leader_target);
                SDL_Rect temp_trooper_target = leader_target;
                SDL_Color white = {255,255,255,255};
                int w,h;
                TTF_SizeText(number_of_soldiers,"100",&w,&h);
                if(difftime(time_now,start_time)>=1 && politic_sides[i].player_id!=nomansland_playerid &&
                ((politic_sides[i].player_id==nomansland_playerid && politic_sides[i].number_of_troopers<max_troop_no_mans_land) || (politic_sides[i].player_id!=nomansland_playerid && politic_sides[i].number_of_troopers<max_troop_in_someones_land)))
                {
                    spell_type_four(politic_sides[i].player_id);
                    politic_sides[i].number_of_troopers+=difftime(time_now,start_time) * players[politic_sides[i].player_id].create_trooper_rate;
                    if(politic_sides[i].player_id==nomansland_playerid && politic_sides[i].number_of_troopers>max_troop_no_mans_land)
                        politic_sides[i].number_of_troopers = max_troop_no_mans_land;
                    if(politic_sides[i].player_id!=nomansland_playerid && politic_sides[i].number_of_troopers>max_troop_in_someones_land)
                        politic_sides[i].number_of_troopers = max_troop_in_someones_land;
                }
                char test[4];
                if(politic_sides[i].number_of_troopers<0)
                {
                    int a=0;
                    sprintf(test, "%d", a);
                }
                else
                    sprintf(test, "%d", politic_sides[i].number_of_troopers);
                leader_target.h = h;
                leader_target.w = w;
                leader_target.x += size_of_leaders_x_y/2;
                leader_target.y += size_of_leaders_x_y-5;
                TTF_SizeText(number_of_soldiers_outline, test, &leader_target.w, &leader_target.h);
                leader_target.x -=leader_target.w/2;
                SDL_Surface *textsurface = TTF_RenderText_Solid(number_of_soldiers_outline,test, black);
                SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
                SDL_RenderCopy(renderer,text_texture,NULL,&leader_target);
                SDL_DestroyTexture(text_texture);
                SDL_FreeSurface(textsurface);
                leader_target.y+=2, leader_target.x+=2;
                TTF_SizeText(number_of_soldiers, test, &leader_target.w, &leader_target.h);
                textsurface = TTF_RenderText_Solid(number_of_soldiers,test, white);
                text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
                SDL_RenderCopy(renderer,text_texture,NULL,&leader_target);
                SDL_DestroyTexture(text_texture);
                SDL_FreeSurface(textsurface);
                leader_target.y-=2, leader_target.x-=2;
            }
        }   
        savebutton_target.w = size_of_wall_y*0.8*700/298;
        savebutton_target.h = size_of_wall_y*0.8;
    }
    for(int i=0; i<size_of_kybers;i++)
    {
        if(kybers[i].is_dead==1)
            continue;
        SDL_Rect kyber_target = {kybers[i].x, kybers[i].y, size_of_kyber_photo_x, size_of_kyber_photo_y};
        if(kybers[i].is_on==0)
            SDL_RenderCopy(renderer, kybertexture[kybers[i].type], NULL, &kyber_target);
        else
        {
            kyber_target.w *=2;
            kyber_target.h *=2;
            kyber_target.x -=size_of_kyber_photo_x/2;
            kyber_target.y -=size_of_kyber_photo_y/2;
            SDL_RenderCopy(renderer, kyberontexture[kybers[i].type], NULL, &kyber_target);
            kyber_target.w = 24*1920/window_width;
            kyber_target.h = 5.5*kyber_target.w;
            SDL_RenderCopy(renderer,kybersabertexture[kybers[i].player_id],NULL,&kyber_target);
        }
    }
    for(int j =0 ;j<size_of_politic_sides;j++)
    {
        if(politic_sides[j].id_of_moving_troppers==0 || politic_sides[j].player_id==nomansland_playerid)
            continue;
        for(int i = 0 ; i<politic_sides[j].id_of_moving_troppers ; i++)
        {
            if(politic_sides[j].troopers[i].is_out==0 || politic_sides[j].troopers[i].did_end==1)
                continue;
            SDL_Rect movingtrooper_target = {politic_sides[j].troopers[i].current_x, politic_sides[j].troopers[i].current_y, size_of_troopers_x_y, size_of_troopers_x_y};
            SDL_RenderCopy(renderer, movingtrooper_texture[politic_sides[j].troopers[0].player_id], NULL, &movingtrooper_target);
        }
    }
    for(int j=0;j<size_of_troops_with_no_home;j++)
    {
        if(troops_with_no_home[j].is_out==0 || troops_with_no_home[j].did_end==1)
            continue;
        SDL_Rect movingtrooper_target = {troops_with_no_home[j].current_x, troops_with_no_home[j].current_y, size_of_troopers_x_y, size_of_troopers_x_y};
        SDL_RenderCopy(renderer, movingtrooper_texture[troops_with_no_home[j].player_id], NULL, &movingtrooper_target);
    }
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
}
void rendercpywinpage()
{
    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;
    SDL_Texture *startscreentexture;
    startscreentexture = SDL_CreateTextureFromSurface(renderer, winbackground);
    if(did_win_int==-1)
        startscreentexture = SDL_CreateTextureFromSurface(renderer, losebackground);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    if(did_win_int==1)
    {
        SDL_Rect ifyoudefine_target = {window_width/2 - ifyoudefine_x/2 , 20, ifyoudefine_x, ifyoudefine_y};
        SDL_RenderCopy(renderer, quote_texture, NULL, &ifyoudefine_target);
    }
    else
    {
        SDL_Rect doordonot_target = {window_width/2 - doordonot_x/2 , 20, doordonot_x, doordonot_y};
        SDL_RenderCopy(renderer, doordonot_texture, NULL, &doordonot_target);
    }
    char test[150];
    SDL_Surface *textsurface;
    SDL_Texture *text_texture;
    if(did_win_int==-1)
    {
        sprintf(test, "you lost!");
        TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);        
        enemies_target.x = window_width/2 - enemies_target.w/2;
        enemies_target.y = window_height/2 - enemies_target.h/2 - enemies_target.h*3/2;
        rendercpypage3text(test,textsurface,text_texture,&enemies_target);
    }
    sprintf(test, "game duration: %d minutes",(int)difftime(calc_time,game_start_time)/60);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    enemies_target.x = window_width/2 - enemies_target.w/2;
    enemies_target.y = window_height/2 - enemies_target.h/2;
    rendercpypage3text(test,textsurface,text_texture,&enemies_target);

    sprintf(test, "your score from this game: %d",added_score);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    enemies_target.x = window_width/2 - enemies_target.w/2;
    enemies_target.y = window_height/2 - enemies_target.h/2 + enemies_target.h*3/2;
    rendercpypage3text(test,textsurface,text_texture,&enemies_target);

    sprintf(test, "your total score: %d",user_score);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    enemies_target.x = window_width/2 - enemies_target.w/2;
    enemies_target.y = window_height/2 - enemies_target.h/2 + enemies_target.h*3;
    rendercpypage3text(test,textsurface,text_texture,&enemies_target);

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
}
void pageminusone()
{
    struct timeval time_tea;
    gettimeofday(&time_tea,NULL);
    long long int diff=(time_tea.tv_sec-the_begin.tv_sec)*1000000 + time_tea.tv_usec - the_begin.tv_usec;
    SDL_Delay(40);
    if(diff>43000000)
    {
        Mix_PausedMusic();
        Mix_PlayMusic(menu_music,-1);
        page=0;
        return;
    }
    if(diff<2000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<5000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff-2000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<9000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogo);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<12000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 9000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<15000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogobef);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 12000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }

    else if(diff<18000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 15000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<22000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogo);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }

    else if(diff<25000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 22000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<28000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 25000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<32000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogo);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<36000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 32000000)*255/4000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<39000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, menubef);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        diff/=10000;
        int temp=(diff - 3600)*255/300;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<43000000)
    {
        diff/=10000;
        int temp=(diff - 3900)*255/400;
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, menubef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, menubefwithlogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_DestroyTexture(startscreentexture);
        SDL_RenderPresent(renderer);
    }
}