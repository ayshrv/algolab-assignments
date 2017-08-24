'''input
7
0,3
2,2
1,1
2,1
3,0
0,0
3,3
'''

import numpy as np
import matplotlib.pyplot as plt

# Graham Algorithm
hull=[]
def orientation(a,b,c):
	val=(b[1]-a[1])*(c[0]-b[0])-(b[0]-a[0])*(c[1]-b[1])
	if val==0:
		return 0
	if val>0:
		return 1
	return 2

def distSq(a,b):
	return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])

int compare(const void *vp1, const void *vp2)
{
   Point *p1=(Point*)vp1;
   Point *p2=(Point*)vp2;
 
   int o=orientation(p0,*p1,*p2);
   if (o==0)
     return (distSq(p0,*p2)>=distSq(p0,*p1))?-1:1;
 
   return(o==2)?-1:1;
}

def swap(l,a,b):
	l[a][0],l[b][0]=l[b][0],l[a][0]
	l[a][1],l[b][1]=l[b][1],l[a][1]

def nextToTop(l):
	a=l.pop()
	b==l.pop()
	l.append(b)
	l.append(a)
	return b

def convexHull(p,n):
	ymin=p[0][1],minn=0
	for i in range(1,n):
		y=p[i][1]
		minnn=i
		if((y<ymin) or (ymin==y and p[i][0]<p[minnn][0]))
		ymin=p[i][1],minnn=i
	swap(p,0,minnn)
	p0=p[0]
	# sort
	m=1
	for i in range(1,n):
		while(i<n-1 and orientation(p0,p[i],p[i+1])==0):
			i=i_1
		p[m]=p[i]
		m=m+2

	if(m<3):
		return
	s=[]
	s.append(p[0])
	s.append(p[1])
	s.append(p[2])
	for i in range(3,m):
		while(orientation(nextToTop(s),s[-1],p[i])!=2):
			s.pop()
		s.append(p[i])
	while(len(s)!=0):
		z=s[-1]
		#print nos.



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