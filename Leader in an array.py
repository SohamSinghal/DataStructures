#Task 1: Leader in the Array
def leaderElements(arr):
    leader = [arr[-1]]
    max_element = arr[-1]
    for i in range(len(arr)-2,-1,-1):   
        if(arr[i]>max_element):
            leader.append(arr[i])
            max_element = arr[i]
    return leader[::-1]
array = [7, 10, 4, 10, 6, 5, 2]
print(leaderElements(array))
array = [16, 17, 4, 3, 5, 2]
print(leaderElements(array))


