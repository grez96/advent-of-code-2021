#include <stdio.h>

int main() {
    FILE *fp = fopen("input.txt", "r");

    int prev = -1;
    int curr = -1;
    int largerCount = 0;
    while (fscanf(fp, "%d", &curr) == 1) {
        if(prev == -1) {
            prev = curr;
        }

        if(curr > prev) {
            ++largerCount;
        }

        prev = curr;
    }

    printf("%d\n", largerCount);

    fclose(fp);
    return 0;
}
