#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <sys/time.h>
struct troop{
    int current_x;
    int current_y;
    int dest_x;
    int dest_y;
    int player_id;
    int did_end;
    int till_end_a;
    int is_out;
    struct timeval time;
    double seconds_till_out;
    int politic_side_number;
};
struct cell{
    int x;
    int y;
    int is_territoy;
    int politic_side_number;
    int does_it_have_military;
    int is_occupied;
};
struct politic_side{
    int cells_x[7];
    int cells_y[7];
    int size_of_cells;
    int player_id;
    int number_of_troopers;
    int number_of_moving_troppers;
    int is_sending_troopers;
    struct troop troopers[1000];
};
struct kyber_cristal{
    int type;
    int x;
    int y;
};
void check_to_create_politic_side(struct politic_side politic_sides[], struct cell cells[][100], int temp_x, int temp_y,int size_of_politic_sides, int a, int b)
{
    if(cells[temp_x+a][temp_y+b].is_territoy==1 && cells[temp_x+a][temp_y+b].is_occupied!=1)
    {
        politic_sides[size_of_politic_sides].cells_x[politic_sides[size_of_politic_sides].size_of_cells] = temp_x+a;
        politic_sides[size_of_politic_sides].cells_y[politic_sides[size_of_politic_sides].size_of_cells] = temp_y+b;
        politic_sides[size_of_politic_sides].size_of_cells++;
        cells[temp_x+a][temp_y+b].is_occupied=1;
        cells[temp_x+a][temp_y+b].politic_side_number=size_of_politic_sides;
    }
}

int window_width;
int window_height;
TTF_Font *number_of_soldiers;
TTF_Font *number_of_soldiers_outline;
TTF_Font *details_page;
TTF_Font *details_page_outline;
SDL_Color white= {255,255,255,255};
SDL_Color black = {0,0,0,0};
int size_new_game_x, size_new_game_y;
int size_load_game_x, size_load_game_y;
int leaderboard_game_x, leaderboard_game_y;
int size_credits_x, size_credits_y;
int backbutton_x_y;
int start_game_x, start_game_y;
int generatemap_x, generatemap_y;
int size_of_leaders_x_y;
int size_of_troopers_x_y;
int size_of_kyber_photo_x, size_of_kyber_photo_y;
int credits_text_x, credits_text_y;
int credits_text_loc_y;
int size_of_closebutton_x_y;
int loc_number_of_enemies_x, loc_number_of_enemies_y;
int number_of_enemies_w, number_of_enemies_h;
int per_user_w, per_user_h;
int mapsel_w, mapsel_h;
int mapseltype_w,mapseltype_h;
int usernametype_w,usernametype_h;
const double FPS = 30;
int size_of_each_cell_x=162,size_of_each_cell_y=140 ,number_of_cells_x=0, number_of_cells_y=0;
int first_click_x=-10,first_click_y=-10;
int second_click_x, second_click_y;
int is_first_clicked=0;
int max_troop_in_poliside=150;
// struct troop moving_troopers[2000];
// int size_of_moving_troopers=0;
int dist_from_mid=10;
int dist_moving_trooper_per_sec=5;
int start_ticks;
double seconds_until_trooper_is_out = 0.8 * 1000000;
int size_of_wall_y=40;
char test3[33] = "............................";
char mapselect[33] = "............................";


int number_of_enemies=4;
int number_of_politic_sides_per_user=1;


SDL_Surface *startbackground;
SDL_Surface *starsbackground;
SDL_Surface *load_game;
SDL_Surface *leaderboard;
SDL_Surface *new_game;
SDL_Surface *credits_button;
SDL_Surface *credits_text;
SDL_Surface *padmegrave1;
SDL_Surface *padmegrave2;
SDL_Surface *closebutton;
SDL_Surface *soundonphoto;
SDL_Surface *new_game_background;
SDL_Surface *backbutton;
SDL_Surface *startgame;
// SDL_Surface *generatemap;
SDL_Surface *updownbutton;
SDL_Surface *faces[15];
SDL_Surface *troopers[15];
SDL_Surface *planets_photos[15];
SDL_Surface *kyber_cristal_photos[4];
SDL_Surface *wall;
SDL_Surface *wallflipped;
SDL_Surface *backtomenu;

SDL_Event ev;
int page=0;
struct cell cells[100][100];
struct politic_side politic_sides[100];
struct kyber_cristal kybers[100];
int size_of_kybers=0;
int size_of_politic_sides=0;
int is_sound_on=1,size_of_cells=0;
int writing_mode_username=0,size_of_text_username=0;
int writing_mode_map_select=0,size_of_text_mapselect=0;
int selected_map_num=0;
int mapnumsel=0;
time_t time_now;
 time_t start_time;


SDL_Renderer* renderer;
void load_variables()
{
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
    size_of_kyber_photo_x = 40, size_of_kyber_photo_y=72;
    credits_text_x=1100*window_width/1335,credits_text_y=1307*window_width/1335;
    credits_text_loc_y=5;
    size_of_closebutton_x_y = 20;
    loc_number_of_enemies_x = window_width*0.1, loc_number_of_enemies_y = window_height*0.1;
}

void loadimages()
{
    double ratio = (double)window_width/(double)window_height;
    
    if(abs(ratio - 3/2)< 0.0001)
    {
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource3-2.bmp");
        startbackground = SDL_LoadBMP("assets/background3-2.bmp");
    }
    else if(abs(ratio - 4/3)< 0.0001)
    {
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource4-3.bmp");
        startbackground = SDL_LoadBMP("assets/background4-3.bmp");
    }
    else if(abs(ratio - 5/4)< 0.0001)
    {
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource5-4.bmp");
        startbackground = SDL_LoadBMP("assets/background5-4.bmp");
    }
    else if(abs(ratio - 16/10)< 0.0001)
    {
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource16-10.bmp");
        startbackground = SDL_LoadBMP("assets/background16-10.bmp");
    }
    else
    {
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource16-9.bmp");
        startbackground = SDL_LoadBMP("assets/background16-9.bmp");
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
    // generatemap = SDL_LoadBMP("assets/generatemap.bmp");
    updownbutton = SDL_LoadBMP("assets/updown.bmp");
    soundonphoto = SDL_LoadBMP("assets/soundon.bmp");

    closebutton = SDL_LoadBMP("assets/closebutton.bmp");


    wall = SDL_LoadBMP("assets/wall.bmp");
    wallflipped = SDL_LoadBMP("assets/wallflipped.bmp");
    backtomenu = SDL_LoadBMP("assets/backtomenu.bmp");

    faces[0] = SDL_LoadBMP("assets/faces/vader.bmp");
    faces[1] = SDL_LoadBMP("assets/faces/boba.bmp");
    faces[2] = SDL_LoadBMP("assets/faces/tano.bmp");
    faces[3] = SDL_LoadBMP("assets/faces/luke.bmp");
    faces[4] = SDL_LoadBMP("assets/faces/maul.bmp");
    faces[10] = SDL_LoadBMP("assets/faces/r2d2.bmp");

    troopers[0] = SDL_LoadBMP("assets/troopers/stormtrooper.bmp");
    troopers[1] = SDL_LoadBMP("assets/troopers/deathtrooper.bmp");
    troopers[2] = SDL_LoadBMP("assets/troopers/ahsokatrooper.bmp");
    troopers[3] = SDL_LoadBMP("assets/troopers/clonetrooper.bmp");
    troopers[4] = SDL_LoadBMP("assets/troopers/mandalorian.bmp");

    kyber_cristal_photos[0] = SDL_LoadBMP("assets/kybers/kyber_blue.bmp");
    kyber_cristal_photos[1] = SDL_LoadBMP("assets/kybers/kyber_green.bmp");
    kyber_cristal_photos[2] = SDL_LoadBMP("assets/kybers/kyber_purple.bmp");
    kyber_cristal_photos[3] = SDL_LoadBMP("assets/kybers/kyber_red.bmp");

    planets_photos[0] = SDL_LoadBMP("assets/planet_death_star.bmp");
    planets_photos[1] = SDL_LoadBMP("assets/planet_lothal.bmp");
    planets_photos[2] = SDL_LoadBMP("assets/planet_rodia.bmp");
    planets_photos[3] = SDL_LoadBMP("assets/planet_naboo.bmp");
    planets_photos[4] = SDL_LoadBMP("assets/planet_mustafar.bmp");
    planets_photos[10] = SDL_LoadBMP("assets/metal.bmp");

    number_of_soldiers = TTF_OpenFont("assets/EPISODE1.TTF",18*window_width/1920);
    number_of_soldiers_outline = TTF_OpenFont("assets/EPISODE1.TTF",18*window_width/1920);
    details_page = TTF_OpenFont("assets/Starjedi.ttf",40*window_width/1920);
    details_page_outline = TTF_OpenFont("assets/Starjedi.ttf",40*window_width/1920);
    TTF_SetFontOutline(details_page_outline,2);
    TTF_SetFontOutline(number_of_soldiers_outline,2);
    TTF_SizeText(details_page,"number of enemies: 04",&number_of_enemies_w,&number_of_enemies_h);
    TTF_SizeText(details_page,"number of systems per player: 01",&per_user_w,&per_user_h);
    TTF_SizeText(details_page,"there are 00 maps. select one of them:",&mapsel_w,&mapsel_h);
    TTF_SizeText(details_page,"............................",&mapseltype_w,&mapseltype_h);
    TTF_SizeText(details_page,"............................",&usernametype_w,&usernametype_h);

}
void rendercpypage0(SDL_Rect new_game_target,SDL_Rect load_game_target,SDL_Rect leaderboard_target,SDL_Rect sound_target,SDL_Rect credits_target,SDL_Rect closebutton_target)
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
void rendercpypage1(char test3[], SDL_Rect per_user_target, SDL_Rect username_target, SDL_Rect backbutton_target, SDL_Rect start_game_target, SDL_Rect enemies_target, SDL_Rect sound_target,SDL_Rect closebutton_target ,SDL_Rect updownbutton_target, SDL_Rect updownbutton_sec_target)
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
    SDL_Surface *textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    enemies_target.y+=2, enemies_target.x+=2, enemies_target.w -=4;

    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    textsurface = TTF_RenderText_Solid(details_page,test, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    SDL_FreeSurface(textsurface);
    char test2[33];
    sprintf(test2, "number of systems per player: %d",number_of_politic_sides_per_user);
    textsurface = TTF_RenderText_Solid(details_page_outline,test2, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&per_user_target);
    per_user_target.y+=2, per_user_target.x+=2, per_user_target.w-=2;

    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    textsurface = TTF_RenderText_Solid(details_page,test2, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&per_user_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    textsurface = TTF_RenderText_Solid(details_page_outline,test3, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    username_target.y+=2, username_target.x+=2, username_target.w-=1;

    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    textsurface = TTF_RenderText_Solid(details_page,test3, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(backbuttontexture);
    SDL_DestroyTexture(startgametexture);
    SDL_DestroyTexture(closebutton_texture);
    SDL_DestroyTexture(updownbutton_texture);
    SDL_DestroyTexture(updownbutton_sec_texture);
}
void rendercpypage2(char mapselect[],SDL_Rect start_game_target,SDL_Rect backbutton_target, SDL_Rect enemies_target, SDL_Rect username_target, SDL_Rect sound_target, SDL_Rect closebutton_target)
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
    char test[60] = "there are 00 maps. select one of them:";
    test[10]=mapnumsel/10 + '0';
    test[11]=mapnumsel%10 + '0';

    SDL_Surface *textsurface = TTF_RenderText_Solid(details_page_outline,test, black);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    enemies_target.y-=2, enemies_target.x-=2, enemies_target.w+=4;
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    enemies_target.y+=2, enemies_target.x+=2, enemies_target.w-=4;
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    textsurface = TTF_RenderText_Solid(details_page,test, white);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    SDL_RenderCopy(renderer,text_texture,NULL,&enemies_target);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
    textsurface = TTF_RenderText_Solid(details_page_outline,mapselect, black);
    text_texture = SDL_CreateTextureFromSurface(renderer,textsurface);
    username_target.y-=2, enemies_target.x-=2, enemies_target.w+=4;
    SDL_RenderCopy(renderer,text_texture,NULL,&username_target);
    username_target.y+=2, enemies_target.x+=2, enemies_target.w-=4;
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(textsurface);
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
void rendercpypage4(SDL_Rect backbutton_target, SDL_Rect credits_text_target,SDL_Rect sound_target)
{
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
void rendercpypage10(SDL_Rect wall_target, SDL_Rect wallflipped_target, SDL_Rect backtomenu_target,SDL_Rect sound_target, SDL_Rect closebutton_target,time_t time_now, time_t start_time)
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
                if(difftime(time_now,start_time)>=1)
                    politic_sides[i].number_of_troopers+=difftime(time_now,start_time);
                char test[4];
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
    int rand_to_do_kyber = rand()%150;
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
            SDL_Rect movingtrooper_target = {politic_sides[j].troopers[i].current_x, politic_sides[j].troopers[i].current_y, size_of_troopers_x_y, size_of_troopers_x_y};
            if(politic_sides[j].troopers[i].is_out==0)
                continue;
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
    SDL_DestroyTexture(startscreentexture);
    SDL_DestroyTexture(walltexture);
    SDL_DestroyTexture(wallflippedtexture);
    SDL_DestroyTexture(backtomenutexture);
    SDL_DestroyTexture(soundtexture);
    SDL_DestroyTexture(closebutton_texture);
}
void soundchange()
{
    SDL_FreeSurface(soundonphoto);
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
void findtotalofsaves()
{
    char teemp[1000];
    FILE *mapsave = fopen("assets/save/files_details.txt", "r+");
    while(1)
        if(fscanf(mapsave,"assets/save/maps/map%d.txt\n",&mapnumsel)==EOF)
            break;
    fclose(mapsave);
}
int findclickedcell(int click_x, int click_y, int *ret_x, int *ret_y, int id_is_zero)
{
    for(int j=0;j<number_of_cells_y;j++)
        for(int i=0;i<number_of_cells_x;i++)
            if(click_x>cells[i][j].x && click_x<cells[i][j].x + size_of_each_cell_x
            && click_y>cells[i][j].y && click_y<cells[i][j].y + size_of_each_cell_y)
            {
                if(cells[i][j].does_it_have_military==1 && i!=first_click_x && j!=first_click_y)
                {
                    if((id_is_zero==1 && politic_sides[cells[i][j].politic_side_number].player_id==0) || id_is_zero==0)
                    {
                        *ret_x=i;
                        *ret_y=j;
                        return 1;
                    }
                }
            }
    return 0;
    
}

void moving_troopers_update_location()
{
    struct timeval tv;
    for(int j=0;j<size_of_politic_sides;j++)
        for(int i = 0 ; i<politic_sides[j].number_of_moving_troppers; i++)
        {
            gettimeofday(&tv,NULL);
            // printf("%lf --- %lf\n", difftime(time_tt,moving_troopers[i].time_now) , moving_troopers[i].seconds_till_out);
            if(politic_sides[j].troopers[i].is_out==0 && (tv.tv_sec -politic_sides[j].troopers[i].time.tv_sec)*1000000LL + tv.tv_usec-politic_sides[j].troopers[i].time.tv_usec >politic_sides[j].troopers[i].seconds_till_out)
            {
                politic_sides[politic_sides[j].troopers[i].politic_side_number].number_of_troopers--;
                politic_sides[j].troopers[i].is_out=1;
            }
            if(politic_sides[j].troopers[i].did_end==1 || politic_sides[j].troopers[i].is_out==0)
                continue;
            politic_sides[j].troopers[i].current_y = ((politic_sides[j].troopers[i].dest_y*politic_sides[j].troopers[i].till_end_a) + politic_sides[j].troopers[i].current_y
                                            *(politic_sides[j].troopers[i].dest_x - politic_sides[j].troopers[i].current_x - politic_sides[j].troopers[i].till_end_a))
                                            /(politic_sides[j].troopers[i].dest_x - politic_sides[j].troopers[i].current_x);
            politic_sides[j].troopers[i].current_x += politic_sides[j].troopers[i].till_end_a; 
            if(abs(politic_sides[j].troopers[i].current_x - politic_sides[j].troopers[i].dest_x)< size_of_each_cell_x*1/5)
                politic_sides[j].troopers[i].did_end=1;
        }
}

void create_cells()
{
    int rand_start_y = rand()%size_of_each_cell_y;
    int rand_start_x = rand()%size_of_each_cell_x;
    for(int i =0; i*size_of_each_cell_x*3/2 + size_of_each_cell_x*7/4 + rand_start_x < window_width;i++)
        number_of_cells_x++;
    for(int j = 0;(j+1)*size_of_each_cell_y/2 + size_of_each_cell_y + rand_start_y < window_height-size_of_wall_y && (j+1)*size_of_each_cell_y/2 + rand_start_y > size_of_wall_y;j++)
    {
        for(int i=0;i<number_of_cells_x;i++)
        {

            if(j%2==0)
                cells[i][j].x=i*size_of_each_cell_x*3/2 + size_of_each_cell_x*3/4;
            else
                cells[i][j].x=i*size_of_each_cell_x*3/2;
            if(rand()%2==0)
                cells[i][j].is_territoy=0;
            else
                cells[i][j].is_territoy=1;
            cells[i][j].is_occupied=0;
            cells[i][j].y=(j+1)*size_of_each_cell_y/2 + rand_start_y;
        }
        number_of_cells_y++;
    }
}

void assign_politic_sides()
{
    size_of_politic_sides=0;
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
                if(i>number_of_enemies)
                {
                    if(politic_sides_of_user==1)
                        break;
                    politic_sides[size_of_politic_sides].player_id=10;
                }
                else if(i==0)
                    politic_sides[size_of_politic_sides].player_id=0;
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
                    planets[temp_rand]=1;
                }
                politic_sides[size_of_politic_sides].number_of_troopers=50;
                politic_sides[size_of_politic_sides].size_of_cells=1;
                politic_sides[size_of_politic_sides].is_sending_troopers=0;
                politic_sides[size_of_politic_sides].number_of_moving_troppers=0;
                politic_sides[size_of_politic_sides].cells_x[0] = temp_x, politic_sides[size_of_politic_sides].cells_y[0] = temp_y;
                cells[temp_x][temp_y].politic_side_number=size_of_politic_sides;
                cells[temp_x][temp_y].does_it_have_military=1;
                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,0,1);
                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,0,-1);
                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,0,2);
                check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,0,-2);
                if(temp_y%2==1)
                {
                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,-1,1);
                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,-1,-1);
                }
                else
                {
                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,1,1);
                    check_to_create_politic_side(politic_sides,cells,temp_x,temp_y,size_of_politic_sides,1,-1);
                }
                size_of_politic_sides++;
                politic_sides_of_user++;
            }
        }
    }
}
void save_the_map()
{
    FILE *mapsave = fopen("assets/save/files_details.txt", "r+");
    int mapnum=0;
    while(1)
        if(fscanf(mapsave,"assets/save/maps/map%d.txt\n",&mapnum)==EOF)
            break;
    mapnum++;
    char path[100];
    sprintf(path, "assets/save/maps/map%d.txt\n", mapnum);
    fprintf(mapsave, "%s", path);
    fclose(mapsave);
    FILE *mapwrite = fopen(path, "w");
    fprintf(mapwrite, "%d\n%d\n%d\n", number_of_enemies,number_of_politic_sides_per_user,size_of_politic_sides);
    for(int j = 0;j<number_of_cells_y;j++)
        for(int i=0;i<number_of_cells_x;i++)
            fprintf(mapwrite,"%d %d %d %d %d %d\n",cells[i][j].x, cells[i][j].y, cells[i][j].is_territoy, cells[i][j].politic_side_number,cells[i][j].does_it_have_military,cells[i][j].is_occupied);
    fprintf(mapwrite,"\n");
    for(int i=0;i<=size_of_politic_sides;i++)
    {
        fprintf(mapwrite,"%d %d %d\n", politic_sides[i].player_id,politic_sides[i].size_of_cells,politic_sides[i].number_of_troopers);
        for(int j=0;j<politic_sides[i].size_of_cells;j++)
            fprintf(mapwrite,"%d %d\n",politic_sides[i].cells_x[j],politic_sides[i].cells_y[j]);
        fprintf(mapwrite,"\n");
    }
    fclose(mapwrite);
}

void load_the_map()
{
    int mapseltonum=0;
    for(int i =0;i<size_of_text_mapselect;i++)
        mapseltonum = mapseltonum *10 + mapselect[i] - '0'; 
    char path[100];
    sprintf(path, "assets/save/maps/map%d.txt\n", mapseltonum);
    FILE *loadedmap = fopen(path, "r");
    fscanf(loadedmap, "%d %d %d", &number_of_enemies, &number_of_politic_sides_per_user, &size_of_politic_sides);
    for(int j = 0;j<number_of_cells_y;j++)
        for(int i=0;i<number_of_cells_x;i++)
            fscanf(loadedmap,"%d %d %d %d %d %d",&cells[i][j].x, &cells[i][j].y, &cells[i][j].is_territoy, &cells[i][j].politic_side_number, &cells[i][j].does_it_have_military, &cells[i][j].is_occupied);
    for(int i=0;i<=size_of_politic_sides;i++)
    {
        fscanf(loadedmap,"%d %d %d\n", &politic_sides[i].player_id, &politic_sides[i].size_of_cells, &politic_sides[i].number_of_troopers);
        for(int j=0;j<politic_sides[i].size_of_cells;j++)
            fscanf(loadedmap,"%d %d\n", &politic_sides[i].cells_x[j], &politic_sides[i].cells_y[j]);
    }
    fclose(loadedmap);
}
void create_moving_troopers()
{
    is_first_clicked=0;
    int q = cells[first_click_x][first_click_y].politic_side_number;
    int last_sec = (seconds_until_trooper_is_out/1000000 * floor((politic_sides[q].number_of_troopers-1)/3) + politic_sides[q].number_of_troopers+difftime(time_now,start_time));
    for(int i=0;i<last_sec;i++)
    {
        int size_of_moving_troopers = politic_sides[q].number_of_moving_troppers;
        struct timeval tv;
        gettimeofday(&tv,NULL);
        politic_sides[q].troopers[size_of_moving_troopers].time = tv;
        politic_sides[q].troopers[size_of_moving_troopers].seconds_till_out = seconds_until_trooper_is_out * floor(i/3);
        politic_sides[q].troopers[size_of_moving_troopers].is_out = 0;
        politic_sides[q].troopers[size_of_moving_troopers].did_end=0;
        politic_sides[q].troopers[size_of_moving_troopers].current_x=cells[first_click_x][first_click_y].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
        politic_sides[q].troopers[size_of_moving_troopers].current_y=cells[first_click_x][first_click_y].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
        politic_sides[q].troopers[size_of_moving_troopers].dest_x = cells[second_click_x][second_click_y].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
        politic_sides[q].troopers[size_of_moving_troopers].dest_y = cells[second_click_x][second_click_y].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
        if(size_of_moving_troopers%3==0)
        {
            politic_sides[q].troopers[size_of_moving_troopers].current_y +=
                            (politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            *(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            *(size_of_each_cell_y/6);
            politic_sides[q].troopers[size_of_moving_troopers].current_x -= size_of_each_cell_x/6;
            politic_sides[q].troopers[size_of_moving_troopers].dest_y += 
                            (politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            *(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            *(size_of_each_cell_y/6);
            politic_sides[q].troopers[size_of_moving_troopers].dest_x -= size_of_each_cell_x/6;
        }
        else if(size_of_moving_troopers%3==2)
        {
            politic_sides[q].troopers[size_of_moving_troopers].current_y -=
                            (politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            *(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            *(size_of_each_cell_y/6);
            politic_sides[q].troopers[size_of_moving_troopers].current_x += size_of_each_cell_x/6;
            politic_sides[q].troopers[size_of_moving_troopers].dest_y -= 
                            (politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_x - politic_sides[q].troopers[size_of_moving_troopers].dest_x)
                            *(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            /abs(politic_sides[q].troopers[size_of_moving_troopers].current_y - politic_sides[q].troopers[size_of_moving_troopers].dest_y)
                            *(size_of_each_cell_y/6);
            politic_sides[q].troopers[size_of_moving_troopers].dest_x += size_of_each_cell_x/6;
        }
        int m= (politic_sides[q].troopers[i].dest_x - politic_sides[q].troopers[i].current_x);
        int n= (politic_sides[q].troopers[i].dest_y - politic_sides[q].troopers[i].current_y);
        politic_sides[q].troopers[size_of_moving_troopers].till_end_a = dist_moving_trooper_per_sec*m/sqrt(m*m+n*n);
        politic_sides[q].troopers[size_of_moving_troopers].player_id = politic_sides[cells[first_click_x][first_click_y].politic_side_number].player_id;
        politic_sides[q].number_of_moving_troppers++;
    }
}

