
Compiler for custom-designed language for the Compilers course

Target language: Assembler x86 (32-bit, AT&T syntax)

The program can be compiled using the Makefile located in the project's root directory. Just execute:

```
make
```

Then you can use the compiler as follows:

```
./latc_x86 [file]
```

Directory Structure:

Root:
- `./src/` – Directory containing C++ source code
- `./src/libs/` – Common files for Backend and Frontend
- `./src/libs/Frontend` – Files used for static analysis (type checking, correctness checking) and gathering data necessary for compilation
- `./src/libs/Backend` – Files for generating ASM code
- `./lib/` – Helper files for compilation: `runtime.o`, `crt1.o`, `libc.a`, etc.
- `./Tests/lattests/` – Tests provided by the class instructor
- `./Tests/` – Tests created by me during compiler development

Technologies used:
- BNFC (v. 2.8.1) – Used for generating the frontend (parsers, lexers, etc.)
- C++ – The entire compiler is written in C++ without external libraries except those provided by BNFC.

Registers in ASM are only used to perform basic operations—most computations occur on the stack. Values are loaded from the stack into registers for calculations and then stored back onto the stack afterward.

The grammar includes arrays, structs, and objects; however, code generation for these features is not yet implemented. During static analysis, the compiler returns an error indicating that these features are not yet implemented.
