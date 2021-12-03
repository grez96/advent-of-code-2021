#include <stdio.h>
#include <string.h>

#define FORWARD "forward"
#define UP "up"
#define DOWN "down"

int main() {
    FILE *fp = fopen("input.txt", "r");

    char dir[20];
    int mag;
    int pos = 0;
    int depth = 0;
    int aim = 0;
    while (fscanf(fp, "%s %d", dir, &mag) == 2) {
        if(strcmp(dir, FORWARD) == 0) {
            pos += mag;
            depth += aim * mag;
        }
        else if(strcmp(dir, UP) == 0) {
            aim -= mag;
        }
        else if(strcmp(dir, DOWN) == 0) {
            aim += mag;
        }
    }

    printf("%d\n", pos * depth);

    return 0;
}