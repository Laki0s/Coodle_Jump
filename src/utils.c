#include <unistd.h>  // Assure l'inclusion correcte pour usleep

#include "../include/utils.h"

void delay(int milliseconds) {
    sleep(milliseconds * 1000);
}
