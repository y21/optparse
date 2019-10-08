#include <optparse/parser.hpp>
#include <stdio.h>
#include <vector>
#include <iostream>

int main(int argc, char** argv) {

	// Create instance of optparse::parser and listen for options "a", "b", and "c"
	optparse::parser parser(argc, argv, "abc");

	// Get options
	std::vector<optparse::option> opts = parser.get_options();

	// Iterate over options
	for (int i = 0; i < opts.size(); ++i) {
		std::cout << opts.at(i).name << ": " << opts.at(i).value << "\n";
	}
}
