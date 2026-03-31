#include <stdio.h>
#include "row.h"
#include "table.h"


void initialize_table(struct Table* table)
{
    table->rowCount = 0;
}

void insert_row(struct Table* table, struct Row row)
{
    if(table->rowCount >= MAX_ROWS)
        printf("Its full");
    else {
        table->rows[table->rowCount] = row;
        table->rowCount += 1;
    }
}

void select_rows(struct Table* table)
{
    for(int i = 0; i < table->rowCount; i++)
        printf("%d %s %s\n", table->rows[i].id, table->rows[i].userName, table->rows[i].email);
}