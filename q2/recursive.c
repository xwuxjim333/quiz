/* FIXME: Implement! */
#include <stdio.h>
#include <time.h>

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
    char str[length] = "cfilorux";
    char c, out;
    clock_t start, end;
    double time;
    FILE *file = fopen("recursive.txt", "a");

    printf("Input a sorted character array: %s\n", str);
    c = *argv[argc-1];
    printf("Input a character: %c\n", c);
    fflush(stdin);
    start = clock();
    out = smallest_character(str, c);
    end = clock();
    time = (end - start) / (double)(CLOCKS_PER_SEC);

    printf("Output: %c\n", out);
    if (file) {
        fprintf(file, "execution time of smallest_character() : %f sec\n", time);
        fclose(file);
    }
    return 0;
}
