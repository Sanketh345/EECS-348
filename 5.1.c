#include <stdio.h>
#include <stdlib.h>
#define NUM_MONTHS 12

double calculateAverage(double sales[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += sales[i];
    }
    return sum / size;
}

void sortSales(double sales[], int indices[], int size) {
    for (int i = 0; i < size; i++) {
        indices[i] = i;
    }
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                double temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
                int tempIndex = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tempIndex;
            }
        }
    }
}

int main() {
    double sales[NUM_MONTHS] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
        72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
    };

    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    double minSales = sales[0];
    double maxSales = sales[0];
    double avgSales = calculateAverage(sales, NUM_MONTHS);

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
    }

    int movingAverageMonths = 6;
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s $%.2lf\n", months[i], sales[i]);
    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", minSales, months[0]);
    printf("Maximum sales: $%.2lf (%s)\n", maxSales, months[NUM_MONTHS - 1]);
    printf("Average sales: $%.2lf\n", avgSales);

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= NUM_MONTHS - movingAverageMonths; i++) {
        double sum = 0.0;
        for (int j = i; j < i + movingAverageMonths; j++) {
            sum += sales[j];
        }
        double movingAvg = sum / movingAverageMonths;
        printf("%s - %s $%.2lf\n", months[i], months[i + movingAverageMonths - 1], movingAvg);
    }

    int indices[NUM_MONTHS];
    sortSales(sales, indices, NUM_MONTHS);

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        int index = indices[i];
        printf("%s $%.2lf\n", months[index], sales[i]);
    }

    return 0;
}
