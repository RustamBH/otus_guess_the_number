#include <cstdlib>
#include <ctime>
#include "check_value.h"


void random_value(int& target_value, const int& max_value) {
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	target_value = std::rand() % max_value;
}


int check_value(int& attempts_count, int& max_value) {
	int target_value = 0;
	int current_value = 0;
	//bool not_win = true;

	random_value(target_value, max_value);

	std::cout << "Random_value:" << target_value << std::endl;
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
