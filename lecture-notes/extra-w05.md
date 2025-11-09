MIT License
Copyright (c) 2025 Emir Baha Yıldırım
Please see the LICENSE file for more details.

-------------------------------------------------------------------------------

# Prefix/Infix/Postfix

## What are they?

In programming languages, operators can be classified based on their position
relative to their operands. The three main types are prefix, infix, and postfix
notations. The position of the operator affects how expressions are evaluated.

## Infix Notation - The Human-Friendly Choice

In infix notation, operators are placed between their operands. This is the
most common notation used in everyday arithmetic and many programming
languages. For example, the addition operator `+` is an infix operator:

```cpp
int result = 3 + 4; // Infix notation
```

In this example, the `+` operator is between the two operands `3` and `4`.
Thus, making it an infix operator; however, infix operators can sometimes lead
to ambiguity in expressions, which is usually resolved using parantheses.

```cpp
int result = 3 + 4 * 5;      // Ambiguous without operator precedence rules
int result = (3 + 4) * 5;    // Clearer with parentheses, but harder for the
                             // computer to parse
```

## Prefix (Polish) Notation - Before the Operand

Prefix operators are placed before their operands. They are often used for
unary operations, such as negation or incrementing a value. For example, the
unary plus operator `+` is a prefix operator:

```cpp
// suppose this as pseudocode
int a = 5;
int b = 6;
int c;
c = + a b; // Prefix notation
```

What if we wanted to use a third variable?
```cpp
int a = 5;
int b = 6;
int c = 7;
int d;
d = + + a b c; // Prefix notation with three operands
               // Easier for the computer to parse, harder for humans to read
```

How the evaluation works:
1. Read the expression from right to left.
2. When an operand is encountered, push it onto the stack.
3. When an operator is encountered, pop the required number of operands from
the stack, apply the operator, and push the result back onto the stack.

So, in the above example the computer would:
- Push `c` (7) onto the stack.
- Push `b` (6) onto the stack.
- Push `a` (5) onto the stack.
- Encounter the first `+` operator, pop `5` and `6`, add them to get `11`, and
push `11` back onto the stack.
- Encounter the second `+` operator, pop `11` and `7`, add them to get `18`,
and push `18` back onto the stack.
- The final result `18` remains on the stack, and evaluation is complete.

## Postfix (Reverse Polish) Notation - After the Operand

Postfix operators are placed after their operands.

```cpp
int a = 5;
int b = 6;
int c;
c = a b + ; // Postfix notation
```

If we wanted to use a third variable:
```cpp
int a = 5;
int b = 6;
int c = 7;
int d;
d = a b + c + ; // Postfix notation with three operands
                // Easier for the computer to parse, harder for humans to read
```

How the evaluation works:
1. Read the expression from left to right.
2. When an operand is encountered, push it onto the stack.
3. When an operator is encountered, pop the required number of operands from
the stack, apply the operator, and push the result back onto the stack.

So, in the above example the computer would:
- Push `a` (5) onto the stack.
- Push `b` (6) onto the stack.
- Encounter the `+` operator, pop `5` and `6`, add them to get `11`, and push
`11` back onto the stack.
- Push `c` (7) onto the stack.
- Encounter the `+` operator again, pop `11` and `7`, add them to get `18`, and
push `18` back onto the stack.
- The final result `18` remains on the stack, and evaluation is complete.

## So, what is the problem?

Humans find `infix` notation natural and intuitive because it aligns with
traditional arithmetic taught in schools, but computers process `prefix` and
`postfix` notations more efficiently as they avoid the need for complex rules,
such as stack-based evaluations, or user interaction. So, we need to convert
the human-readable `infix` notation to machine-readable `prefix/postfix`
notation, but how do we do that?

## Real-World Use Cases

1. **Programming Languages (Infix):** Most programming languages use infix
notation for arithmetic operations due to its readability.
```cpp
int result = (3 + 4) * 5;
std::cout << result << std::endl; // Output: 35
```

2. **Compilers and Parsers (Prefix):** Compilers often convert infix
expressions to prefix, or postfix, for easier evaluation. For example:
- **Infix:** `(a + b) * c
- **Prefix:** `* + a b c

How does the evaluation work for prefix in that example?
So, in the above example the computer would:
- Push `c` onto the stack.
- Push `b` onto the stack.
- Push `a` onto the stack.
- Encounter the `+` operator, pop `a` and `b`, add them, and push the result
back onto the stack.
- Encounter the `*` operator, pop the result of `a + b` and `c`, multiply them,
and push the final result back onto the stack.

3. **Calculators and Stack-Based Systems (Postfix):** Postfix is widely used in
calculators and stack-based systems because of its simplicity in evaluation.
```cpp
// Basic arithmetic calculator function in pseudocode
int evaluatePostfix(const std::vector<std::string>& tokens) {
    std::stack<int> stack;
    for (const auto& token : tokens) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") stack.push(a / b);
        }
    }
    return stack.top();
}
```

## [Example Infix to Postfix Conversion Using Stack in C++](https://en.cppreference.com/w/cpp/string/byte/isalnum.html)

This is from a [GeeksforGeeks](https://www.geeksforgeeks.org)
[article](https://en.cppreference.com/w/cpp/string/byte/isalnum.html).

```cpp
// C++ Program to illustrate how to use a stack to convert
// an infix expression to a postfix expression
#include <iostream>
#include <stack>
#include <string>

// Function to check the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
// expression
std::string infixToPostfix(std::string infix)
{
    std::stack<char> st;
    std::string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the scanned character is an operand, add it to
        // output string.
        if (std::isalnum(c))
            postfix += c;

        // If the scanned character is an '(', push it to
        // the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ')', pop and to
        // output string from the stack until an '(' is
        // encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else {
            while (!st.empty()
                   && precedence(c)
                          <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    std::string infix = "A+B*C";
    std::cout << "Infix Expression: " << infix << std::endl;
    std::cout << "Postfix Expression: " << infixToPostfix(infix)
         << std::endl;
    return 0;
}
```
