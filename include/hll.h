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
	uint64_t __payload[11];
};

struct HLL_UUID
{
	uint64_t data[2];
};

/**
Creates HLL instance.

constraint: p ∈ [4..min(pPrime, 18)]"
constraint: pPrime ∈ [4..63]
*/
int dlang_hll_create(
    struct HLL *hll,
    uint32_t p,
    uint32_t pPrime,
    void* (*malloc)(size_t size),
    void* (*realloc)(void* ptr, size_t size),
    void (*free)(void* ptr));

/**
Destroys HLL instance.
*/
void dlang_hll_destroy(struct HLL *hll);

/**
Adds hash value to the counter.
*/
void dlang_hll_put_hash(struct HLL *hll, uint64_t hash);

/**
Adds UUID to the counter.
*/
void dlang_hll_put_uuid(struct HLL *hll, struct HLL_UUID *uuid);

/**
Returns estimated cardinality number.
*/
uint64_t dlang_hll_count(struct HLL *hll);

/**
Returns 64bit Murmurhash3 value.
*/
uint64_t dlang_hll_murmurhash(const void *ptr, size_t size);

#ifdef __cplusplus
}
#endif
#endif
