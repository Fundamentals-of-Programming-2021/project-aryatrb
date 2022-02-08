#ifndef LOADEVERYTHINGH_H
#define LOADEVERYTHINGH_H
#include <sys/time.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
struct troop{
    int current_x;
    int current_y;
    int dest_x;
    int dest_y;
    int player_id;
    int did_end;
    int is_out;
    struct timeval time;
    double seconds_till_out;
    int politic_side_number;
    int enemy_politic_side_number;
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
    int id_of_moving_troppers;
    int number_of_moving_troopers;
    int is_moving;
    struct troop troopers[1000];
};
struct player_himself{
    int player_id;
    int is_on;
    int till_end_a;
    int does_have_kyber;
    int create_trooper_rate;
};
struct kyber_cristal{
    int type;
    int x;
    int y;
    int is_on;
    int is_dead;
    struct timeval time;
    double seconds_till_off;
    int player_id;
};
struct leaderboard_or_something{
    char name[100];
    int score;
    int rank;
};
int sgn(int a);
void pageminusone();
void page0();
void page1();
void page2();
void page3();
void page4();
void page10();
void winpage();
void page1to10();
void rendercpypage0();
void rendercpypage1();
void rendercpypage2();
void rendercpypage3();
void rendercpypage4();
void rendercpypage10();
void rendercpywinpage();
void page2to10();
void pageto1();
void pageto2();
void check_to_create_politic_side(struct politic_side politic_sides[], struct cell cells[][100], int temp_x, int temp_y,int size_of_politic_sides, int a, int b);
void soundchange();
void findtotalofsaves();
int findclickedcell(int click_x, int click_y, int *ret, int id_is_zero);
int check_if_any_enemy_soldier_is_nearby_poli(struct troop *chosen_troop);
int dist_two_point(int i_one, int j_one, int i_two, int j_two);
void spell_type_one(struct troop *chosen_troop);
void spell_type_two_endcheck();
void spell_type_three_endcheck();
void spell_type_four(int player_id);
void spell_type_five();
void moving_troopers_update_location();
void moving_troopers_without_a_home_update_location();
void make_troopers_without_a_home(int q);
void create_cells();
int assign_politic_sides();
void save_the_map();
void load_the_map();
void first_user_save();
int read_users_score(int do_add, char username_entry_text[]);
void create_moving_troopers(int start_loc, int des_loc);
void main_while_operation();
void destroy_the_few_things_left();
void update_politic_sides_of_users();
int did_win();
int did_lose();
void create_kyber();
int calculate_score();
void enemy_ai();
double dist_between_two_poliside(int i, int j);
void leaderboard_set();
void upboard_setup();
void load_everything();
void loadimages();
void rendercpypage1text(char text[],SDL_Surface *textsurface,SDL_Texture *text_texture ,SDL_Rect *target);
void rendercpypage3text(char text[],SDL_Surface *textsurface,SDL_Texture *text_texture ,SDL_Rect *target);


struct player_himself players[11];
struct leaderboard_or_something leaderboard_users[50];
int number_of_leaderboard_users;
int nomansland_playerid;
int main_players_id;

int did_we_even_calculate;
int is_there_any_type_n_kyber[5];

struct troop troops_with_no_home[2000];
int size_of_troops_with_no_home;
int window_width;
int window_height;
int user_score;
int politic_sides_of_user[100];
TTF_Font *number_of_soldiers;
TTF_Font *number_of_soldiers_outline;
TTF_Font *details_page;
TTF_Font *details_page_outline;
SDL_Color white;
SDL_Color black;
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
int doordonot_x,doordonot_y;
int ifyoudefine_x,ifyoudefine_y;
int credits_text_loc_y;
int leaderboard_page_y;

int size_of_closebutton_x_y;
int loc_number_of_enemies_x, loc_number_of_enemies_y;
int number_of_enemies_w, number_of_enemies_h;
int per_user_w, per_user_h;
int mapsel_w, mapsel_h;
int mapseltype_w,mapseltype_h;
int usernametype_w,usernametype_h;
int number_of_nomansland_x, number_of_nomansland_y;
double FPS;
int size_of_each_cell_x,size_of_each_cell_y ,number_of_cells_x, number_of_cells_y;
int first_click;
int second_click;
int is_first_clicked;
int global_second_kyber;
int global_third_kyber;
// struct troop moving_troopers[2000];
// int size_of_moving_troopers=0;
int dist_from_mid;
int dist_moving_trooper_per_sec;
int start_ticks;
double seconds_until_trooper_is_out;
double kybers_time_till_end[5];
int size_of_wall_y;
char username_text[33];
char mapselect[33];
int game_running;
int max_troop_no_mans_land;
int max_troop_in_someones_land;
int start_troop_in_someones_land;
int rand_start_y;
int rand_start_x;
int added_score;
int did_win_int;

int number_of_enemies;
int number_of_politic_sides_per_user;
int number_of_nomansland;
int upboardwidth[15];
int total_of_soldiers_in_map;
int number_of_systems_of_the_user;

struct timeval the_begin;

SDL_Surface *startbackground;
SDL_Surface *starsbackground;
SDL_Surface *winbackground;
SDL_Surface *leaderboardbackground;
SDL_Surface *losebackground;
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
SDL_Surface *updownbutton;
SDL_Surface *faces[15];
SDL_Surface *troopers[15];
SDL_Surface *planets_photos[15];
SDL_Surface *upboardcolor[15];
SDL_Surface *kybersaber[15];
SDL_Surface *lightsaberhandle;
SDL_Surface *kyber_cristal_photos[5];
SDL_Surface *kyber_cristalon_photos[5];
SDL_Surface *wall;
SDL_Surface *wallflipped;
SDL_Surface *backtomenu;
SDL_Surface *savebutton;
SDL_Surface *doordonot;
SDL_Surface *ifyoudefine;

Mix_Music *menu_music;
Mix_Music *game_music;
Mix_Music *intro_music;

SDL_Rect closebutton_target;

SDL_Rect updownbutton_target;
SDL_Rect updownbutton_sec_target;
SDL_Rect updownbutton_thi_target;
SDL_Rect updownbutton_fou_target;
SDL_Rect updownbutton_fiv_target;
SDL_Rect updownbutton_six_target;
SDL_Rect updownbutton_sev_target;

SDL_Rect wall_target;
SDL_Rect wallflipped_target;
SDL_Rect backtomenu_target;
SDL_Rect savebutton_target;
SDL_Rect sound_target;

SDL_Rect new_game_target;
SDL_Rect load_game_target;
SDL_Rect leaderboard_target;
SDL_Rect credits_target;
SDL_Rect start_game_target;
SDL_Rect backbutton_target;
SDL_Rect enemies_target;
SDL_Rect per_user_target;
SDL_Rect username_target;
SDL_Rect maxtrooperinplayers_house;
SDL_Rect maxtrooperinnomansland_target;
SDL_Rect start_troop_insomo_la_target;
SDL_Rect number_of_systems_of_user_target;
SDL_Rect win_page_target;
SDL_Rect mapsel_target;

SDL_Rect number_of_nomansland_target;
SDL_Rect textbox_target;
SDL_Surface *textbox;


SDL_Surface *shariflogobef;
SDL_Surface *shariflogo;
SDL_Surface *lucasfilmlogobef;
SDL_Surface *lucasfilmlogo;
SDL_Surface *gamelogobef;
SDL_Surface *gamelogo;
SDL_Surface *menubef;
SDL_Surface *menubefwithlogo;






SDL_Event ev;
int page;
struct cell cells[100][100];
struct politic_side politic_sides[100];
struct kyber_cristal kybers[100];
int size_of_kybers;
int size_of_politic_sides;
int is_sound_on,size_of_cells;
int writing_mode_username,size_of_text_username;
int writing_mode_map_select,size_of_text_mapselect;
int selected_map_num;
int mapnumsel;
time_t time_now;
time_t game_start_time;
time_t start_time;
time_t start_time_troop;
time_t calc_time;

SDL_Texture *movingtrooper_texture[10];
SDL_Texture *kybertexture[5];
SDL_Texture *kyberontexture[5];
SDL_Texture *kybersabertexture[15];
SDL_Texture *facestexture[15];
SDL_Texture *planetphotostexture[15];
SDL_Texture *savebuttontexture;
SDL_Texture *backtomenutexture;
SDL_Texture *soundtexture;
SDL_Texture *closebutton_texture;
SDL_Texture *walltexture;
SDL_Texture *wallflippedtexture;
SDL_Texture *handletexture;
SDL_Texture *newgame_texture;
SDL_Texture *loadgame_texture;
SDL_Texture *leaderboard_texture;
SDL_Texture *creditstexture;
SDL_Texture *backbuttontexture;
SDL_Texture *startgametexture;
SDL_Texture *updownbutton_texture;
SDL_Texture *creditstext_texture;
SDL_Texture *textbox_texture;
SDL_Texture *quote_texture;
SDL_Texture *doordonot_texture;
SDL_Texture *upboardcolortexture[15];


SDL_Renderer* renderer;
SDL_Window* window;
#endif // LOADEVERYTHINGH