#include <stdio.h>
int max,temp;
void indexFunction(int indPrice[],int quantity[],int btlenmbr);
int main()
{
    int quantity[100];
    int totalPrice[100];
    int indPrice[100];
    int btlenmbr;
    printf("Enter Bottle number : ");
    scanf("%d",&btlenmbr);
    for(int i=0; i<btlenmbr; i++)
    {
        printf("Enter %d bottle quantity : ",i+1);
        scanf("%d",&quantity[i]);
        printf("Enter %d bottle price : ",i+1);
        scanf("%d",&totalPrice[i]);
        indPrice[i] = totalPrice[i]/quantity[i];
    }
    for(int i=0; i<btlenmbr; i++)
    {
        printf("%d ",indPrice[i]);
    }
    printf("\n");
    int mainbtle;
    printf("Enter main bottle quantity : ");
    scanf("%d",&mainbtle);

    int value[100];
    int price[100];
    for(int i=0; i<btlenmbr; i++)
    {
        value[i]=quantity[i];
        price[i]=indPrice[i];
    }


    indexFunction(indPrice,quantity,btlenmbr);
    printf("\n");
    printf("per ml: ");
    for(int i=0; i<btlenmbr; i++)
    {
        printf("%d ",indPrice[i]);
    }
    printf("\n value : ");
    for(int i=0; i<btlenmbr; i++)
    {
        printf("%d ",quantity[i]);
    }

    int i=0,nmbr=0,due;
    int sumweight=0;
    int sumprice=0;
    printf("\nSolution  :\t P\n");
    while(sumweight<mainbtle)
    {
        sumweight=sumweight+quantity[i];
        int n=quantity[i];
        for(int j=0; i<btlenmbr; j++)
        {
            if(value[j]==n)
            {
                nmbr=j;
                break;
            }
        }
        if(sumweight>mainbtle)
        {
            break;
        }

        sumprice+=totalPrice[nmbr];
        printf(" %d ml of %d     \t %d$\n",quantity[i],nmbr+1,totalPrice[nmbr]);
        i++;
    }
    if(sumweight>mainbtle)
    {
        sumweight-=quantity[i];
        due = mainbtle-sumweight;
        sumweight+=due;
        printf(" %d ml of %d     \t %d$\n",due,nmbr+1,price[nmbr]);
        sumprice+=price[nmbr];
    }
    printf("  Total Profit : %d$\n",sumprice);



}
void indexFunction(int indPrice[],int quantity[],int btlenmbr)
{

    for(int i=0; i<btlenmbr; i++)
    {
        max = i;
        for(int j=i+1; j<btlenmbr; j++)
        {
            if(indPrice[j]>indPrice[max])
            {
                max=j;
            }
        }
        temp=indPrice[i];
        indPrice[i]=indPrice[max];
        indPrice[max]=temp;

        temp=quantity[i];
        quantity[i] = quantity[max];
        quantity[max]=temp;
    }
}






