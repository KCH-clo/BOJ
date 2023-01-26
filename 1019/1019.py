from operator import add

nums = [[0] * 10 for i in range(10)]

def add_wise(lis):
    global res
    res = list(map(add, res, lis))

def mul(lis1, c):
    return [i * c for i in lis1]

def get_ones(n):
    return [1] * (n+1) + [0] * (9-n)

def cnt(n):
    r = [0] * 10
    r[n] = 1
    return r

nums = [0] * 12
nums[1] = 1
for i in range(11):
    nums[i+1] = nums[i] * 10 + 10**i

num = input()[::-1]

res = [0] * 10

for i in range(len(num)-1, 0, -1):
    cur = int(num[i])
    add_wise(mul(get_ones(cur-1), 10**i))
    add_wise(mul([nums[i]] * 10, cur))
    add_wise(mul(cnt(cur),int(num[:i][::-1]) + 1))
    res[0] -= 10**i

add_wise(get_ones(int(num[0])))
res[0] -= 1

print(' '.join(map(str, res)))