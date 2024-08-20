#include <ncurses.h>
#include <stdlib.h>
#include "../include/doodle.h"
#include "../include/platform.h"


void move_doodle_left(Doodle *doodle) {
    if (doodle->x > 0) doodle->x--;
}

void move_doodle_right(Doodle *doodle) {
    if (doodle->x < WIDTH - 1) doodle->x++;
}

void init_doodle(Doodle *doodle, Platform platforms[], int platform_count) {
    doodle->x = platforms[0].x + 2;  // Positionne le doodle au-dessus de la première plateforme
    doodle->y = platforms[0].y - 1;
    doodle->vy = 0;  // Initialement, aucune vitesse verticale
}

void draw_doodle(Doodle *doodle) {
    mvprintw(doodle->y, doodle->x, "O");
}

void update_doodle(Doodle *doodle, Platform platforms[], int platform_count) {
    // Appliquer la gravité
    doodle->vy += 1;  // Augmente la vitesse vers le bas progressivement
    doodle->y += doodle->vy;  // Applique la vitesse à la position

    // Vérifier si le personnage touche le bas de l'écran
    if (doodle->y >= HEIGHT - 1) {
        doodle->y = HEIGHT - 1;
        if (!is_on_platform(doodle, platforms, platform_count)) {
            endwin();
            printf("Game Over! Vous êtes tombé.\n");
            exit(0);  // Terminer le jeu si le personnage n'est pas sur une plateforme
        }
        doodle->vy = -10;  // Force le rebond si le personnage touche le bas
    }

    // Vérifier les collisions avec les plateformes
    if (is_on_platform(doodle, platforms, platform_count)) {
        doodle->vy = -10;  // Rebond si le personnage touche une plateforme
    }

    // Déplacer les plateformes si le personnage monte au-dessus de la moitié de l'écran
    if (doodle->y < HEIGHT / 2) {
        for (int i = 0; i < platform_count; i++) {
            platforms[i].y += 1;
            if (platforms[i].y >= HEIGHT) {
                platforms[i].y = 0;
                platforms[i].x = rand() % WIDTH;
            }
        }
        doodle->y = HEIGHT / 2;  // Fixer la position du personnage à mi-hauteur
    }

    // Affichage pour débogage
    mvprintw(0, 0, "Position du doodle: x=%d, y=%d, vy=%d", doodle->x, doodle->y, doodle->vy);
}


int is_on_platform(Doodle *doodle, Platform platforms[], int platform_count) {
    for (int i = 0; i < platform_count; i++) {
        if (doodle->y == platforms[i].y && doodle->x >= platforms[i].x && doodle->x <= platforms[i].x + 5) {
            return 1; // Collision détectée
        }
    }
    return 0; // Pas de collision
}
