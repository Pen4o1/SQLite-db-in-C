#ifndef TABLE_H
#define TABLE_H
#include "row.h"

#define MAX_ROWS 1000

struct Table{
    struct Row rows[MAX_ROWS];
    int rowCount; 
};

void initialize_table(struct Table* table);
void insert_row(struct Table* table, struct Row row);
void select_rows(struct Table* table);

#endif