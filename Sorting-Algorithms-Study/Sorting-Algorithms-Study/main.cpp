#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>

#include "sort.h"
#include "time.h"
#include <experimental/filesystem>

int main()
{
	//std::chrono::system_clock::now().time_since_epoch()).std::count()

	// Variables to hold method start, end, and total times.
	long long time_start = 0;
	long long time_end = 0;
	long long time_total = 0;

	// Vector to be used for testing.
	std::vector<int> test_vector;

	// Variable to hold the original size.
	const int org_max_size = 50000;

	// Varables to hold the max insert sizes for the various methods.
	int insert_max_size = 50000;

	// Variables to hold increments.
	const int increment_50_k_i = 50000;
	const int increment_100_k_i = 100000;

	/***
	 * Populate a vector with random integer values and run the insertion sort.
	 * Do this until total count = 300k items.
	 */
	while (insert_max_size <= 300000)
	{
		nwacc::fill_vector(test_vector, insert_max_size);
		time_start = std::chrono::system_clock::now().time_since_epoch().count();
		nwacc::insertion_sort(test_vector);
		time_end = std::chrono::system_clock::now().time_since_epoch().count();
		time_total = time_end - time_start;
		std::cout << "The vector size was: " << insert_max_size << std::endl;
		std::cout << "The type of sort was: Insertion Sort" << std::endl;
		std::cout << "Time running time was from: " << time_start << "to" << time_end << std::endl;
		std::cout << "Total time was: " << time_total << std::endl;
		std::cout << "Restarting simulation with new vector size of + " << increment_50_k_i << std::endl;
		std::cout << std::endl;
		insert_max_size += increment_50_k_i;
		time_start = 0;
		time_end = 0;
	}

	std::system("pause");
	return 0;
}
