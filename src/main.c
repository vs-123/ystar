#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "ystar.h"

typedef uint64_t u64;
typedef uint32_t u32;

int
main (void)
{
#define min 1
#define max 25

   u64 seed           = time (NULL) ^ (u64)&seed ^ (u64)main;
   u64 freq[max + 1]  = { 0 };
   u32 sequence[2000] = { 0 };

   for (u32 i = 0; i < 1000000; i++)
      {
         u32 num = ystar_between (&seed, min, max);
         freq[num - 1]++;

         if (i + 1 < 2000)
            {
               sequence[i] = num;
            }
      }

   printf ("Sequence (first 2K) -- ");
   for (u32 i = 0; i < 2000; i++)
      {
         printf ("%u  ", sequence[i]);
      }

   printf ("\n");

   for (u32 i = 0; i < max; i++)
      {
         u32 num       = i + 1;
         u64 frequency = freq[i];

         printf ("%u \t %llu times\n", num, frequency);
      }

   return 0;
}
