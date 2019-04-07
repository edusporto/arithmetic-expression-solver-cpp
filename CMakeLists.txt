cmake_minimum_required(VERSION 3.12)
project(ArithmeticExpression)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(ArithmeticExpression main.cpp src/ExpressionTable.cpp src/ExpressionPart.cpp src/ExpressionOperator.cpp src/ExpressionNumber.cpp src/Expression.cpp)