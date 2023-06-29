#Task 3: Sum of All Subset XOR Totals
def backtracking(arr,cur_sub,start,sub):
    sub.append(cur_sub[:])
    for i in range(start,len(arr)):
        cur_sub.append(arr[i])
        backtracking(arr,cur_sub,i+1,sub)
        cur_sub.pop()
def subsets(arr):
    subset = []
    backtracking(arr,[],0,subset)
    return subset
def xor_sum(arr):
    array = subsets(arr)
    result = 0
    for i in array:
        res = 0
        for j in i:
            res ^= j
        result += res
    return result
print(xor_sum([5,1,6]))
print(xor_sum([3,1]))

    