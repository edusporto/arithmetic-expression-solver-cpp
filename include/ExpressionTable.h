#ifndef EXPRESSIONTABLE_H
#define EXPRESSIONTABLE_H

class ExpressionTable
{
public:
    const static char* symbols;
    const static bool  table[7][7];

    static bool shouldUnstack(char, char);
};

#endif
