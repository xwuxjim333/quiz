#include <stdio.h>
#include <time.h>
#define findmax(a, b) (((a) > (b)) ? (a) : (b))

int maxSubArray(int A[], int n)
{
//Kadane's algorithm
    int max = A[0], test = A[0];
    int i = 0;

    for (i = 0; i < n; i++) {
        test = findmax(A[i], test+A[i]);
        max = findmax(max, test);
    }

    if (max > 0)
        return max;
    else
        return 0;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    double total_time;
    clock_t start, end;
    FILE *file = fopen("recursive.txt", "a");

    start = clock();
    int output = maxSubArray(arr, size);
    end = clock();
    printf("The largest sum: %d\n", output);

    if (file) {
	    total_time = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%f\n", total_time);
        fclose(file);
    } 
    printf("execution time of flatten() : %f sec\n", total_time);

    return 0;
}
