#include "ExpressionNumber.h"

ExpressionNumber::ExpressionNumber(double value) : ExpressionPart(Type::Number)
{
    this->number = value;
}

double ExpressionNumber::getNumber()
{
    return this->number;
}

ExpressionNumber::~ExpressionNumber() {}