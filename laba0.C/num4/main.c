#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


FILE* file_row_three;
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Enter file name in arguments console command");
        return 1;
    }
    if ((file_row_three = fopen(argv[1], "r")) == NULL) {
        printf("Invalid reading file");
        return 2;
    }
    char c; int max_count_string = -1;
    while ((c = getc(file_row_three)) != EOF) {
        int count = 0;
        while (c != '\n') {
            ++count;
            c = getc(file_row_three);
        }
        if (count >= max_count_string) {
            max_count_string = count;
        }
    }
    rewind(file_row_three);
    FILE* outputFile = fopen("output.txt", "w");
    char strings[max_count_string + 2];
    char first[max_count_string + 2];
    char second[max_count_string + 2];
    char third[max_count_string + 2];
    while (fgets(strings, sizeof(strings), file_row_three) != NULL) {
        sscanf(strings, "%s %s %s", first, second, third);
        fprintf(outputFile, "%s %s %s\n", third, first, second);
    }


    fclose(file_row_three);
    fclose(outputFile);

}


/*#include <stdio.h>
#include <string.h>
int main()
{
    char* line_1 = "rrrrr hhhh www\n";
    char* line_2 = "rrrrr hhhh www\n";
    char* line_3 = "rrrrr hhhh www\n";
    char arr[500], arr2[500], arr3[500];
    FILE* f = fopen("xrp", "w");
    FILE* f_2 = fopen("lite", "w");
    if (f)
    {
        fputs(line_1, f);
        fputs(line_2, f);
        fputs(line_3, f);
    }
    fclose(f);
    f = fopen("xrp", "r");
    for (int i = 0; i < 3; ++i)
    {
        fscanf(f, "%s %s %s", arr, arr2, arr3);
        fprintf(f_2, "%s %s %s\n", arr, arr2, arr3);
    }
    fclose(f);
    fclose(f_2);
    f = fopen("xrp", "w");
    f_2 = fopen("lite", "r");
    for (int i = 0; i < 3; ++i)
    {
        fscanf(f_2, "%s %s %s", arr, arr2, arr3);
        fprintf(f, "%s %s %s\n", arr3, arr, arr2);
    }
    fclose(f);
    fclose(f_2);
}*/