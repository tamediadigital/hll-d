# Complete Generic [HyperLogLog++](https://research.google.com/pubs/pub40671.html) Implementation

```d
import hll;
import std.experimental.allocator;
import std.experimental.allocator.mallocator;
auto counter = HLL!(shared Mallocator)(Mallocator.instance);

/// loop
  counter.put(anArrayOrString);
  // or
  //counter.put(anUlong);
  //counter.put(anUUID); // for 64bit targets only

ulong count = counter.count;

```
