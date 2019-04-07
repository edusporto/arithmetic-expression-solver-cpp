#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

class Expression
{
protected:
    std::string expression;

public:
    Expression(std::string);

    virtual ~Expression();

    double solve();

    std::string getExpression() { return this->expression; };
};

#endif
