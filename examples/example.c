#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hll.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct HLL hll;
    dlang_hll_create(&hll, 18, 25, malloc, realloc, free);
    for (;;)
    {
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        uint64_t hash = dlang_hll_murmurhash(line, read);
        dlang_hll_put_hash(&hll, hash);
    }
    free(line);
    uint64_t count = dlang_hll_count(&hll);
    dlang_hll_destroy(&hll);
    printf("Estimated cardinality number: %llu\n", count);
    return 0;
}
