Source Files for the Stock Analyzer

The API Entrance Point handles taking the ticker, pulling data from the url, parsing it into a string, and then pulling the indicators that are necessary such as EPSEstimate for the current year, the Ask Price, the PERatio, and the daily % Change in the price of the stock. Finally it parses those values into a float to be used.

The Stock class handles the logic associated with investing in the stock. There are some relatively arbitrary calculations the stock class does based on the earnings, the peratio and the percent change to decide whether it is a good stock to long term invest in. It does some different calculations based on a more aggresive percent change and a clear increase in price between the dailylow and the dailyhigh to calculate if it would be a good short term investment. If it is neither, then it simply says to sell.

AAPL ticker works best in demonstration.
