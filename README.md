# CMatrix

A lightweight and fast sugarfree matrices with an assembly friendly ABI.

Features:
1. Assembly-compatible ABI/calling convention, as easy to use from C++ as from C as from assembly.
2. Each source file is independant of others, enabling copy-pasting in case you want to make it inlineable.
3. The Code is relatively short and more or less understandable.

Flaws:
1. Not inlineable by default, which is a significant speed overhead over just having the whole library as a single header file,
   allowing the compiler to avoid the function call altogether along with passing of arguments, and have more efficient copying by
   rearranging the call to cater to each callee based on prior compilation context rather than being uniform with each callee. 
2. matrix_identityf is too generic, in reality, it would be a lot faster if it only dealt with 2x2,3x3,and 4x4 matrices, as 
   anything above that is seldom used. 
