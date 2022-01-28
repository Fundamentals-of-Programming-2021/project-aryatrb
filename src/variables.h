struct cell{
    int x;
    int y;
    int is_territoy;
    SDL_Surface *photo;
    int id;
    int does_it_have_military;
    int is_occupied;
};
struct politic_side{
    int cells_x[7];
    int cells_y[7];
    int size_of_cells;
    int player_id;
    SDL_Surface *leader_face;
    SDL_Surface *trooper;
    int number_of_troopers;
};
struct kyber_cristal{
    SDL_Surface *kyber_photo;
    int x;
    int y;
};


int number_of_enemies=4;
int number_of_politic_sides_per_user=1;
int window_width;
int window_height;
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
SDL_GetRendererOutputSize(renderer,&window_width,&window_height);
const double FPS = 30;
int window_width;
int window_height;
int size_new_game_x = 327*window_width/1335,size_new_game_y=37*window_height/801;
int size_load_game_x = 327*window_width/1335,size_load_game_y=37*window_height/801;
int leaderboard_game_x = 327*window_width/1335,leaderboard_game_y=37*window_height/801;
int size_credits_x = 327*window_width/1335,size_credits_y=37*window_height/801;
int backbutton_x_y=50;
int start_game_x = 327*window_width/1335 , start_game_y =37*window_height/801;
int generatemap_x = 327*window_width/1335 , generatemap_y =37*window_height/801;
int size_of_leaders_x_y=45;
int size_of_troopers_x_y=20;
int size_of_kyber_photo_x = 40, size_of_kyber_photo_y=72;
int credits_text_x=1100*window_width/1335,credits_text_y=1307*window_height/801;
int credits_text_loc_y=5;
int size_of_closebutton_x_y = 20;
int loc_number_of_enemies_x = window_width*0.1, loc_number_of_enemies_y = window_height*0.1;
int number_of_enemies_w, number_of_enemies_h;