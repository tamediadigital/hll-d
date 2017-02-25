# Complete [HyperLogLog++](https://research.google.com/pubs/pub40671.html) Implementation

Written in D to use in C and other languages.

```d
import hll;
auto counter = auto hll = HLL(18);

/// loop
  counter.put(anArrayOrString);
  // or
  //counter.put(anUlong);
  //counter.put(anUUID); // for 64bit targets only

ulong count = counter.count;

```

### Building the library with C API

BetterC mode allows to use D libraries without DRuntome and Phobos.

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
