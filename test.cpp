#include <optparse/parser.hpp>
#include <stdio.h>

int main(int argc, char** argv) {
	optparse::option* opts = optparse::parse(argc, argv, "abc");
	for (int i = 0;; ++i) {
		if (!opts[i].name) break;
		printf("Found option: %c\n", opts[i].name);
	}
	free(opts);
}
