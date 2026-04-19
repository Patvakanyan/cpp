#include "ScalarConverter.hpp"
#include <iomanip>
#include <sstream>

static std::string format_float(float value)
{
	std::ostringstream out;

	if (std::isnan(value))
		return "nanf";
	if (std::isinf(value))
		return (value < 0) ? "-inff" : "+inff";
	if (value == static_cast<int>(value))
		out << std::fixed << std::setprecision(1) << value;
	else
		out << value;
	return out.str() + "f";
}

static std::string format_double(double value)
{
	std::ostringstream out;

	if (std::isnan(value))
		return "nan";
	if (std::isinf(value))
		return (value < 0) ? "-inf" : "+inf";
	if (value == static_cast<int>(value))
		out << std::fixed << std::setprecision(1) << value;
	else
		out << value;
	return out.str();
}

static bool check_int(const std::string &str)
{
	const char *num = str.c_str();
	errno = 0;
	char *end;
	long val = std::strtol(num, &end, 10);

	if (errno == ERANGE)
		return false;
	if (end == num)
		return false;
	while (*end)
	{
		if (!std::isspace(static_cast<unsigned char>(*end)))
			return false;
		end++;
	}
	return val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

static bool check_char(const std::string &str)
{
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	return false;
}

static bool check_float(const std::string &str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	if (str.empty() || str[str.length() - 1] != 'f')
		return false;
	const char *c_str = str.c_str();
	char *end;
	errno = 0;
	double value = std::strtod(c_str, &end);
	if (errno == ERANGE)
		return false;
	if (end == c_str)
		return false;
	if ((value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) && !std::isinf(value) && !std::isnan(value))
		return false;
	return *end == 'f' && *(end + 1) == '\0';
}

static bool check_double(const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	if (str.find('f') != std::string::npos)
		return false;
	const char *c_str = str.c_str();
	char *end;
	errno = 0;
	std::strtod(c_str, &end);
	if (errno == ERANGE)
		return false;
	if (end == c_str)
		return false;
	while (*end)
	{
		if (!std::isspace(static_cast<unsigned char>(*end)))
			return false;
		++end;
	}
	return true;
}

Type get_type(const std::string &str)
{
	if (check_int(str))
		return TypeInt;
	else if (check_char(str))
		return TypeChar;
	else if (check_float(str))
		return TypeFloat;
	else if (check_double(str))
		return TypeDouble;
	return TypeInvalid;
}

void ScalarConverter::convert(const std::string &str)
{
	int i;
	float f;
	double d;
	char c;
	char *end;
	const Type type = get_type(str);

	switch (type)
	{
	case TypeChar:
		c = static_cast<char>(str[0]);
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << format_float(static_cast<float>(c)) << std::endl;
		std::cout << "double: " << format_double(static_cast<double>(c)) << std::endl;
		break;
	case TypeFloat:
		errno = 0;
		d = std::strtod(str.c_str(), &end);
		f = static_cast<float>(d);
		std::cout << "char: ";
		if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
			std::cout << "impossible";
		else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(f))))
			std::cout << "Non displayable";
		else
			std::cout << "'" << static_cast<char>(f) << "'";
		std::cout << std::endl;
		std::cout << "int: ";
		if (std::isnan(f) || std::isinf(f) ||
			f < std::numeric_limits<int>::min() ||
			f > std::numeric_limits<int>::max())
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(f);
		std::cout << std::endl;
		std::cout << "float: " << format_float(f) << std::endl;
		std::cout << "double: " << format_double(static_cast<double>(f)) << std::endl;
		break;
	case TypeInt:
		errno = 0;
		i = static_cast<int>(std::strtol(str.c_str(), &end, 10));

		std::cout << "char: ";
		if (i < 0 || i > 127)
			std::cout << "impossible";
		else if (!std::isprint(static_cast<unsigned char>(i)))
			std::cout << "Non displayable";
		else
			std::cout << "'" << static_cast<char>(i) << "'";
		std::cout << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << format_float(static_cast<float>(i)) << std::endl;
		std::cout << "double: " << format_double(static_cast<double>(i)) << std::endl;
		break;
	case TypeDouble:
		errno = 0;
		d = std::strtod(str.c_str(), &end);
		std::cout << "char: ";
		if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
			std::cout << "impossible";
		else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
			std::cout << "Non displayable";
		else
			std::cout << "'" << static_cast<char>(d) << "'";
		std::cout << std::endl;
		std::cout << "int: ";
		if (std::isnan(d) || std::isinf(d) ||
			d < std::numeric_limits<int>::min() ||
			d > std::numeric_limits<int>::max())
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(d);
		std::cout << std::endl;
		std::cout << "float: ";
		if (!std::isinf(d) && (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()))
			std::cout << "impossible";
		else
			std::cout << format_float(static_cast<float>(d));
		std::cout << std::endl;
		std::cout << "double: " << format_double(d) << std::endl;
		break;
	default:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		break;
	}
}
