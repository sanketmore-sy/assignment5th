#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        swap(exp[i], exp[n - i - 1]);
    }
}

void infixToPrefix(char* s) {
    
    reverse(s);

    char postfix[1000]; 
    int postIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stacktop = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

     
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[postIndex] = c;
            postIndex++;
        }
        
        else if (c == ')') {
            ++stacktop;
            stack[stacktop] = c;
        }
       
        else if (c == '(') {
            while (stacktop >= 0 && stack[stacktop] != ')') {
                postfix[postIndex] = stack[stacktop];
                postIndex++;
                stacktop--;
            }
            stacktop--; 
        }
        
        else {
            while (stacktop >= 0 && (prec(c) < prec(stack[stacktop]) || prec(c) == prec(stack[stacktop]))) {
                postfix[postIndex] = stack[stacktop];
                postIndex++;
                stacktop--;
            }
            stacktop++;
            stack[stacktop] = c;
        }
    }
    while (stacktop >= 0) {
        postfix[postIndex] = stack[stacktop];
        postIndex++;
        stacktop--;
    }

    postfix[postIndex] = '\0';

  
    reverse(postfix);
    cout <<"After the conversion prefix expression is:"<<postfix;
}
int main() {
    char exp[] = "(A+B)*(C-D)/(E+F)"; 
    cout<<"The infix expression: "<<exp<<endl;
    infixToPrefix(exp);

    return 0;
}
