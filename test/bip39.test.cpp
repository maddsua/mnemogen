#include "../src/app.hpp"
#include <iostream>
#include <stdexcept>

bool testIsWord(const std::string& input) {

	for (char item : input) {

		const bool isUppercaseChar = item >= 'A' && item <= 'Z';
		const bool isLowercaseChar = item >= 'a' && item <= 'z';

		if (!isUppercaseChar && !isLowercaseChar) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {

	for (const auto& item : mnemonicTokens) {
		if (!testIsWord(item)) {
			throw std::runtime_error("Invalid BIP39 token: \"" + item + "\" is not a word");
		} else if (item.size() < 3) {
			throw std::runtime_error("Invalid BIP39 token: \"" + item + "\" is too short");
		} else if (item.size() > 20) {
			throw std::runtime_error("Invalid BIP39 token: \"" + item + "\" is too long");
		} 
	}

	return 0;
}
