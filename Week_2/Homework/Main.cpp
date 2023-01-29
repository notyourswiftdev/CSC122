// AARON CLEVELAND
// CSC122
// 
// Due: 01/30/2023


#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

double validateCurrency(const char* str)
{
    int len = strlen(str);
    bool negative = false, decimal = false, comma = false;
    int dollars = 0, cents = 0, fraction = 1;

    // Check if the first character is '-'
    if (str[0] == '-')
    {
        negative = true;
    }

    // Check for dollar sign and process digits
    int i = negative ? 1 : 0;
    if (str[i] == '$')
    {
        i++;
        for (; i < len; i++)
        {
            if (isdigit(str[i]))
            {
                dollars = dollars * 10 + str[i] - '0';
                continue;
            }
            else if (str[i] == '.')
            {
                decimal = true;
                i++;
                break;
            }
            else if (str[i] == ',')
            {
                comma = true;
                continue;
            }
            else
            {
                break;
            }
        }
    }

    // Check for cent sign and process digits
    if (str[len - 1] == '¢')
    {
        for (; i < len - 1; i++)
        {
            if (isdigit(str[i]))
            {
                cents = cents * 10 + str[i] - '0';
                fraction *= 10;
                continue;
            }
            else
            {
                break;
            }
        }
    }

    // Check for correct format of comma-separated dollars
    if (comma)
    {
        int count = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (str[j] == ',')
            {
                count = 0;
            }
            else
            {
                count++;
            }
            if (count == 3)
            {
                break;
            }
        }
        if (count != 3)
        {
            return 0.0;
        }
    }

    // Check for correct format of decimal dollars
    if (decimal)
    {
        int count = 0;
        for (; i < len; i++)
        {
            if (isdigit(str[i]))
            {
                cents = cents * 10 + str[i] - '0';
                fraction *= 10;
                count++;
            }
            else
            {
                break;
            }
        }
        if (count != 2)
        {
            return 0.0;
        }
    }

    // Check for extra characters
    if (i < len)
    {
        return 0.0;
    }

    double result = (dollars + (double)cents / fraction) * (negative ? -1.0 : 1.0);
    return result;
}

int main()
{
    char input[20];

    while (true)
    {
        cout << "Enter a currency amount: ";
        cin.getline(input, 20);

        double result = validateCurrency(input);

        if (result == 0.0)
        {
            cout << "Invalid currency format" << endl;
        }
        else
        {
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Valid currency: " << result << endl;
        }

        cout << "Enter another currency amount? (yes / no): ";
        string response;
        getline(cin, response);
        if (response != "yes")
        {
            break;
        }
    }
    return 0;
}