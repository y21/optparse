#include <optparse/parser.hpp>
#include <stdio.h>

int main(int argc, char** argv) {
	// Store result of optparse::parse in a variable
	// to iterate over it
	optparse::option* opts = optparse::parse(argc, argv, "abc");
	
	for (int i = 0;; ++i) {
		// Break out of the loop if !opts[i].name: no more flags
		if (!opts[i].name) break;
		
		// opts[i].name holds the option name, while opts[i].value holds the value.
		printf("Found option: %c\n", opts[i].name);
	}
	
	// Free allocated memory
	free(opts);
}
