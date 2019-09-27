#ifndef __OPTPARSE__
#define __OPTPARSE__
#define __OPTPARSE_DEFAULT_BUFF__ 0x10
#define __OPTPARSE_OPT_COUNT__ 0x10
#include <stdlib.h>
#include <cstring>
namespace optparse {
	typedef struct {
		char name;
		char* value;
	} option;

	class parser {
		private:
			int option_count = 0;
			int option_limit = __OPTPARSE_OPT_COUNT__;
			option* options = (option*) malloc(sizeof(option) * option_limit);
		public:
			parser(int _argc, char** _argv, const char* _opt) {
				for (int i = 0; i < _argc; ++i) {
					const int len = strlen(_argv[i]);
					for (int j = 0; j < len; ++j) {
						const char current_char = _argv[i][j];
						const char next_char = _argv[i][j+1];
						if (current_char == '-' && j + 1 <= len && (!strcmp((const char*)_opt, "*") || strchr(_opt, next_char) != NULL) && next_char != ':') {
							option opt;
							opt.name = _argv[i][j + 1];

							if (_argv[i + 1] && _argv[i + 1][0] != '-') {
								int opt_val_index = 0;
								int opt_val_limit = __OPTPARSE_DEFAULT_BUFF__;
								opt.value = (char*)malloc(sizeof(char) * opt_val_limit);
								for (int k = 0; k < strlen(_argv[i + 1]); ++k) {
									if (opt_val_index >= opt_val_limit) {
										opt.value = (char*)realloc(opt.value,  opt_val_limit *= 2);
									}
									opt.value[opt_val_index++] = _argv[i + 1][k];
								}
								opt.value[opt_val_index] = '\0';
							}


							if (this->option_count >= this->option_limit)
								this->options = (option*) realloc(this->options, sizeof(option) * (this->option_limit *= 2));
							this->options[this->option_count++] = opt;
						}
					}
				}
			}
			
			int get_option_count() const {
				return this->option_count;
			}

			int get_option_limit() const {
				return this->option_limit;
			}

			option* get_options() const {
				return this->options;
			}

			~parser() {
				free(this->options);
			}
	};
}

#endif
