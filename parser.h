#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <string_view>

#include "json.h"

class Parser
{
public:
	Parser() = default;

	Parser(const std::string_view& source) : source_(source) {}

	void Load(const std::string& str);

	Json Parse();

private:
	void IgnoreWhitespace();

	// 让index_指向当前正在解析的字符的下一个非空白字符
	// 即每次调用该函数时index_都会自动向后走
	char& GetNextToken();

	Json ParseNull();
	Json ParseBool();
	Json ParseNumber();
	std::string ParseString();
	Json ParseArray();
	Json ParseObject();

protected:
	std::string source_;
	size_t index_{};
};

#endif  // PARSER_H