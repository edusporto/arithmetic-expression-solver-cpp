#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

class Expression
{
protected:
    std::string expression;

public:
    explicit Expression(std::string);

    virtual ~Expression();

    double solve();

    double static calculateValues(double, double, char);

    std::string getExpression() { return this->expression; };
};

#endif
