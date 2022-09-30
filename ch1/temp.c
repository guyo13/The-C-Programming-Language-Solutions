#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    float fahr, celsius;

    fahr=LOWER;
    printf("Fahr Celsius\n");
    while(fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }

    printf("Celsius Fahr\n");
    celsius = LOWER;
    while(celsius <= UPPER) {
        fahr = (9.0/5.0) * celsius +32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += STEP;
    }

    printf("Fahr Celsius reversed\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
    }
}