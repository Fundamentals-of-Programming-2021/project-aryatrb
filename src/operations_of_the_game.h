void check_to_create_politic_side(struct politic_side politic_sides[], struct cell cells[][100], int temp_x, int temp_y,int size_of_politic_sides, int a, int b)
{
    if(temp_x+a>number_of_cells_x-1 || temp_x+a<0 || temp_y+b>number_of_cells_y-1 || temp_y+a<0)
        return;
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
            if((id_is_zero==1 && politic_sides[j].player_id==main_players_id) || id_is_zero==0)
            {
                *ret=j;
                return 1;
            }
        }
    }
    return 0;
}
int check_if_any_enemy_soldier_is_nearby_poli(struct troop *chosen_troop)
{
    for(int i=0;players[chosen_troop->player_id].does_have_kyber==-1 && i<size_of_kybers;i++)
    {
        if(kybers[i].is_on==0 && kybers[i].is_dead==0 &&
           dist_two_point(chosen_troop->current_x+size_of_troopers_x_y/2, chosen_troop->current_y+size_of_troopers_x_y/2, kybers[i].x + size_of_kyber_photo_x/2,kybers[i].y+size_of_kyber_photo_y/2)
           <size_of_kyber_photo_y)
        {
            players[chosen_troop->player_id].does_have_kyber=i;
            kybers[i].is_on=1;
            kybers[i].player_id=chosen_troop->player_id;
            if(kybers[i].type==1)
                for(int i=0;i<number_of_enemies+1;i++)
                    if(i!=chosen_troop->player_id)
                        players[i].till_end_a*=3;
            if(kybers[i].type==2)
                for(int i=0;i<number_of_enemies+1;i++)
                    if(i!=chosen_troop->player_id)
                        players[i].till_end_a=0;
            gettimeofday(&kybers[i].time,NULL);
        }
    }
    for(int i=0;i<size_of_politic_sides;i++)
    {
        for(int j=0;j<politic_sides[i].id_of_moving_troppers;j++)
        {
            if(politic_sides[i].troopers[j].is_out==1 && politic_sides[i].troopers[j].did_end==0 && 
                politic_sides[i].troopers[j].player_id!=chosen_troop->player_id &&
                dist_two_point(chosen_troop->current_x, chosen_troop->current_y, politic_sides[i].troopers[j].current_x,politic_sides[i].troopers[j].current_y)
             <size_of_troopers_x_y*1.5)
             {
                 politic_sides[i].troopers[j].did_end=1;
                 chosen_troop->did_end=1;
                 return 1;
             }
        }
    }
    for(int i=0;i<size_of_troops_with_no_home;i++)
    {
        if(troops_with_no_home[i].is_out==1 && troops_with_no_home[i].did_end==0 &&
        dist_two_point(chosen_troop->current_x, chosen_troop->current_y, troops_with_no_home[i].current_x, troops_with_no_home[i].current_y)
        <size_of_troopers_x_y*1.5)
        {
            troops_with_no_home[i].did_end=1;
            chosen_troop->did_end=1;
            return 1;
        }
    }
    return 0;
}
int dist_two_point(int i_one, int j_one, int i_two, int j_two)
{
    return sqrt((i_one-i_two)*(i_one-i_two)+(j_one-j_two)*(j_one-j_two));
}
void spell_type_one(struct troop *chosen_troop)
{
    struct timeval tv;
    if(players[chosen_troop->player_id].does_have_kyber==-1 || kybers[players[chosen_troop->player_id].does_have_kyber].type!=0)
    {
        players[chosen_troop->player_id].till_end_a = dist_moving_trooper_per_sec;
        return;
    }
    gettimeofday(&tv,NULL);
    if((tv.tv_sec - kybers[players[chosen_troop->player_id].does_have_kyber].time.tv_sec)*1000000 +
        tv.tv_usec - kybers[players[chosen_troop->player_id].does_have_kyber].time.tv_usec
        >
        kybers_time_till_end[0])
        {
            kybers[players[chosen_troop->player_id].does_have_kyber].is_dead=1;
            players[chosen_troop->player_id].till_end_a =dist_moving_trooper_per_sec;
            players[chosen_troop->player_id].does_have_kyber=-1;
        }
    else if(players[chosen_troop->player_id].does_have_kyber!=-1 &&
            kybers[players[chosen_troop->player_id].does_have_kyber].type==0 &&
            kybers[players[chosen_troop->player_id].does_have_kyber].is_dead==0)
        players[chosen_troop->player_id].till_end_a=dist_moving_trooper_per_sec*3;
}
void spell_type_two_endcheck()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    for(int i=0;i<size_of_kybers;i++)
    {
        if(kybers[i].type==1 && kybers[i].is_dead==0 && kybers[i].is_on==1)
        {
            if((tv.tv_sec - kybers[i].time.tv_sec)*1000000 +
            tv.tv_usec - kybers[i].time.tv_usec
            >
            kybers_time_till_end[1])
            {
                kybers[i].is_dead=1;
                for(int i=0;i<10;i++)
                    if(i!=kybers[i].player_id)
                        players[i].till_end_a /=3;
                players[kybers[i].player_id].does_have_kyber=-1;
            }
        }
    }
}
void spell_type_three_endcheck()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    for(int i=0;i<size_of_kybers;i++)
    {
        if(kybers[i].type==2 && kybers[i].is_dead==0 && kybers[i].is_on==1)
        {
            if((tv.tv_sec - kybers[i].time.tv_sec)*1000000 +
            tv.tv_usec - kybers[i].time.tv_usec
            >
            kybers_time_till_end[2])
            {
                kybers[i].is_dead=1;
                for(int i=0;i<10;i++)
                    if(i!=kybers[i].player_id)
                        players[i].till_end_a = dist_moving_trooper_per_sec;
                players[kybers[i].player_id].does_have_kyber=-1;
            }
        }
    }
}
void spell_type_four(int player_id)
{
    struct timeval tv;
    if(players[player_id].does_have_kyber==-1 || kybers[players[player_id].does_have_kyber].type!=3)
    {
        return;
    }
    gettimeofday(&tv,NULL);
    if((tv.tv_sec - kybers[players[player_id].does_have_kyber].time.tv_sec)*1000000 +
        tv.tv_usec - kybers[players[player_id].does_have_kyber].time.tv_usec
        >
        kybers_time_till_end[3])
        {
            kybers[players[player_id].does_have_kyber].is_dead=1;
            players[player_id].create_trooper_rate = 1;
            players[player_id].does_have_kyber=-1;
        }
    else if(players[player_id].does_have_kyber!=-1 &&
            kybers[players[player_id].does_have_kyber].type==3 &&
            kybers[players[player_id].does_have_kyber].is_dead==0)
        players[player_id].create_trooper_rate=3;
}
void spell_type_five()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    for(int i = 0 ; i< number_of_enemies+1;i++)
    {
        if(players[i].does_have_kyber!=-1 &&
            kybers[players[i].does_have_kyber].type==4 &&
            kybers[players[i].does_have_kyber].is_dead==0 &&
            (tv.tv_sec - kybers[players[i].does_have_kyber].time.tv_sec)*1000000 +
        tv.tv_usec - kybers[players[i].does_have_kyber].time.tv_usec
        >
        kybers_time_till_end[4])
        {
            kybers[players[i].does_have_kyber].is_dead=1;
            players[i].does_have_kyber=-1;
        }
    }
}
void moving_troopers_update_location()
{
    struct timeval tv;
    for(int j=0;j<size_of_politic_sides;j++)
        for(int i = 0 ; i<politic_sides[j].id_of_moving_troppers; i++)
        {
            gettimeofday(&tv,NULL);
            if(politic_sides[j].troopers[i].is_out==0 && (tv.tv_sec -politic_sides[j].troopers[i].time.tv_sec)*1000000 + tv.tv_usec-politic_sides[j].troopers[i].time.tv_usec >politic_sides[j].troopers[i].seconds_till_out)
            {
                politic_sides[politic_sides[j].troopers[i].politic_side_number].number_of_troopers--;
                politic_sides[j].number_of_moving_troopers--;
                politic_sides[j].troopers[i].is_out=1;
            }
            if(politic_sides[j].troopers[i].did_end==1 || politic_sides[j].troopers[i].is_out==0)
                continue;
            if(check_if_any_enemy_soldier_is_nearby_poli(&politic_sides[j].troopers[i]))
                continue;
            
            // if(players[politic_sides[j].player_id].does_have_kyber!=-1 && kybers[players[politic_sides[j].player_id].does_have_kyber].type==0 && kybers[players[politic_sides[j].player_id].does_have_kyber].is_dead==0)
                spell_type_one(&politic_sides[j].troopers[i]);
            // if(players[politic_sides[j].player_id].does_have_kyber!=-1 && kybers[players[politic_sides[j].player_id].does_have_kyber].type==3 && kybers[players[politic_sides[j].player_id].does_have_kyber].is_dead==0)
            int m = politic_sides[j].troopers[i].dest_x - politic_sides[j].troopers[i].current_x;
            int sgn_m = sgn(m);
            m = abs(m);
            int n = politic_sides[j].troopers[i].dest_y - politic_sides[j].troopers[i].current_y;
            int sgn_n = sgn(n);
            n = abs(n);
            if(abs(m)>abs(n) && m!=0 && n!=0)
            {
                politic_sides[j].troopers[i].current_x += ceil(players[politic_sides[j].player_id].till_end_a*(double)m/(double)(sqrt(m*m+n*n))*sgn_m);
                politic_sides[j].troopers[i].current_y += ceil(players[politic_sides[j].player_id].till_end_a)*(double)n/(double)(sqrt(m*m+n*n))*sgn_n;
            }
            else if(m!=0 && n!=0)
            {
                politic_sides[j].troopers[i].current_x += ceil(players[politic_sides[j].player_id].till_end_a)*(double)m/(double)(sqrt(m*m+n*n))*sgn_m;
                politic_sides[j].troopers[i].current_y += ceil((players[politic_sides[j].player_id].till_end_a)*(double)n/(double)(sqrt(m*m+n*n))*sgn_n);
            }
            else if(m==0)
                politic_sides[j].troopers[i].current_y += players[politic_sides[j].player_id].till_end_a*sgn_n;
            else if(n==0)
                politic_sides[j].troopers[i].current_x += players[politic_sides[j].player_id].till_end_a*sgn_m;
            m = politic_sides[j].troopers[i].current_x - politic_sides[j].troopers[i].dest_x;
            n = politic_sides[j].troopers[i].current_y - politic_sides[j].troopers[i].dest_y;
            if(sqrt(m*m+n*n) < size_of_each_cell_x*1/5)
            {
                if(i==politic_sides[j].id_of_moving_troppers-1)
                {
                    politic_sides[j].id_of_moving_troppers=0;
                    politic_sides[j].number_of_moving_troopers=0;
                }
                politic_sides[j].troopers[i].did_end=1;
                if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id!=politic_sides[j].player_id)
                {
                    if(players[politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id].does_have_kyber!=-1 &&
                       kybers[players[politic_sides[j].troopers[i].enemy_politic_side_number].does_have_kyber].type==4 &&
                       kybers[players[politic_sides[j].troopers[i].enemy_politic_side_number].does_have_kyber].is_dead==0)
                    {
                        politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers++;  
                        if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_moving_troopers>politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers)
                            politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_moving_troopers++;    
                    }
                    else   
                    {
                        politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers--;
                        if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_moving_troopers>politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers)
                            politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_moving_troopers--;    
                    }
                }
                else
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers++;
                if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers<0 && politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id!=politic_sides[j].player_id)
                {
                    
                    politic_sides_of_user[politic_sides[j].troopers[i].enemy_politic_side_number]--;
                    politic_sides_of_user[politic_sides[j].player_id]++;
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].player_id=politic_sides[j].player_id;
                    make_troopers_without_a_home(politic_sides[j].troopers[i].enemy_politic_side_number);
                    for(int i=0;i<politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].id_of_moving_troppers;i++)
                        if(politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].troopers[i].is_out==0)
                            politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].troopers[i].seconds_till_out=0;
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].id_of_moving_troppers=0;
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_troopers=0;
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].number_of_moving_troopers=0;
                    politic_sides[politic_sides[j].troopers[i].enemy_politic_side_number].is_moving=0;
                }
                if(politic_sides[j].id_of_moving_troppers<=0)
                    politic_sides[j].is_moving=0;
            }
        }
}
void moving_troopers_without_a_home_update_location()
{
    struct timeval tv;
    for(int i = 0 ; i<size_of_troops_with_no_home; i++)
    {
        gettimeofday(&tv,NULL);
        if(troops_with_no_home[i].is_out==0 && (tv.tv_sec -troops_with_no_home[i].time.tv_sec)*1000000 + tv.tv_usec-troops_with_no_home[i].time.tv_usec >troops_with_no_home[i].seconds_till_out)
        {
            politic_sides[troops_with_no_home[i].politic_side_number].number_of_troopers--;
            // politic_sides[troops_with_no_home[i].pla].number_of_moving_troopers--;
            troops_with_no_home[i].is_out=1;
        }
        if(troops_with_no_home[i].did_end==1 || troops_with_no_home[i].is_out==0)
            continue;
        if(check_if_any_enemy_soldier_is_nearby_poli(&troops_with_no_home[i]))
            continue;
        if(players[troops_with_no_home[i].player_id].does_have_kyber!=-1 && kybers[players[troops_with_no_home[i].player_id].does_have_kyber].type==0 && kybers[players[troops_with_no_home[i].player_id].does_have_kyber].is_dead==0)
            spell_type_one(&troops_with_no_home[i]);
        int m = troops_with_no_home[i].dest_x - troops_with_no_home[i].current_x;
        int sgn_m = sgn(m);
        m = abs(m);
        int n = troops_with_no_home[i].dest_y - troops_with_no_home[i].current_y;
        int sgn_n = sgn(n);
        n = abs(n);
        if(abs(m)>abs(n) && m!=0 && n!=0)
        {
            
            troops_with_no_home[i].current_x += ceil(players[troops_with_no_home[i].player_id].till_end_a*(double)m/(double)(sqrt(m*m+n*n))*sgn_m);
            troops_with_no_home[i].current_y += ceil(players[troops_with_no_home[i].player_id].till_end_a)*(double)n/(double)(sqrt(m*m+n*n))*sgn_n;
        }
        else if(m!=0 && n!=0)
        {
            troops_with_no_home[i].current_x += ceil(players[troops_with_no_home[i].player_id].till_end_a)*(double)m/(double)(sqrt(m*m+n*n))*sgn_m;
            troops_with_no_home[i].current_y += ceil((players[troops_with_no_home[i].player_id].till_end_a)*(double)n/(double)(sqrt(m*m+n*n))*sgn_n);
        }
        else if(m==0)
            troops_with_no_home[i].current_y += players[troops_with_no_home[i].player_id].till_end_a*sgn_n;
        else if(n==0)
            troops_with_no_home[i].current_x += players[troops_with_no_home[i].player_id].till_end_a*sgn_m;
        m = troops_with_no_home[i].current_x - troops_with_no_home[i].dest_x;
        n = troops_with_no_home[i].current_y - troops_with_no_home[i].dest_y;
        if(sqrt(m*m+n*n) < size_of_each_cell_x*1/5)
        {
            troops_with_no_home[i].did_end=1;
            if(politic_sides[troops_with_no_home[i].enemy_politic_side_number].player_id!=troops_with_no_home[i].player_id)
            {
                if(players[troops_with_no_home[troops_with_no_home[i].enemy_politic_side_number].player_id].does_have_kyber!=-1 &&
                       kybers[players[troops_with_no_home[i].enemy_politic_side_number].does_have_kyber].type==4 &&
                       kybers[players[troops_with_no_home[i].enemy_politic_side_number].does_have_kyber].is_dead==0)
                {
                        politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers++;
                        if(politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_moving_troopers>politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers)
                            politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_moving_troopers++;
                }
                else
                {
                    politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers--;
                    if(politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_moving_troopers>politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers)
                        politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_moving_troopers--;
                }
            }
            else
                politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers++;
            if(politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers<0 && politic_sides[troops_with_no_home[i].enemy_politic_side_number].player_id!=troops_with_no_home[i].player_id)
            {
                
                politic_sides_of_user[troops_with_no_home[i].enemy_politic_side_number]--;
                politic_sides_of_user[troops_with_no_home[i].player_id]++;
                politic_sides[troops_with_no_home[i].enemy_politic_side_number].player_id=troops_with_no_home[i].player_id;
                make_troopers_without_a_home(troops_with_no_home[i].enemy_politic_side_number);
                politic_sides[troops_with_no_home[i].enemy_politic_side_number].id_of_moving_troppers=0;
                politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_troopers=0;
                politic_sides[troops_with_no_home[i].enemy_politic_side_number].number_of_moving_troopers=0;
                politic_sides[troops_with_no_home[i].enemy_politic_side_number].is_moving=0;
            }
        }
    }
}
void make_troopers_without_a_home(int q)
{
    for(int i=0;i<politic_sides[q].id_of_moving_troppers;i++)
    {
        troops_with_no_home[size_of_troops_with_no_home] = politic_sides[q].troopers[i];
        size_of_troops_with_no_home++;
    }
}
void create_cells()
{
    number_of_cells_x=0;
    number_of_cells_y=0;
    rand_start_y = rand()%size_of_each_cell_y + size_of_wall_y;
    rand_start_x = rand()%size_of_each_cell_x;
    for(int i =0; i*size_of_each_cell_x*3/2 + size_of_each_cell_x*7/4 + rand_start_x < window_width;i++)
        number_of_cells_x++;
    for(int j = 0;(j+1)*size_of_each_cell_y/2 + size_of_each_cell_y + rand_start_y < window_height - size_of_wall_y;j++)
    {
        for(int i=0;i<number_of_cells_x;i++)
        {
            if(j%2==0)
                cells[i][j].x=i*size_of_each_cell_x*3/2 + size_of_each_cell_x*3/4 + rand_start_x;
            else
                cells[i][j].x=i*size_of_each_cell_x*3/2 + rand_start_x;
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
    for(int i =0 ;i<100;i++)
        politic_sides_of_user[i]=0;
    int politic_sides_of_user_temp=0;
    for(int i=0;i<10;i++)
    {
        players[i].till_end_a = dist_moving_trooper_per_sec;
        players[i].does_have_kyber=-1;
        players[i].create_trooper_rate=1;
    }
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
                    politic_sides[size_of_politic_sides].player_id=nomansland_playerid;
                }
                else if(i==main_players_id)
                    politic_sides[size_of_politic_sides].player_id=main_players_id;
                else
                {
                    int temp_rand;
                    if(politic_sides_of_user_temp!=0)
                        temp_rand=temp_id;
                    else
                    {
                        temp_rand=2;
                        while(planets[temp_rand]==1)
                            temp_rand=rand()%number_of_enemies+1;
                        temp_id=temp_rand;
                    }
                    politic_sides[size_of_politic_sides].player_id=temp_id;
                    planets[temp_rand]=1;
                }
                politic_sides[size_of_politic_sides].number_of_troopers = start_troop_in_someones_land;
                if(politic_sides[size_of_politic_sides].player_id==nomansland_playerid)
                    politic_sides[size_of_politic_sides].number_of_troopers = max_troop_no_mans_land;
                politic_sides[size_of_politic_sides].size_of_cells=1;
                politic_sides[size_of_politic_sides].id_of_moving_troppers=0;
                politic_sides[size_of_politic_sides].number_of_moving_troopers=0;
                politic_sides[size_of_politic_sides].is_moving=0;
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
    fprintf(mapwrite,"%s\n", username_text);
    fprintf(mapwrite, "%d %d %d %d\n%d\n%d\n%d\n", number_of_cells_x,number_of_cells_y,rand_start_x, rand_start_y, number_of_enemies,number_of_politic_sides_per_user,size_of_politic_sides);
    for(int j = 0;j<number_of_cells_y;j++)
        for(int i=0;i<number_of_cells_x;i++)
            fprintf(mapwrite,"%d %d %d %d %d %d\n",cells[i][j].x, cells[i][j].y, cells[i][j].is_territoy, cells[i][j].politic_side_number,cells[i][j].does_it_have_military,cells[i][j].is_occupied);
    fprintf(mapwrite,"\n");
    for(int i=0;i<=size_of_politic_sides;i++)
    {
        fprintf(mapwrite,"%d %d %d %d %d %d\n", politic_sides[i].player_id,politic_sides[i].size_of_cells,politic_sides[i].number_of_troopers,politic_sides[i].number_of_moving_troopers, 
        politic_sides[i].id_of_moving_troppers, politic_sides[i].is_moving);
        
        for(int j=0;j<politic_sides[i].size_of_cells;j++)
            fprintf(mapwrite,"%d %d\n",politic_sides[i].cells_x[j],politic_sides[i].cells_y[j]);
        fprintf(mapwrite,"\n");
    }
    fclose(mapwrite);
}
void first_user_save()
{
    char temp_text[80], filechar[40],temper_text[100];
    for(int i=0; i<40 && username_text[i]!='.';i++)
    {
        filechar[i]=username_text[i];
        if(i+1==40 || username_text[i+1]=='.')
        {
            filechar[i+1]='\0';
            break;
        }
    }
    FILE *mapsave = fopen("assets/leaderboard/users_list.txt", "r+");
    while(1)
    {
        int al;
        if(fgets(temper_text,100, mapsave)==NULL)
            break;
        sscanf(temper_text,"assets/leaderboard/1users_files/%s.txt", temp_text);
        char ss[40];
        for(int i=0;i<strlen(temper_text);i++)
            if(temp_text[i]=='.')
            {
                ss[i]='\0';
                break;
            }
            else
                ss[i]=temp_text[i];
        if(strcmp(filechar,ss)==0)
        {
            fclose(mapsave);
            return;
        }
    }
    char path[100];
    sprintf(path,"assets/leaderboard/1users_files/%s.txt\n",filechar);
    fprintf(mapsave, "%s", path);
    fclose(mapsave);
    FILE *user_file = fopen(path, "w");
    int a =0;
    fprintf(user_file,"%d\n",a);
    fclose(user_file);
}
int read_users_score(int do_add, char username_entry_text[])
{
    char filechar[40];
    for(int i=0; i<40 && username_entry_text[i]!='.';i++)
    {
        filechar[i]=username_entry_text[i];
        if(i+1==40 || username_entry_text[i+1]=='.')
        {
            filechar[i+1]='\0';
            break;
        }
    }
    char path[100];
    sprintf(path,"assets/leaderboard/1users_files/%s.txt\n",filechar);
    int sco,ret=0;
    char temp_tex[100];
    FILE *mapwrite = fopen(path, "r+");
    while(1)
    {
        if(fgets(temp_tex,100, mapwrite)==NULL)
            break;
        // fscanf(mapwrite,"w%d\n",&sco);
        sscanf(temp_tex,"%d",&sco);
        ret+=sco;
    }
    if(do_add==1)
    {
        int new_score= calculate_score();
        ret+=new_score;
        fprintf(mapwrite,"%d\n", new_score);
    }
    fclose(mapwrite);
    return ret;
}
void load_the_map()
{
    int mapseltonum=0;
    // for(int i =0;i<size_of_text_mapselect;i++)
    //     mapseltonum = mapseltonum *10 + mapselect[i] - '0'; 
    sscanf(mapselect, "%d", &mapseltonum);
    char path[100];
    sprintf(path, "assets/save/maps/map%d.txt\n", mapseltonum);
    FILE *loadedmap = fopen(path, "r");
    fscanf(loadedmap,"%s\n", username_text);
    fscanf(loadedmap, "%d %d %d %d %d %d %d",&number_of_cells_x,&number_of_cells_y, &rand_start_x, &rand_start_y, &number_of_enemies, &number_of_politic_sides_per_user, &size_of_politic_sides);
    for(int j = 0;j<number_of_cells_y;j++)
        for(int i=0;i<number_of_cells_x;i++)
            fscanf(loadedmap,"%d %d %d %d %d %d",&cells[i][j].x, &cells[i][j].y, &cells[i][j].is_territoy, &cells[i][j].politic_side_number, &cells[i][j].does_it_have_military, &cells[i][j].is_occupied);
    for(int i=0;i<=size_of_politic_sides;i++)
    {
        fscanf(loadedmap,"%d %d %d %d %d %d\n", &politic_sides[i].player_id, &politic_sides[i].size_of_cells, &politic_sides[i].number_of_troopers,&politic_sides[i].number_of_moving_troopers,&politic_sides[i].id_of_moving_troppers,&politic_sides[i].is_moving);
        for(int j=0;j<politic_sides[i].size_of_cells;j++)
            fscanf(loadedmap,"%d %d\n", &politic_sides[i].cells_x[j], &politic_sides[i].cells_y[j]);
    }
    update_politic_sides_of_users();
    fclose(loadedmap);
}

void create_moving_troopers(int start_loc, int des_loc)
{
    if(start_loc==des_loc)
        return;
    // int last_sec = (seconds_until_trooper_is_out * floor((politic_sides[start_loc].number_of_troopers-1)/3) + politic_sides[start_loc].number_of_troopers+difftime(time_now,start_time));
    int last_sec = politic_sides[start_loc].number_of_troopers - politic_sides[start_loc].number_of_moving_troopers;
    for(int i=0;i<last_sec;i++)
    {
        int size_of_moving_troopers = politic_sides[start_loc].id_of_moving_troppers;
        struct timeval tv;
        gettimeofday(&tv,NULL);
        politic_sides[start_loc].troopers[size_of_moving_troopers].time = tv;
        politic_sides[start_loc].is_moving=1;
        politic_sides[start_loc].troopers[size_of_moving_troopers].politic_side_number = start_loc;
        politic_sides[start_loc].troopers[size_of_moving_troopers].enemy_politic_side_number = des_loc;
        politic_sides[start_loc].troopers[size_of_moving_troopers].seconds_till_out = seconds_until_trooper_is_out*1000000 * floor(i/3);
        if(i<5 && i>politic_sides[start_loc].number_of_troopers)
            politic_sides[start_loc].troopers[size_of_moving_troopers].seconds_till_out+=1000000;
        politic_sides[start_loc].troopers[size_of_moving_troopers].is_out = 0;
        politic_sides[start_loc].troopers[size_of_moving_troopers].did_end=0;
        politic_sides[start_loc].troopers[size_of_moving_troopers].current_x = cells[politic_sides[start_loc].cells_x[0]][politic_sides[start_loc].cells_y[0]].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
        politic_sides[start_loc].troopers[size_of_moving_troopers].current_y = cells[politic_sides[start_loc].cells_x[0]][politic_sides[start_loc].cells_y[0]].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
        politic_sides[start_loc].troopers[size_of_moving_troopers].dest_x = cells[politic_sides[des_loc].cells_x[0]][politic_sides[des_loc].cells_y[0]].x + size_of_each_cell_x/2 - size_of_troopers_x_y/2;
        politic_sides[start_loc].troopers[size_of_moving_troopers].dest_y = cells[politic_sides[des_loc].cells_x[0]][politic_sides[des_loc].cells_y[0]].y + size_of_each_cell_y/2 - size_of_troopers_x_y/2;
        int dist_x,dist_y = size_of_each_cell_y/4;
        if(size_of_moving_troopers%3!=1)
        {
            if(abs(politic_sides[start_loc].troopers[size_of_moving_troopers].current_x - politic_sides[start_loc].troopers[size_of_moving_troopers].dest_x)>5)
            {
                dist_x= -dist_y
                *(politic_sides[start_loc].troopers[size_of_moving_troopers].current_y - politic_sides[start_loc].troopers[size_of_moving_troopers].dest_y)
                /(politic_sides[start_loc].troopers[size_of_moving_troopers].current_x - politic_sides[start_loc].troopers[size_of_moving_troopers].dest_x);
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
                politic_sides[start_loc].troopers[size_of_moving_troopers].current_y += dist_y;
                politic_sides[start_loc].troopers[size_of_moving_troopers].current_x += dist_x;
                politic_sides[start_loc].troopers[size_of_moving_troopers].dest_y += dist_y;
                politic_sides[start_loc].troopers[size_of_moving_troopers].dest_x += dist_x;
            }
            else if(size_of_moving_troopers%3==2)
            {
                politic_sides[start_loc].troopers[size_of_moving_troopers].current_y -= dist_y;
                politic_sides[start_loc].troopers[size_of_moving_troopers].current_x -= dist_x;
                politic_sides[start_loc].troopers[size_of_moving_troopers].dest_y -= dist_y;
                politic_sides[start_loc].troopers[size_of_moving_troopers].dest_x -= dist_x;
            }
        }
        politic_sides[start_loc].troopers[size_of_moving_troopers].player_id = politic_sides[start_loc].player_id;
        politic_sides[start_loc].id_of_moving_troppers++;
        politic_sides[start_loc].number_of_moving_troopers++;
    }
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
        else if(page==3)
            page3();
        else if(page==4)
            page4();
        else if (page==10)
            page10();
        else if(page==99)
            winpage();
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
    SDL_FreeSurface(startbackground);
    SDL_FreeSurface(starsbackground);
    SDL_FreeSurface(winbackground);
    SDL_FreeSurface(losebackground);
    SDL_FreeSurface(load_game);
    SDL_FreeSurface(leaderboard);
    SDL_FreeSurface(new_game);
    SDL_FreeSurface(credits_button);
    SDL_FreeSurface(credits_text);
    SDL_FreeSurface(padmegrave1);
    SDL_FreeSurface(padmegrave2);
    SDL_FreeSurface(closebutton);
    SDL_FreeSurface(soundonphoto);
    SDL_FreeSurface(new_game_background);
    SDL_FreeSurface(backbutton);
    SDL_FreeSurface(startgame);
    SDL_FreeSurface(updownbutton);
    for(int i=0;i<15;i++)
    {
        SDL_FreeSurface(faces[i]);
        SDL_FreeSurface(troopers[i]);
        SDL_FreeSurface(planets_photos[i]);
    }
    for(int i=0;i<4;i++)
    {
        SDL_DestroyTexture(kybertexture[i]);
        SDL_DestroyTexture(kyberontexture[i]);
        SDL_FreeSurface(kyber_cristal_photos[i]);
    }
    for(int i=0;i<10;i++)
        SDL_DestroyTexture(movingtrooper_texture[i]);
    
    SDL_FreeSurface(wall);
    SDL_FreeSurface(wallflipped);
    SDL_FreeSurface(backtomenu);
    SDL_FreeSurface(doordonot);
    Mix_FreeMusic(menu_music);
    Mix_FreeMusic(game_music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}
void update_politic_sides_of_users()
{
    for(int i = 0; i<100;i++)
        politic_sides_of_user[i]=0;
    for(int i = 0; i<size_of_politic_sides;i++)
        politic_sides_of_user[politic_sides[i].player_id]++;
}

int did_win()
{
    for(int i=0;i<size_of_politic_sides;i++)
        if(i!=main_players_id && upboardwidth[i]>0)
            return 0;
    return 1;
}
int did_lose()
{
    if(upboardwidth[main_players_id]==0)
        return 1;
    return 0;
}
void create_kyber()
{
    int rand_to_do_kyber = rand()%300;
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
        kybers[size_of_kybers].type = 4;
        kybers[size_of_kybers].is_on=0;
        kybers[size_of_kybers].is_dead=0;
        size_of_kybers++;
    }
}
int calculate_score()
{
    time(&calc_time);
    return (20-difftime(calc_time,game_start_time)/60)*number_of_enemies*did_win_int;
}

void enemy_ai()
{
    int tot_of_user[10] = {0};
    for(int j=0;j<number_of_enemies+1;j++)
        if(j!=nomansland_playerid && j!=main_players_id && politic_sides_of_user[j]>1)
            for(int i=0,d=0;i<size_of_politic_sides && d<politic_sides_of_user[j];i++)
                if(politic_sides[i].player_id==j)
                {
                    d++;
                    tot_of_user[j]+= politic_sides[i].number_of_troopers - politic_sides[i].number_of_moving_troopers;
                    // printf("%d %d %d id:%d\n",tot_of_user[j],politic_sides[i].number_of_troopers, politic_sides[i].number_of_moving_troopers,politic_sides[i].player_id);
                    for(int k=0;k<size_of_politic_sides;k++)
                        if(j!=politic_sides[k].player_id &&
                            politic_sides[j].player_id!=nomansland_playerid
                            &&
                                ((politic_sides[k].is_moving==1 &&  
                                tot_of_user[j]>10)
                                ||
                                (tot_of_user[j]>politic_sides[k].number_of_troopers*3/2)))
                                {
                                    for(int w=0;w<i;w++)
                                        if(politic_sides[w].player_id==j)
                                            create_moving_troopers(w,k);
                                }
                }
    for(int j=0;j<size_of_politic_sides;j++)
    {
        int optionss[20] = {0};
        int choosen_ans=-1;
        int does_have_anything_other_than_nomansland=0;
        int dist = 10000;
        for(int i=0;i<size_of_politic_sides;i++)
            if((politic_sides[j].player_id!=nomansland_playerid && 
                politic_sides[j].is_moving==0 &&
                politic_sides[j].player_id!=politic_sides[i].player_id &&
                politic_sides[j].player_id!=0)
                &&
                    (/*(politic_sides[i].is_moving==1 &&  
                    politic_sides[j].number_of_troopers>10)
                    ||*/
                    (politic_sides[j].number_of_troopers - politic_sides[j].number_of_moving_troopers>politic_sides[i].number_of_troopers*3/2)))
                    {
                        if(politic_sides[i].player_id!=nomansland_playerid)
                            does_have_anything_other_than_nomansland=1;
                        choosen_ans=i;
                        optionss[i]=1;
                        // create_moving_troopers(j,i);
                        // return;
                    }
        if(choosen_ans==-1)
            continue;
        for(int i=0;i<size_of_politic_sides;i++)
        {
            if(does_have_anything_other_than_nomansland==1 && optionss[i]==1 && politic_sides[i].player_id !=nomansland_playerid && dist_between_two_poliside(i,j)<dist)
            {
                dist=dist_between_two_poliside(i,j);
                choosen_ans=i;
            }
            else if(does_have_anything_other_than_nomansland==0 && optionss[i]==1 && dist_between_two_poliside(i,j)<dist)
            {
                dist=dist_between_two_poliside(i,j);
                choosen_ans=i;
            }
        }
        create_moving_troopers(j,choosen_ans);
    }
}
double dist_between_two_poliside(int i, int j)
{
    return sqrt((politic_sides[i].cells_x[0] - politic_sides[j].cells_x[0])*
        (politic_sides[i].cells_x[0] - politic_sides[j].cells_x[0])
        +
        (politic_sides[i].cells_y[0] - politic_sides[j].cells_y[0])*
        (politic_sides[i].cells_y[0] - politic_sides[j].cells_y[0]));
}

void leaderboard_set()
{
    char temper_text[100],temp_text[100];
    FILE *mapsave = fopen("assets/leaderboard/users_list.txt", "r");
    while(1)
    {
        int al;
        if(fgets(temper_text,100, mapsave)==NULL)
            break;
        sscanf(temper_text,"assets/leaderboard/1users_files/%s.txt", temp_text);
        char ss[40];
        for(int i=0;i<strlen(temper_text);i++)
            if(temp_text[i]=='.')
            {
                ss[i]='\0';
                break;
            }
            else
                ss[i]=temp_text[i];
        strcpy(leaderboard_users[number_of_leaderboard_users].name, ss);
        leaderboard_users[number_of_leaderboard_users].score = read_users_score(0,ss);
        number_of_leaderboard_users++;
        leaderboard_users[number_of_leaderboard_users].rank=number_of_leaderboard_users;
    }
    fclose(mapsave);
    for(int i=0;i<number_of_leaderboard_users;i++)
    {
        for(int j=0;j<number_of_leaderboard_users;j++)
        {
            if(leaderboard_users[j].score>leaderboard_users[i].score)
            {
                struct leaderboard_or_something temp;
                temp = leaderboard_users[j];
                leaderboard_users[j]=leaderboard_users[i];
                leaderboard_users[i]=temp;
            }
        }
    }

}


void upboard_setup()
{
    total_of_soldiers_in_map=0;
    for(int i=0;i<15;i++)
        upboardwidth[i]=0;
    for(int i=0;i<size_of_politic_sides;i++)
    {
        upboardwidth[politic_sides[i].player_id]+=politic_sides[i].number_of_troopers;
        for(int j=0;j<politic_sides[i].id_of_moving_troppers;j++)
        {
            if(politic_sides[i].troopers[j].is_out==0 || politic_sides[i].troopers[j].did_end==1)
                continue;
            upboardwidth[politic_sides[i].player_id]++;
        }
    }
    for(int i=0;i<size_of_troops_with_no_home;i++)
    {
        if(troops_with_no_home[i].is_out==0 || troops_with_no_home[i].did_end==1)
            continue;
        upboardwidth[troops_with_no_home[i].player_id]++;
    }
    for(int i=0;i<number_of_enemies + 1;i++)
        total_of_soldiers_in_map+= upboardwidth[i];
    total_of_soldiers_in_map+= upboardwidth[nomansland_playerid];
    did_we_even_calculate=1;
}