#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    const int SIZE = 20;
    int arr[SIZE][SIZE]{};
    int rows, cols;
    printf("Enter the number of array rows: ");
    scanf_s("%i", &rows);
    printf("Enter the number of array columns: ");
    scanf_s("%i", &cols);
    if (rows <= SIZE && cols <= SIZE) {
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < cols; i++) {
                arr[j][i] = rand() % 100;
            }
        }
        printf("\nEntered array elements: \n");
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < cols; i++) {
                printf("%3i", arr[j][i]);
            }
            printf("\n");
        }
        printf("\n");
        bool fl = true;
        while (fl) {
            for (int j = 0; j < rows; j++) {
                fl = false;
                for (int i = 0; i < cols - 1; i++) {
                    if (arr[j][i] > arr[j][i + 1]) {
                        int temp = arr[j][i];
                        arr[j][i] = arr[j][i + 1];
                        arr[j][i + 1] = temp;
                        fl = true;
                    }
                }
            }
        }
        printf("Sorted array elements: \n");
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < cols; i++) {
                printf("%3i", arr[j][i]);
            }
            printf("\n");
        }
        for (int j = 0; j < rows; j++) {
            int temp = arr[j][0];
            arr[j][0] = arr[j][cols - 1]; //Visial Studio выдает предупреждение С6385 Reading invalid data from arr[j]
            arr[j][cols - 1] = temp; //Visual Studio выдает предупреждение С6385 Buffer overrun
        }
        printf("\n");
        printf("Modified Array: \n");
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < cols; i++) {
                printf("%3i", arr[j][i]);
            }
            printf("\n");
        }
    }
    else {
        printf("ERROR! The number of rows or columns entered exceeds the size of the array!");
    }
    return 0;
}