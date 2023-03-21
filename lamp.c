#include<stdio.h>
// Function to find maximum between two number
int max(int a,int b)
{
if(a>b)
return a;
else return b;
}
void display(int e1,int e2,int p1[5],int p2[3])
{
int i;
printf("\nThe time stamps of events in p1:\n");

for(int i=0;i<e1;i++)
printf("%d ",p1[i]);

printf("\n The time stamps of events in p2:\n");
for(int i=0;i<e2;i++)
printf("%d ",p2[i]);

}

void lamportLogicalclock(int e1,int e2,int m[5][3])
{
int i,j,k,p1[e1],p2[e2];

// Initialize p1 and p2
for(i=0;i<e1;i++)
p1[i]=i+1;

for(i=0;i<e2;i++)
p2[i]=i+1;

for(i=0;i<e2;i++)
printf("\te2%d",i+1);

for(i=0;i<e1;i++){
printf("\n e1%d \t",i+1);

for(j=0;j<e2;j++)
printf("%d\t",m[i][j]);
}



for(i=0;i<e1;i++)
{
for(j=0;j<e2;j++)
{

//Change the timestamp if the message is sent
if(m[i][j]==1){
p2[j]=max(p2[j],p1[i]+1);
for(k=j+1;k<e2;k++)
p2[k]=p2[k-1]+1;
}

//Change the timestamp if the message is received 
if(m[i][j]==-1)
{
p1[i]=max(p1[i],p2[j]+1);
for(k=i+1;k<e1;k++)
p1[k]=p1[k-1]+1;

}
}
}
display(e1,e2,p1,p2);}
int main()
{
int e1=5,e2=3,m[5][3]={0}; 
// Message is sent and reeived between 2 process
// m[i][j]=1, if message is sent from ei to ej
// m[i][j]=-1, if message is sent from ej to ei
// m[i][j]=0 , otherwise 

m[1][1]=1;
m[1][2]=1;

m[4][1]=-1;

lamportLogicalclock(e1,e2,m);
return 0;
}

