#include<iostream>
#include<stack>
#include<string>

using namespace std ;

bool checkBrackets(string brackets)
{
    stack<char> S ;

    char B ;

    for( int i = 0 ; i < brackets.length() ; i++ )
    {
        if(brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')  
        {
            S.push(brackets[i]) ;
            continue ;
        }

        switch (brackets[i])
        {
            case ')':
                B = S.top();
                S.pop();
                if(B == '{' || B == '[')
                    return false ;
                break;
            case '}':
                B = S.top();
                S.pop();
                if(B == '(' || B == '[')
                    return false ;
                break;
            case ']':
                B = S.top();
                S.pop();
                if(B == '{' || B == '(')
                    return false ;
                break;
       }
    } 
    return S.empty();
}

int main()
{
    string input ;
    cout << "ENTER THE STRING" << endl ;
    cin  >> input ;
    cout << checkBrackets(input);
    return 0 ;
}