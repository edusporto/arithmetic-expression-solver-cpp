#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Expression.h"

void inline remove_whitespaces(std::string& str)
{
    std::string::iterator end_pos = std::remove(str.begin(),
                                                str.end(), ' ');
    str.erase(end_pos, str.end());
}


int main()
{
    std::string str; // contains the expression inputted by the user

    std::cout << "Input an arithmetic expression: " << std::endl;
    std::getline(std::cin, str);

    remove_whitespaces(str);

    // Next step is to tokenize the expression inputted by the user
    std::vector<std::string> tokens;
    /*stringTokenize(str, tokens, ExpressionTable::symbols);

    for (std::string& s : tokens) {
        std::cout << s << std::endl;
    }*/

    Expression exp(str);
    exp.solve();

    std::cin.ignore();

    return 0;
}
