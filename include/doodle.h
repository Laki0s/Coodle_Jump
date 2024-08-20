#ifndef DOODLE_H
#define DOODLE_H

#include "platform.h"

typedef struct {
    int x, y;
    int vy;
} Doodle;

void init_doodle(Doodle *doodle, Platform platforms[], int platform_count);  // Mise à jour de la déclaration
void draw_doodle(Doodle *doodle);
void update_doodle(Doodle *doodle, Platform platforms[], int platform_count);
void move_doodle_left(Doodle *doodle);
void move_doodle_right(Doodle *doodle);
int is_on_platform(Doodle *doodle, Platform platforms[], int platform_count);

#endif
