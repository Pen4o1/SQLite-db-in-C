#include <stdio.h>
#include "table.h"
#include "row.h"

void repl(struct Table* table);

int main()
{
    struct Table table;
    initialize_table(&table);
    repl(&table);

    return 0;
}