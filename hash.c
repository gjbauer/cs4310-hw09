#include "hash.h"
#include <stdio.h>


int hash(const unsigned char *str)
{
    unsigned long hash = 137;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 512;
}

/*int main() {
	printf("%ld\n", hash("hello") % 512);
}*/

