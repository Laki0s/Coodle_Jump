#ifndef PLATFORM_H
#define PLATFORM_H

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} Platform;

void init_platforms(Platform platforms[], int count);
void draw_platforms(Platform platforms[], int count);
void update_platforms(Platform platforms[], int count);

#endif
