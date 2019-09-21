#include <optparse/parser.hpp>
#include <stdio.h>

int main(int argc, char** argv) {
	// Create instance and listen for ALL options
	// Alternatively, you could pass "abc" for example
	// to only listen for options "a", "b" and "c"
	// Like you would using getopt()
	optparse::parser parser(argc, argv, (char*)"*");
	// Get all options and store it in opts
	optparse::option* opts = parser.get_options();

	for (int i = 0;; ++i) {
		// Break out of the loop if !opts[i].name: no more flags
		if (!opts[i].name) break;
		
		// opts[i].name holds the option name, while opts[i].value holds the value.
		printf("Found option: %c (%s)\n", opts[i].name, opts[i].value);
	}
}
