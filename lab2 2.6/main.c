#include <stdio.h>
#include <math.h>
#include "main.h"

int Fact(int n){
    if(n == 0){
        return 1;
    }
    return n * Fact(n - 1);
}

int FactLoop(int fact, int detorminator){
    fact *= (fact-1);
    detorminator *= fact;
    return detorminator;
}


int CountN(double angel, double sinAnswer, double epsilon, int choise){
    if (angel <= epsilon){
        return 0;
    }
    int n = 1;
    double leftAnswer = angel;
    int fact = 3;
    int detorminator = 1;
    double power = angel;
    while (fabs(leftAnswer-sinAnswer) >= epsilon){
        power *= angel * angel;
        if (choise == 1){
            detorminator = Fact(fact);
        } else {
            detorminator = FactLoop(fact, detorminator);
        }
        fact += 2;
        double currentAnswer = power / detorminator;
        if (n % 2 == 0){
            leftAnswer += currentAnswer;
        } else {
            leftAnswer -= currentAnswer;
        }
        n++;
    }
    return n;
}

double EnterOneDouble(){
    double number;
    while(scanf("%d",&number)!=1 || number <= 0){
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n') {
        }
    }
    return number;
}

int main(){
    printf("Enter your epsilon\n");
    double epsilon = EnterOneDouble();
    printf("Enter angel (greater than epsilon)\n");
    double angel = EnterOneDouble();
    double sinAnswer = sin(angel);
    int nAnswerLoop = CountN(angel, sinAnswer, epsilon, 0);
    int nAnswerRecurse = CountN(angel, sinAnswer, epsilon, 1);
    printf("Loop result: N = %d\n", nAnswerLoop);
    printf("Recurse result: N = %d\n", nAnswerRecurse);
    system("pause");
    return 0;
}