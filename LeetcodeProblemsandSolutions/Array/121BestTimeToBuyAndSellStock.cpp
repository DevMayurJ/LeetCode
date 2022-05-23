#include <iostream>
#include <vector>

using namespace std;

//Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//Note that you cannot sell a stock before you buy one.

class Solution
{
public:
	int maxProfit(vector<int>& vctPrices)
	{
		int iProfit, iMaxProfit = 0;
		int iTransacFlag = 0;
		int iVctSize = vctPrices.size();

		for (int i = 0; i < iVctSize; i++)
		{
			for (int j = i + 1; j < iVctSize; j++)
			{

				//Only calculate profit if buy price is less sell price and the profit is greater than current maximum profit (iMaxProfit)
				if (vctPrices[i] < vctPrices[j] && (iMaxProfit < (iProfit = vctPrices[j] - vctPrices[i])))
				{
					iMaxProfit = iProfit;
					//cout<<iMax<<"\t";						
					iTransacFlag = 1;
				}
			}
		}

		if (iTransacFlag)
		{
			return iMaxProfit;
		}
		else
		{
			return 0;
		}
	}

	int maxProfitOnePass(vector<int>& vctPrices)
	{
		int iMaxProfit = 0;
		int iMinBuyPrice = INT_MAX;
		int iVctSize = vctPrices.size();

		for (int i = 0; i < iVctSize; i++)
		{
			if (iMinBuyPrice > vctPrices[i])
			{
				iMinBuyPrice = vctPrices[i];
			}
			else if(iMaxProfit < vctPrices[i] - iMinBuyPrice)
			{
				iMaxProfit = vctPrices[i] - iMinBuyPrice;
			}
		}

		return iMaxProfit;
	}
};

int main()
{
	vector <int> vctStockPrices{ 7,1,4,6,1,8 };
	int profit;
	Solution objSolution;

	profit = objSolution.maxProfit(vctStockPrices);
	cout << "\nOutput: " << profit << "$\n";
	profit = objSolution.maxProfitOnePass(vctStockPrices);
	cout << "\nOutput: " << profit << "$\n";
	return 0;
}
