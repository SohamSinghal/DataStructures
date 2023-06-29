def profit_loss(arr):
    if arr == sorted(arr) or len(arr) == 1:
        return 0
    min_price = arr[0]
    max_profit = 0
    for price in arr[1:]:
        if price < min_price:
            min_price = price
        elif price - min_price > max_profit:
            max_profit = price - min_price
    return max_profit
prices = [7, 1, 5, 3, 6, 4]
print(profit_loss(prices))
prices = [7, 6, 4, 3, 1]
print(profit_loss(prices))