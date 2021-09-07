/* Given an expression string, write a program to check parenthesis
 * are valid or not.
 * Example : ((a+b)*x-d) - True
 * ((a+b]+c) * (d-e) - False
 */


#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool checkParenthesis(string str)
{
    stack<char> s;
    for(int i=0; i<str.length(); i++)
    {
        switch(str[i])
        {
            case '(':
            case '[':
            case '{':
                s.push(str[i]);
                break;
            case ')':
                if(!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if(!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if(!s.empty() && s.top() == '{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                break;
        }
    }
    if(s.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "((a+b]+c) * (d-e)";
    bool res = checkParenthesis(s);
    if(res)
    {
        cout<<"Parenethesis is balanced!"<<endl;
    }
    else
    {
        cout<<"Not balanced!"<<endl;
    }
    return 0;
}