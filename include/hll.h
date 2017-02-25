#ifndef Have_HLL_D
#define Have_HLL_D
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif

struct HLL
{
	uint64_t[11] __payload;
}

struct HLL_UUID
{
	uint64_t[2] data;
}

/**
Creates HLL instance.
*/
int dlang_hll_create(
    HLL *hll,
    uint p,
    uint pPrime,
    void* (*malloc)(size_t size),
    void* (*realloc)(void* ptr, size_t size),
    void (*free)(void* ptr));

/**
Destroys HLL instance.
*/
void dlang_hll_destroy(HLL *hll);

/**
Adds hash value to the counter.
*/
void dlang_hll_put_hash(HLL *hll, uint64_t hash);

/**
Adds UUID to the counter.
*/
void dlang_hll_put_uuid(HLL *hll, HLL_UUID uuid);

/**
Returns estimated cardinality number.
*/
uint64_t dlang_hll_count(HLL *hll);

/**
Returns 64bit Murmurhash3 value.
*/
uint64_t dlang_hll_murmurhash(HLL *hll, const void *ptr, size_t size);

#ifdef __cplusplus
}
#endif
#endif
