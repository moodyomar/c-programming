#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ws5functions.h"
#include <assert.h>

struct Functions
{
    char *name_of_operation;
    int (*Operation)(char *, char *);
    int (*Compare)(char *, char *);
};
void Action(char *user_input, char *file_name, struct Functions array[5], int size);

void *GetUserInput();                           // Get input from user
int AppStringToTop(char *, char *);             // Appends a new string to the beginning of the file ( "<"
int AppStringToBottom(char *, char *);          // Append a new string to EOF (end of file)
int Compare(char *operation, char *user_input); // Comparison function return int
int Remove(char *file_name, char *nothing);     // Remove the file from your computer
int Count(char *file_name, char *nothing);      // Count the amount of lines and prints localy from the function
int Exit(char *, char *);                       // Closes the file


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please Pass One command line arg as filename! \n");
        return 0;
    }

    struct Functions array[5] = {
        {"-remove",&Remove,&Compare,},
        {"-count",&Count,&Compare,},
        {"-exit",&Exit,&Compare,},
        {">",&AppStringToTop,&Compare,},
        {"default",&AppStringToBottom,&Compare,}};

    char *filename = argv[1];

    do
    {
        char *user_input = GetUserInput();
        Action(user_input, filename, array, 5);
        free(user_input);
    } while (1);

    return 0;
}


void Action(char *user_input, char *file_name, struct Functions array[5], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].Compare(array[i].name_of_operation, user_input) == 1)
        {
            printf("NOP: %s \n", array[i].name_of_operation);
            array[i].Operation(file_name, user_input);
            break;
        }
        else if (i == size - 1)
        {
            printf("NOP: %s \n", array[i].name_of_operation);
            array[i].Operation(file_name, user_input);
            break;
        }
    }
}
void *GetUserInput()
{
    char *input = (char *)malloc(1000 * sizeof(char));
    printf("Enter Desired strings: \n");
    fgets(input, 1000, stdin); // read from stdin

    return input;
}
int AppStringToTop(char *file_name, char *input)
{
    FILE *fptr = fopen(file_name, "a+");
    assert(fptr);
    if (input[0] == '>')
    {

        // char *new_file_name = "temp_file.txt";
        // AppStringToBottom(new_file_name, input);
        // FILE *fptr2 = fopen(new_file_name, "a+");
        // // we have new file with new string till here


        // int count = Count(new_file_name,NULL);
        // printf("count: %d \n",count);

        // for (int i = 0; i < count; i++)
        // {
        // fprintf(fptr2,"%s",fptr);
        // }
        
        


    }
    if (input)
    {
        fseek(fptr, 0, SEEK_SET);
        fputs(input, fptr);
    }

    fclose(fptr);
    return 1;
}
int AppStringToBottom(char *file_name, char *input)
{
    FILE *fptr = fopen(file_name, "a");
    assert(fptr);
    fputs(input, fptr);
    fputc('\n', fptr);
    fclose(fptr);
    return 1;
}
int Compare(char *operation, char *user_input)
{
    user_input[strcspn(user_input, "\n")] = 0;
    if (!strcmp(operation, user_input))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Remove(char *file_name, char *nothing)
{
    int status;
    if (remove(file_name) == 0)
    {
        printf("%s file deleted successfully.\n", file_name);
    }
    else
    {
        printf("Unable to delete the file\n");
        perror("Error");
    }
    return status;
}
int Count(char *file_name, char *nothing)
{
    FILE *fp;
    int count = 0; // Line counter (result)
    char c;        // To store a character read from file

    fp = fopen(file_name, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", file_name);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n') // Increment count if this character is newline
        {
            count += 1;
        }
    }

    // Close the file
    fclose(fp);
    printf("Lines in file: %d \n", count);
    return count;
}
int Exit(char *file_name, char *nothing)
{
    exit(0);
    return 0;
}