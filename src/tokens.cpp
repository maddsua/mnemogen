#include "./tokens.hpp"

extern char _binary_var_bip39_txt_start;
extern char _binary_var_bip39_txt_end;

std::vector<std::string> parseObject();

std::vector<std::string> mnemonicTokens = parseObject();

std::vector<std::string> parseObject() {

	const size_t objsize = &_binary_var_bip39_txt_end - &_binary_var_bip39_txt_start;

	std::vector<std::string> result;

	std::string temp;

	for (size_t i = 0; i < objsize; i++) {

		char next = (&_binary_var_bip39_txt_start)[i];

		if (next != ' ' && next != '\t' && next != '\n' && next != '\n') {
			temp.push_back(next);
		} else if (temp.size()) {
			result.push_back(temp);
			temp.clear();
		}
	}

	if (temp.size()) {
		result.push_back(temp);
	}

	return result;
}
