cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(guess_the_number
	guess_the_number.cpp
 	check_value.cpp
  	check_value.h
   	get_high_score.cpp
    	get_high_score.h
   	write_scores.cpp
    	write_scores.h
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
