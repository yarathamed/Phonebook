#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validate.h"
int main()
{
    int i,choice;
    char aut[40];
    while(d){
    printf("Choose ");
    scanf("%d",&choice);
    //printf("%s",c[n].fname);
    switch(choice)
    {
    case 1:
        load();
        break;
    case 2:
        printf("Please enter the last name: \n");
        scanf("%s",aut);
        search(aut);
        break;
    case 3:
        add();
        break;
    case 4:
        modify();
           for(i=0;i<n;i++)
    {
        printf("%s\n",c[i].fname);
    }
        break;
    case 5:
        erase();
            for(i=0; i<n; i++)
            {
                printf("%s\n",c[i].fname);
            }
            break;
    case 6:
        save();
            break;
    case 7:
        quit();
            break;
     case 8:
            print();
            break;
    }
    //printf("%s",c[0].lname);

    /*char aut[40];
    printf("Please enter the last name: \n");
    gets(aut);
    search(aut);*/
    }
    return 0;

}
