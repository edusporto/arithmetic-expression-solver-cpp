#include "ExpressionPart.h"

ExpressionPart::ExpressionPart(ExpressionPart::Type type)
{
    this->type = type;
}

ExpressionPart::Type ExpressionPart::getType()
{
    return this->type;
}

ExpressionPart::~ExpressionPart() {}