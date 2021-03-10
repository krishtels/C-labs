#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "main.h"

void PasteParameters(int** planets, int planetNumber) {
    printf("Enter mass in kilos, radius of orbit in meters and speed of the planet in meters per sec in that order\n");
    int mass, radius, speed;
    while (scanf("%d%d%d", &mass, &radius, &speed) != 3 || mass <= 0 || radius <= 0 || speed <= 0) {
        printf("Wrong input\nTry again\n");
        while (getchar() != '\n') {}
    }
    planets[planetNumber][0] = mass;
    planets[planetNumber][1] = radius;
    planets[planetNumber][2] = speed;
}

float YearLength(int radius, int speed){
    float yearLength = 2 * 3.14 * radius / speed;
    return yearLength;
}

float CalculateYearLength(int** planets, int planetNumber) {
    if (planets[planetNumber][1] && planets[planetNumber][2]) {
        return YearLength(planets[planetNumber][1], planets[planetNumber][2]);
    } else {
        return 0;
    }
}

float Distance(int time, int radius1, int speed1, int radius2, int speed2){
    float firstAngle = time * 2 * 3.14 / YearLength(radius1, speed1);
    float secondAngle = time * 2 * 3.14 / YearLength(radius2, speed2);
    float firstProection = fabs(radius1 * cos(firstAngle) - radius2 * cos(secondAngle));
    float secondProection = fabs(radius1 * sin(firstAngle) - radius2 * sin(secondAngle));
    float distance = sqrt(pow(firstProection, 2) + pow(secondProection, 2));
    return distance;
}

float CalculateDistance(int planet1, int planet2, int time, int** planets) {
    if (planets[planet1][1] && planets[planet1][2] && planets[planet2][1] && planets[planet2][2]) {
        return Distance(time, planets[planet1][1],planets[planet1][2], planets[planet2][1], planets[planet2][2]);
    } else{
        return 0;
    }
}

float Power(int mass1, float distance, int mass2){
    float power = mass1*mass2*6.67/(distance*distance*100);
    return power;
}

float CalculatePower(int planet1, int planet2, int time, int** planets) {
    float distance = CalculateDistance(planet1, planet2, time, planets);
    float power = 0;
    if (distance && planets[planet1][0] && planets[planet2][0]) {
        return Power(planets[planet1][0], distance, planets[planet2][0]);
    }
    else if (planets[planet1][0] == 0 && planets[planet2][0] == 0) {
        return 0;
    }
    else {
        return -1;
    }
    
}
int main() {
    int i, j;
    int** planets = (int**)malloc(3 * sizeof(int*));
    for (i = 0; i < 3; i++) {
        planets[i] = (int*)malloc(3 * sizeof(int));
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            planets[i][j] = 0;
        }
    }
    int program = 1;
    while (program) {
        int responce;
        printf("1. Paste parameters of planet 2G_1\n");
        printf("2. Paste parameters of planet 2G_2\n");
        printf("3. Paste parameters of planet 2G_3\n");
        printf("4. Calculate year length\n");
        printf("5. Distance between planets\n");
        printf("6. Power pair gravitational interaction\n");
        printf("7. Exit\n");
        while (scanf("%d", &responce) != 1) {
            printf("Wrong input\nTry again\n");
            while (getchar() != '\n') {}
        }
        switch (responce) {
        case 1: {
            PasteParameters(planets, 0);
            printf("Mass of 2G_1 = %d,\nRadius of orbit 2G_1 = %d,\nSpeed of 2G_1 = %d\n", planets[0][0], planets[0][1], planets[0][2]);
            break;
        }
        case 2: {
            PasteParameters(planets, 1);
            printf("Mass of 2G_2 = %d,\nRadius of orbit 2G_2 = %d,\nSpeed of 2G_2 = %d\n", planets[1][0], planets[1][1], planets[1][2]);
            break;
        }
        case 3: {
            PasteParameters(planets, 2);
            printf("Mass of 2G_3 = %d,\nRadius of orbit 2G_3 = %d,\nSpeed of 2G_3 = %d\n", planets[2][0], planets[2][1], planets[2][2]);
            break;
        }
        case 4: {
            int planetNumber = 0;
            printf("Enter planet number\n");
            while (scanf("%d", &planetNumber) != 1 || planetNumber<1 || planetNumber>3) {
                printf("Wrong input! Planet number available: 1, 2, 3\nTry again\n");
                while (getchar() != '\n') {}
            }
            planetNumber--;
            float year = CalculateYearLength(planets, planetNumber);
            if (year) {
                printf("Year length is %.2f seconds\n", year);
            }
            else {
                printf("You need to enter data first\n");
            }
            break;
        }
        case 5: {
            int planet1, planet2;
            printf("Enter planets' numbers\n");
            while (scanf("%d%d", &planet1, &planet2) != 2 || planet1 < 1 || planet1>3 || planet2 < 1 || planet2>3) {
                printf("Wrong input! Planets number available: 1, 2, 3\nTry again\n");
                while (getchar() != '\n') {}
            }
            planet1--;
            planet2--;
            printf("Enter time in seconds\n");
            int time;
            while (scanf("%d", &time) != 1 || time < 0) {
                printf("Wrong input!\nTry again\n");
                while (getchar() != '\n') {}
            }
            float distance = CalculateDistance(planet1, planet2, time, planets);
            if (planets[planet1][1] && planets[planet2][1]) {
                printf("Distance between planet 2G_%d and 2G_%d = %.2f meters\n", planet1, planet2, distance);
            }
            else {
                printf("You need to enter data first\n");
            }
            break;
        }
        case 6: {
            int planet1, planet2;
            printf("Enter planets' numbers\n");
            while (scanf("%d%d", &planet1, &planet2) != 2 || planet1 < 1 || planet1>3 || planet2 < 1 || planet2>3) {
                printf("Wrong input! Planets number available: 1, 2, 3\nTry again\n");
                while (getchar() != '\n') {}
            }
            planet1--;
            planet2--;
            printf("Enter time\n");
            int time;
            while (scanf("%d", &time) != 1 || time < 0) {
                printf("Wrong input!\nTry again\n");
                while (getchar() != '\n') {}
            }
            float power = CalculatePower(planet1, planet2, time, planets);
            if (power == 0) {
                printf("You need to enter data first\n");
            }
            else if (power == -1) {
                printf("Error! Distance = 0\n");
            }
            else {
                printf("Power between planet 2G_%d and 2G_%d = %.2f nH\n", planet1, planet2, power);
            }
            break;
        }
        case 7: {
            program = 0;
            break;
        }
        default: {
            printf("Wrong number! Try again\n");
            break;
        }
        }
    }
    for (i = 0; i < 3; i++) {
        free(planets[i]);
    }
    free(planets);
    return 0;
}
