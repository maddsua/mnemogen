#ifndef __APP_MOD_ARGS__
#define __APP_MOD_ARGS__

#include <string>
#include <vector>
#include <optional>

class ArgParser {

	std::vector<std::string> m_entries;

	public:
		ArgParser(int argc, char const *argv[]);
		std::optional<std::string> getArgValue(const std::string& key);
		int getArgNumValue(const std::string& key, int fallback_val);

};

#endif
