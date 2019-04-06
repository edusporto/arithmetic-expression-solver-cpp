#ifndef EXPRESSIONOPERATOR_H
#define EXPRESSIONOPERATOR_H

#include "ExpressionPart.h"

class ExpressionOperator : public ExpressionPart
{
protected:
    char op;

public:
    ExpressionOperator(char);
    virtual ~ExpressionOperator();

    char getOperator();
};

#endif
