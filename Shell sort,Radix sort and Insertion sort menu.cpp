#include<stdio.h>
#include<conio.h>
int arr[100],n;
void InsertSort();
void QuickSort(int,int);
int partition(int,int);
void swap(int,int);
void ShellSort(int);
int main()
{
 int choice;
 int i,temp;
 printf("Enter the number of elements:-\n");
 scanf("%d",&n);
 printf("Enter %d elements:-\n",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 
 printf("Select your choice:-\n");
 printf("1. Insertion Sort\n");
 printf("2. Quicksort\n");
 printf("3. Shellsort\n");
 x:scanf("%d",&choice);
 switch(choice)
 {
  case 1:
   InsertSort();
   break;
  case 2:
   QuickSort(0,n-1);
   break;
  case 3:
   ShellSort(5);
   break;
  default:
   printf("Enter 1,2 or 3.\n");
   goto x;
 }
 
 printf("\n\nSorted Array:-\n");
 for(i=0;i<n;i++)
 {
  printf("%d ",arr[i]);
 }
 return 0;
}

//Insert Sort
void InsertSort()
{
 int temp,i,j,k;
 for(i=1;i<n;i++)
 {
  temp=arr[i];
  j=i-1;
  while((j>=0) && (arr[j]>temp))
  {
   arr[j+1]=arr[j];
   j=j-1;
  }
  arr[j+1]=temp;
  printf("\nPass %d: ",i);
  for(k=0;k<n;k++)
  {
   printf("%d ",arr[k]);
  }
 }
}

//Quick Sort
void QuickSort(int low, int high)
{
 int m;
 if(low<high)
 {
  m=partition(low,high);
  QuickSort(low,m-1);
  QuickSort(m+1,high);
 }
}
int partition(int low, int high)
{
 int pivot=arr[low];
 int i=low;
 int j=high;
 while(i<=j)
 {
  while(arr[i]<=pivot)
   i++;
  while(arr[j]>pivot)
   j--;
  if(i<j)
   swap(i,j);
 }
 swap(low,j);
 return j;
}
void swap(int i,int j)
{
 int temp;
 int k;
 temp = arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
 printf("\nPass: ");
 for(k=0;k<n;k++)
 {
  printf("%d ",arr[k]);
 }

}

//ShellSort
void ShellSort(int incr)
{
 int i,j,k,temp;
 while(incr>=1)
 {
  for(j=incr;j<n;j++)
  {
   int temp=arr[j];
   for(i=j-incr;i>=0 && temp<arr[i];i=i-incr)
    arr[i+incr]=arr[i];
   arr[i+incr]=temp;
   printf("\nPass: ");
   for(k=0;k<n;k++)
    printf("%d ",arr[k]);
  }
  incr=incr-2;
 }
}
