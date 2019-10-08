#include <optparse/parser.hpp>
#include <stdio.h>
#include <vector>
#include <iostream>

int main(int argc, char** argv) {

	optparse::parser parser(argc, argv, "*");

	std::vector<optparse::option> opts = parser.get_options();

	for (int i = 0; i < opts.size(); ++i) {
		std::cout << opts.at(i).name << ": " << opts.at(i).value << "\n";
	}
}
