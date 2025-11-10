https://medium.com/@luischaparroc/compilation-process-with-gcc-and-c-programs-344445180ac8
[godbolt](https://godbolt.org/)

## 1. preprocessing (-E)
-> source code : include, define, remove comments, "searched" <implementation-defined-rules-to-find-the-file>
macros replaced

## 2. compilation (-S)
-> output of preprocessor -> generates assembly code

## 3. assemble (-c)
-> assembly code -> converts it into machine code (.o - object file with low-level language)

## 4. linking
-> merges the codes into single one

---

Some options
-g - turn on debugging (so GDB gives more friendly output)
-Wall - turns on most warnings
-O or -O2 - turn on optimizations
-o <name> - name of the output file
-c - output an object file (.o)
-I<include path> - specify an include directory
-L<library path> - specify a lib directory
-l<library> - link with library lib<library>.a

---

https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

#### -O/-O1

Optimize. Optimizing compilation takes somewhat more time, and a lot more memory for a large function.
With -O, the compiler tries to reduce code size and execution time, without performing any optimizations that take a great deal of compilation time.

-O is the recommended optimization level for large machine-generated code as a sensible balance between time taken to compile and memory use: higher optimization levels perform optimizations with greater algorithmic complexity than at -O.

-O turns on the following optimization flags:

#### -O2

Optimize even more. GCC performs nearly all supported optimizations that do not involve a space-speed tradeoff. As compared to -O, this option increases both compilation time and the performance of the generated code.

-O2 turns on all optimization flags specified by -O1. It also turns on the following optimization flags:

#### -O3
