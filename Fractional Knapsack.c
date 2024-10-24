//
// Created by MANAN on 14/09/24.
//
#include <stdio.h>

struct Item {
    int value, weight;
};

void fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items by value-to-weight ratio (in descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = (double)items[i].value / items[i].weight;
            double r2 = (double)items[j].value / items[j].weight;
            if (r1 < r2) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    double totalValue = 0.0;  // Total value accumulated
    int currentWeight = 0;    // Current weight in knapsack

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of the item
            int remaining = W - currentWeight;
            totalValue += items[i].value * ((double)remaining / items[i].weight);
            break;  // Knapsack is full
        }
    }

    printf("Maximum value we can obtain = %.2f\n", totalValue);
}

int main() {
    int W = 50;  // Knapsack capacity
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    fractionalKnapsack(W, items, n);
    return 0;
}