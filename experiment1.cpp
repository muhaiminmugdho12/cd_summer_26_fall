
#include<iostream>
using namespace std;

bool checkNumber(string input) {
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i]))
            return false;
    }
    return true;
}

void checkOperator(string input) {
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' ||
           input[i] == '/' || input[i] == '%' || input[i] == '=')
            cout << "Operator: " << input[i] << " ";
        else
            cout << "Invalid Operator ";
    }
    cout << endl;
}

void checkComment(string input) {
    if(input[0] == '/' && input[1] == '/')
        cout << "Single Line Comment" << endl;
    else if(input[0] == '/' && input[1] == '*')
        cout << "Multi Line Comment" << endl;
    else
        cout << "Not a Comment" << endl;
}

bool validIdentifier(string input) {
    if(!(isalpha(input[0]) || input[0] == '_'))
        return false;

    for(int i = 1; i < input.length(); i++) {
        if(!(isalnum(input[i]) || input[i] == '_'))
            return false;
    }
    return true;
}

void calculateAverage() {
    int size, total = 0;
    cin >> size;

    int numbers[size];

    for(int i = 0; i < size; i++) {
        cin >> numbers[i];
        total += numbers[i];
    }

    cout << "Average = " << (float)total / size << endl;
}

void findMinMax() {
    int size;
    cin >> size;

    int numbers[size];

    for(int i = 0; i < size; i++)
        cin >> numbers[i];

    int minimum = numbers[0];
    int maximum = numbers[0];

    for(int i = 1; i < size; i++) {
        if(numbers[i] < minimum)
            minimum = numbers[i];

        if(numbers[i] > maximum)
            maximum = numbers[i];
    }

    cout << "Smallest Value = " << minimum << endl;
    cout << "Largest Value = " << maximum << endl;
}

string makeFullName(string fName, string lName) {
    return fName + " " + lName;
}

int main() {
    int option;
    string input, fName, lName;

    cout << "===== MENU =====" << endl;
    cout << "1. Check Numeric Value" << endl;
    cout << "2. Check Operator" << endl;
    cout << "3. Check Comment" << endl;
    cout << "4. Check Identifier" << endl;
    cout << "5. Calculate Average" << endl;
    cout << "6. Find Min and Max" << endl;
    cout << "7. Create Full Name" << endl;

    cout << "\nEnter Your Choice: ";
    cin >> option;
    cin.ignore();

    if(option == 1) {
        cin >> input;

        if(checkNumber(input))
            cout << "Valid Number";
        else
            cout << "Invalid Number";
    }
    else if(option == 2) {
        cin >> input;
        checkOperator(input);
    }
    else if(option == 3) {
        getline(cin, input);
        checkComment(input);
    }
    else if(option == 4) {
        cin >> input;

        if(validIdentifier(input))
            cout << "Identifier is Valid";
        else
            cout << "Identifier is Invalid";
    }
    else if(option == 5) {
        calculateAverage();
    }
    else if(option == 6) {
        findMinMax();
    }
    else if(option == 7) {
        cin >> fName >> lName;
        cout << "Full Name: " << makeFullName(fName, lName);
    }
    else {
        cout << "Wrong Choice";
    }

    return 0;
}
