#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "table.h"
#include "row.h"

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

            insert_row(table, row);
            printf("Executed.\n");
        }
        else if (strcmp(input, "select") == 0)
            select_rows(table);
        else
            printf("Unrecognized command: %s\n", input);
    }
}