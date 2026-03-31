#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "../include/pager.h"

void* get_page(struct Pager* pager, uint32_t page_num)
{
    if (page_num > TABLE_MAX_PAGES) return;

    if (pager->pages[page_num] == NULL) {
        void* page = malloc(PAGE_SIZE);
        uint32_t num_pages = pager->file_lenght / PAGE_SIZE;

        if (pager->file_lenght % PAGE_SIZE) {
            num_pages += 1;
        }

        if (page_num <= num_pages) {
            lseek(pager->file, page_num * PAGE_SIZE, SEEK_SET);
            ssize_t bytes_read = read(pager->file, page, PAGE_SIZE);
            if (bytes_read == -1) {
                printf("Error reading file: %d\n", errno);
                exit(EXIT_FAILURE);
            }
        }

        pager->pages[page_num] = page; 
}
