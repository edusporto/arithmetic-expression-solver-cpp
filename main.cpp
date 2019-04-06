#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "ExpressionTable.h"

void inline remove_whitespaces(std::string& str)
{
    std::string::iterator end_pos = std::remove(str.begin(),
                                                str.end(), ' ');
    str.erase(end_pos, str.end());
}

void stringTokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector
        tokens.push_back(str.substr(lastPos, pos - lastPos));

        // Adding the delimiter(s) to the vector as well
        std::string::size_type posOfOperator = pos;
        while (posOfOperator != std::string::npos &&
               delimiters.find(str[posOfOperator]) != std::string::npos &&
               !isdigit(str[posOfOperator]))
        {
            tokens.push_back(str.substr(posOfOperator, 1));
            posOfOperator++;
        }

        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);

        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}


int main()
{
    std::string str; // contains the expression inputted by the user

    std::cout << "Input an arithmetic expression: " << std::endl;
    std::getline(std::cin, str);

    remove_whitespaces(str);

    // Next step is to tokenize the expression inputted by the user
    std::vector<std::string> tokens;
    stringTokenize(str, tokens, ExpressionTable::symbols);

    for (std::string& s : tokens) {
        std::cout << s << std::endl;
    }

    // TODO: Create Expression class, do the calculations

    std::cin.ignore();

    return 0;
}
