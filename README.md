# Advent of code 2024

Propositions for the Advent of code 2024 (will be done in C++20 with bits/stdc++.h (non-standard but very common))

## Structure

All files are organised in the following structure :

- a directory for each day with the name `day_XX` (e.g. `day_01` for the first day)
- each day directory will have the sample provided as `sample` and the code in `main.cpp`
- a `run_main` script at the root

*Note: I try to keep my solutions as smol as possible in terms of source code. If I go over the arbitrary boundary of 1000 bytes of source code one day, I will do my best to create a source file that satisfies it. This source file will have the name `main_obf.cpp` and will be a lot less readable than the original one, yet will function the same way (heavy use of preprocessor, no unnecessary white space, shorter variable names, ...)*

## Use

Simply use the `run_main` script to run each day

For example, if you want to run the first day, simply do :

```shell
cd day_01
../run_main
```

and the sample input will be run. A `main` executable should also be generated, which can be used later

If you want to run your input, just do

```shell
cd day_01
mv PATH/TO/YOUR/INPUT ./input
../run_main input
```

*Note: The script also displays information about the time to run the program, which can be useful if you want to compare your program to mine :3*

