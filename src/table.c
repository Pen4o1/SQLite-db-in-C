#include <stdio.h>
#include "../include/row.h"
#include "../include/table.h"

void initializeTable(struct Table* table)
{
    table->rowCount = 0;
}

void insertRow(struct Table* table, struct Row row)
{
    if(table->rowCount >= MAX_ROWS)
        printf("Its full");
    else {
        table->rows[table->rowCount] = row;
        table->rowCount += 1;
    }
}

void selectRows(struct Table* table)
{
    for(int i = 0; i < table->rowCount; i++)
    {
        struct Row* row = get_row_at_index(table, i);
        printRow(row);
    }
}