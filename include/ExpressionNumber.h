#ifndef EXPRESSIONNUMBER_H
#define EXPRESSIONNUMBER_H

#include "ExpressionPart.h"

class ExpressionNumber : public ExpressionPart
{
protected:
    double number;

public:
    ExpressionNumber(double);
    virtual ~ExpressionNumber();

    double getNumber();
};

#endif
