#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void formatAmount(double amount, char* buffer)
{
    sprintf(buffer, "$%.2f", amount);
}

void calculateBalance(double balance, double rate, int months, ofstream& outputFile)
{
    for (int i = 0; i < months; i++)
    {
        balance = (1 + rate / 12) * balance;
        char buffer[20];
        formatAmount(balance, buffer);
        outputFile << (i + 1) << " " << buffer << endl;
    }
}

int main()
{
    double balance, rate;
    int months;
    ifstream inputFile("input.txt");
    inputFile >> balance >> rate >> months;

    char outputFileName[20];
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;
    ofstream outputFile(outputFileName);

    calculateBalance(balance, rate, months, outputFile);

    return 0;
}
