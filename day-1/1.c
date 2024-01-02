#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("No file provided.\n");
        return 1;
    }

    FILE *pF = fopen(argv[1], "r");
    char buffer[255];

    if (pF == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    int sum = 0;

    while(fgets(buffer, 255, pF) != NULL) {
        int firstNum = 0;
        int finalNum = 0;
        
        for (int i = 0; i < strlen(buffer); i++) {
            const char current = buffer[i];
            
            const int x = current - '0';

            // check if x is properly bounded
            if (x >= 0 && x <= 9) {
                if (firstNum == 0) {
                    firstNum = x;
                }
                finalNum = x;
            }
        }

        sum += firstNum * 10 + finalNum;
    }

    printf("%d\n", sum);

    fclose(pF);

    return 0;
}