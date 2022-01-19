N, M, K = list(map(int, input().split()))
data = list(map(int,input().split()))

data.sort(reverse=True)

sum = 0
cnt = 0
for i in range(M):
    if(cnt == K):
        sum += data[1]
        cnt = 0
    else:
        sum += data[0]
        cnt += 1

print(sum)
