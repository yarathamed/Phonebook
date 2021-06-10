typedef struct
{
    int day,month,year;
}date;
typedef struct
{
    char fname[20];
    char lname[20];
    date DOB;
    char address[100];
    char email[100];
    int phone;
}details;
details c[100];
int n=0,d=1;
void load()
{
    FILE *f;
    f=fopen("phonebook.txt", "r");

    if(f!=NULL){
        while(!feof(f))
    {
        //printf("ayah");
        fscanf(f,"%[^,],",c[n].fname);
       // printf("%s",c[n].fname);
        fscanf(f,"%[^,],",c[n].lname);
       // printf("%s",c[n].lname);
        fscanf(f,"%d %d %d,", &c[n].DOB.day, &c[n].DOB.month, &c[n].DOB.year);
        fscanf(f,"%[^,],",c[n].address);
        fscanf(f,"%[^,],",c[n].email);
        fscanf(f,"%d\n",&c[n].phone);
        //printf("%d",c[n].phone);
        n++;
    }
    fclose(f);
}
   else
        printf("This file does not exist.");
}

void search(char* lastName){
    printf("%s\n",lastName);
     int result=0,count=0,i;
     for(i=0;i<n; i++){
        result=strcmp(c[i].lname,lastName);
        //printf("%s",c[i].lname);
        //printf("%d\n",result);
        if(result==0){

            count++;
            printf("%s, %s, %s ,0%d\n",c[i].fname,c[i].address,c[i].email,c[i].phone);

        }

     }
     if(count==0){
        printf("no user with this last name");
     }

}

void add()
{
        printf("Please enter first name: \n");
        scanf("%s",c[n].fname);
        //printf("%s",c[n].fname);
        printf("Please enter last name: \n");
        scanf("%s",c[n].lname);
       // printf("%s",c[n].lname);
        printf("Please enter birth date: \n");
        scanf("%d-%d-%d", &c[n].DOB.day, &c[n].DOB.month, &c[n].DOB.year);
        printf("Please enter address: \n");
        scanf("%s",c[n].address);
        printf("Please enter email: \n");
        scanf("%s",c[n].email);
        printf("Please enter phone number: \n");
        scanf("%d",&c[n].phone);



        //printf("%s",c[n].fname);
        n++;
        //printf("%s",c[n].fname);
}

void modify()
{
    char modname[50],modified_mail[50];
    printf("Enter the last name of the contact you want to modify: ");
    scanf("%s",modname);
    search(modname);
    printf("From the given emails above enter the email of the contact you want to modify: ");
    scanf("%s",modified_mail);
    searchEmail(modified_mail);


    }



void searchEmail(char *modified_mail){
    printf("%s\n",modified_mail);
     int result=0,count=0,i;

     for(i=0;i<n; i++){
        result=strcmp(c[i].email,modified_mail);
        if(result==0){
        printf("Please enter first name: \n");
        scanf("%s",c[i].fname);
        //printf("%s",c[n].fname);
        printf("Please enter last name: \n");
        scanf("%s",c[i].lname);
       // printf("%s",c[n].lname);
        printf("Please enter birth date: \n");
        scanf("%d-%d-%d", &c[i].DOB.day, &c[i].DOB.month, &c[i].DOB.year);
        printf("Please enter address: \n");
        scanf("%s",c[i].address);
        printf("Please enter email: \n");
        scanf("%s",c[i].email);
        printf("Please enter phone number: \n");
        scanf("%d",&c[i].phone);

        }
     }
        //else printf("No contact with this email");



}
void erase()
{
    char delfirst[50],dellast[50];
    printf("Enter first name: ");
    scanf("%s",delfirst);
    printf("Enter last name: ");
    scanf("%s",dellast);
    int resultf,resultl,i,j,count=0,locationf,locationl;
    for(i=0; i<n; i++)
    {
        resultf=strcmp(c[i].fname,delfirst);
        resultl=strcmp(c[i].lname,dellast);
        if(resultf==0 && resultl==0)
        {
            for(j=i; j<n; j++)
            {
                c[j]=c[j+1];
                // n--;
            }
            n--;
        }
        /* for(i=0; i<n; i++)
         {
             resultf=strcmp(c[i].fname,delfirst);
             if(resultf==0)
             {
                 count++;
                 locationf=i;
             }
             if(count!=0)
             {
                 printf("fiuhsr\n");
                 for(j=0; j<n; j++)
                 {
                     resultl=strcmp(c[j].lname,dellast);
                     if(resultl==0)
                     {
                         locationl=j;
                     }
                 }
             }
         }
         if(locationl==locationf && resultf==0 && resultl==0)
         {
             printf("fiuhsr\n");
             for(i=locationl;i<n;i++)
             {
                 printf("fiuhsr\n");
                 c[i]=c[i+1];
                 //n--;
             }
             n--;
         }*/
    }
}
void save()
{
    int i;
    FILE *f1;
    f1=fopen("data.txt", "w");

    if(f1!=NULL)
    {
        while(!feof(f1))
        {
            for(i=0;i<n;i++)
            {
                fprintf(f1,"%s,",c[i].fname);
                fprintf(f1,"%s,",c[i].lname);
                fprintf(f1,"%d-%d-%d,",c[n].DOB.day,c[n].DOB.month,c[n].DOB.year);
                fprintf(f1,"%s,",c[i].address);
                fprintf(f1,"%s,",c[i].email);
                fprintf(f1,"%d\n",c[i].phone);

            }
        }
        fclose(f1);
    }
    else
        printf("This file does not exist\n");
}
void quit()
{
    int check;
    printf("Warning: all changes will be discarded.\n");
    printf("To proceed choose 1\nTo cancel choose 2\n");
    scanf("%d",&check);
    if(check==1)
    {
        d=0;
    }
    else d=1;
}


void sortbylastname()
{

 char temp[50];
 int temp_p;
 int temp_d;
 int i,j;
for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (strcmp(c[j].lname,c[j+1].lname) > 0 )
      {

        strcpy(temp,c[j].lname);
        strcpy(c[j].lname,c[j+1].lname);
        strcpy(c[j+1].lname,temp);

        strcpy(temp,c[j].fname);
        strcpy(c[j].fname,c[j+1].fname);
        strcpy(c[j+1].fname,temp);

        strcpy(temp,c[j].address);
        strcpy(c[j].address,c[j+1].address);
        strcpy(c[j+1].address,temp);

        strcpy(temp,c[j].email);
        strcpy(c[j].email,c[j+1].email);
        strcpy(c[j+1].email,temp);

        temp_p=c[j].phone;
        c[j].phone=c[j+1].phone;
        c[j+1].phone =temp_p;

        temp_d = c[j].DOB.day;
        c[j].DOB.day = c[j+1].DOB.day;
        c[j+1].DOB.day = temp_d;

        temp_d = c[j].DOB.month;
        c[j].DOB.month = c[j+1].DOB.month;
        c[j+1].DOB.month = temp_d;

        temp_d = c[j].DOB.year;
        c[j].DOB.year = c[j+1].DOB.year;
        c[j+1].DOB.year = temp_d;
      }
    }
  }
}
long value_DOB(date c)
{
long  value_DOB;
value_DOB = c.year * 10000 +  c.month * 100 + c.day;

//printf("value_DOB = = %ld \n",value_DOB);
//printf("year = = %ld \n",c.year * 10000);
//printf("mon = = %ld \n",c.month * 100);
//printf("day = = %ld \n",c.day);

return value_DOB ;
}

void sortbyDOB()
{
 date temp_DOB;
 int i,j;
  char temp[50];
 int temp_p;
 int temp_d;

for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (value_DOB(c[j].DOB)  > value_DOB(c[j+1].DOB) )
      {
        strcpy(temp,c[j].lname);
        strcpy(c[j].lname,c[j+1].lname);
        strcpy(c[j+1].lname,temp);

 //printf("l %s %s ++",c[j].lname,c[j+1].lname);
        strcpy(temp,c[j].fname);
        strcpy(c[j].fname,c[j+1].fname);
        strcpy(c[j+1].fname,temp);
// printf("f  %s %s ++",c[j].fname,c[j+1].fname);
        strcpy(temp,c[j].address);
        strcpy(c[j].address,c[j+1].address);
        strcpy(c[j+1].address,temp);
 //printf("ad %s %s \n",c[j].address,c[j+1].address);
        strcpy(temp,c[j].email);
        strcpy(c[j].email,c[j+1].email);
        strcpy(c[j+1].email,temp);

        temp_p=c[j].phone;
        c[j].phone=c[j+1].phone;
        c[j+1].phone =temp_p;

        temp_d = c[j].DOB.day;
        c[j].DOB.day = c[j+1].DOB.day;
        c[j+1].DOB.day = temp_d;

        temp_d = c[j].DOB.month;
        c[j].DOB.month = c[j+1].DOB.month;
        c[j+1].DOB.month = temp_d;

        temp_d = c[j].DOB.year;
        c[j].DOB.year = c[j+1].DOB.year;
        c[j+1].DOB.year = temp_d;
      }
    }
  }

}

void print()
{
      int s_choice;
      int i;
      printf("Please choose 1 to sort by Last name or 2 to sort by DOB in ascending order\n");
      scanf("%d",&s_choice);
      if (s_choice == 1)
       {

         sortbylastname();
       }
      else
       {
         sortbyDOB();
       }

// print sorted array
     for(i=0;i<n; i++){
        printf("\n");
        //printf(" last name: \n");
        printf("%s,",c[i].lname);
        //printf("first name: \n");
        printf("%s,",c[i].fname);
        //printf("birth date: \n");
        printf("%d-%d-%d,", c[i].DOB.day, c[i].DOB.month, c[i].DOB.year);
        //printf("Address: \n");
        printf("%s,",c[i].address);
        //printf("Email: \n");
        printf("%s,",c[i].email);
        //printf("Phone number: \n");
        printf("%d,",c[i].phone);
printf("\n");
//printf("\n%s,%s,%d,%d,%d,%s,%s,%d\n",c[i].lname,c[i].fname,c[i].DOB.day, c[i].DOB.month, c[i].DOB.year,c[i].address,c[i].email,c[i].phone);

}
}

