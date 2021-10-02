#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int *a,n;

void merge(int,int,int);
void merge_sort(int low,int high)//splitting the array into smaller fragments
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
    int h,i,j,*b,k;
    b=malloc(n*sizeof(int)); //b is the final array
    i=low;
    k=low;    //h=i=0
    j=mid+1;   //j=5
    while((i<=mid)&&(j<=high))   //if input is lesser than middle and if it is betwen mid and high since we are diving into 3 halves
    {
        if(a[i]<=a[j])     //
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)                            //if i>mid so some ele in j might be left
    {
        for(k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else{                           //means j has become greater than upper bound/high so some eements might remain in i part.
        for(k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++)
        a[k]=b[k];               //final array
}
int main()
{
    int i;
    double clk;
    clock_t start,end;
    printf("MERGE SORT:\n");
    printf("Enter the number of employee records:\n");
    scanf("%d",&n);
    a=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        a[i]=rand()%100;

    printf("The Employee IDs are:(array elements)\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    start=clock();
    merge_sort(0,n-1);
    end=clock();

    clk=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThe sorted Employee IDs are\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    printf("\n\n The run time is %lf ms\n",clk);
}

