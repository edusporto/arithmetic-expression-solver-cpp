#include "ExpressionTable.h"

const char* ExpressionTable::symbols = "(^*/+-)";

const bool ExpressionTable::table[7][7] =
        {{false,false,false,false,false,false,true },
         {false,true ,true ,true ,true ,true ,true },
         {false,false,true ,true ,true ,true ,true },
         {false,false,true ,true ,true ,true ,true },
         {false,false,false,false,true ,true ,true },
         {false,false,false,false,true ,true ,true },
         {false,false,false,false,false,false,false}};


bool ExpressionTable::shouldUnstack(char topOfStack, char currStrToken)
{
    unsigned int topOfStackPos = -1, currStrTokenPos = -1;
    for (unsigned int i=0; i<7; i++) {
        if (ExpressionTable::symbols[i] == topOfStack)
            topOfStackPos = i;
        if (ExpressionTable::symbols[i] == currStrToken)
            currStrTokenPos = i;
    }

    if (topOfStackPos == -1 || currStrTokenPos == -1)
        return false;

    return ExpressionTable::table[topOfStackPos][currStrTokenPos];
}
