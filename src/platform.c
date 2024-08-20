#include <stdlib.h>
#include "../include/platform.h"
#include <time.h>
#include <ncurses.h>

void init_platforms(Platform platforms[], int count) {
    for (int i = 0; i < count; i++) {
        platforms[i].x = rand() % (WIDTH - 6);  // S'assurer que la plateforme reste à l'écran
        platforms[i].y = HEIGHT - (i * (HEIGHT / count)) - 2;  // Espacer les plateformes
    }
}


void draw_platforms(Platform platforms[], int count) {
    for (int i = 0; i < count; i++) {
        mvprintw(platforms[i].y, platforms[i].x, "======");
    }
}

void update_platforms(Platform platforms[], int count) {
    // Déplacement des plateformes vers le bas si nécessaire
}
