# Complete [HyperLogLog++](https://research.google.com/pubs/pub40671.html) Implementation

Written in D to use in C and other languages.

```d
import hll;
// creates HLL++ counter with maximal allowed precision (18)
auto counter = HLL(18); // allocated size is less or equal to 2 ^^ (18 - 3) * 6 / 1024 = 192 KB

/// loop
  counter.put(anArrayOrString);
  // or
  //counter.put(anUlong);
  //counter.put(anUUID);

ulong count = counter.count;

```

### Building the library with C API

BetterC mode allows to use D libraries without DRuntime and Phobos.

hll-d has C API. C/C++ headers can be found at the [include/](include/) directory.

#### Install LDC
1. Install [LDC](https://github.com/ldc-developers/ldc#installation) (LLVM D Compiler).
2. Install [DUB](http://code.dlang.org/download) package manager if it was not installed with LDC.

#### Download
```
git clone https://github.com/tamediadigital/hll-d
cd hll-d
```

#### Build
```
dub build --build=betterC --config=static --compiler=ldc2 --force
```

#### Test
```
gcc examples/example.c -Iinclude libhll-d.a
./a.out < examples/input.txt
```
