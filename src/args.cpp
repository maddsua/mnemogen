#include "./args.hpp"

ArgParser::ArgParser(int argc, char const *argv[]) {

	for (int i = 0; i < argc; i++) {
		this->m_entries.push_back(argv[i]);
	}

}

std::optional<std::string> ArgParser::getArgValue(const std::string& key) {

	const auto prefix = "--" + key + "=";

	std::string argEntry;

	for (const auto& item : this->m_entries) {
		if (item.starts_with(prefix)) {
			argEntry = item;
			break;
		}
	}
	
	if (!argEntry.size()) {
		return std::nullopt;
	}

	const auto value = argEntry.substr(prefix.size());
	if (!value.size()) {
		return std::nullopt;
	}

	return value;
}

int ArgParser::getArgNumValue(const std::string& key, int fallback_val) {

	const auto argValue = this->getArgValue(key);
	if (!argValue.has_value()) {
		return fallback_val;
	}

	const auto& value = argValue.value();

	if (!value.size()) {
		return fallback_val;
	}

	std::string valueTrimmed;
	valueTrimmed.reserve(value.size());

	for (const auto item : value) {
		if (!(item == ' ' || item == '\t')) {
			valueTrimmed.push_back(item);
		}
	}

	for (const auto item : value) {
		if (!((item >= '0' && item <= '9') || item == '-')) {
			return fallback_val;
		}
	}

	return std::stoi(value);
}
