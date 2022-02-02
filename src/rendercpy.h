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
    SDL_Texture *newgame_texture = SDL_CreateTextureFromSurface(renderer, new_game);
    SDL_RenderCopy(renderer, newgame_texture, NULL, &new_game_target);
    SDL_Texture *loadgame_texture = SDL_CreateTextureFromSurface(renderer, load_game);
    SDL_RenderCopy(renderer, loadgame_texture, NULL, &load_game_target);
    SDL_Texture *leaderboard_texture = SDL_CreateTextureFromSurface(renderer, leaderboard);
    SDL_RenderCopy(renderer, leaderboard_texture, NULL, &leaderboard_target);
    SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_Texture *creditstexture = SDL_CreateTextureFromSurface(renderer, credits_button);
    SDL_RenderCopy(renderer, creditstexture, NULL, &credits_target);
    SDL_Texture *closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(newgame_texture);
    SDL_DestroyTexture(loadgame_texture);
    SDL_DestroyTexture(leaderboard_texture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(creditstexture);
    SDL_DestroyTexture(closebutton_texture);
}
void rendercpypage1()
{
    start_game_target.x = window_width - 150*window_width/1335 -start_game_x/2;
    start_game_target.y = window_height - 50*window_height/801 - start_game_y/2;
    start_game_target.w = start_game_x;
    start_game_target.h = start_game_y;
    
    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, new_game_background);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_Texture *backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_Texture *startgametexture = SDL_CreateTextureFromSurface(renderer, startgame);
    SDL_RenderCopy(renderer, startgametexture, NULL, &start_game_target);
    SDL_Texture *closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_Texture *updownbutton_texture = SDL_CreateTextureFromSurface(renderer, updownbutton);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_target);
    SDL_Texture *updownbutton_sec_texture = SDL_CreateTextureFromSurface(renderer, updownbutton);
    SDL_RenderCopy(renderer, updownbutton_sec_texture, NULL, &updownbutton_sec_target);

    char test[22];
    sprintf(test,"number of enemies: %d",number_of_enemies);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    SDL_Surface *textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    enemies_target.y+=2, enemies_target.x+=2;

    TTF_SizeText(details_page, test, &enemies_target.w, &enemies_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    SDL_FreeSurface(textsurface);
    enemies_target.y-=2, enemies_target.x-=2;

    char test2[33];
    sprintf(test2, "number of systems per player: %d",number_of_politic_sides_per_user);
    TTF_SizeText(details_page_outline, test2, &per_user_target.w, &per_user_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,test2, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&per_user_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    per_user_target.y+=2, per_user_target.x+=2;

    TTF_SizeText(details_page, test2, &per_user_target.w, &per_user_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test2, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&per_user_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    per_user_target.y-=2, per_user_target.x-=2;

    TTF_SizeText(details_page_outline, test3, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,test3, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    username_target.y+=2, username_target.x+=2;

    TTF_SizeText(details_page, test3, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test3, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    username_target.y-=2, username_target.x-=2;


    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
    SDL_DestroyTexture(startgametexture);
    SDL_DestroyTexture(closebutton_texture);
    SDL_DestroyTexture(updownbutton_texture);
    SDL_DestroyTexture(updownbutton_sec_texture);
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

    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, padmegrave1);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_Texture *backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_Texture *closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target); 
    SDL_Texture *startgametexture = SDL_CreateTextureFromSurface(renderer, startgame);
    SDL_RenderCopy(renderer, startgametexture, NULL, &start_game_target);
    char test[60];
    sprintf(test, "there are %d maps. select one of them:", mapnumsel);

    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    SDL_Surface *textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);

    enemies_target.y+=2, enemies_target.x+=2;
    TTF_SizeText(details_page, test, &enemies_target.w, &enemies_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);

    TTF_SizeText(details_page_outline, mapselect, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,mapselect, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);

    username_target.y+=2, username_target.x+=2;
    TTF_SizeText(details_page, mapselect, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page,mapselect, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startgametexture);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
}
void rendercpypage4()
{
    SDL_Rect backbutton_target = {50 - backbutton_x_y/2 , 50 - backbutton_x_y/2, backbutton_x_y, backbutton_x_y};
    SDL_Rect credits_text_target = {window_width/2 - credits_text_x/2 , credits_text_loc_y, credits_text_x, credits_text_y};
    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, padmegrave2);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_Texture *backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_Texture *creditstext_texture = SDL_CreateTextureFromSurface(renderer, credits_text);
    SDL_RenderCopy(renderer, creditstext_texture, NULL, &credits_text_target);

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
    SDL_DestroyTexture(creditstext_texture);
}
void rendercpypage10()
{
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
    SDL_Texture *startgametexture;
    SDL_Texture *leaders_faces_texture;
    for(int i=0;i<size_of_politic_sides;i++)
    {
        leaders_faces_texture = SDL_CreateTextureFromSurface(renderer, faces[politic_sides[i].player_id]);
        startgametexture = SDL_CreateTextureFromSurface(renderer, planets_photos[politic_sides[i].player_id]);
        for(int j=0;j<politic_sides[i].size_of_cells;j++)
        {
            int x = politic_sides[i].cells_x[j], y = politic_sides[i].cells_y[j];
            SDL_Rect cell_target = {cells[x][y].x , cells[x][y].y, size_of_each_cell_x, size_of_each_cell_y};
            SDL_RenderCopy(renderer, startgametexture, NULL, &cell_target);
            if(j==0)
            {
                SDL_Rect leader_target = {cells[x][y].x+ size_of_each_cell_x/2 - size_of_leaders_x_y/2, cells[x][y].y + size_of_each_cell_y*1/10, size_of_leaders_x_y, size_of_leaders_x_y};
                SDL_RenderCopy(renderer, leaders_faces_texture, NULL, &leader_target);
                SDL_Rect temp_trooper_target = leader_target;
                SDL_Color white = {255,255,255,255};
                int w,h;
                TTF_SizeText(number_of_soldiers,"100",&w,&h);
                if(difftime(time_now,start_time)>=1 && ((politic_sides[i].player_id==10 && politic_sides[i].number_of_troopers<max_troop_no_mans_land) || (politic_sides[i].player_id!=10 && politic_sides[i].number_of_troopers<max_troop_in_someones_land)))
                {
                    politic_sides[i].number_of_troopers+=difftime(time_now,start_time);
                    if(politic_sides[i].player_id==10 && politic_sides[i].number_of_troopers>max_troop_no_mans_land)
                    {
                        politic_sides[i].number_of_troopers = max_troop_no_mans_land;
                    }
                    if(politic_sides[i].player_id!=10 && politic_sides[i].number_of_troopers>max_troop_in_someones_land)
                    {
                        politic_sides[i].number_of_troopers = max_troop_in_someones_land;
                    }
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
                leader_target.x += size_of_leaders_x_y/2 - w/2;
                leader_target.y += size_of_leaders_x_y-5;
                SDL_Surface *textsurface = TTF_RenderText_Solid(number_of_soldiers_outline,test, black);
                SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
                leader_target.y-=2, leader_target.x-=2, leader_target.w+=4;
                SDL_RenderCopy(renderer,text_texture,NULL,&leader_target);
                leader_target.y+=2, leader_target.x+=2, leader_target.w-=4;
                SDL_DestroyTexture(text_texture);
                SDL_FreeSurface(textsurface);
                textsurface = TTF_RenderText_Solid(number_of_soldiers,test, white);
                text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
                SDL_RenderCopy(renderer,text_texture,NULL,&leader_target);
                SDL_DestroyTexture(text_texture);
                SDL_FreeSurface(textsurface);
            }
        }   
        SDL_DestroyTexture(leaders_faces_texture);
        SDL_DestroyTexture(startgametexture);
    }
    int rand_to_do_kyber = rand()%300;
    for(int i=0; i<size_of_kybers;i++)
    {
        SDL_Rect kyber_target = {kybers[i].x, kybers[i].y, size_of_kyber_photo_x, size_of_kyber_photo_y};
        SDL_Texture *kybertexture = SDL_CreateTextureFromSurface(renderer, kyber_cristal_photos[kybers[i].type]);
        SDL_RenderCopy(renderer, kybertexture, NULL, &kyber_target);
        SDL_DestroyTexture(kybertexture);
    }
    for(int j =0 ;j<size_of_politic_sides;j++)
    {
        if(politic_sides[j].number_of_moving_troppers==0)
            continue;
        SDL_Texture *movingtrooper_texture = SDL_CreateTextureFromSurface(renderer, troopers[politic_sides[j].troopers[0].player_id]);
        for(int i = 0 ; i<politic_sides[j].number_of_moving_troppers ; i++)
        {
            if(politic_sides[j].troopers[i].is_out==0 || politic_sides[j].troopers[i].did_end==1)
                continue;
            SDL_Rect movingtrooper_target = {politic_sides[j].troopers[i].current_x, politic_sides[j].troopers[i].current_y, size_of_troopers_x_y, size_of_troopers_x_y};
            SDL_RenderCopy(renderer, movingtrooper_texture, NULL, &movingtrooper_target);
        }
        SDL_DestroyTexture(movingtrooper_texture);
    }
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
        kybers[size_of_kybers].type = rand()%4;
        size_of_kybers++;
    }
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(walltexture);
    SDL_DestroyTexture(wallflippedtexture);
    SDL_DestroyTexture(backtomenutexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(closebutton_texture);
}