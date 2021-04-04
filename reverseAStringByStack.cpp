#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string input ;
    std::stack<char> myString ;
    
    cout << "Enter the string";
    cin >> input ;
    
    for(int i = 0 ; i < input.length() ; i++)
    {
        myString.push(input[i]);
    }
    
    int i = 0 ; 
    while(!myString.empty())
    {
        input[i] = myString.top();
        myString.pop();
        i++ ;
    }
    cout << input << endl ;
    return 0;
}