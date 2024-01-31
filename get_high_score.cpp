#include "get_high_score.h"
#include <iostream>
#include <fstream>
#include <map>



// Read the high score file and print all results
int get_high_score(const std::string& high_scores_filename) {
	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::multimap<std::string, int> score_table;
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

		// Insert information to the score_table
		score_table.insert(std::pair<std::string, int>(username, high_score));
	}

	// Print minimal score of username
	std::string uname = score_table.begin()->first;
	int hscore = score_table.begin()->second;
	for (const auto& [username, high_score] : score_table) {
		if (uname == username) {
			if (hscore > high_score)
				hscore = high_score;
		} else {
			std::cout << uname << "\t" << hscore << std::endl;
			uname = username;
			hscore = high_score;
		}
	}
	std::cout << uname << "\t" << hscore << std::endl;

	return 0;
}
