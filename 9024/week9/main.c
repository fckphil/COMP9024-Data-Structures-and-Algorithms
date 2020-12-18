#include "Trie.h"
#include <math.h>
#include <stdio.h>
#define accuracy pow(10,-10)
double func(double);
double bisection(double, double);
char *words[] = { "so", "boot", "axe", "jaw", "boon", "jaws",
                  "sore" };

int main(void) {
    double x1 = 0.0, x2 = 10.0;
    double root = bisection(x1,x2);
    printf("root = %f\n",root);
    printf("%f\n",func(1.666667));
}
double func(double x){
    double y = 3*x*x*x - 5*x*x +3*x -5;
    return y;
}
double bisection(double x1, double x2){
    double mid = (x1 + x2)/2;
    while(func(mid) != 0 && x2-x1 > accuracy){
        if(func(mid)*func(x1)<0)    x2=mid;
        else x1 = mid;
        mid = (x1+x2)/2;
    }
    return mid;
}