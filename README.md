# Y-STAR

A custom xorshift64* implementation in C, with my own constants.

This project reuses my xorshift* repo @ https://github.com/vs-123/xorshift-star

## INSTALLATION

Clone the repository:
```
% git clone https://github.com/vs-123/ystar
```

Generate the amalgamated single-header file using the Python script: (optional)
```
% python3 ./amalgamate.py
[DONE] 'ystar.h' DISTRIBUTABLE HEADER GENERATED
```   

The single-header file will be generated in dist/, include dist/
in your project to start using it.

**[NOTE]**
While I aim to keep dist/mylib.h updated with every commit,
there's always a chance that it may lag behind the latest changes in `src/` or `include/`.
In order to ensure you have the absolute latest version,
it is recommended to run the `amalgamate.py` Python script manually.

## USAGE

Once you've completed the installation, you may use the library as follows:

-   In any one file (for e.g. `main.c`), define `YSTAR_IMPLEMENTATION`
	  before including the header:
```c
#define YSTAR_IMPLEMENTATION
#include "ystar.h"

/* now you can use ystar! */

uint64_t seed = 5;
uint32_t num = ystar_between (&seed, 1, 10);
```
-   In any other file where you want to use the library functions,
    just include the header normally without the define:
```c
#include "ystar.h"

void some_other_function() {
   uint64_t seed = 10;
   uint32_t num = ystar_between (&seed, 1, 25);
}
```
-   See `examples/` for more.

## OBSERVATION

![Y-star PRNG Plot -- vs-123](https://github.com/vs-123/ystar/blob/main/prng_analysis.png)

**NUMBER OF SAMPLES** --> **10K**

**RANGE** --> **1 to 25**

**SEQUENCE (FIRST 2K)**
```
1  22  18  10  16  1  8  7  17  19  8  5  19  25  23  8  15  25  4  19  6  1  8  21  11  3  17  22  3  16  23  11  11  3  25  22  3  4  6  16  4  23  19  3  3  1  16  14  10  7  6  23  20  19  5  16  13  21  22  21  9  15  13  15  24  25  25  13  9  2  8  24  5  13  6  12  2  7  1  23  16  14  9  1  25  16  22  4  13  11  16  13  13  5  11  12  10  14  15  10  15  20  18  5  13  3  17  3  14  14  22  4  7  5  4  16  3  3  3  3  14  10  13  7  4  21  6  17  13  9  22  10  18  18  9  22  12  16  13  4  5  14  5  16  2  20  11  1  14  7  21  24  19  16  24  4  17  21  12  12  12  8  17  23  3  8  11  25  12  18  1  24  16  8  17  18  23  6  1  14  6  20  7  24  12  17  9  18  7  10  21  21  4  14  25  24  15  16  19  7  13  5  19  11  2  9  9  10  15  24  13  21  1  1  13  20  15  18  2  19  21  17  22  20  10  2  20  14  7  10  20  16  24  25  2  16  14  16  25  8  2  12  16  20  8  6  25  3  9  19  7  12  20  8  19  7  18  10  2  23  24  6  20  15  21  17  1  24  8  14  14  10  22  3  3  18  11  20  15  15  12  1  9  14  19  4  16  8  5  10  1  1  25  16  16  21  21  10  19  25  2  22  8  1  15  12  2  22  4  20  5  16  1  17  13  5  17  16  12  3  22  17  19  3  16  22  20  14  3  1  19  10  10  17  21  15  1  12  16  3  4  15  16  18  19  17  13  17  14  22  20  12  7  24  13  25  4  4  17  8  21  20  10  1  2  9  6  7  6  12  25  1  23  20  5  6  15  14  20  13  13  3  11  24  9  11  13  12  9  21  3  7  12  1  9  25  21  23  16  16  9  25  8  15  12  18  13  9  10  7  16  11  11  16  12  13  5  19  20  24  22  21  23  22  18  12  14  5  19  3  12  4  21  19  15  22  9  21  17  13  11  3  6  22  11  5  9  1  14  22  21  24  21  10  23  25  21  10  15  1  15  2  12  2  3  10  24  13  5  8  23  23  8  11  12  12  1  6  22  13  17  4  18  7  6  24  17  25  15  25  24  19  12  19  10  4  10  13  15  13  11  11  22  14  13  24  5  3  23  11  10  18  24  13  11  2  15  7  20  16  1  7  5  8  1  19  23  19  21  25  17  20  5  5  7  21  16  5  22  6  4  6  22  17  16  13  5  4  24  23  7  4  3  5  9  3  15  24  19  12  6  20  19  21  8  6  14  13  9  5  8  17  10  21  2  25  16  25  17  20  23  1  24  4  8  8  7  8  5  17  4  5  17  17  18  17  20  17  2  14  16  4  3  10  2  4  25  23  6  24  20  14  17  12  14  12  22  20  23  4  3  25  17  15  24  5  5  24  12  5  13  10  18  6  7  11  16  3  21  13  4  2  3  19  18  6  10  4  1  17  20  5  6  10  22  24  4  16  23  7  3  8  5  1  25  17  16  9  1  16  14  21  3  15  4  19  17  8  18  5  3  22  14  9  19  24  7  9  12  25  25  9  24  9  14  15  8  24  20  17  15  14  25  9  15  23  13  23  21  8  20  11  2  8  6  21  14  7  18  23  1  17  12  13  23  8  13  15  24  21  13  1  21  23  24  20  18  10  1  10  18  24  9  3  4  25  23  10  24  2  10  14  12  23  5  21  1  9  3  15  21  11  11  6  15  23  19  17  3  7  9  4  20  25  4  13  24  7  21  10  9  20  2  13  19  4  18  12  9  21  11  21  9  23  1  14  15  3  19  25  15  12  15  21  20  4  20  21  5  18  23  9  13  3  13  12  6  3  4  11  22  18  12  25  4  15  9  20  5  18  7  2  23  24  18  7  17  3  15  6  13  12  9  17  1  18  14  25  4  4  14  19  14  24  19  9  4  7  8  12  5  18  10  23  9  13  21  14  24  23  20  11  16  13  23  9  19  2  7  13  17  1  24  7  16  9  13  14  19  21  5  18  14  6  16  20  17  22  22  13  6  20  16  21  25  11  24  24  23  13  13  6  17  22  18  16  15  2  11  6  19  13  13  25  2  21  1  8  21  14  2  10  23  6  22  22  1  5  5  19  24  12  4  15  24  9  6  7  4  5  5  23  25  17  25  18  1  7  5  19  1  14  11  19  19  10  5  11  4  4  17  4  21  4  20  1  15  15  11  5  25  17  14  12  11  13  9  6  16  3  8  20  6  9  19  22  19  3  2  16  15  17  18  20  17  11  13  25  14  15  18  1  21  5  4  22  7  18  20  10  19  21  20  21  14  13  3  8  17  16  8  15  13  23  4  2  10  9  11  14  15  6  21  9  24  9  2  12  15  4  4  10  13  15  2  25  17  3  5  20  17  23  9  2  14  3  8  16  21  8  7  1  13  8  21  9  24  6  11  6  1  22  21  8  18  10  4  5  8  11  25  12  21  2  25  18  11  25  22  12  10  20  20  25  1  11  1  11  3  18  2  12  17  12  6  9  20  23  19  21  10  9  8  2  2  9  11  20  17  20  24  7  12  9  10  20  22  14  8  17  5  18  6  14  20  5  20  4  17  12  19  1  12  17  14  2  19  4  8  18  22  14  21  7  15  4  3  12  14  10  23  10  2  10  4  14  17  12  12  6  22  7  11  6  22  21  20  25  24  15  10  10  20  21  2  25  4  6  7  5  16  3  13  9  7  15  24  13  22  3  22  22  1  6  19  15  7  1  6  15  19  5  1  7  3  3  6  24  12  5  10  17  16  4  9  12  13  12  14  7  6  22  15  24  20  24  2  1  13  23  18  22  6  2  7  21  2  24  20  17  5  5  3  15  4  8  23  2  18  12  17  5  16  12  10  14  22  6  23  20  21  15  23  7  20  13  2  4  8  24  12  1  24  20  20  19  18  7  3  18  19  25  15  9  14  22  22  7  24  6  8  11  6  16  2  23  9  24  25  11  19  16  11  14  17  17  14  1  22  14  22  11  9  4  15  17  6  3  5  8  2  3  12  5  8  15  23  16  15  12  11  10  8  25  23  14  3  8  2  6  3  12  22  23  12  11  14  10  25  5  20  16  4  20  13  20  1  2  23  4  20  5  15  23  12  20  5  18  10  3  21  12  16  19  24  20  18  4  17  12  19  7  15  21  18  14  3  1  10  9  12  1  22  3  6  15  1  8  16  22  16  8  7  2  12  14  5  12  7  11  25  17  20  21  25  23  11  12  12  6  24  5  24  5  15  15  7  8  6  19  2  15  16  5  24  15  7  23  25  14  19  11  15  3  20  24  13  14  1  4  5  13  1  3  9  18  1  20  3  25  15  12  7  13  10  9  9  3  25  5  24  8  1  7  23  24  25  12  3  24  22  16  4  13  15  18  18  2  9  9  14  6  7  25  15  16  22  6  14  11  22  16  24  23  12  20  19  13  16  5  17  4  22  8  11  15  9  15  25  18  20  25  16  22  20  9  11  15  10  16  21  8  1  2  3  17  13  7  19  7  18  24  10  22  1  2  14  12  18  5  22  6  14  1  22  20  10  2  9  9  14  19  12  19  18  19  6  16  2  5  7  8  11  20  7  1  17  20  23  2  25  9  11  20  6  14  11  20  16  2  16  11  2  9  19  21  11  16  25  4  25  12  16  4  19  7  2  16  17  12  10  3  25  18  7  20  7  1  9  10  4  12  2  4  5  23  25  23  7  9  11  18  22  14  4  22  18  16  21  24  25  21  22  12  13  3  3  23  8  7  2  13  2  8  4  4  6  12  24  4  23  25  16  15  21  15  23  4  20  21  14  22  19  12  2  1  9  9  10  18  2  12  19  18  24  5  10  13  21  13  20  9  20  10  18  7  10  24  25  13  7  18  13  8  4  21  23  7  24  15  5  2  24  20  16  14  13  1  15  8  14  19  15  2  2  10  7  16  12  6  21  14  8  13  10  19  10  17  13  13  10  8  9  19  23  12  14  9  22  21  2  24  12  9  19  14  24  3  21  7  10  16  25  14  5  25  21  8  2  9  1  1  10  21  1  2  25  6  18  7  11  8  24  10  20  13  15  4  19  23  9  19  7  2  24  2  22  11  13  10  25  23  19  10  14  20  8  15  17  13  23  6  6  24  18  22  5  5  24  1  6  17  21  16  4  24  24  20  8  16  3  9  7  8  16  19  6  16  24  8  1  24  9  5  5  25  5  23  24  18  21  15  11  16  25  3  2  19  16  14  6  12  14  1  13  12  24  18  19  25  11  6  8  24  4  14  3  11  14  5  3  22  14  18  5  24  2  1  22  7  6  21  21  19  20  1  15  18  20  17  14  18  4  9  17  23  12  12  20  16  10  23  7  24  9  15  7  16  6  17  10  1  11  9  18  2  20  15  10  18  9  1  21  6  4  9  9  1  10  23  2  5  12  12  4  17  3  25  7  12  15  13  18  16  3  8  6  8  12  11  17  25  16  12  14  16  19  1  12  11  7  21  12  20  24  10  17  6  8  10
```

**CHI-SQUARED (10K TALLY)** --> **24.0310**

**P-VALUE:** --> **0.4598**

This is our uniformity test, this tells how equal are the frequencies of each number in the range 1 to 25 in our sequence.

Generally a P-value between 0.05 to 0.95 is considered good. Our result `0.4598` sits near the centre, it implies that our distribution is balanced perfectly.

If our P-value were less than 0.05, it would've implied that our PRNG is biased (i.e. some numbers appear more frequently than others, kinda like a weighted die). On the other hand, if it were greater than 0.95, it would've implied that our generator is "too perfect". This generally occurs in predictable sequences like `1, 2, 3, ...` where the counts are equal, which is of course not expected in true randomness.

**WALD-WOLFOWITZ RUNS TEST (2K SEQUENCE):**

- **TOTAL RUNS**   --> **957**

- **EXPECTED**     --> **959.00**

- **Z-SCORE**      --> **-0.0914**

- **P-VALUE**      --> **0.9272**

This test checks for streaks, basically it tells how long the sequence stays above or below the median.

A negative Z-score would tell that our PRNG is clumping, i.e. if it spits a high number then the next one's most likely to be high as well. A positive Z-score would tell that our PRNG is oscillating, i.e. it's switching between high and low numbers predictably like `high, low, high, low`.

Our Z-score is `-0.0914`, and that's very very close to zero. It means the PRNG is close to being ideally "random".

Our P-value of `0.9272` tells that the generate sequence is pretty "choppy", which is what we'd expect from a random process.

**LAG-1 CORRELATION** --> **0.0067**

This test tells how predictable our PRNG is. Basically, if I am given a number from the sequence, can I guess the next number accurately?

A correlation close to +1 implies that the sequence would form a linear plot, which would allow one to predict the next number. A correlation close to -1 implies that a high number would be followed by a low number.

Our correlation of `0.0067` is very close to `0`, which tells that if I gave you a number from a sequence generated by this PRNG, you wouldn't be able to guess the next number.

**[NOTE]**

You may run the tests manually. Just run `make r` at project root,
take the sequence from `stdout` xand edit it in `analyse.py`'s `sequence_str` variable,
update `tally_data` and then execute `analyse.py` to get the test results in `stdout`
along with the plot @ `prng_analysis.png` in project root.

## LICENSE

This project is licensed under AGPLv3 or later.
**NO WARRANTY PROVIDED**
See LICENSE file for full terms or visit https://www.gnu.org/licenses/agpl-3.0.html