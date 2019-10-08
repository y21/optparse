#include <optparse/parser.hpp>
#include <stdio.h>
#include <vector>
#include <iostream>

int main(int argc, char** argv) {

	// Create instance of optparse::parser
	optparse::parser parser(argc, argv, "*");

	// Get options
	std::vector<optparse::option> opts = parser.get_options();

	// Iterate over options
	for (int i = 0; i < opts.size(); ++i) {
		std::cout << opts.at(i).name << ": " << opts.at(i).value << "\n";
	}
}
