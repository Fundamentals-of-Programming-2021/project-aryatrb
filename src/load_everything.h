int sgn(int a);
void page0();
void page1();
void page2();
void page4();
void page10();
void loadimages();
void rendercpypage0();
void rendercpypage1();
void rendercpypage2();
void rendercpypage4();
void rendercpypage10();
void page1to10();
int calculate_score();
void winpage();
void moving_troopers_without_a_home_update_location();
void make_troopers_without_a_home(int q);

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
    int number_of_moving_troppers;
    int is_moving;
    struct troop troopers[1000];
};
struct kyber_cristal{
    int type;
    int x;
    int y;
};

struct troop troops_with_no_home[2000];
int size_of_troops_with_no_home=0;
int window_width;
int window_height;
int user_score;
int politic_sides_of_user[100] = {0};
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
int doordonot_x,doordonot_y;
int ifyoudefine_x,ifyoudefine_y;
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
int first_click=-10;
int second_click;
int is_first_clicked=0;
// struct troop moving_troopers[2000];
// int size_of_moving_troopers=0;
int dist_from_mid=10;
int dist_moving_trooper_per_sec=10;
int start_ticks;
double seconds_until_trooper_is_out = 0.18;
int size_of_wall_y=40;
char username_text[33] = "............................";
char mapselect[33] = "............................";
int game_running=1;
int max_troop_no_mans_land=20;
int max_troop_in_someones_land=50;
int start_troop_in_someones_land=10;
int rand_start_y;
int rand_start_x;
int added_score;
int did_win_int=0;

int number_of_enemies=4;
int number_of_politic_sides_per_user=1;


SDL_Surface *startbackground;
SDL_Surface *starsbackground;
SDL_Surface *winbackground;
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
SDL_Surface *kyber_cristal_photos[4];
SDL_Surface *wall;
SDL_Surface *wallflipped;
SDL_Surface *backtomenu;
SDL_Surface *doordonot;
SDL_Surface *ifyoudefine;

Mix_Music *menu_music;
Mix_Music *game_music;

SDL_Rect closebutton_target;

SDL_Rect updownbutton_target;
SDL_Rect updownbutton_sec_target;

SDL_Rect wall_target;
SDL_Rect wallflipped_target;
SDL_Rect backtomenu_target;
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
SDL_Rect win_page_target;


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
time_t game_start_time;
time_t start_time;
time_t start_time_troop;
time_t calc_time;

SDL_Texture *movingtrooper_texture[10];


SDL_Renderer* renderer;
SDL_Window* window;
void load_everything()
{
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
    size_of_kyber_photo_x = 40, size_of_kyber_photo_y=72;
    credits_text_x=1100*window_width/1335,credits_text_y=1307*window_width/1335;
    doordonot_x = 726*window_width/1335, doordonot_y = 37*window_width/1335;
    ifyoudefine_x = 801*window_width/1335, ifyoudefine_y = 115*window_width/1335;
    credits_text_loc_y=5;
    size_of_closebutton_x_y = 20;
    loc_number_of_enemies_x = window_width*0.1, loc_number_of_enemies_y = window_height*0.1;


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

    closebutton_target.x = window_width - 10 - size_of_closebutton_x_y;
    closebutton_target.y = 25 - size_of_closebutton_x_y;
    closebutton_target.w = size_of_closebutton_x_y;
    closebutton_target.h = size_of_closebutton_x_y;
    updownbutton_target.x = loc_number_of_enemies_x + number_of_enemies_w + 10*window_width/1920;
    updownbutton_target.y = loc_number_of_enemies_y;
    updownbutton_target.w = 40*window_width/1920;
    updownbutton_target.h = 60*window_width/1920;
    updownbutton_sec_target.x = loc_number_of_enemies_x + per_user_w + 10*window_width/1920;
    updownbutton_sec_target.y = loc_number_of_enemies_y + per_user_h + 10*window_width/1920;
    updownbutton_sec_target.w = 40*window_width/1920;
    updownbutton_sec_target.h = 60*window_width/1920;
    wall_target.x = 0;
    wall_target.y = window_height - size_of_wall_y;
    wall_target.w = window_width;
    wall_target.h = size_of_wall_y;
    wallflipped_target.x = 0;
    wallflipped_target.y = 0;
    wallflipped_target.w = window_width;
    wallflipped_target.h = size_of_wall_y;
    backtomenu_target.x = 60;
    backtomenu_target.y = window_height - 35;
    backtomenu_target.w = 60;
    backtomenu_target.h = 30;
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
    enemies_target.y = loc_number_of_enemies_y;
    enemies_target.w = number_of_enemies_w;
    enemies_target.h = number_of_enemies_h;
    per_user_target.x = loc_number_of_enemies_x;
    per_user_target.y = loc_number_of_enemies_y + number_of_enemies_h + 10;
    per_user_target.w = per_user_w;
    per_user_target.h = per_user_h;
    username_target.x = loc_number_of_enemies_x;
    username_target.y = loc_number_of_enemies_y + 2* (number_of_enemies_h + 10);
    username_target.w = usernametype_w;
    username_target.h = usernametype_h;

    time(&start_time);
    time(&start_time_troop);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    menu_music = Mix_LoadMUS("assets/menu.mp3");
    game_music = Mix_LoadMUS("assets/Anakins_Symphony.mp3");
    Mix_PlayMusic(menu_music,-1);
    loadimages();
}

void loadimages()
{
    double ratio = (double)window_width/(double)window_height;
    
    if(ratio - 3/2< 0.0000001 && ratio - 3/2> -0.0000001)
    {
        winbackground = SDL_LoadBMP("assets/vaderrogueone3-2.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning3-2.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource3-2.bmp");
        startbackground = SDL_LoadBMP("assets/background3-2.bmp");
    }
    else if(ratio - 4/3 < 0.0001 && ratio - 4/3 > -0.0001)
    {
        winbackground = SDL_LoadBMP("assets/vaderrogueone4-3.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning4-3.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource4-3.bmp");
        startbackground = SDL_LoadBMP("assets/background4-3.bmp");
    }
    else if(ratio - 5/4< 0.0001 && ratio - 5/4> -0.0001)
    {
        winbackground = SDL_LoadBMP("assets/vaderrogueone5-4.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning5-4.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource5-4.bmp");
        startbackground = SDL_LoadBMP("assets/background5-4.bmp");
    }
    else if(ratio - 16/10< 0.0001 && ratio - 16/10> -0.0001)
    {
        winbackground = SDL_LoadBMP("assets/vaderrogueone16-10.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning16-10.bmp");
        new_game_background = SDL_LoadBMP("assets/backgroundtroopersource16-10.bmp");
        startbackground = SDL_LoadBMP("assets/background16-10.bmp");
    }
    else
    {
        winbackground = SDL_LoadBMP("assets/vaderrogueone16-9.bmp");
        losebackground = SDL_LoadBMP("assets/vaderburning16-9.bmp");
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
    updownbutton = SDL_LoadBMP("assets/updown.bmp");
    soundonphoto = SDL_LoadBMP("assets/soundon.bmp");
    doordonot = SDL_LoadBMP("assets/doordonot.bmp");
    ifyoudefine = SDL_LoadBMP("assets/ifyoudefine.bmp");
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
}