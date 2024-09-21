#include <stdio.h>

int main() {

    float weight;
    printf("Enter your weight in kilograms:");
    scanf("%f", &weight);

    float height;
    printf("Enter your height in metres:");
    scanf("%f", &height);

    float bmi = weight / (height * height);

    const char *evaluation;

    if (bmi < 18.5) {
        evaluation = "Underweight";
    }

    else if (bmi >= 18.5 && bmi < 25.0) {
        evaluation = "Normal";
    }

    else if (bmi >= 25.0 && bmi < 30.0) {
        evaluation = "Overweight";
    }

    else {
        evaluation = "Obese";
    }

    printf("Your BMI is %.1f. That is %s.", bmi, evaluation);

    return 0;
}