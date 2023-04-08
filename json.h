#ifndef JSON_H
#define JSON_H

#include <variant>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

class Json
{
public:
	enum class JsonType
	{
		json_null,
		json_bool,
		json_int,
		json_double,
		json_string,
		json_array,
		json_object
	};

	Json();
	Json(bool value);
	Json(int32_t value);
	Json(double value);
	Json(const char* value);
	Json(const std::string& value);
	Json(JsonType type);
	Json(const Json& other);
	// Json(std::vector<Json> value);
	// Json(std::unordered_map<std::string, Json> value);

	Json& operator=(Json other);

	void Swap(Json& other);

	operator bool() const;
	operator int() const;
	operator double() const;
	operator std::string() const;

	bool asBool() const;
	int asInt() const;
	double asDouble() const;
	std::string asString() const;

	Json& operator [](size_t index);
	void append(const Json& other);

	Json& operator [](const char* key);
	Json& operator [](const std::string& key);

	bool operator==(const Json&) const;
	bool operator!=(const Json&) const;

	using array_iterator = std::vector<Json>::iterator;
	using object_iterator = std::unordered_map<std::string, Json>::iterator;

	array_iterator array_begin();
	array_iterator array_end();
	object_iterator object_begin();
	object_iterator object_end();

	bool isNull() const { return type_ == JsonType::json_null; }
	bool isBool() const { return type_ == JsonType::json_bool; }
	bool isInt() const { return type_ == JsonType::json_int; }
	bool isDouble() const { return type_ == JsonType::json_double; }
	bool isNumber() const { return isInt() || isDouble(); }
	bool isString() const { return type_ == JsonType::json_string; }
	bool isArray() const { return type_ == JsonType::json_array; }
	bool isObject() const { return type_ == JsonType::json_object; }

	bool Has(int index) const;
	// bool Has(const char* key) const;
	bool Has(const std::string& key) const;

	void Remove(int index);
	// void Remove(const char* key);
	void Remove(const std::string& key);

	void Parse(const std::string& str);

	std::string Str();

	int& Count() { return format_level_; }

private:
	JsonType type_;
	std::variant<bool, int32_t, double, std::string, std::vector<Json>, std::unordered_map<std::string, Json>> value_;
	static int format_level_;
};

#endif  // JSON_H