import matplotlib.pyplot as plt
f = open('example.txt', 'r')
s = f.read()
print s
x = []
y=[]
s = s.split(" ")
print s
i = 0
for i in range(len(s)-1):
    k = int(s[i])
    x.append(k);
    #k = int(s[i +1])
    #y.append(k);
print x
t = []
emp1 = []
emp2 = []
n = 0
for i in range(len(x)):
    if i is 0:
        n = x[i]
    elif i%2 is 0 and i <= (2*n):
        emp2.append(x[i])
    elif i%2 is not 0 and i <= (2*n):
        emp1.append(x[i])
    elif i%2 is 0:
        y.append(x[i])
    else:
        t.append(x[i])
print t
print y
print emp1
plt.plot(t,y,linestyle='--')
plt.plot(emp1, emp2, marker='o', linestyle='')
plt.show()
