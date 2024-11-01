/*
Problem Description

Question – : There are two banks – Bank A and Bank B. Their interest rates vary. You have received offers from both banks in terms of the annual rate of interest, 
tenure, and variations of the rate of interest over the entire tenure.You have to choose the offer which costs you least interest and reject the other.
 Do the computation and make a wise choice.

The loan repayment happens at a monthly frequency and Equated Monthly Installment (EMI) is calculated using the formula given below :

EMI = loanAmount * monthlyInterestRate / 
( 1 – 1 / (1 + monthlyInterestRate)^(numberOfYears * 12))

Constraints:
    1 <= P <= 1000000
    1 <=T <= 50
    1<= N1 <= 30
    1<= N2 <= 30

Input Format:
    First line: P principal (Loan Amount)
    Second line: T Total Tenure (in years).
    Third Line: N1 is the number of slabs of interest rates for a given period by Bank A. First slab starts from the first year and the second slab starts from the end of the first slab and so on.
    Next N1 line will contain the interest rate and their period.
    After N1 lines we will receive N2 viz. the number of slabs offered by the second bank.
    Next N2 lines are the number of slabs of interest rates for a given period by Bank B. The first slab starts from the first year and the second slab starts from the end of the first slab and so on.
    The period and rate will be delimited by single white space.

Output Format: Your decision either Bank A or Bank B.

Explanation:

    Example 1
        Input
        10000
        20
        3
        5 9.5
        10 9.6
        5 8.5
        3
        10 6.9
        5 8.5
        5 7.9

    Output: Bank B

    Example 2
        Input
        500000
        26
        3
        13  9.5
        3  6.9
        10  5.6
        3
        14  8.5
        6  7.4
        6  9.6
    Output: Bank A

 */

#include <bits/stdc++.h>
using namespace std;

double calculateEMI(double loanAmount, double annualRate, int years) 
{
    double monthlyInterestRate = (annualRate / 100) / 12;
    int numberOfMonths = years * 12;
    return loanAmount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -numberOfMonths));
    //como la formula es 1/blabla hacemos el exponente negativo
}

double calculateTotalInterest(int principal, vector<pair<int, double>> slabs) 
{
    double totalPayment = 0;
    for (auto &slab : slabs) {
        int years = slab.first;
        double rate = slab.second;
        double EMI = calculateEMI(principal, rate, years);
        totalPayment += EMI * (years * 12);  // Total payment for this slab
    }
    return totalPayment - principal;  // Interest is total payment minus principal
}

int main()
{
    int P; //loan amount
    int T;  //Total tenure (realmente no sivre no es como que hay un chequeo de que si sume esto los años)
    int N1, N2; //n slabs por banco
    cin >> P;
    cin >> T;

    //Banco 1
    cin >> N1;
    vector<pair<int, double>> slabsA(N1);

    for (int i = 0; i < N1; ++i) 
    {
        int period;
        double rate;
        cin >> period >> rate;
        slabsA[i] = {period, rate};
    }

    //Banco 2
    cin >> N2;
    vector<pair<int, double>> slabsB(N2);
    for (int i = 0; i < N2; ++i) 
    {
        int period;
        double rate;
        cin >> period >> rate;
        slabsB[i] = {period, rate};
    }

    double interestA = calculateTotalInterest(P, slabsA);
    double interestB = calculateTotalInterest(P, slabsB);

    //el de menos
    if (interestA < interestB)
        cout << "Bank A" << endl;
    else
        cout << "Bank B" << endl;

    return 0;
}



