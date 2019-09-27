# optparse
A cross-platform header-only C++ library to parse unix-like options. This should work on all platforms, as it only uses native headers.

### Why?
`getopt()` (defined in `unistd.h`) is not available on Windows and other operating systems, so I have decided to write a simple library that parses options.

### Compiling and Linking
Since this is a library that only consists of a header file, simply using the `-I` option to link would work:
```sh
g++ -Iinclude/ test.cpp -o parse
```

### Usage
To use optparse, create an instance of optparse::parser. It works very similar to `getopt`, which is why it takes the same parameters: `int argument_count, char** argument_values, const char* opt`. <br/>
To get an array of all options, use `optparse::option* optparse::parser::get_options()`. You can then use it in a loop. The method `get_option_count()` gives you the amount of options that were found.<br/>
See [example file](https://github.com/y21/optparse/blob/master/test.cpp) for a simple example that displays the given options.

### API
##### optparse::option (`struct`)
Represents an option. <br/>
- `char optparse::option::name`: Option name<br/>
- `char* optparse::option::value`: Option value

##### optparse::parser (`class`)
This class is used to parse options. It takes the number of `char*` as first parameter, an array of `char*` that holds all C-Strings containing options and `const char*` which tells the parser which options to listen to. You can use `*` to listen for ALL options<br/>
Implementation:
```c
optparse::parser(int __argc, char** __argv, const char* __opt);
```

##### optparse::parser::get\_option\_count (`const method: returns int`)
This method returns the number of options that were found as signed integer. It may be used as condition in a for-loop.

##### optparse::parser::get\_option\_limit (`const method: returns int`)
This method can be ignored. It is used to determine if new memory needs to be allocated.

##### optparse::parser::get\_options (`const method: returns optparse::option*`)
This method returns an `optparse::option` array which holds all options.

#### ~optparse::parser (`destructor`)
Frees allocated memory (`this->options` and other data)
