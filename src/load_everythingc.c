#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <sys/time.h>
#include "math.h"
#include "string.h"
#include "load_everything.h"

void load_everything()
{
    number_of_leaderboard_users=0;
    nomansland_playerid=10;
    main_players_id=0;

    did_we_even_calculate=0;
    for(int i=0;i<5;i++)
        is_there_any_type_n_kyber[i] =0;
    size_of_troops_with_no_home=0;
    for(int i=0;i<100;i++)
        politic_sides_of_user[i]=0;
    white.a= 255,white.b=255,white.g =255, white.r = 255;
    black.a = 0,black.b =0,black.g =0,black.r=0;
    leaderboard_page_y=-60;
    FPS = 30;
    size_of_each_cell_x=162,size_of_each_cell_y=140 ,number_of_cells_x=0, number_of_cells_y=0;
    first_click=-10;
    is_first_clicked=0;
    dist_from_mid=10;
    dist_moving_trooper_per_sec=10;
    seconds_until_trooper_is_out = 0.18;
    kybers_time_till_end[0] = 5000000;
    kybers_time_till_end[1] = 5000000;
    kybers_time_till_end[2] = 5000000;
    kybers_time_till_end[3] = 5000000;
    kybers_time_till_end[4] = 5000000;
    size_of_wall_y=60;
    char tempchar[55]="                                ";
    username_text[33];
    strcpy(username_text,tempchar);
    mapselect[33];
    strcpy(mapselect,tempchar);
    game_running=1;
    max_troop_no_mans_land=20;
    max_troop_in_someones_land=50;
    start_troop_in_someones_land=10;
    did_win_int=0;

    number_of_enemies=4;
    number_of_politic_sides_per_user=1;
    number_of_nomansland=8;
    for(int i=0;i<15;i++)
        upboardwidth[i] = 0;
    number_of_systems_of_the_user=1;
    page=-1;
    size_of_kybers=0;
    size_of_politic_sides=0;
    is_sound_on=1,size_of_cells=0;
    writing_mode_username=0,size_of_text_username=0;
    writing_mode_map_select=0,size_of_text_mapselect=0;
    selected_map_num=0;
    mapnumsel=0;
    gettimeofday(&the_begin,NULL);
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("State.io: A Star Wars Story", 20, 20, window_width, window_height, SDL_WINDOW_OPENGL);
    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    srand(time(NULL));
    TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GetRendererOutputSize(renderer,&window_width,&window_height);
    size_of_each_cell_x=162*window_width/1920,size_of_each_cell_y=140*window_width/1920;
    size_new_game_x = 327*window_width/1335,size_new_game_y=37*window_width/1335;
    size_load_game_x = 327*window_width/1335,size_load_game_y=37*window_width/1335;
    leaderboard_game_x = 327*window_width/1335,leaderboard_game_y=37*window_width/1335;
    size_credits_x = 163*window_width/1335,size_credits_y=37*window_width/1335;
    backbutton_x_y=50;
    start_game_x = 327*window_width/1335 , start_game_y =37*window_width/1335;
    generatemap_x = 327*window_width/1335 , generatemap_y =37*window_width/1335;
    size_of_leaders_x_y=45*(size_of_each_cell_x/81);
    size_of_troopers_x_y=20*(size_of_each_cell_x/81);
    size_of_kyber_photo_x = 40*(size_of_each_cell_x/162), size_of_kyber_photo_y=72*(size_of_each_cell_x/162);
    credits_text_x=1100*window_width/1352,credits_text_y=1307*window_width/1335;
    doordonot_x = 726*window_width/1335, doordonot_y = 37*window_width/1335;
    ifyoudefine_x = 801*window_width/1335, ifyoudefine_y = 115*window_width/1335;
    credits_text_loc_y=10;
    size_of_closebutton_x_y = 20;
    loc_number_of_enemies_x = window_width*0.1, loc_number_of_enemies_y = window_height*0.1;


    number_of_soldiers = TTF_OpenFont("assets/EPISODE1.TTF",18*window_width/1920);
    number_of_soldiers_outline = TTF_OpenFont("assets/EPISODE1.TTF",18*window_width/1920);
    details_page = TTF_OpenFont("assets/Starjedi.ttf",40*window_width/1920);
    details_page_outline = TTF_OpenFont("assets/Starjedi.ttf",40*window_width/1920);
    TTF_SetFontOutline(details_page_outline,2);
    TTF_SetFontOutline(number_of_soldiers_outline,2);
    TTF_SizeText(details_page,"number of enemies: 4",&number_of_enemies_w,&number_of_enemies_h);
    TTF_SizeText(details_page,"number of systems per player: 1",&per_user_w,&per_user_h);
    TTF_SizeText(details_page,"there are 00 maps. select one of them:",&mapsel_w,&mapsel_h);
    TTF_SizeText(details_page,"............................",&mapseltype_w,&mapseltype_h);
    TTF_SizeText(details_page,"............................",&usernametype_w,&usernametype_h);
    TTF_SizeText(details_page,"number of no man's land: 8",&number_of_nomansland_x,&number_of_nomansland_y);
    TTF_SizeText(details_page,"max troopers in a players planet: 50",&maxtrooperinplayers_house.w,&maxtrooperinplayers_house.h);
    TTF_SizeText(details_page,"max troopers in no man's land: 50",&maxtrooperinnomansland_target.w,&maxtrooperinnomansland_target.h);
    TTF_SizeText(details_page,"number of troopers the land has in the beginning: 50",&start_troop_insomo_la_target.w,&start_troop_insomo_la_target.h);
    TTF_SizeText(details_page,"number of systems of the main player: 8",&number_of_systems_of_user_target.w,&number_of_systems_of_user_target.h);
    closebutton_target.x = window_width - 10 - size_of_closebutton_x_y;
    closebutton_target.y = 25 - size_of_closebutton_x_y;
    closebutton_target.w = size_of_closebutton_x_y;
    closebutton_target.h = size_of_closebutton_x_y;
    wall_target.x = 0;
    wall_target.y = window_height - size_of_wall_y;
    wall_target.w = window_width;
    wall_target.h = size_of_wall_y;
    wallflipped_target.x = 0;
    wallflipped_target.y = 0;
    wallflipped_target.w = window_width;
    wallflipped_target.h = size_of_wall_y;
    backtomenu_target.x = 60*window_width/1920;
    backtomenu_target.y = window_height - size_of_wall_y*0.85;
    backtomenu_target.w = size_of_wall_y*0.8*700/298;
    backtomenu_target.h = size_of_wall_y*0.8;
    savebutton_target.y = window_height - size_of_wall_y*0.85;
    savebutton_target.w = size_of_wall_y*0.8*700/298;
    savebutton_target.x = window_width - 60*window_width/1920 - savebutton_target.w;
    savebutton_target.h = size_of_wall_y*0.8;
    sound_target.x = 5;
    sound_target.y = window_height-40;
    sound_target.w = 35;
    sound_target.h = 35;


    new_game_target.x= window_width/2 - size_new_game_x/2;
    new_game_target.y= window_height/2 + window_height/2*160/300 - size_new_game_y/2;
    new_game_target.w= size_new_game_x;
    new_game_target.h= size_new_game_y;
    load_game_target.x = window_width/2 - size_load_game_x/2;
    load_game_target.y = window_height/2 + window_height/2*205/300 - size_load_game_y/2;
    load_game_target.w = size_load_game_x;
    load_game_target.h = size_load_game_y;
    leaderboard_target.x = window_width/2 - leaderboard_game_x/2;
    leaderboard_target.y = window_height/2 + window_height/2*250/300 - leaderboard_game_y/2;
    leaderboard_target.w = leaderboard_game_x;
    leaderboard_target.h = leaderboard_game_y;
    credits_target.x = 180*window_width/1335- size_credits_x/2;
    credits_target.y = window_height -50*window_width/1335 - size_credits_y/2;
    credits_target.w = size_credits_x;
    credits_target.h = size_credits_y;
    start_game_target.x = window_width - 150*window_width/1335 -start_game_x/2;
    start_game_target.y = window_height - 50*window_width/1335 - start_game_y/2;
    start_game_target.w = start_game_x;
    start_game_target.h = start_game_y;
    backbutton_target.x = 50 - backbutton_x_y/2;
    backbutton_target.y = 50 - backbutton_x_y/2;
    backbutton_target.w = backbutton_x_y;
    backbutton_target.h = backbutton_x_y;
    enemies_target.x = loc_number_of_enemies_x;
    enemies_target.y = loc_number_of_enemies_y + number_of_enemies_h + 10;
    enemies_target.w = number_of_enemies_w;
    enemies_target.h = number_of_enemies_h;
    per_user_target.x = loc_number_of_enemies_x;
    per_user_target.y = loc_number_of_enemies_y + 2*(number_of_enemies_h + 10);
    per_user_target.w = per_user_w;
    per_user_target.h = per_user_h;
    number_of_nomansland_target.x = loc_number_of_enemies_x;
    number_of_nomansland_target.y = loc_number_of_enemies_y + 3* (number_of_enemies_h + 10);
    number_of_nomansland_target.w = number_of_nomansland_x;
    number_of_nomansland_target.h = number_of_nomansland_y;

    maxtrooperinplayers_house.x = loc_number_of_enemies_x;
    maxtrooperinplayers_house.y = loc_number_of_enemies_y + 4*(number_of_enemies_h + 10);
    maxtrooperinnomansland_target.x = loc_number_of_enemies_x;
    maxtrooperinnomansland_target.y = loc_number_of_enemies_y + 5*(number_of_enemies_h + 10);
    start_troop_insomo_la_target.x = loc_number_of_enemies_x;
    start_troop_insomo_la_target.y = loc_number_of_enemies_y + 6*(number_of_enemies_h + 10);
    number_of_systems_of_user_target.x = loc_number_of_enemies_x;
    number_of_systems_of_user_target.y = loc_number_of_enemies_y + 7*(number_of_enemies_h + 10);

    updownbutton_target.x = loc_number_of_enemies_x + number_of_enemies_w + 50*window_width/1920;
    updownbutton_target.y = enemies_target.y + enemies_target.h*0.1;
    updownbutton_target.w = 40*window_width/1920;
    updownbutton_target.h = 60*window_width/1920;
    updownbutton_sec_target.x = loc_number_of_enemies_x + per_user_w + 50*window_width/1920;
    updownbutton_sec_target.y = per_user_target.y + per_user_target.h*0.1;
    updownbutton_sec_target.w = 40*window_width/1920;
    updownbutton_sec_target.h = 60*window_width/1920;
    updownbutton_thi_target.x = loc_number_of_enemies_x + number_of_nomansland_target.w + 50*window_width/1920;
    updownbutton_thi_target.y = number_of_nomansland_target.y + number_of_nomansland_target.h*0.1;
    updownbutton_thi_target.w = 40*window_width/1920;
    updownbutton_thi_target.h = 60*window_width/1920;
    updownbutton_fou_target.x = loc_number_of_enemies_x + maxtrooperinplayers_house.w + 50*window_width/1920;
    updownbutton_fou_target.y = maxtrooperinplayers_house.y + maxtrooperinplayers_house.h*0.1;
    updownbutton_fou_target.w = 40*window_width/1920;
    updownbutton_fou_target.h = 60*window_width/1920;
    updownbutton_fiv_target.x = maxtrooperinnomansland_target.x + maxtrooperinnomansland_target.w + 50*window_width/1920;
    updownbutton_fiv_target.y = maxtrooperinnomansland_target.y + maxtrooperinnomansland_target.h*0.1;
    updownbutton_fiv_target.w = 40*window_width/1920;
    updownbutton_fiv_target.h = 60*window_width/1920;
    updownbutton_six_target.x = start_troop_insomo_la_target.x + start_troop_insomo_la_target.w + 50*window_width/1920;
    updownbutton_six_target.y = start_troop_insomo_la_target.y + start_troop_insomo_la_target.h*0.1;
    updownbutton_six_target.w = 40*window_width/1920;
    updownbutton_six_target.h = 60*window_width/1920;
    updownbutton_sev_target.x = number_of_systems_of_user_target.x + number_of_systems_of_user_target.w + 50*window_width/1920;
    updownbutton_sev_target.y = number_of_systems_of_user_target.y + number_of_systems_of_user_target.h*0.1;
    updownbutton_sev_target.w = 40*window_width/1920;
    updownbutton_sev_target.h = 60*window_width/1920;

    username_target.x = loc_number_of_enemies_x;
    username_target.y = loc_number_of_enemies_y;
    username_target.w = usernametype_w;
    username_target.h = usernametype_h;

    time(&start_time);
    time(&start_time_troop);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,2048);
    menu_music = Mix_LoadMUS("assets/menu.mp3");
    game_music = Mix_LoadMUS("assets/Anakins_Symphony.mp3");
    intro_music =Mix_LoadMUS("assets/intro/intromusic.mp3");
    Mix_PlayMusic(intro_music,-1);
    loadimages();
}

void loadimages()
{
    double ratio = (double)window_width/(double)window_height;
    
    if(ratio - 3/2< 0.0000001 && ratio - 3/2> -0.0000001)
    {
        leaderboardbackground = SDL_LoadBMP("assets/kenobivsmaul3-2.bmp");
        winbackground = SDL_LoadBMP("assets/vaderrogueone3-2.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning3-2.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource3-2.bmp");
        startbackground = SDL_LoadBMP("assets/background3-2.bmp");
    }
    else if(ratio - 4/3 < 0.0001 && ratio - 4/3 > -0.0001)
    {
        leaderboardbackground = SDL_LoadBMP("assets/kenobivsmaul4-3.bmp");
        winbackground = SDL_LoadBMP("assets/vaderrogueone4-3.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning4-3.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource4-3.bmp");
        startbackground = SDL_LoadBMP("assets/background4-3.bmp");
    }
    else if(ratio - 5/4< 0.0001 && ratio - 5/4> -0.0001)
    {
        leaderboardbackground = SDL_LoadBMP("assets/kenobivsmaul5-4.bmp");
        winbackground = SDL_LoadBMP("assets/vaderrogueone5-4.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning5-4.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource5-4.bmp");
        startbackground = SDL_LoadBMP("assets/background5-4.bmp");
    }
    else if(ratio - 16/10< 0.0001 && ratio - 16/10> -0.0001)
    {
        leaderboardbackground = SDL_LoadBMP("assets/kenobivsmaul16-10.bmp");
        winbackground = SDL_LoadBMP("assets/vaderrogueone16-10.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning16-10.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource16-10.bmp");
        startbackground = SDL_LoadBMP("assets/background16-10.bmp");
    }
    else
    {
        leaderboardbackground = SDL_LoadBMP("assets/kenobivsmaul16-9.bmp");
        winbackground = SDL_LoadBMP("assets/vaderrogueone16-9.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning16-9.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource16-9.bmp");
        startbackground = SDL_LoadBMP("assets/intro/menubefwihlogo.bmp");
    }
    starsbackground = SDL_LoadBMP("assets/stars.bmp");
    load_game = SDL_LoadBMP("assets/load_game.bmp");
    leaderboard = SDL_LoadBMP("assets/leaderboard.bmp");
    new_game = SDL_LoadBMP("assets/new_game.bmp");
    credits_button = SDL_LoadBMP("assets/credits_button.bmp");
    credits_text = SDL_LoadBMP("assets/credits.bmp");
    padmegrave1 = SDL_LoadBMP("assets/padmegrave1.bmp");
    padmegrave2 = SDL_LoadBMP("assets/padmegrave2.bmp");
    backbutton = SDL_LoadBMP("assets/backbutton.bmp");
    startgame = SDL_LoadBMP("assets/startgame.bmp");
    updownbutton = SDL_LoadBMP("assets/updown.bmp");
    soundonphoto = SDL_LoadBMP("assets/soundon.bmp");
    doordonot = SDL_LoadBMP("assets/doordonot.bmp");
    ifyoudefine = SDL_LoadBMP("assets/ifyoudefine.bmp");
    closebutton = SDL_LoadBMP("assets/closebutton.bmp");
    
    textbox = SDL_LoadBMP("assets/textbox.bmp");


    lucasfilmlogobef = SDL_LoadBMP("assets/intro/lucasfilmback.bmp");
    lucasfilmlogo = SDL_LoadBMP("assets/intro/lucasfilm.bmp");
    shariflogobef =  SDL_LoadBMP("assets/intro/shariflogobef.bmp");
    shariflogo =  SDL_LoadBMP("assets/intro/shariflogo.bmp");
    gamelogobef = SDL_LoadBMP("assets/intro/gamelogobef.bmp");
    gamelogo = SDL_LoadBMP("assets/intro/gamelogo.bmp");
    menubef = SDL_LoadBMP("assets/intro/menubef.bmp");
    menubefwithlogo = SDL_LoadBMP("assets/intro/menubefwithlogo.bmp");


    wall = SDL_LoadBMP("assets/wall.bmp");
    wallflipped = SDL_LoadBMP("assets/wallflipped.bmp");
    backtomenu = SDL_LoadBMP("assets/backtomenu.bmp");
    savebutton = SDL_LoadBMP("assets/savegame.bmp");

    faces[0] = SDL_LoadBMP("assets/faces/vader.bmp");
    faces[1] = SDL_LoadBMP("assets/faces/boba.bmp");
    faces[2] = SDL_LoadBMP("assets/faces/tano.bmp");
    faces[3] = SDL_LoadBMP("assets/faces/luke.bmp");
    faces[4] = SDL_LoadBMP("assets/faces/maul.bmp");
    faces[nomansland_playerid] = SDL_LoadBMP("assets/faces/r2d2.bmp");

    for(int i=0;i<5;i++)
        facestexture[i]=SDL_CreateTextureFromSurface(renderer, faces[i]);
    facestexture[nomansland_playerid] =SDL_CreateTextureFromSurface(renderer, faces[nomansland_playerid]);

    troopers[0] = SDL_LoadBMP("assets/troopers/stormtrooper.bmp");
    troopers[1] = SDL_LoadBMP("assets/troopers/deathtrooper.bmp");
    troopers[2] = SDL_LoadBMP("assets/troopers/ahsokatrooper.bmp");
    troopers[3] = SDL_LoadBMP("assets/troopers/clonetrooper.bmp");
    troopers[4] = SDL_LoadBMP("assets/troopers/mandalorian.bmp");

    for(int i=0;i<number_of_enemies+1;i++)
        movingtrooper_texture[i]=SDL_CreateTextureFromSurface(renderer, troopers[i]);

    kyber_cristal_photos[0] = SDL_LoadBMP("assets/kybers/kyber_blue.bmp");
    kyber_cristal_photos[1] = SDL_LoadBMP("assets/kybers/kyber_red.bmp");
    kyber_cristal_photos[2] = SDL_LoadBMP("assets/kybers/kyber_purple.bmp");
    kyber_cristal_photos[3] = SDL_LoadBMP("assets/kybers/kyber_green.bmp");
    kyber_cristal_photos[4] = SDL_LoadBMP("assets/kybers/kyber_orange.bmp");
    for(int i=0;i<5;i++)
        kybertexture[i]=SDL_CreateTextureFromSurface(renderer, kyber_cristal_photos[i]);


    kyber_cristalon_photos[0] = SDL_LoadBMP("assets/kyberson/kyber_blueon.bmp");
    kyber_cristalon_photos[1] = SDL_LoadBMP("assets/kyberson/kyber_redon.bmp");
    kyber_cristalon_photos[2] = SDL_LoadBMP("assets/kyberson/kyber_purpleon.bmp");
    kyber_cristalon_photos[3] = SDL_LoadBMP("assets/kyberson/kyber_greenon.bmp");
    kyber_cristalon_photos[4] = SDL_LoadBMP("assets/kyberson/kyber_orangeon.bmp");
    for(int i=0;i<5;i++)
        kyberontexture[i]=SDL_CreateTextureFromSurface(renderer, kyber_cristalon_photos[i]);

    planets_photos[0] = SDL_LoadBMP("assets/planet_death_star.bmp");
    planets_photos[1] = SDL_LoadBMP("assets/planet_lothal.bmp");
    planets_photos[2] = SDL_LoadBMP("assets/planet_rodia.bmp");
    planets_photos[3] = SDL_LoadBMP("assets/planet_naboo.bmp");
    planets_photos[4] = SDL_LoadBMP("assets/planet_mustafar.bmp");
    planets_photos[nomansland_playerid] = SDL_LoadBMP("assets/metal.bmp");

    for(int i=0;i<5;i++)
        planetphotostexture[i]=SDL_CreateTextureFromSurface(renderer,planets_photos[i]);
    planetphotostexture[nomansland_playerid]=SDL_CreateTextureFromSurface(renderer,planets_photos[nomansland_playerid]);

    lightsaberhandle=SDL_LoadBMP("assets/sabers/handle.bmp");
    upboardcolor[0]=SDL_LoadBMP("assets/sabers/lightsaberred.bmp");
    upboardcolor[1]=SDL_LoadBMP("assets/sabers/spear.bmp");
    upboardcolor[2]=SDL_LoadBMP("assets/sabers/lightsaberblue.bmp");
    upboardcolor[3]=SDL_LoadBMP("assets/sabers/lightsabergreen.bmp");
    upboardcolor[4]=SDL_LoadBMP("assets/sabers/darksaber.bmp");
    upboardcolor[nomansland_playerid]=SDL_LoadBMP("assets/sabers/lightsaberwhite.bmp");
    for(int i=0;i<5;i++)
        upboardcolortexture[i] = SDL_CreateTextureFromSurface(renderer, upboardcolor[i]);
    upboardcolortexture[nomansland_playerid] = SDL_CreateTextureFromSurface(renderer, upboardcolor[nomansland_playerid]);

    kybersaber[0] =SDL_LoadBMP("assets/kybersaber/lightsaberred.bmp");
    kybersaber[1] =SDL_LoadBMP("assets/kybersaber/spear.bmp");
    kybersaber[2] =SDL_LoadBMP("assets/kybersaber/lightsaberblue.bmp");
    kybersaber[3] =SDL_LoadBMP("assets/kybersaber/lightsabergreen.bmp");
    kybersaber[4] =SDL_LoadBMP("assets/kybersaber/darksaber.bmp");
    for(int i=0;i<5;i++)
        kybersabertexture[i] =SDL_CreateTextureFromSurface(renderer, kybersaber[i]);
    savebuttontexture = SDL_CreateTextureFromSurface(renderer, savebutton);
    backtomenutexture = SDL_CreateTextureFromSurface(renderer, backtomenu);
    soundtexture = SDL_CreateTextureFromSurface(renderer, soundonphoto);
    closebutton_texture = SDL_CreateTextureFromSurface(renderer, closebutton);
    walltexture = SDL_CreateTextureFromSurface(renderer, wall);
    wallflippedtexture = SDL_CreateTextureFromSurface(renderer, wallflipped);
    handletexture = SDL_CreateTextureFromSurface(renderer, lightsaberhandle);
    newgame_texture = SDL_CreateTextureFromSurface(renderer, new_game);
    loadgame_texture = SDL_CreateTextureFromSurface(renderer, load_game);
    leaderboard_texture = SDL_CreateTextureFromSurface(renderer, leaderboard);
    creditstexture = SDL_CreateTextureFromSurface(renderer, credits_button);
    backbuttontexture = SDL_CreateTextureFromSurface(renderer, backbutton);
    startgametexture = SDL_CreateTextureFromSurface(renderer, startgame);
    updownbutton_texture = SDL_CreateTextureFromSurface(renderer, updownbutton);
    creditstext_texture = SDL_CreateTextureFromSurface(renderer, credits_text);
    textbox_texture = SDL_CreateTextureFromSurface(renderer, textbox);
    quote_texture = SDL_CreateTextureFromSurface(renderer, ifyoudefine);
    doordonot_texture = SDL_CreateTextureFromSurface(renderer, doordonot);
    global_second_kyber=0;
    global_third_kyber=0;
}