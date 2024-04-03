#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <unordered_map>

class Model
{
public:
    Model();
    std::string reverseToRPN(const std::string& input);
    //double calculateRPN(const std::string& input);
private:
    std::unordered_map<char, int> priorities{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    std::string separateNum(const std::string &input, size_t index);
};

#endif // MODEL_H
