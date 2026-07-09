#include <iostream>
using namespace std;

void token(string input)
{
    string temp = "";
    int i = 0;

    while (i < input.length())
    {
        if (input[i] == ' ')
        {
            if (temp != "")
            {
                if (temp == "cout")
                    cout << temp << " -> Keyword" << endl;
                else if (temp[0] >= '0' && temp[0] <= '9')
                    cout << temp << " -> Constant" << endl;
                else
                    cout << temp << " -> Identifier" << endl;

                temp = "";
            }
        }

        else if (input[i] == '<' && input[i + 1] == '<')
        {
            if (temp != "")
            {
                if (temp == "cout")
                    cout << temp << " -> Keyword" << endl;
                else if (temp[0] >= '0' && temp[0] <= '9')
                    cout << temp << " -> Constant" << endl;
                else
                    cout << temp << " -> Identifier" << endl;

                temp = "";
            }

            cout << "<< -> Operator" << endl;
            i++;
        }

        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
                 input[i] == '/' || input[i] == '%' || input[i] == '=')
        {
            if (temp != "")
            {
                if (temp == "cout")
                    cout << temp << " -> Keyword" << endl;
                else if (temp[0] >= '0' && temp[0] <= '9')
                    cout << temp << " -> Constant" << endl;
                else
                    cout << temp << " -> Identifier" << endl;

                temp = "";
            }

            cout << input[i] << " -> Operator" << endl;
        }

        else if (input[i] == ';' || input[i] == ',' ||
                 input[i] == '(' || input[i] == ')')
        {
            if (temp != "")
            {
                if (temp == "cout")
                    cout << temp << " -> Keyword" << endl;
                else if (temp[0] >= '0' && temp[0] <= '9')
                    cout << temp << " -> Constant" << endl;
                else
                    cout << temp << " -> Identifier" << endl;

                temp = "";
            }

            cout << input[i] << " -> Punctuation" << endl;
        }

        else
        {
            temp += input[i];
        }

        i++;
    }

    if (temp != "")
    {
        if (temp == "cout")
            cout << temp << " -> Keyword" << endl;
        else if (temp[0] >= '0' && temp[0] <= '9')
            cout << temp << " -> Constant" << endl;
        else
            cout << temp << " -> Identifier" << endl;
    }
}

int main()
{
    string input = "cout<< a+b % 60 * 2.75;";

    token(input);

    return 0;
}
