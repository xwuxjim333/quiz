#include <stdio.h>
#include <time.h>
#include <string.h>

#define length 26

char smallest_character(char str[], char c)
{
    char out;
    if (str[0] != '\0') {
        if(str[0] > c) {
            return str[0];
        } else {
            out = smallest_character(str+1, c);
            if (out > c) {
                return out;
            } else {

//If no such character exists, return the smallest character in the array. 
                return str[0];
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char str[length];
    char c, output;
    double total_time;
    clock_t start, end;
    FILE *file = fopen("recursive.txt", "a");

    strcpy(str, argv[1]);
    printf("Input a sorted character array: %s\n", str);
    c = *argv[argc-1];
    printf("Input a character: %c\n", c);
    start = clock();
    output = smallest_character(str, c);
    printf("Ouput : %c\n", output);
    end = clock();

    if(file){
	    total_time = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%f\n", total_time);
        fclose(file);
    }
    printf("execution time of smallest_character() : %f sec\n", total_time);  
    return 0;
}
