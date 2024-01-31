#include "write_scores.h"
#include <iostream>
#include <fstream>
#include <string>


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
}
// end of score here just to mark end of the logic block of code
