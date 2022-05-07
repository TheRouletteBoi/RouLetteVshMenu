# super_simple_yaml
A super simple parser for a YAML subset

TBD - no copy parser
- event based parser
- two passes - pass 1:count, allocate nodes array, pass 2:get data
- data objects are small, accessor objects are proxies that are build on demand
- data objects
  - str: int pos offset, int size
  - num: 64 bit double or 64 bit long
  - array: int length, int start offset in nodes array (HOW?)
  - map: int length, int start offset of chaind elements of str(key) and node(value)
how arrays - need to know the length of the array at the start of parsing it
? when seeing an array, parse till its end? bad idea too many passes
- array need to be random access
- no allocations after initial allocation 
