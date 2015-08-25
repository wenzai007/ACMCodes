# Description: Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete at most k transactions. Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

# 题意：用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。最多交易k次，手上最多只能持有一支股票，求最大收益。

分析：特殊动态规划法。传统的动态规划我们会这样想，到第i天时进行j次交易的最大收益，要么等于到第i-1天时进行j次交易的最大收益（第i天价格低于第i-1天的价格），要么等于到第i-1天时进行j-1次交易，然后第i天进行一次交易（第i天价格高于第i-1天价格时）。于是得到动规方程如下（其中diff = prices[i] – prices[i – 1]）：
		
		profit[i][j] = max(profit[i – 1][j], profit[i – 1][j – 1] + diff)
<font color="82932"  size=22>注意了啊  是 第i天卖出！！！！！   并且 profit[i][j]是正好第i天卖出最后一笔，profit[i-1][j-1]是正好第i-1天卖出最后一笔  </font>

局部最有和全局最优的定义：
<font color="F80000">local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。</font>








