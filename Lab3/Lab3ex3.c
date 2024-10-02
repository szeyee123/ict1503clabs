#include <stdio.h>
#include <string.h>

#define CURRENCY_LEN 4

typedef struct {
    float value;
    char currency[CURRENCY_LEN];
} INTL_MONEY_VALUE;

typedef INTL_MONEY_VALUE* INTL_MONEY_VALUE_PTR;

void printIntlMoneyValue(INTL_MONEY_VALUE_PTR moneyPtr) {
    if (moneyPtr != NULL) {
        printf("Money value: %.2f\n", (*moneyPtr).value);
        printf("Currency: %s\n", (*moneyPtr).currency);
    } else {
        printf("Pointer is NULL\n");
    }
}

int main() {
    INTL_MONEY_VALUE money1;
    money1.value = 1234.56;
    strncpy(money1.currency, "USD", CURRENCY_LEN);
    
    INTL_MONEY_VALUE_PTR moneyPtr = &money1;

    printf("Printing money1 through pointer:\n");
    printIntlMoneyValue(moneyPtr);

    INTL_MONEY_VALUE money2;
    money2.value = 7890.12;
    strncpy(money2.currency, "SGD", CURRENCY_LEN);

    moneyPtr = &money2;
    printf("\nPrinting money2 through pointer:\n");
    printIntlMoneyValue(moneyPtr);

    return 0;
}
