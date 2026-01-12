#include <stdio.h>
#include <time.h>

#define YSTAR_IMPLEMENTATION
#include "ystar.h"

int
main (void)
{
   u64 seed = time(NULL) ^ (u64)&main;
   u32 num  = ystar_between (&seed, 1, 10);

   printf ("Random number is: %u\n", num);

   return 0;
}
