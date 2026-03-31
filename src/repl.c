#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/table.h"
#include "../include/row.h"


int numOfArgs(char* str)
{
    int count = 0;

    char tempStr[1024];
    strcpy(tempStr, str);

    char* token = strtok(tempStr, " ");
    while(token != NULL)
    {
        count+=1;
        token = strtok(NULL, " ");
    }
    return count - 1;
}

void repl(struct Table* table)
{
    char input[1024];

    while (true)
    {
        printf("db > ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, ".exit") == 0)
            break;
        else if (strncmp(input, "insert", 6) == 0)
        {
            struct Row row;
            printf("Eneter the id, name and email \n");
            sscanf(input, "insert %d %s %s", &row.id, row.userName, row.email);

            int countArgs = numOfArgs(input);

            if(countArgs > 3)
                printf("Too many args\n");
            else if (countArgs < 3)
                printf("Too few args\n");
            if(countArgs == 3)
            {
                insert_row(table, row);
                printf("Executed.\n");
            }
        }
        else if (strcmp(input, "select") == 0)
            select_rows(table);
        else
            printf("Unrecognized command: %s\n", input);
    }
}