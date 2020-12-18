#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int len = 6;
    int seed = 2;
    int i = 0;
    char output[len+1];
    srand(seed);
    for(i=0; i<len; i++){
        output[i] = 'a' + rand()%26;
    }
    output[i] = '\0';
    printf("%s",output);
}
