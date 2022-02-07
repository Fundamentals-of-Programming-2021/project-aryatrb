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

    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;
    
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
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_sec_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_thi_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_fou_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_fiv_target);
    SDL_RenderCopy(renderer, updownbutton_texture, NULL, &updownbutton_six_target);
    SDL_DestroyTexture(updownbutton_texture);

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

    char test2[70];
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

    sprintf(test2, "number of no man's land: %d",number_of_nomansland);
    TTF_SizeText(details_page_outline, test2, &number_of_nomansland_target.w, &number_of_nomansland_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,test2, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&number_of_nomansland_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    number_of_nomansland_target.y+=2, number_of_nomansland_target.x+=2;

    TTF_SizeText(details_page, test2, &number_of_nomansland_target.w, &number_of_nomansland_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test2, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&number_of_nomansland_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    number_of_nomansland_target.y-=2, number_of_nomansland_target.x-=2;


    char text_temp[13] = "username: ";
    TTF_SizeText(details_page_outline, text_temp, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,text_temp, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    username_target.y+=2, username_target.x+=2;

    TTF_SizeText(details_page, text_temp, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page,text_temp, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer, text_texture, NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    username_target.y-=2, username_target.x-=2;
    int temp_w= username_target.w;
    
    username_target.x +=temp_w;
    textbox_target = username_target;
    textbox_target.w = 600 * window_width/1920;
    textbox_target.h *=1.2;
    textbox_target.x*=0.97;
    SDL_Texture *textbox_texture = SDL_CreateTextureFromSurface(renderer, textbox);
    SDL_RenderCopy(renderer, textbox_texture, NULL, &textbox_target);
    SDL_DestroyTexture(textbox_texture);

    TTF_SizeText(details_page_outline, username_text, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,username_text, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    username_target.y+=2, username_target.x+=2;

    TTF_SizeText(details_page, username_text, &username_target.w, &username_target.h);
    textsurface = TTF_RenderText_Solid(details_page,username_text, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    username_target.y-=2, username_target.x-=2;
    username_target.x-=temp_w;

    sprintf(test2, "max troopers in a players planet: %d",max_troop_in_someones_land);
    TTF_SizeText(details_page_outline, test2, &maxtrooperinplayers_house.w, &maxtrooperinplayers_house.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,test2, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&maxtrooperinplayers_house);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    maxtrooperinplayers_house.y+=2, maxtrooperinplayers_house.x+=2;

    TTF_SizeText(details_page, test2, &maxtrooperinplayers_house.w, &maxtrooperinplayers_house.h);
    textsurface = TTF_RenderText_Solid(details_page,test2, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer, text_texture, NULL,&maxtrooperinplayers_house);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    maxtrooperinplayers_house.y-=2, maxtrooperinplayers_house.x-=2;

    sprintf(test2, "max troopers in no man's land: %d",max_troop_no_mans_land);
    TTF_SizeText(details_page_outline, test2, &maxtrooperinnomansland_target.w, &maxtrooperinnomansland_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,test2, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&maxtrooperinnomansland_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    maxtrooperinnomansland_target.y+=2, maxtrooperinnomansland_target.x+=2;

    TTF_SizeText(details_page, test2, &maxtrooperinnomansland_target.w, &maxtrooperinnomansland_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test2, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer, text_texture, NULL,&maxtrooperinnomansland_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    maxtrooperinnomansland_target.y-=2, maxtrooperinnomansland_target.x-=2;

    sprintf(test2, "number of troopers the land has in the beginning: %d",start_troop_in_someones_land);
    TTF_SizeText(details_page_outline, test2, &start_troop_insomo_la_target.w, &start_troop_insomo_la_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,test2, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&start_troop_insomo_la_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    start_troop_insomo_la_target.y+=2, start_troop_insomo_la_target.x+=2;

    TTF_SizeText(details_page, test2, &start_troop_insomo_la_target.w, &start_troop_insomo_la_target.h);
    textsurface = TTF_RenderText_Solid(details_page,test2, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer, text_texture, NULL,&start_troop_insomo_la_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    start_troop_insomo_la_target.y-=2, start_troop_insomo_la_target.x-=2;
    

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
    SDL_DestroyTexture(startgametexture);
    SDL_DestroyTexture(closebutton_texture);
    SDL_DestroyTexture(updownbutton_texture);
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
    enemies_target.y-=2, enemies_target.x-=2;

    int temp_w= username_target.w;    
    textbox_target = username_target;
    textbox_target.w = 600 * window_width/1920;
    textbox_target.h *=1.2;
    // textbox_target.x*=0.97;
    SDL_Texture *textbox_texture = SDL_CreateTextureFromSurface(renderer, textbox);
    SDL_RenderCopy(renderer, textbox_texture, NULL, &textbox_target);
    SDL_DestroyTexture(textbox_texture);
    mapsel_target=username_target;
    mapsel_target.x*=1.08;
    TTF_SizeText(details_page_outline, mapselect, &mapsel_target.w, &mapsel_target.h);
    textsurface = TTF_RenderText_Solid(details_page_outline,mapselect, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&mapsel_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    mapsel_target.y+=2, mapsel_target.x+=2;
    TTF_SizeText(details_page, mapselect, &mapsel_target.w, &mapsel_target.h);
    textsurface = TTF_RenderText_Solid(details_page,mapselect, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&mapsel_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    mapsel_target.y-=2, mapsel_target.x-=2;
    
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startgametexture);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
}
void rendercpypage3()
{
    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;

    SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, leaderboardbackground);
    SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
    SDL_Texture *backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    SDL_Texture *closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
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
        textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
        text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
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
    }
    for(int i=0;i<number_of_leaderboard_users;i++)
    {
        sprintf(test, "%d",leaderboard_users[i].score);
        TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);        
        enemies_target.x = window_width*9/10 - enemies_target.w/2;
        enemies_target.y = enemies_target.h*3/2*(i+1) + leaderboard_page_y;
        textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
        text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
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
    }


    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
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
    SDL_Rect upboard_target = {window_width*0.2, size_of_wall_y*0.1,window_width*0.6,size_of_wall_y*0.8};
    int k=0;
    if(did_we_even_calculate)
    {
        for(int i=0;i<number_of_enemies+1;i++)
        {
            SDL_Texture *tempture = SDL_CreateTextureFromSurface(renderer, upboardcolor[i]);
            upboard_target.x = window_width*0.2 + window_width*0.6*(double)((double)k/(double)total_of_soldiers_in_map);
            k+=upboardwidth[i];
            upboard_target.w= (window_width*0.8) - upboard_target.x;
            // printf("%d %d\n", upboard_target.x, upboard_target.w);
            SDL_RenderCopy(renderer, tempture, NULL, &upboard_target);
            SDL_DestroyTexture(tempture);
        }
        SDL_Texture *tempture = SDL_CreateTextureFromSurface(renderer, upboardcolor[nomansland_playerid]);
        upboard_target.x = window_width*0.2 + window_width*0.6*(double)((double)k/(double)total_of_soldiers_in_map);
        k+=upboardwidth[nomansland_playerid];
        upboard_target.w= (window_width*0.8) - upboard_target.x;
        // printf("%d %d\n", upboard_target.x, upboard_target.w);
        SDL_RenderCopy(renderer, tempture, NULL, &upboard_target);
        SDL_DestroyTexture(tempture);
    }
   
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
                if(difftime(time_now,start_time)>=1 && politic_sides[i].player_id!=nomansland_playerid &&
                ((politic_sides[i].player_id==nomansland_playerid && politic_sides[i].number_of_troopers<max_troop_no_mans_land) || (politic_sides[i].player_id!=nomansland_playerid && politic_sides[i].number_of_troopers<max_troop_in_someones_land)))
                {
                    spell_type_four(politic_sides[i].player_id);
                    politic_sides[i].number_of_troopers+=difftime(time_now,start_time) * players[politic_sides[i].player_id].create_trooper_rate;
                    if(politic_sides[i].player_id==nomansland_playerid && politic_sides[i].number_of_troopers>max_troop_no_mans_land)
                    {
                        politic_sides[i].number_of_troopers = max_troop_no_mans_land;
                    }
                    if(politic_sides[i].player_id!=nomansland_playerid && politic_sides[i].number_of_troopers>max_troop_in_someones_land)
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
        SDL_DestroyTexture(leaders_faces_texture);
        SDL_DestroyTexture(startgametexture);
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
        }
    }
    for(int j =0 ;j<size_of_politic_sides;j++)
    {
        if(politic_sides[j].id_of_moving_troppers==0)
            continue;
        // SDL_Texture *movingtrooper_texture = SDL_CreateTextureFromSurface(renderer, troopers[politic_sides[j].troopers[0].player_id]);
        for(int i = 0 ; i<politic_sides[j].id_of_moving_troppers ; i++)
        {
            if(politic_sides[j].troopers[i].is_out==0 || politic_sides[j].troopers[i].did_end==1)
                continue;
            SDL_Rect movingtrooper_target = {politic_sides[j].troopers[i].current_x, politic_sides[j].troopers[i].current_y, size_of_troopers_x_y, size_of_troopers_x_y};
            SDL_RenderCopy(renderer, movingtrooper_texture[politic_sides[j].troopers[0].player_id], NULL, &movingtrooper_target);
        }
        // SDL_DestroyTexture(movingtrooper_texture);
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
    SDL_DestroyTexture(walltexture);
    SDL_DestroyTexture(wallflippedtexture);
    SDL_DestroyTexture(backtomenutexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(closebutton_texture);
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
    SDL_Texture *backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
    SDL_RenderCopy(renderer, backbuttontexture, NULL, &backbutton_target);
    SDL_Texture *closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
    SDL_RenderCopy(renderer, closebutton_texture, NULL, &closebutton_target);
    SDL_Texture *soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    SDL_RenderCopy(renderer, soundtexture, NULL, &sound_target);
    if(did_win_int==1)
    {
        SDL_Rect ifyoudefine_target = {window_width/2 - ifyoudefine_x/2 , 20, ifyoudefine_x, ifyoudefine_y};
        SDL_Texture *quote_texture = SDL_CreateTextureFromSurface(renderer, ifyoudefine);
        SDL_RenderCopy(renderer, quote_texture, NULL, &ifyoudefine_target);
        SDL_DestroyTexture(quote_texture);
    }
    else
    {
        SDL_Rect doordonot_target = {window_width/2 - doordonot_x/2 , 20, doordonot_x, doordonot_y};
        SDL_Texture *doordonot_texture = SDL_CreateTextureFromSurface(renderer, doordonot);
        SDL_RenderCopy(renderer, doordonot_texture, NULL, &doordonot_target);
        SDL_DestroyTexture(doordonot_texture);
    }
    char test[150];
    SDL_Surface *textsurface;
    SDL_Texture *text_texture;
    if(did_win_int==0)
    {
        sprintf(test, "you lost!");
        TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);        
        enemies_target.x = window_width/2 - enemies_target.w/2;
        enemies_target.y = window_height/2 - enemies_target.h/2 - enemies_target.h*3/2;
        textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
        text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
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
    }
    sprintf(test, "game duration: %d",(int)difftime(calc_time,game_start_time)/60);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    enemies_target.x = window_width/2 - enemies_target.w/2;
    enemies_target.y = window_height/2 - enemies_target.h/2;
    textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
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

    sprintf(test, "your score from this game: %d",added_score);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    enemies_target.x = window_width/2 - enemies_target.w/2;
    enemies_target.y = window_height/2 - enemies_target.h/2 + enemies_target.h*3/2;
    textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
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

    sprintf(test, "your total score: %d",user_score);
    TTF_SizeText(details_page_outline, test, &enemies_target.w, &enemies_target.h);
    enemies_target.x = window_width/2 - enemies_target.w/2;
    enemies_target.y = window_height/2 - enemies_target.h/2 + enemies_target.h*3;
    textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
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

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
}
void pageminusone()
{
    struct timeval time_tea;
    gettimeofday(&time_tea,NULL);
    long long int diff=(time_tea.tv_sec-the_begin.tv_sec)*1000000 + time_tea.tv_usec - the_begin.tv_usec;
    SDL_Delay(50);
    if(diff>41000000)
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
        startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff-2000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<8000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogo);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<11000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 8000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<14000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogobef);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 11000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }

    else if(diff<17000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 14000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<20000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogo);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<23000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, shariflogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 20000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }

    else if(diff<26000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 23000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }

    else if(diff<29000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogobef);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 26000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<32000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=(diff - 29000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<35000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogo);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<38000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogo);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 35000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
    else if(diff<41000000)
    {
        SDL_Texture *startscreentexture = SDL_CreateTextureFromSurface(renderer, lucasfilmlogobef);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        startscreentexture = SDL_CreateTextureFromSurface(renderer, gamelogobef);
        SDL_SetTextureBlendMode(startscreentexture,SDL_BLENDMODE_BLEND);
        int temp=255 -(diff - 38000000)*255/3000000;
        SDL_SetTextureAlphaMod(startscreentexture,temp);
        SDL_RenderCopy(renderer, startscreentexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(startscreentexture);
    }
}