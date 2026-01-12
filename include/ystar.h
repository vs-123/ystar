#ifndef YSTAR_H
#define YSTAR_H

#include <stdint.h>

/**
 * @brief 64-bit PRNG. Applies xor-shifts followed by a multiplicative scrambler.
 * @param seed Pointer to a 64-bit state variable.
 * NOTE: seed must be non-zero
 * @return uin64_t A new pseudo-random 64-bit integer  
*/
uint64_t ystar (uint64_t *seed);

/**
 * @brief Generates a pseudo-random number between =min= and =max= using ystar PRNG (inclusive).
 * @param seed Pointer to a 64-bit state variable.
 * @param min Minimum value to generate
 * @param max Maximum value to generate
*/
uint32_t ystar_between (uint64_t *seed, uint32_t min, uint32_t max);
   
#endif /* YSTAR_H */
