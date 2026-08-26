#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static bool isSpecial(const std::string &text)
{
    return (text == "nan" || text == "+inf" || text == "-inf"
        || text == "nanf" || text == "+inff" || text == "-inff");
}

static bool isInteger(const std::string &text)
{
    std::size_t pos = 0;

    if (text.empty())
        return false;

    if (text[0] == '+' || text[0] == '-')
        pos++;

    if (pos == text.length())
        return false;

    while (pos < text.length())
    {
        if (text[pos] < '0' || text[pos] > '9')
            return false;
        pos++;
    }

    return true;
}

static bool isFloatLiteral(const std::string &text)
{
    if (text.empty() || text[text.length() - 1] != 'f')
        return false;

    std::string number = text.substr(0, text.length() - 1);

    if (isSpecial(text))
        return true;

    std::size_t pos = 0;
    bool dotFound = false;
    bool digitFound = false;

    if (number[0] == '+' || number[0] == '-')
        pos++;

    if (pos == number.length())
        return false;

    while (pos < number.length())
    {
        if (number[pos] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (number[pos] >= '0' && number[pos] <= '9')
        {
            digitFound = true;
        }
        else
        {
            return false;
        }
        pos++;
    }

    return dotFound && digitFound;
}

static bool isDoubleLiteral(const std::string &text)
{
    if (text.empty() || isSpecial(text))
        return false;

    std::size_t pos = 0;
    bool dotFound = false;
    bool digitFound = false;

    if (text[0] == '+' || text[0] == '-')
        pos++;

    if (pos == text.length())
        return false;

    while (pos < text.length())
    {
        if (text[pos] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (text[pos] >= '0' && text[pos] <= '9')
        {
            digitFound = true;
        }
        else
        {
            return false;
        }
        pos++;
    }

    return dotFound && digitFound;
}

static void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value)
        || value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char character = static_cast<char>(value);

    if (std::isprint(static_cast<unsigned char>(character)))
        std::cout << "char: '" << character << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double value)
{
    if (std::isnan(value) || std::isinf(value)
        || value < INT_MIN || value > INT_MAX)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    if (std::isnan(value))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }

    if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: +inff" << std::endl;
        return;
    }

    if (value > FLT_MAX || value < -FLT_MAX)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    float result = static_cast<float>(value);

    std::cout << "float: " << result;

    if (result == static_cast<int>(result))
        std::cout << ".0f";
    else
        std::cout << "f";

    std::cout << std::endl;
}

static void printDouble(double value)
{
    if (std::isnan(value))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: +inf" << std::endl;
        return;
    }

    std::cout << "double: " << value;

    if (value == static_cast<long long>(value))
        std::cout << ".0";

    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    double numericValue;

    if (literal.length() == 1
        && !(literal[0] >= '0' && literal[0] <= '9'))
    {
        numericValue = static_cast<double>(literal[0]);
    }
    else if (isInteger(literal))
    {
        char *end = NULL;
        errno = 0;
        long parsed = std::strtol(literal.c_str(), &end, 10);

        if (errno != 0 || *end != '\0'
            || parsed < INT_MIN || parsed > INT_MAX)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        numericValue = static_cast<double>(parsed);
    }
    else if (isFloatLiteral(literal))
    {
        if (literal == "nanf")
            numericValue = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inff")
            numericValue = std::numeric_limits<double>::infinity();
        else if (literal == "-inff")
            numericValue = -std::numeric_limits<double>::infinity();
        else
            numericValue = std::strtod(literal.c_str(), NULL);
    }
    else if (isDoubleLiteral(literal))
    {
        if (literal == "nan")
            numericValue = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            numericValue = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            numericValue = -std::numeric_limits<double>::infinity();
        else
            numericValue = std::strtod(literal.c_str(), NULL);
    }
    else if (literal == "nan")
    {
        numericValue = std::numeric_limits<double>::quiet_NaN();
    }
    else if (literal == "+inf")
    {
        numericValue = std::numeric_limits<double>::infinity();
    }
    else if (literal == "-inf")
    {
        numericValue = -std::numeric_limits<double>::infinity();
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(numericValue);
    printInt(numericValue);
    printFloat(numericValue);
    printDouble(numericValue);
}