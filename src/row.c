#include "../include/row.h"
#include <string.h>


void cleanRow(struct Row* row)
{
    if (row == NULL) return;

    memset(row->userName, 0, MAX_USERNAME_LENGTH);
    memset(row->email, 0, MAX_EMAIL_LENGTH);
}

void printRow(struct Row* row)
{
    if (row == NULL) return;
    
    printf("(%d %s %s)", row->id, row->userName, row->email);
}