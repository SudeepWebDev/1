
#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int top;
    int arr[MAX_SIZE];

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cerr << "Stack overflow. Cannot push.\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop.\n";
            return -1; // Assuming -1 as an error value
        }
        return arr[top--];
    }

    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty. No top element.\n";
            return -1; // Assuming -1 as an error value
        }
        return arr[top];
    }
};

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return static_cast<int>(std::pow(operand1, operand2));
        default:
            std::cerr << "Invalid operator.\n";
            return 0; // Assuming 0 as a default value
    }
}

int evaluatePostfix(const std::string& postfix) {
    Stack stack;
    for (char ch : postfix) {
        if (std::isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            stack.push(performOperation(ch, operand1, operand2));
        }
    }
    return stack.pop();
}

int evaluatePrefix(const std::string& prefix) {
    Stack stack;
    for (int i = prefix.size() - 1; i >= 0; --i) {
        char ch = prefix[i];
        if (std::isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) {
            int operand1 = stack.pop();
            int operand2 = stack.pop();
            stack.push(performOperation(ch, operand1, operand2));
        }
    }
    return stack.pop();
}

int main() {
    std::string postfixExpression = "23*5+";
    std::string prefixExpression = "+*235";

    std::cout << "Postfix Expression: " << postfixExpression << "\n";
    std::cout << "Result of Postfix Evaluation: " << evaluatePostfix(postfixExpression) << "\n";

    std::cout << "\nPrefix Expression: " << prefixExpression << "\n";
    std::cout << "Result of Prefix Evaluation: " << evaluatePrefix(prefixExpression) << "\n";

    return 0;
}
