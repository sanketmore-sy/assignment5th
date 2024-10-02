#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int stack[100];  
    int top;         
    int n;           

public:
    
    Stack(int size = 100) {
        n = size;
        top = -1;
    }

   
    void push(int val) {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else {
            top++;
            stack[top] = val;
        }
    }

    int pop() {
        if (top <= -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            int val = stack[top];
            top--;
            return val;
        }
    }

    
    bool isEmpty() {
        return top == -1;
    }

    
    int peek() {
        if (top >= 0)
            return stack[top];
        else
            return -1; 
    }
};

class PrefixEvaluator {
private:
    Stack stack; 

public:
    
    bool isOperand(char c) {
        return isdigit(c);  
    }

    
    int evaluatePrefix(string exp) {
        
        for (int i = exp.size() - 1; i >= 0; --i) {
            
            if (isOperand(exp[i])) {
                stack.push(exp[i] - '0'); 
            } else {  
                int o1 = stack.pop();
                int o2 = stack.pop();

                
                switch (exp[i]) {
                    case '+':
                        stack.push(o1 + o2);
                        break;
                    case '-':
                        stack.push(o1 - o2);
                        break;
                    case '*':
                        stack.push(o1 * o2);
                        break;
                    case '/':
                        stack.push(o1 / o2);
                        break;
                }
            }
        }
        return stack.peek();
    }
};


int main() {
    string exp = "-+*2345"; 

    PrefixEvaluator evaluator;
    cout << "Prefix evaluation: " << evaluator.evaluatePrefix(exp) << endl;

    return 0;
}
