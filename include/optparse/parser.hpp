#ifndef __OPTPARSE__
#define __OPTPARSE__
#define __OPTPARSE_DEFAULT_BUFF__ 0x10
#define __OPTPARSE_OPT_COUNT__ 0x8
#include<stdlib.h>
#include<cstring>
namespace optparse {
	typedef struct {
		char name;
		char value[__OPTPARSE_DEFAULT_BUFF__];
	} option;
	
	option* parse(int __argc, char** __argv, const char* _opt) {
		int optCount = 0;
		int optLimit = __OPTPARSE_OPT_COUNT__;
		option* options = (option*)malloc(sizeof(option) * optLimit);
		for (int i = 0; i < __argc; ++i) {
			const int len = strlen(__argv[i]);
			for (int j = 0; j < len; ++j) {
				if (__argv[i][j] == '-' && j + 1 <= len) {
					option opt;
					opt.name = __argv[i][j + 1];
					if (optCount >= optLimit)
						options = (option*) realloc(options, sizeof(option) * (optLimit *= 2));
					options[optCount++] = opt;
				}
			}
		}
		return options;
	}
}

#endif
