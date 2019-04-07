#include "Expression.h"

#include <memory>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "ExpressionTable.h"
#include "ExpressionPart.h"
#include "ExpressionNumber.h"
#include "ExpressionOperator.h"

void stringTokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector
        tokens.push_back(str.substr(lastPos, pos - lastPos));

        // Adding the delimiter(s) to the vector as well
        std::string::size_type posOfOperator = pos;
        while (posOfOperator != std::string::npos &&
               delimiters.find(str[posOfOperator]) != std::string::npos &&
               !isdigit(str[posOfOperator]))
        {
            tokens.push_back(str.substr(posOfOperator, 1));
            posOfOperator++;
        }

        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);

        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

void inline remove_whitespaces(std::string& str)
{
    std::string::iterator end_pos = std::remove(str.begin(),
                                                str.end(), ' ');
    str.erase(end_pos, str.end());
}

bool is_numeric (const std::string& str, double& value)
{
    auto result = double();
    auto i = std::istringstream(str);

    i >> result;
    i >> std::ws;

    value = result;

    return !i.fail() && i.eof();
}





Expression::Expression(const std::string& expression)
{
    this->expression = expression;

    if (this->expression.find(' ') != std::string::npos) {
        remove_whitespaces(this->expression);
    }
}

Expression::~Expression() {}

void postfix_notation(std::queue<std::shared_ptr<ExpressionPart>>& exp_queue,
                      const std::string& expression)
{
    std::stack<std::shared_ptr<ExpressionOperator>> operator_stack;
    std::vector<std::string> tokens;

    stringTokenize(expression, tokens, ExpressionTable::symbols);

    for (std::string& curr_token : tokens)
    {
        // If the current token is "("
        if (curr_token == "(")
        {
            operator_stack.push(std::make_shared<ExpressionOperator>('('));
            continue;
        }

        // If the current token is a number
        double number;
        if (is_numeric(curr_token, number))
        {
            exp_queue.push(std::make_shared<ExpressionNumber>(number));
            continue;
        }

        // If the current token is ")"
        if (curr_token == ")")
        {
            while (!operator_stack.empty())
            {
                auto topOfStack = std::move(operator_stack.top());

                if (topOfStack->getOperator() == '(')
                    break;

                exp_queue.push(std::move(topOfStack));
                operator_stack.pop();
            }

            operator_stack.pop();

            continue;
        }

        // The current token is an arithmetic operator
        while (!operator_stack.empty() &&
               ExpressionTable::shouldUnstack(operator_stack.top()->getOperator(),
                                              curr_token[0])) {
            exp_queue.push(std::move(operator_stack.top()));
            operator_stack.pop();
        }

        operator_stack.push(std::make_shared<ExpressionOperator>(curr_token[0]));
    }

    while (!operator_stack.empty()) {
        exp_queue.push(std::move(operator_stack.top()));
        operator_stack.pop();
    }

    while (!exp_queue.empty())
    {
        auto curr = exp_queue.front();

        if (curr->getType() == ExpressionPart::Type::Operator) {
            std::cout << ((ExpressionOperator*)curr.get())->getOperator() << std::endl;
        } else {
            std::cout << ((ExpressionNumber*)curr.get())->getNumber() << std::endl;
        }

        exp_queue.pop();
    }
}

double expression_calculator(std::queue<std::shared_ptr<ExpressionPart>>& exp_queue)
{
    double v1, v2;
    char op;

    std::stack<std::shared_ptr<ExpressionNumber>> number_stack;
}


double Expression::solve()
{
    std::queue<std::shared_ptr<ExpressionPart>> exp_queue;
    postfix_notation(exp_queue, this->expression);




    // TODO: Implement second step



    return 0;
}