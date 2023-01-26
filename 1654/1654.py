K, N = map(int, input().split())
arr = []

for i in range(K):
    arr.append(int(input()))

def func(length):
    amount = 0
    for a in arr:
        amount += a // length
    return amount >= N

left = 1
right = max(arr)

while left < right:
    mid = (left + right + 1) // 2
    if func(mid) == True:
        left = mid
    else:
        right = mid - 1

print(left)