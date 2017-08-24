'''input
7
0,3
2,2
1,1
2,1
3,0
0,0
4,4
'''

import numpy as np
import matplotlib.pyplot as plt

# Jarvis Algorithm
hull=[]
def orientation(a,b,c):
	val=(b[1]-a[1])*(c[0]-b[0])-(b[0]-a[0])*(c[1]-b[1])
	if val==0:
		return 0
	if val>0:
		return 1
	return 2



def convexHull(p,n):
	if n<3:
		return
	l=0
	for i in range(1,n):
		if(p[i][0]<p[l][0]):
			l=i

	a=l
	while True:
		hull.append((p[a][0],p[a][1]))
		b=(a+1)%n
		for i in  range(n):
			if(orientation(p[a],p[i],p[b])==2):
				b=i
		a=b
		if(a==l):
			break
	for i in range(len(hull)):
		print('('+str(hull[i][0])+','+str(hull[i][1])+')')


#Driver Program
n=input("Enter the number of points: ")
print(n)
points=[]
print("Enter the points: ")
for i in range(n):
	a,b=map(int,raw_input().split(','))
	print(str(i+1)+'.('+str(a)+','+str(b)+')')
	points.append((a,b))
convexHull(points,n)
print(points)
print(hull)
points=np.array(points)
hull=np.array(hull)
print(hull[:,0])
print(hull[:,1])

# Plotting Points
x_min=min(points[:,0])
x_max=max(points[:,0])
y_min=min(points[:,1])
y_max=max(points[:,1])
x_length=abs(x_max-x_min)
y_length=abs(y_max-y_min)
# plt.axis([x_min,x_max,y_min,y_max])
plt.axis([x_min-0.1*x_length,x_max+.1*x_length,y_min-.1*y_length,y_max+.1*y_length])
# plt.axis([-5,5,-5,5])
plt.plot(points[:,0],points[:,1],'bo',marker='o',markerfacecolor='green',markersize=6)
plt.plot(hull[:,0],hull[:,1],'r-',marker='o',markerfacecolor='black',markersize=8)
# plt.plot(hull[:,0],hull[:,1],'r-',markersize=8)
plt.plot([hull[0][0],hull[-1][0]],[hull[0][1],hull[-1][1]],'r-',marker='o',markerfacecolor='black',markersize=8)
plt.show()


