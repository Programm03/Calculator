#include <iostream>
#include "model.h"
#include <stack>

Model::Model()
{

}

std::string Model::reverseToRPN(const std::string &input)
{
    std::string result = "";
    std::stack<char> operations;

    std::cout << "/ is digit? REAL?! (" << std::isdigit('/') << ')' << std::endl;

    for (size_t i = 0; i < input.size(); ++i) {
        std::cout << "i is: " << i << " | Element: " << input[i] << std::endl;
        if (std::isdigit(input[i]) || input[i] == '.') {
            std::string separate = separateNum(input, i);
            std::cout << "Index: " << i << " | Element: " << input[i] << " | Result separate: " << separate << std::endl;
            result.append(separate);
            //result.push_back(input[i]);
        } else if (input[i] == '(') {
            operations.push(input[i]);
        } else if (input[i] == ')') {
            while (operations.top() != '(') {
                result.push_back(operations.top());
                result.push_back(' ');
                operations.pop();
            }
            operations.pop();
        } else {
            while (!operations.empty() && priorities[operations.top()] >= priorities[input[i]]) {
                result.push_back(operations.top());
                result.push_back(' ');
                operations.pop();
            }
            operations.push(input[i]);
        }
    }

    while(!operations.empty()) {
        result.push_back(operations.top());
        operations.pop();
    }

    return result;
}

double Model::calculateRPN(const std::string &input)
{
    std::stack<double> operands;

    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == ' ') {
            continue;
        }
        if (std::isdigit(input[i])) {
            std::string num = separateNum(input, i);
            num.pop_back();
            operands.push(std::stod(num));
            ++i;
        } else {
            double s = operands.top();
            operands.pop();
            double f = operands.top();
            operands.pop();

            std::cout << "Input[i]: " << input[i] << std::endl;

            switch (input[i]) {
                case '+':
                    operands.push(f + s);
                    break;
                case '-':
                    operands.push(f - s);
                    break;
                case '*':
                    operands.push(f * s);
                    break;
                case '/':
                    operands.push(f / s);
                    break;
            }
        }
    }

    return operands.top();
}

std::string Model::separateNum(const std::string &input, size_t &index)
{
    std::string result = "";

    while(std::isdigit(input[index]) && index < input.size()) {
        result.push_back(input[index]);
        ++index;
    }

    --index;

    result.push_back(' ');

    return result;

}





// 120+30
// 120
