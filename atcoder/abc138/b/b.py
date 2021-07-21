x=int(input())
a=[]
n=input().split(" ")
for i in range(0,x):
    a.append(int(n[i]))
s=1
for j in range(0,len(a)):
    s = s * a[j]
t=1
sum=0
for k in range(0,len(a)):
    t=s/a[k]
    sum=sum+t
print(s/sum)
