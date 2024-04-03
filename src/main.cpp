#include <cstdio>

#include "./app.hpp"

int main(int argc, char const *argv[]) {

	ArgParser args(argc, argv);

	if (args.getBooleanFlag("help")) {
		puts(Text::help.c_str());
		return 0;
	}

	const auto tokensNumber = args.getArgNumValue("tokens", 8);
	if (tokensNumber < 4) {
		fprintf(stderr, "Too few tokens selected. Use 4 or more\r");
		return 1;
	}

	const auto alighIn = args.getArgNumValue("align", 4);
	if (alighIn < 1) {
		fprintf(stderr, "Too few columns selected. Use 1 or more\r");
		return 1;
	}

	std::vector<std::string> generatedTokens;
	for (const auto& idx : generateRandomSequence(tokensNumber, 0, mnemonicTokens.size() - 1)) {
		generatedTokens.push_back(mnemonicTokens.at(idx));
	}

	puts("\nYo here\'s your new mnemonic phrase:\n--------");

	int columnIdx = 0;

	for (const auto& item : generatedTokens) {

		columnIdx++;

		char splitToken = ' ';

		if (columnIdx == alighIn) {
			splitToken = '\n';
			columnIdx = 0;
		}

		printf("%s %c", item.c_str(), splitToken);
	}

	puts("--------");

	return 0;
}
