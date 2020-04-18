#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    while(ch != EOF)
    {
        ch = getchar();
        if(ch == EOF)
            continue;
        putchar(ch);
    }

    return 0;
}
