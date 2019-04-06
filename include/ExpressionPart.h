#ifndef EXPRESSIONPART_H
#define EXPRESSIONPART_H

class ExpressionPart
{
public:
    enum class Type : unsigned char
    {
        Operator,
        Number
    };

    ExpressionPart(Type);
    virtual ~ExpressionPart();

    Type getType();

protected:
    Type type;
};

#endif
