// Test your CPU might!!!
// By: Lester Millan
//
// Run this program on your computer and check how much it takes to
// finish the execution. It will display the time in seconds.
//

#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

void runTime()
{
	unsigned static long numberGenerated = 0;
	unsigned int numberOfIters = ~0;
	std::default_random_engine generator;
	std::uniform_int_distribution<long> distribution(0, numberOfIters);
	auto start = std::chrono::steady_clock::now();

	for(unsigned long i = 0; i < numberOfIters; i++)
	{
		numberGenerated = distribution(generator);
	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	numberGenerated = 0;
	std::cout << "Time executing: " << seconds.count() << " seconds" << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << std::endl;
	std::cout << "Number of threads: " << std::thread::hardware_concurrency() << std::endl;
	std::cout << "Executing, this might take a while...\n" << std::endl;
	std::thread t1(&runTime);
	t1.join();

	return 0;
}
