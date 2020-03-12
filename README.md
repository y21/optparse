# optparse
A lightweight cross-platform header-only C++ library to parse unix-like options. This works on all platforms, as it only uses native headers.

| | [optparse](https://github.com/y21/optparse) | [argh](https://github.com/aardvarkk/argh) |
|-|------------|---------------|
| Size | 2 KB | 7 KB |
| Raw String Manipulation | Yes | Yes |
| Documentation | Yes | Only examples |

### Why?
`getopt()` (defined in `unistd.h`) is not available on Windows and other operating systems, so I have decided to write a simple library that parses options.

### Compiling and Linking
Since this is a library that only consists of a header file, simply using the `-I` option to link would work:
```sh
g++ -Iinclude/ test.cpp -o parse
```

### Usage
To use optparse, create an instance of optparse::parser. It works very similar to `getopt`, which is why it takes the same parameters: `int argument_count, char** argument_values, const char* opt`. <br/>
To get a vector of all options, use `std::vector<optparse::option> optparse::parser::get_options()`. You can then use it in a loop. <br/>
See [example file](https://github.com/y21/optparse/blob/master/test.cpp) for a simple example that displays the given options.

### API
API documentation can be found [here](https://y21.github.io/optparse)
