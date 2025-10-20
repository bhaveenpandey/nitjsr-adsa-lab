#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
    int count[10] = {0};
    printf("Coins used to make amount %d:\n", amount);
    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            count[i] = amount / coins[i];
            amount = amount % coins[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (count[i] != 0)
            printf("Coin %d used %d times\n", coins[i], count[i]);
    }
}

int main() {
    int coins[] = {25, 10, 5, 1}; // coin denominations
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 63;

    coinChange(coins, n, amount);
    return 0;
}
