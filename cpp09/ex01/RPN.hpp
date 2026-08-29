#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _numbers;

		bool isNumber(char c) const;
		bool isOperator(char c) const;
		void calculate(char operation);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int evaluate(const std::string& expression);
};

#endif