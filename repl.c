#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void repl()
{
    char input[1024];
    while (true)
    {
        printf("db > ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, ".exit") == 0)
        {
            break;
        }
        printf("You entered: %s\n", input);
    }
}

int main() 
{
    repl();
    return 0;
}