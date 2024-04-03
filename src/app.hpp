#ifndef __APP_MOD_SINGLE__
#define __APP_MOD_SINGLE__

#include <string>
#include <vector>
#include <optional>

class ArgParser {

	std::vector<std::string> m_entries;

	public:
		ArgParser(int argc, char const *argv[]);
		std::optional<std::string> getArgValue(const std::string& key);
		int getArgNumValue(const std::string& key, int fallback_val);
		bool getBoolFlag(const std::string& key);

};

std::vector<int> generateRandomSequence(size_t length, int32_t minInt, int32_t maxInt);

extern const std::vector<std::string> mnemonicTokens;

namespace Text {

	extern const std::string help;

};

#endif
