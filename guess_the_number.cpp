#include "check_value.h"
#include "write_scores.h"
#include "get_high_score.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	const std::string high_scores_filename = "high_scores.txt";

	// Print No Extra Command Line Argument Passed Other Than Program Name
	if(argc == 1) {
		std::cout << "Wrong usage! The application needs argument '-max' with some value or argument '-table' to get high score table!" << std::endl;		
		return -1;
	}	

	// Print table of names and scores
	if (argc == 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-table") {
			get_high_score(high_scores_filename);
			return 0;
		}
	}

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	if (argc >= 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
			int parameter_value = 0;
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			parameter_value = std::stoi(argv[2]);
			int attempts_count = 0;
			check_value(attempts_count, parameter_value);
			write_scores(user_name, attempts_count, high_scores_filename);
		}
	}

	return 0;
}
