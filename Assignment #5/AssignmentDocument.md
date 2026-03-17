# Exercise #5
# Name: Maksym Tymchyshyn

## Architecture Diagram

```
+-------------------+         +-------------------+
|   ComplexNumber    |         |    ComplexArray    |
|-------------------|         |-------------------|
| double real       |<------->| ComplexNumber* data|
| double imag       |  owns   | int size           |
|-------------------|         |-------------------|
| print()           |         | ComplexArray(int)  |
| operator==        |         | ~ComplexArray()    |
| operator>>        |         | move ctor          |
+-------------------+         | move assign        |
                              | operator[]         |
                              | print()            |
                              | size()             |
                              +-------------------+

       main.cpp                test_complex_array.cpp
      +--------+               +-------------------+
      | reads  |               | 8 doctest cases   |
      | input, |---uses------->| testing edge      |
      | demos  |               | cases for         |
      | moves  |               | ComplexArray       |
      +--------+               +-------------------+
```

## Use-Flow Diagram

```
User starts program
     |
     v
"How many complex numbers?" --> read n
     |
     v
Create ComplexArray(n)
     |
     v
Loop: read n complex numbers from stdin
     |
     v
Print original array
     |
     v
Move construct new array from original (std::move)
--> original is now empty (size = 0)
     |
     v
Print new array, show original size = 0
     |
     v
Move assign to another array (std::move)
--> moved-from is now empty (size = 0)
     |
     v
Print final array, show moved-from size = 0
     |
     v
All arrays destroyed (no leaks)
```
