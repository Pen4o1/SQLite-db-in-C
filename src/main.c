#include <stdio.h>
#include "../include/table.h"
#include "../include/row.h"

void repl(struct Table* table);

int main()
{
    struct Table table;
    initializeTable(&table);
    repl(&table);

    return 0;
}