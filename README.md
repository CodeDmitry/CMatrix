# CMatrix

A lightweight and fast sugar-free matrix library with an assembly-friendly ABI.

Contents:
- include: contains the header(s) for interfacing with the library.
- lib: contains the library file for statically linking to.
- src: contains the source files.
- obj: contains the object files used to create the library.
- tests: some proofs of concepts to check if the library works.
- README.md: this file.
- build.pl: builds the project, written in Perl because it's my library and I want to use Perl for my building process.

Features:
1. Assembly-compatible ABI/calling convention, as easy to use from C++ as from C as from assembly.
2. Each function is completely independant of others, and can be compiled as its own file, enabling copy-pasting in case you want to make it inlineable.
3. None of the functions do any C header imports, the only files that rely on C standard functions are the rotation functions(for sin and cos) and the dump function for fputc and fprintf, but they use a local forward declaration instead of a full C header include.
4. The Code is relatively short and more or less understandable.

Main Flaws: 
1. Not inlineable by default, which is a significant speed overhead over just having the whole library as a single header file,
   allowing the compiler to avoid the function call altogether along with passing of arguments, and have more efficient copying by
   rearranging the call to cater to each callee based on prior compilation context rather than being uniform with each callee. 
2. Not complete, no versioning is implemented and anybody using any particular version is responsible of taking it as a fork and managing
    it themselves.
    
Goals: 
- Make each line of the library cap at 60 characters, to be viewable comfortably on a phone.
- Document each service of the library(in the header file) with explicit weak/strong contracts.
- Limit matrices to 16 bits(uint16_t) rather than 32 bits(uint32_t), this would greatly increase their portability,
    as I do not want to support matrices greater than 16,000x16,000(256,000,000 elements)
    as it is rediculous except for stress testing. 
