#include <stdio.h>
#include <math.h>
#include "main.h"

int power(int a){
    return a*a*a;
}

int check(int a) {
    int first = a % 10;
    int second = (a / 10) % 10;
    int third = a / 100;
    int number = power(first) + power(second) + power(third);
    if (number == a) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i = 100;
    for (i; i < 1000; i++) {
        if (check(i) == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}
