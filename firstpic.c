#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

int main() {
    int file;
    int x, y, i, j, r, g, b;
    char buffer[20];
    file = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    snprintf(buffer, sizeof(buffer), "P3 750 750 255\n");
    write(file, buffer, strlen(buffer));
    for(i = -375; i < 375; i++) {
        for(j = -375; j < 375; j++) {
            x = pow(j, 2);
            //printf("x: %d", x);
            y = pow(i, 2);
            //printf("y: %d", y);
            if ((((x)/90000) + ((y)/40000)) < 1) {
                r = 255;
                g = 0;
                b = abs(abs(j) - 130);
            }
            else {
                r = abs(abs(j) - 130);
                g = 0;
                b = 255;
            }
            x = 0;
            y = 0;
            snprintf(buffer, sizeof(buffer), "%d %d %d\n", r, g, b);
            write(file, buffer, strlen(buffer));
        }
    }
}
