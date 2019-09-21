#ifndef __OPTPARSE__
#define __OPTPARSE__
#define __OPTPARSE_DEFAULT_BUFF__ 0x10
#define __OPTPARSE_OPT_COUNT__ 0x8
#include <stdlib.h>
#include <cstring>
namespace optparse {
	typedef struct {
		char name;
		char* value;
	} option;
	
	option* parse(int __argc, char** __argv, const char* __opt) {
		int optCount = 0;
		int optLimit = __OPTPARSE_OPT_COUNT__;
		option* options = (option*)malloc(sizeof(option) * optLimit);
		for (int i = 0; i < __argc; ++i) {
			const int len = strlen(__argv[i]);
			for (int j = 0; j < len; ++j) {
				const char current_char = __argv[i][j];
				const char next_char = __argv[i][j+1];
				if (current_char == '-' && j + 1 <= len && strchr(__opt, next_char) != NULL && next_char != ':') {
					option opt;
					opt.name = __argv[i][j + 1];

					if (__argv[i + 1] && __argv[i + 1][0] != '-') {
						int opt_val_index = 0;
						int opt_val_limit = __OPTPARSE_DEFAULT_BUFF__;
						opt.value = (char*)malloc(sizeof(char) * opt_val_limit);
						for (int k = 0; k < strlen(__argv[i + 1]); ++k) {
							if (opt_val_index >= opt_val_limit) {
								opt.value = (char*)realloc(opt.value,  opt_val_limit *= 2);
							}
							opt.value[opt_val_index++] = __argv[i + 1][k];
						}
						opt.value[opt_val_index] = '\0';
					}


					if (optCount >= optLimit)
						options = (option*) realloc(options, sizeof(option) * (optLimit *= 2));
					options[optCount++] = opt;
				}
			}
		}
		return options;
	}
	
	option* parse(char* __argv, const char* __opt) {
		char** __argvP = (char**) malloc(sizeof(char) * strlen(__argv));
		__argvP[0] = __argv;
		return parse(1, __argvP, __opt);
	}
}

#endif
