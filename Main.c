#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;
int seat = 100 ;
void insert_details();
void viewAll(); 
void find();
void book_ticket();
void old_record(); 

void main()
{
	 int ch;
 	do{
	printf("\n");	
	printf("\t Cinema Ticket booking ");
	printf("\n");
	printf("\nPress <1> Insert Movie");
   	printf("\nPress <2> View All Movie");
	printf("\nPress <3> Find Movie ");
	printf("\nPress <4> Book Ticket");
	printf("\nPress <5> View All Transections");
   	printf("\nPress <0> Exit ");
   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch); 	

   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;
    		
		case 3:
    		find();
   		break;

		case 4:
		book_ticket();
		break;
		
		case 5:
		old_record();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);
}
void insert_details()
{
	FILE *fp;
	struct book b;
	printf("Entre movie code :- # ");	
	scanf("%s",b.code);
	printf("Enter  name :- ");	
	scanf("%s",b.name);
	printf("Enter Relice Date:- ");	
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");	
	scanf("%d",&b.cost);
	fp=fopen("data.txt","a");
	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s\n %s\n %s\n %d \n",b.code,b.name,b.date,b.cost); //this line print the given variable value from the file.
		printf("Data insert Sucessfull");
	}
		printf("\n");
	fclose(fp);
}
void find()
{
	struct book b;
	FILE *fp;
	char ch[20];
	printf("Enter movie code : ");
	scanf("%s",ch);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF) // EOF stands for End of the file.
		{
			fscanf(fp,"%s\n %s\n %s\n %d\n",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode :: #%s",b.code);
				printf("\n\t\tmovie name :: %s",b.name);
				printf("\n\t\tmovie date :: %s",b.date);
				printf("\n\t\tprice of ticket :: Rs.%d",b.cost);
				break;
			}
		}
	}

	fclose(fp);//this is used to close the current file.
}
void viewAll()
{
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r"); // this line is use to open the avila. file and read the old data.
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{	
		system("cls"); // this line is used to clear the above output in the terminal.
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);		
	}
	fclose(fp); //to close the file(fclose)
}
void book_ticket()
{
 struct book b;
	FILE *fp; //fp is a pointer use to store the address.
	FILE *ufp; //ufp is a pointer use to located the end of the line.
	int total_seat,total_amount;
	long long int mobile;
	char name[20];
	char ch; 
	char movie_code[20]; 
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      	printf("%c",ch);
	}
	fclose(fp);
	printf("\n For Book ticket Choise Movie(Enter Movie Code First Latter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r"); // open the file(fopen) and for read the file we use ("r")
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s\n %s\n %s\n %d\n",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0) //this (strcmp) is used to compair the two given string with eaach other.
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode :: #%s",b.code);
				printf("\n\t\tMovie name :: %s",b.name);
				printf("\n\t\tdate name :: %s",b.date);
				printf("\n\t\tPrice of ticket:: Rs.%d",b.cost);
			}
		}
	}
	printf("\n* Fill Deatails  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%lld",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	total_amount = b.cost * total_seat;
	printf("\n ***** ENJOY MOVIE ****\n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number :%lld",mobile);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : Rs.%d",b.cost);
	printf("\n\t\tTotal Amount : Rs.%d",total_amount);
	ufp=fopen("oldTransection.txt","a"); // append the data in the already given file.("a")
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s\n %lld\n %d\n %d\n %d\n",name,mobile,total_seat,total_amount,b.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}
void old_record()
{
	char ch;
	FILE *fp;	
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
}
