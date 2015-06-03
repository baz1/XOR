# XOR

## Presentation

This little program is a tool for xor-ing two binary files.
If the sizes of the files differ, the smaller size will be used.

## Usage

`xor file1 [file2]`

## Examples:

### Merging random seeds

```
xor random-seed-1 random-seed-2 > mixed-rnd-seed
```

### One-time-cipher

```
xor my-private-file < /dev/random > key
xor my-private-file key > encrypted-file
```

## Installation

There is no simpler thing!
1. Compile main.cpp (e.g. `gcc main.cpp -o xor`)
2. Put the `xor` program somewhere in the PATH
