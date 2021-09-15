#include <stdio.h>
void main()
{
    //considering frame no as index and page no as array elements
    int number_of_pages;
    int i, user;
    printf("Size of frame number\n");
    scanf("%d", &number_of_pages);
    if(number_of_pages < 4)
    {
        printf("Underflow\n");
    }
    int pagearray[number_of_pages];
    for(i   =   0; i    <   number_of_pages;i++)
    {
        pagearray[i] = -1;

    }
    //hardcoding the existing table
    pagearray[0] = 0;
    pagearray[1] = 3;
    pagearray[2] = 5;
    pagearray[3] = 2;
     
    printf("User process input:\n");
    scanf("%d", &user);
    
    for(i=4;i<number_of_pages;i++)
    {
        if(pagearray[i]!=-1)
        {
            continue;
        }
        else
        {
            pagearray[i] = user;
            break;
        }
        
    }
     printf("----------------------------------------------\n");
    printf("|%20s || %20s|\n","Page Number","Frame number");
     printf("----------------------------------------------\n");
    for(i=0;i   <   number_of_pages;i++)
    {
        printf("|%21d||%21d|\n",pagearray[i], i);

    } printf("----------------------------------------------\n");
    
}