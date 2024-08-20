#include <ncurses.h>
#include "../include/game.h"
#include "../include/doodle.h"
#include "../include/platform.h"

#define PLATFORM_COUNT 5

Doodle doodle;
Platform platforms[PLATFORM_COUNT];

void init_game() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100);

    init_platforms(platforms, PLATFORM_COUNT);  // Initialiser les plateformes en premier
    init_doodle(&doodle, platforms, PLATFORM_COUNT);  // Puis initialiser le personnage avec les plateformes
}


void game_loop() {
    while (1) {
        draw_game();
        update_game();

        int ch = getch();
        if (ch == 'q') break;

        handle_input(ch);
    }
}

void end_game() {
    endwin();
}

void draw_game() {
    clear();
    draw_platforms(platforms, PLATFORM_COUNT);
    draw_doodle(&doodle);
    refresh();
}

void update_game() {
    update_doodle(&doodle, platforms, PLATFORM_COUNT);
    update_platforms(platforms, PLATFORM_COUNT);
}

void handle_input(int ch) {
    if (ch == KEY_LEFT) {
        move_doodle_left(&doodle);
    } else if (ch == KEY_RIGHT) {
        move_doodle_right(&doodle);
    }
}
