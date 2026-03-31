#ifndef PAGER_H
#define PAGER_H
#include <stdint.h>

#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 100

struct Pager {
    int file;
    uint32_t file_lenght;
    void* pages[TABLE_MAX_PAGES]; 
};

void* get_page(struct Pager* pager, uint32_t page_num);

#endif