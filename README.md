# optparse
A cross-platform header-only C++ library to parse unix-like options. This should work on all platforms, as it only uses native headers.

### Why?
`getopt()` (defined in `unistd.h`) is not available on Windows and other operating systems, so I have decided to write a really simple library that parses options.

### Compiling and Linking
Since this is a library that only consists of a header file, simply using the `-I` option would work:
```sh
g++ -Iinclude/ test.cpp -o parse
```

### How to use
To parse options, simply call `optparse::parse(int argc, char** argv, const char* opts);`, just like you would call `getopt`. <br/>
The difference here is that instead of using it in a loop, it returns an array of `optparse::option`s. <br/>
You can then iterate over it using the sizeof operator to determine how big the array is and simply break out of the loop if option.name == NULL. <br/>
See [example file](https://github.com/y21/optparse/blob/master/test.cpp) for a simple example that displays the given options.
