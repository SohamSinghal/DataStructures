''' 
    4312
    /   \
   43   12    
  /  \  / \
 4    3 1  2
  \  /   \ /
   34     12
    \     /
     1234
'''
def MergeSort(arr):
    n = len(arr)
    if n>1:
        mid = int(n/2)
        left = arr[:mid]
        right = arr[mid:]
        MergeSort(left)
        MergeSort(right)
        i = j = k = 0
        lenl = len(left)
        lenr = len(right)
        while i<lenl and j <lenr:
            if left[i]<right[j]:
                arr[k] = left[i]
                i += 1
                k += 1
            else:
                arr[k] = right[j]
                j += 1
                k += 1
        while i<lenl:
            arr[k] = left[i]
            i += 1
            k += 1
        while j<lenr:
            arr[k] = right[j]
            j += 1
            k += 1
arr = [4,3,1,2]
print(arr)
print("Sorted Array:")
MergeSort(arr)
print(arr)
