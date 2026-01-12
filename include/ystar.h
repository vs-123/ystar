#ifndef YSTAR_H
#define YSTAR_H

#include <stdint.h>

uint64_t ystar (uint64_t *seed);
uint32_t ystar_between (uint64_t *seed, uint32_t min, uint32_t max);
   
#endif /* YSTAR_H */
