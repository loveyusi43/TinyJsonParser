#include <iostream>
#include <string>
#include <sstream>
#include <variant>
#include <vector>
#include <fstream>
#include <sstream>

#include "json.h"

int main(void)
{
	try
	{
		std::ifstream fin("./test.json");
		std::stringstream ss;
		ss << fin.rdbuf();
		const std::string& str = ss.str();
		Json v;
		v.Parse(str);
		std::cout << v.Str();

		/*std::string str = R"({ "name": "anran758", "avatar": "https://xxx", "detail": { "desc": "some description", "level": 2 } })";
		Json v;
		v.Parse(str);
		std::cout << v.Str();*/
		/*std::string msg = "hello world";
		std::cout << msg << "\b\b";*/
	}
	catch (const std::logic_error& error)
	{
		std::cout << error.what();
	}

	return 0;
}