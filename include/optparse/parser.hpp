//  optparse
//
//  Copyright (c) 2019 y21. All rights reserved.
//  MIT License
#ifndef __OPTPARSE__
#define __OPTPARSE__
#define __OPTPARSE_DEFAULT_BUFF__ 0x10
#define __OPTPARSE_OPT_COUNT__ 0x10

#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>

namespace optparse {
	/// @brief Represents an option that was found
	struct option {
		/// Holds the option name
		std::string name;

		/// Holds the option value
		std::string value;
	};

	/// @brief The class that parses options
	class parser {
		private:
			std::vector<option> options;
		public:
			/// @brief Constructor that parses options
			// @param argument_count The number of argument_values
			// @param argument_values An array of char* containing text that will be searched for options
			// @param options A C-String that specifies what to search for; use * to listen for all options
			parser(int argument_count, char** argument_values, const char* options) {
				for (int i = 0; i < argument_count; ++i) {
					const int value_length = strlen(argument_values[i]);
					for (int j = 0; j < value_length; ++j) {
						const char current_char = argument_values[i][j];
						const char next_char    = argument_values[i][j + 1];

						if (current_char == '-' && 
							j <= value_length && 
							(!strcmp(options, "*") || strchr(options, next_char) != NULL)) {
								// ^ might cause bug, changed strchr() != NULL to !strchr(); check git
								option opt = {"", ""};

								// Parse option name
								for (int k = 1; k < value_length; ++k) {
									const char current_char_k = argument_values[i][k];
									if ((current_char_k >= 65 && current_char_k <= 90) || (current_char_k >= 97 && current_char_k <= 122)) {
										opt.name += current_char_k;
									} else { // space; indicates beginning of value
										break;
									}
								}

								// Parse option value
								for (int k = 0; k < strlen(argument_values[i + 1]); ++k) {
									const char current_char_k = argument_values[i + 1][k];
									if (current_char_k != 32) {
										opt.value += current_char_k;
									} else { // space; indicates end of value
										break;
									}
								}
								// Check if option name is empty
								// This may be because argument_values has - in it followed by a character that is not A-Za-z
								if (opt.name == "") throw std::runtime_error("Invalid option name");

								this->options.push_back(opt);
						}
					}
				}
			}

			/// @brief Returns a vector of all options that were found in argument_values
			std::vector<option>& get_options() {
				return this->options;
			}

			/// @brief Sets options of this instance
			/// @param options A vector of option objects
			void set_options(std::vector<option> options) {
				this->options = options;
			}
	};
}

#endif
