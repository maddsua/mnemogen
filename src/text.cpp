#include "./app.hpp"

extern char _binary_src_text_help_txt_start;
extern char _binary_src_text_help_txt_end;

const std::string Text::help = std::string(
	&_binary_src_text_help_txt_start,
	&_binary_src_text_help_txt_end - &_binary_src_text_help_txt_start
);
