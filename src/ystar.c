#include <stdint.h>

#include "ystar.h"

typedef uint64_t u64;
typedef uint32_t u32;

u64
ystar (u64 *seed)
{
   u64 x = *seed;
   x ^= x << 12;
   x ^= x >> 25;
   x ^= x << 27;
   *seed = x;
   return x * 0x8A55AE51A34D786FULL;
}

u32
ystar_between (u64 *seed, u32 min, u32 max)
{
   u32 range        = max - min + 1;
   u64 random_32bit = (u32)ystar (seed);
   u64 multiresult  = random_32bit * range;
   u32 leftover     = (u32)multiresult;

   if (leftover < range)
      {
         u32 threshold = -range % range;
         while (leftover < threshold)
            {
               random_32bit = (u32)ystar (seed);
               multiresult  = random_32bit * range;
               leftover     = (u32)multiresult;
            }
      }

   return (multiresult >> 32) + min;
}
