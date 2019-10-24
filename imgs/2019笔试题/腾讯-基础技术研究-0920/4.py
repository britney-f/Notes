import sys

def dec2K(n,x):
    a=[0,1,2,3,4,5,6,7,8,9]+list(map(chr, range(65,100)))
    b=[]
    ans = ''
    while True:
        s=n//x
        y=n%x
        b=b+[y]
        if s==0:
            break
        n=s
    b.reverse()
    for i in b:
        ans = ans+str(a[i])
    return ans

if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    ans_all = []
    for i in range(T):
        K = int(sys.stdin.readline().strip())
        line = sys.stdin.readline().strip().split()
        num1,num2,opr = line[0],line[1],line[2]
        num1,num2 = int(num1,base=K),int(num2,base=K)
        if opr == '+':
            ans = dec2K(num1 + num2, K)
        elif opr == '*':
            ans = dec2K(num1 * num2, K)
        elif opr == '-':
            ans = dec2K(num1 - num2, K)
        ans_all.append(ans)
    for i in range(T):
        print(ans_all[i])
