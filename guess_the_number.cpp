#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


// Generate random value
void random_value(int& target_value, const int& max_value) {
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	target_value = std::rand() % max_value;
}


// Check guess number
int check_value(int& attempts_count, const int& max_value) {	
	int target_value = 0;
	int current_value = 0;
	bool not_win = true;

	random_value(target_value, max_value);

	//std::cout << "Random_value:" << target_value << std::endl;
	std::cout << "Enter your guess:" << std::endl;

	do {
		attempts_count++;
		std::cin >> current_value;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! attempts = " << attempts_count << std::endl;
			break;
		}

	} while (true);

	return 0;
}


// Write new high score to the records table
int write_scores(const std::string& user_name, const int& attempts_count, const std::string& high_scores_filename)
{
	// We should open the output file in the append mode - we don't want
	// to erase previous results.
	std::ofstream out_file{ high_scores_filename, std::ios_base::app };
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	// Append new results to the table:
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;

	return 0;
} // end of score here just to mark end of the logic block of code


// Read the high score file and print all results
int get_high_score(const std::string& high_scores_filename) {
	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}

	return 0;
}

int main(int argc, char** argv) {
	const std::string high_scores_filename = "high_scores.txt";

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

	if (argc == 1) {
		argv[1] = const_cast<char*>("-max");
		argv[2] = const_cast< char*>("100");
		argc = 3;
	}
	else if (argc == 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
			argv[2] = const_cast<char*>("100");
			argc = 3;
		}
	}

	if (argc > 2) {
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

