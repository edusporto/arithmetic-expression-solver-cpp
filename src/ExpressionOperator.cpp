#include "ExpressionOperator.h"

ExpressionOperator::ExpressionOperator(char op) : ExpressionPart(Type::Operator)
{

    this->op = op;
}

char ExpressionOperator::getOperator()
{
    return this->op;
}

ExpressionOperator::~ExpressionOperator() {}