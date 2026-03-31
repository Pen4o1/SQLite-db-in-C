#ifndef ROW_H
#define ROW_H

#define MAX_USERNAME_LENGTH 255
#define MAX_EMAIL_LENGTH 255

struct Row
{
    int id;
    char userName[MAX_USERNAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

void printRow(struct Row* row);
void cleanRow(struct Row* row);

#endif