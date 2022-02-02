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
int findclickedcell(int click_x, int click_y, int *ret, int id_is_zero)
{
    for(int j=0;j<size_of_politic_sides;j++)
    {
        politic_sides[j].cells_x[0];
        politic_sides[j].cells_y[0];
        if(click_x>cells[politic_sides[j].cells_x[0]][politic_sides[j].cells_y[0]].x && click_x<cells[politic_sides[j].cells_x[0]][politic_sides[j].cells_y[0]].x + size_of_each_cell_x
        && click_y>cells[politic_sides[j].cells_x[0]][politic_sides[j].cells_y[0]].y && click_y<cells[politic_sides[j].cells_x[0]][politic_sides[j].cells_y[0]].y + size_of_each_cell_y)
        {
            if((id_is_zero==1 && politic_sides[j].player_id==0) || id_is_zero==0)
            {
                // printf("%d\n", j);
                *ret=j;
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
            if(politic_sides[j].troopers[i].is_out==0 && (tv.tv_sec -politic_sides[j].troopers[i].time.tv_sec)*1000000 + tv.tv_usec-politic_sides[j].troopers[i].time.tv_usec >politic_sides[j].troopers[i].seconds_till_out)
            {
                politic_sides[politic_sides[j].troopers[i].politic_side_number].number_of_troopers--;
                politic_sides[j].troopers[i].is_out=1;
            }
            if(politic_sides[j].troopers[i].did_end==1 || politic_sides[j].troopers[i].is_out==0)
                continue;
            int m = politic_sides[j].troopers[i].current_x - politic_sides[j].troopers[i].dest_x;
            int n = politic_sides[j].troopers[i].current_y - politic_sides[j].troopers[i].dest_y;
            if(abs(politic_sides[j].troopers[i].dest_x - politic_sides[j].troopers[i].current_x)>5)
            {
                politic_sides[j].troopers[i].current_y = (double)((politic_sides[j].troopers[i].dest_y*politic_sides[j].troopers[i].till_end_a) + politic_sides[j].troopers[i].current_y
                                            *(politic_sides[j].troopers[i].dest_x - politic_sides[j].troopers[i].current_x - politic_sides[j].troopers[i].till_end_a))
                                            /(double)(politic_sides[j].troopers[i].dest_x - politic_sides[j].troopers[i].current_x);
                // politic_sides[j].troopers[i].current_y += politic_sides[j].troopers[i].till_end_a/tan((double)m/(double)n);
                politic_sides[j].troopers[i].current_x += politic_sides[j].troopers[i].till_end_a; 
            }
            else
            {
                politic_sides[j].troopers[i].current_y += politic_sides[j].troopers[i].till_end_a;
            }
            // printf("%d %d %d\n", politic_sides[j].troopers[i].current_x, politic_sides[j].troopers[i].current_y, i);
            m = politic_sides[j].troopers[i].current_x - politic_sides[j].troopers[i].dest_x;
            n = politic_sides[j].troopers[i].current_y - politic_sides[j].troopers[i].dest_y;
            if(sqrt(m*m+n*n) < size_of_each_cell_x*1/5)
            {
                if(i==politic_sides[j].number_of_moving_troppers-1)
                    politic_sides[j].number_of_moving_troppers=0;
                politic_sides[j].troopers[i].did_end=1;
                if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id!=politic_sides[j].player_id)
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers--;
                else
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers++;
                if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers<0 && politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id!=politic_sides[j].player_id)
                {
                    politic_sides_of_user[politic_sides[j].troopers[i].enemy_politic_side_number]--;
                    politic_sides_of_user[j]++;
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id=politic_sides[j].player_id;
                }
            }
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
    int politic_sides_of_user_temp=0;
    for(int i=0;i<=number_of_enemies*number_of_politic_sides_per_user*3;i++)
    {
        politic_sides_of_user_temp=0;
        int temp_id;
        while(politic_sides_of_user_temp<number_of_politic_sides_per_user)
        {
            int temp_x = rand()%number_of_cells_x;
            int temp_y = rand()%number_of_cells_y;
            if(cells[temp_x][temp_y].is_territoy==1 && cells[temp_x][temp_y].is_occupied!=1)
            {
                cells[temp_x][temp_y].is_occupied=1;
                if(i>number_of_enemies)
                {
                    if(politic_sides_of_user_temp==1)
                        break;
                    politic_sides[size_of_politic_sides].player_id=10;
                }
                else if(i==0)
                    politic_sides[size_of_politic_sides].player_id=0;
                else
                {
                    int temp_rand;
                    if(politic_sides_of_user_temp!=0)
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
                politic_sides[size_of_politic_sides].number_of_troopers = start_troop_in_someones_land;
                if(politic_sides[size_of_politic_sides].player_id==10)
                    politic_sides[size_of_politic_sides].number_of_troopers = max_troop_no_mans_land;
                politic_sides[size_of_politic_sides].size_of_cells=1;
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
                politic_sides_of_user_temp++;
                politic_sides_of_user[i]=politic_sides_of_user_temp;

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

double count_moving_troopers(double last)
{
    if(abs(seconds_until_trooper_is_out * last/3)<0.3)
        return last;
    return last + count_moving_troopers(seconds_until_trooper_is_out * last/3);
}

void create_moving_troopers()
{
    is_first_clicked=0;
    // int last_sec = (seconds_until_trooper_is_out * floor((politic_sides[first_click].number_of_troopers-1)/3) + politic_sides[first_click].number_of_troopers+difftime(time_now,start_time));
    int last_sec = (int)count_moving_troopers((double)politic_sides[first_click].number_of_troopers) +1;
    for(int i=0;i<last_sec;i++)
    {
        int size_of_moving_troopers = politic_sides[first_click].number_of_moving_troppers;
        struct timeval tv;
        gettimeofday(&tv,NULL);
        politic_sides[first_click].troopers[size_of_moving_troopers].time = tv;
        politic_sides[first_click].troopers[size_of_moving_troopers].politic_side_number = first_click;
        politic_sides[first_click].troopers[size_of_moving_troopers].enemy_politic_side_number = second_click;
        politic_sides[first_click].troopers[size_of_moving_troopers].seconds_till_out = seconds_until_trooper_is_out*1000000 * floor(i/3);
        politic_sides[first_click].troopers[size_of_moving_troopers].is_out = 0;
        politic_sides[first_click].troopers[size_of_moving_troopers].did_end=0;
        politic_sides[first_click].troopers[size_of_moving_troopers].current_x= cells[politic_sides[first_click].cells_x[0]][politic_sides[first_click].cells_y[0]].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
        politic_sides[first_click].troopers[size_of_moving_troopers].current_y= cells[politic_sides[first_click].cells_x[0]][politic_sides[first_click].cells_y[0]].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
        politic_sides[first_click].troopers[size_of_moving_troopers].dest_x = cells[politic_sides[second_click].cells_x[0]][politic_sides[second_click].cells_y[0]].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
        politic_sides[first_click].troopers[size_of_moving_troopers].dest_y = cells[politic_sides[second_click].cells_x[0]][politic_sides[second_click].cells_y[0]].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
        int dist_x,dist_y = size_of_each_cell_y/4;
        if(size_of_moving_troopers%3!=1)
        {
            if(abs(politic_sides[first_click].troopers[size_of_moving_troopers].current_x - politic_sides[first_click].troopers[size_of_moving_troopers].dest_x)>5)
            {
                dist_x= -dist_y
                *(politic_sides[first_click].troopers[size_of_moving_troopers].current_y - politic_sides[first_click].troopers[size_of_moving_troopers].dest_y)
                /(politic_sides[first_click].troopers[size_of_moving_troopers].current_x - politic_sides[first_click].troopers[size_of_moving_troopers].dest_x);
            }
            else
            {
                dist_x= size_of_each_cell_x/4;
                dist_y =0;
            }
            if(abs(dist_x)>size_of_each_cell_x/4)
                dist_x=sgn(dist_x)*size_of_each_cell_x/4;
            if(size_of_moving_troopers%3==0)
            {
                politic_sides[first_click].troopers[size_of_moving_troopers].current_y += dist_y;
                politic_sides[first_click].troopers[size_of_moving_troopers].current_x += dist_x;
                politic_sides[first_click].troopers[size_of_moving_troopers].dest_y += dist_y;
                politic_sides[first_click].troopers[size_of_moving_troopers].dest_x += dist_x;
            }
            else if(size_of_moving_troopers%3==2)
            {
                politic_sides[first_click].troopers[size_of_moving_troopers].current_y -= dist_y;
                politic_sides[first_click].troopers[size_of_moving_troopers].current_x -= dist_x;
                politic_sides[first_click].troopers[size_of_moving_troopers].dest_y -= dist_y;
                politic_sides[first_click].troopers[size_of_moving_troopers].dest_x -= dist_x;
            }
        }
        // printf("%d %d\n", politic_sides[first_click].troopers[size_of_moving_troopers].current_x,politic_sides[first_click].troopers[size_of_moving_troopers].current_y);
        int m= (politic_sides[first_click].troopers[i].dest_x - politic_sides[first_click].troopers[i].current_x);
        int n= (politic_sides[first_click].troopers[i].dest_y - politic_sides[first_click].troopers[i].current_y);
        politic_sides[first_click].troopers[size_of_moving_troopers].till_end_a = dist_moving_trooper_per_sec*m/sqrt(m*m+n*n);
        if(politic_sides[first_click].troopers[size_of_moving_troopers].till_end_a==0)
            politic_sides[first_click].troopers[size_of_moving_troopers].till_end_a = dist_moving_trooper_per_sec*n/sqrt(m*m+n*n);
        // printf("--%d--\n",politic_sides[first_click].troopers[size_of_moving_troopers].till_end_a);
        politic_sides[first_click].troopers[size_of_moving_troopers].player_id = politic_sides[first_click].player_id;
        politic_sides[first_click].number_of_moving_troppers++;
    }
}
void stop_the_moving_troopers__new_destination(int firs_t)
{
    int new_num_mov_tro=0;
    for(int i=0;i<politic_sides[firs_t].number_of_moving_troppers;i++)
        if(politic_sides[firs_t].troopers[i].is_out==0)
            new_num_mov_tro++;
    
    politic_sides[firs_t].number_of_moving_troppers = 0;
    politic_sides[firs_t].number_of_troopers = new_num_mov_tro;
}
int sgn(int a)
{
    if(a<0)
        return -1;
    return 1;
}
void main_while_operation()
{
    while (1) 
    {
        start_ticks = SDL_GetTicks();
        time(&time_now);
        if(page==0)
            page0();
        else if(page==1)
            page1();
        else if(page==2)
            page2();
        else if(page==4)
            page4();
        else if (page==10)
            page10();
        if(game_running==0)
            break;
        SDL_RenderClear(renderer);
        if(difftime(time_now,start_time_troop)>=0.3)
            time(&start_time_troop);
        if(difftime(time_now,start_time)>=1)
            time(&start_time);
        while (SDL_GetTicks() - start_ticks < 1000 / FPS);
    }
}
void destroy_the_few_things_left()
{
    Mix_FreeMusic(menu_music);
    Mix_FreeMusic(game_music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}
void update_politic_sides_of_users()
{
    for(int i = 0; i<size_of_politic_sides;i++)
        politic_sides_of_user[politic_sides[i].player_id]++;
}
int check_for_winner()
{
    int number_of_players_left=0;
    for(int i = 0; i<number_of_enemies+1; i++)
    {
        if(politic_sides_of_user[i]>0)
            number_of_players_left++;
    }
    printf("%d\n",number_of_players_left);
    return number_of_players_left;
}