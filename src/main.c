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

int main() 
{
    load_everything();
    main_while_operation();
    destroy_the_few_things_left();
}
