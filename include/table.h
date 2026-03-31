#ifndef TABLE_H
#define TABLE_H

#include "row.h"
#include "pager.h"

#define MAX_ROWS 1000

#define ROWS_PER_PAGE (PAGE_SIZE / sizeof(struct Row))
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)


struct Table{
    uint32_t rowCount; 
    struct Pager* pager;
};

struct Table* db_open(const char* filename);
void initializeTable(struct Table* table);
void insertRow(struct Table* table, struct Row row);
void selectRows(struct Table* table);

#endif