#include <stdio.h>
#include <iostream>
#include <cmath>
#include <map>
#include <iomanip>

double TaxesDue(double &income);
double HighestRate(double &income);

std::map<double, std::string> taxRate =
    {
        {0.35, "499999"},
        {0.31, "349999"},
        {0.25, "249999"},
        {0.21, "169999"},
        {0.18, "119999"},
        {0.14, "79999"},
        {0.10, "44999"},
        {0.05, "29999"}};

int main()
{
    double income;

    std::cout << "Enter your income: " << std::endl;
    std::cin >> income;

    double taxesDue = TaxesDue(income);
    std::cout << taxesDue << std::endl;
}

double TaxesDue(double &income)
{
    double totalTaxes = 0.0;
    double taxDiff = 0.0; //as taxes are calculates, subtract the income

    double highestRate = HighestRate(income);

    for (double i = income; i > 29999;) //knowing the lowest tax rate is 0.05
    {
        taxDiff = (income - std::stod(taxRate[highestRate]));
        totalTaxes += (highestRate * taxDiff);
        i -= taxDiff;
        highestRate = HighestRate(i);
    }

    return totalTaxes;
}

double HighestRate(double &income)
{
    /*
    std::map<double, std::string> taxRate =
    {
        {  0.35, "499999" },
        {0.31,"349999"},
        {0.25,"249999"},
        {0.21,"169999"},
        {0.18,"119999"},
        {0.14,"79999"},
        {0.10,"44999"},
        {0.05,"29999"}
    };
    */

    if (income > std::stod(taxRate[0.35]))
    {
        return 0.35;
    }
    if (income > std::stod(taxRate[0.31]))
    {
        return 0.31;
    }
    if (income > std::stod(taxRate[0.25]))
    {
        return 0.25;
    }
    if (income > std::stod(taxRate[0.21]))
    {
        return 0.21;
    }
    if (income > std::stod(taxRate[0.18]))
    {
        return 0.18;
    }
    if (income > std::stod(taxRate[0.14]))
    {
        return 0.14;
    }
    if (income > std::stod(taxRate[0.10]))
    {
        return 0.10;
    }
    if (income > std::stod(taxRate[0.05]))
    {
        return 0.05;
    }

    return 0.0;
}