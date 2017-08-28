MSP432 Template
===============

A template for projects that uses MSP432 as target

* [ARM GCC](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) and [DSLite (part of MSP432Ware)](http://www.ti.com/tool/MSP432Ware) must be downloaded.

## How to use
* Define device name, compiler and DSLite paths in the `Makefile`

* Execute:\
`make release` to compile\
`make clean` to clean\
`make run` to write target with DSLite

* If want to use MSP432P401M, remove the `x` from extensions of:\
`/code/include/msp432p401m.hx`\
`/code/include/msp432p401m.ldsx`\
`/code/include/msp432p401m_classic.hx`\
`/code/include/system_msp432p401m.hx`\
`/code/src/startup_msp432p401m_gcc.cx`\
`/code/src/system_msp432p401m_gcc.cx`\
and add the `x` to extensions of `r` terminated file names.

## Compatibility

* MCU\
`MSP432P401M`\
`MSP432P401R`

## Features
* Compiles all source files inside de `code` directory.
* Compiles most recently modified files first, to hopefully find problems earlier.
* Automatically generates dependecies as files are compiled, ensuring that files are correctly recompiled when dependecies have updated.
* Includes configurations for normal (release) build and debug build suitable for GDB debugging.
* Times the compilation of each file and the entire build.
* By default, builds in a "quiet" mode that only lists the actions being performed. By passing V=true to make, you can compile in verbose mode to see the full compiler commands being issued.

## Limitations
* Assumes GNU make.
* Timing does not work correctly with MacOS. See [issue #6](https://github.com/mbcrawfo/GenericMakefile/issues/6) of original makefile template repository for a workaround patch that allows timing in seconds on Mac.
* Doesn't really support multiple types of source files in the same project.
* No easy way to exclude files from the build. You can either change the
  extension of files to be excluded, or use preprocessor flags for
  conditional compilation.

The `Makefile` and `README.md` are modified versions of [mbcrawfo/GenericMakefile](https://github.com/mbcrawfo/GenericMakefile)
