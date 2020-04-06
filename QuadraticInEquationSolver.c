/*  

    IMPORTANT
    I've used scanf_s instead of scanf which may cause problems while compiling this code on your machine. You can change these to scanf without any unwanted consequences.

*/

#include <stdio.h>
#include <math.h>

#define graphSize 30

float a, b, c, delta;
char sign;

void graph();
void inEquation();
void logic(int finalResponse);
float max(float num1, float num2);
float min(float num1, float num2);

void graph() {
    int i, j;
    for (j = 0; j < graphSize; j++) {
        for (i = 0; i < graphSize; i++) {
            if (a * pow((i - graphSize / 2), 2) + b * (i - graphSize / 2) + c > (float)(graphSize / 2 - j - 1) && a * pow((i - graphSize / 2), 2) + b * (i - graphSize / 2) + c < (float)(graphSize / 2 - j + 1)) {
                printf("* ");
            }
            else if (j == graphSize / 2) {
                if (i == graphSize - 1) {
                    printf("> ");
                }
                else {
                    printf("- ");
                }
            }
            else if (i == graphSize / 2) {
                if (j == 0) {
                    printf("^ ");
                }
                else {
                    printf("| ");
                }
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void inEquation() {
    if (sign != '=' && delta > 0) {
        switch (sign) {
        case '>':
            if (a < 0) {
                printf("X belongs to (%f; %f)", min(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))), max(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))));
            }
            else {
                printf("X belongs to (-infinity; %f) and (%f; +infinity)", min(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))), max(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))));
            }
            break;
        case '<':
            if (a < 0) {
                printf("X belongs to (-infinity; %f) and (%f; +infinity)", min(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))), max(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))));
            }
            else {
                printf("X belongs to (%f; %f)", min(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))), max(((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a))));
            }
            break;
        }
    }
    else if (sign != '=' && delta == 0) {
        switch (sign) {
        case '>':
            if (a > 0) {
                printf("X belongs to (-infinity; %f) and (%f; + infinity)", min((-1 * b) / (2 * a), (-1 * b) / (2 * a)), max((-1 * b) / (2 * a), (-1 * b) / (2 * a)));
            }
            else {
                printf("X is equal to %f", (-1 * b) / (2 * a));
            }
            break;
        case '<':
            if (a > 0) {
                printf("X is equal to %f", (-1 * b) / (2 * a));
            }
            else {
                printf("X belongs to (-infinity; %f) and (%f; + infinity)", min((-1 * b) / (2 * a), (-1 * b) / (2 * a)), max((-1 * b) / (2 * a), (-1 * b) / (2 * a)));
            }
            break;
        }
    }
    else {
        logic(1);
    }
}

void logic(int finalResponse) {
    if (a == 0) {
        if (finalResponse == 1) {
            printf("This is not a quadratic (in)equation, it cannot be solved by this software.");
        }
    }
    else if (delta < 0) {
        if (finalResponse == 1) {
            printf("This equation is not possible to solve.");
        }
    }
    else if (delta == 0) {
        if (finalResponse == 1) {
            printf("The value of x: %f", ((-1 * b) / 2 * a));
        }
        else {
            printf("\n\n");
            graph();
            printf("\n\n");
        }
    }
    else {
        if (finalResponse == 1) {
            printf("Possible values of x: %f; %f", ((-1 * b - sqrt(delta)) / (2 * a)), ((-1 * b + sqrt(delta)) / (2 * a)));
        }
        else {
            printf("\n\n");
            graph();
            printf("\n\n");
        }
    }
}

float max(float num1, float num2) {
    if (num1 > num2) {
        return num1;
    }
    else {
        return num2;
    }
}

float min(float num1, float num2) {
    if (num1 < num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int main()
{
    printf("=====================================================\n            QUADRATIC (IN)EQUATION SOLVER            \n=====================================================\n");
    printf("\n");
    printf("Please enter the values of a, b and c and select the sign (=, > or <).\n\nax^2 + bx + c ? 0");
    printf("\n^\na > ");
    scanf_s("%f", &a);
    printf("\nax^2 + bx + c ? 0\n       ^\nb > ");
    scanf_s("%f", &b);
    printf("\nax^2 + bx + c ? 0\n            ^\nc > ");
    scanf_s("%f", &c);
    printf("\nax^2 + bx + c ? 0\n              ^\n? > ");
    while ((getchar()) != '\n');
    scanf_s("%c", &sign);
    printf("\nThis is how your (in)equation looks like:\n%fx^2 + %fx + %f %c 0\n\n", a, b, c, sign);
    delta = pow(b, 2) - (4 * a * c);
    logic(0);
    inEquation();
    printf("\n\n\n");
    printf("Developed by Cubesome.\n\n");
    return 0;
}
