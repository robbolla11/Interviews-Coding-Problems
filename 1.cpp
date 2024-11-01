/*
Problem Statement  :
Ratan is a crazy rich person. And he is blessed with luck, so he always made the best profit possible with the shares he bought. That means he bought a share at a low price 
and sold it at a high price to maximize his profit. Now you are an income tax officer and you need to calculate the profit he made with the given values of stock prices each day.
 You have to calculate only the maximum profit Ratan earned.
Note that:
Ratan never goes into loss.

Example 1 :
Price=[1,6,2]
Ratan buys it on the first day and sells it on the second.
Example 2 :
Price=[9,8,6]

The Price always went down, Ratan never bought it.

Input Format:
First line with an integer n, denoting the number days with the value of the stack
Next n days, telling the price of the stock on that very day.

Output Format:
Maximum profit done by Ratan in a single line.
Constraints:
Number of days <=10^8

*/


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices)  // & para usar la direccion y aumentra la vel o algo asi
{
    int maxProfit = 0;
    int minPrice = INT_MAX; //val maximo

    for (int price : prices) 
    {
        if (price < minPrice) // al hacer el chequeo, se ve si hay un valor mayor al de los dias anteriores, asi evitando comprar para perdida
            minPrice = price;
        else
            maxProfit = max(maxProfit, price - minPrice); // obtiene la max profit, precio actual - menor precio
    }
    return maxProfit;

}

int main() 
{
    int n; //num dias
    cin >> n;

    vector<int> prices(n); //precio ´por dia
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int result = maxProfit(prices);
    cout << result << endl;

    return 0;
}