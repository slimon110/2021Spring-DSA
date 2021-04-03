import random as rd
def generate(n, mode=1):
    if mode == 1:
        i = rd.randint(1, n+1)
        x = rd.randint(-1000,1000)
        return 'Insert ' + str(i) + ' ' + str(x) + '\n'
    if mode == 2:
        l = rd.randint(1, n)
        r = rd.randint(l, n)
        return "Reverse {} {}\n".format(l,r)

n = 50
q = 50
# seq = [str(rd.randrange(-100, 100)) for i in range(n)]
seq = [str(i) for i in range(1, 1+n)]
# with open('test.in', 'w', encoding='utf-8') as f:
print("{} {}".format(n,q))
print(' '.join(seq)+'')
for i in range(q):
    print(generate(n, 2),end='')