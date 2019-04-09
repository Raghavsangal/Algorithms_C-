t=int(input())
for _ in range (t):
    n=int(input())
    a=input().split()
    a=list(map(int,a))
    max_so_far=-1
    max_sum=0
    if(n==1):
        print(*a)
    else:
        for i in range(n):
            max_sum=max_sum+a[i]
            if(max_sum>max_so_far):
                max_so_far=max_sum
            if(max_sum<0):
                max_sum=0
        print(max_so_far)