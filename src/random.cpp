#include <random>
#include "./app.hpp"

std::vector<int> generateRandomSequence(size_t length, int32_t minInt, int32_t maxInt) {

	std::vector<int> result;
	result.resize(length);

	std::random_device dev;
    std::mt19937 rng(dev());

	std::uniform_int_distribution<std::mt19937::result_type> dist6(minInt, maxInt);

	for (size_t i = 0; i < result.size(); i++){
		result[i] = dist6(rng);
	}
	
	return result;
}
