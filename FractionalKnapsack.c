#include <stdio.h>

//Compiler version gcc  6.3.0
float p[10],v[10],w[10],t,x[10];
int W,n;
void sort()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(p[i]<p[j])
      {
        t=p[j];
        p[j]=p[i];
        p[i]=t;
        t=w[j];
        w[j]=w[i];
        w[i]=t;
        t=v[j];
        v[j]=v[i];
        v[i]=t;
      }
    }
  }
}
float knapsack()
{
  int i;
  float total=0;
  for(i=0;i<=n;i++)
  {
    if(w[i]>W)
    {
      x[i]=W/w[i];
      total=total+p[i]*W;
      break;
    }
    else
    {
      x[i]=1;
      total=total+v[i];
      W=W-w[i];
    }
  }
  return total;
}
int main()
{
  int i;
  float s;
  printf("Subhayu Kumar Bala\nEnter the number of items: ");
  scanf("%d",&n);
  printf("\nEnter the weights of corresponding items: ");
  for(i=1;i<=n;i++)
  {
    scanf("%f",&w[i]);
  }
  printf("\nEnter the corresponding values: ");
  for(i=1;i<=n;i++)
  {
    scanf("%f",&v[i]);
  }
  printf("\nEnter the maximum weight: ");
  scanf("%d",&W);
  for(i=1;i<=n;i++)
  {
    x[i]=0;
    p[i]=v[i]/w[i];
  }
  sort();
  s=knapsack();
  printf("\nTotal/Maximum value=%f",s);
  for(i=1;i<=n;i++)
  {
     printf("\n%f",x[i]);
  }
}
