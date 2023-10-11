#include <stdio.h>

#define admin_pass ("password")
#define MIN 5 // create alert if item chosen becomes less or equal to min
#define total_amount // gives the total amount of sale since last reset.

typedef struct product{ //typedef used to give a name to a data type
  int stock,price;
  char name[20];
} 
Product A={5,10,"Chips"};
Product B={1,6,"Candy"};
Product C={2,5"Water"};

void prodinfo() {
	printf("\n(1) The displayed products are: \n");
	printf("A. %s ($%d)\n",A.name,A.price);
	printf("B. %s ($%d)\n",B.name,B.price);
	printf("C. %s ($%d)\n",C.name,C.price);

}


int mainmenu() {
	int choice,i=0;
  while (i==0) {
	  printf("\nWhat would you like to do?\n");
	  printf("1. Read product information\n");
	  printf("2. Insert coin\n");
	  printf("3. Press product button\n");
	  printf("4. Press return button\n");
	  printf("9. Open service menu (code required)\n");
	  printf("0. Quit\n");
	  printf("Your choice:");
	  scanf("%d",&choice);
	  if ((choice>=0)&&(choice<=4)){i++;}
  	  else if(choice==9) {i++;}
  	  else {printf("\nInvalid choice!\n");}
  }return choice;
}


void amount() {
  int choice;
  printf("\n(2) How much money would you like to insert?\n");
  printf("1. DHS 1\n");
  printf("2. DHS 2\n");
  printf("3. DHS 5\n");
  printf("4. DHS 10\n");
  printf("5. Go back\n");
  printf("Your choice:");
  scanf("%d",&choice);
  if (choice==1) {
    money=money+1;
    printf("You have inserted DHS 1.\n\n");
    display2();
    amount();}
  else if (choice==2) {
    money=money+2;
    printf("You have inserted DHS 2.\n\n");
    display2();
    amount();}
  else if (choice==3) {
    money=money+5;
    printf("You have inserted DHS 5.\n\n");
    display2();
    amount();}
  else if (choice==4) {
    money=money+10;
    printf("You have inserted DHS 10.\n\n");
    display2();
    amount();}
  else if (choice==5) {
    printf("returning\n\n");
    display2();}
  else {
    printf("\nInvalid\n");
    amount();}
}

void product() {
  int choice,i=0;
  while (i==0) {
    printf("\n(3) Which product button would you like to press?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("0. Go back\n");
    printf("Your choice:");
    scanf("%d",&choice);
    if (choice==1) {
      printf("You have pressed button A.\n\n");
      if ((A.stock!=0)&&(money>=10)){A.stock--;money=money-A.price;
      prodlight=65;}
      total_amount=total_amount+A.price;
      display2();
      i++;}
    else if (choice==2) {
      printf("You have pressed button B.\n\n");
      if ((B.stock!=0)&&(money>=6)){B.stock--;money=money-B.price;
      prodlight=66;}
      total_amount=total_amount+B.price;
      display2();
      i++;}
    else if (choice==3) {
      printf("You have pressed button C.\n\n");
      if ((C.stock!=0)&&(money>=5)){C.stock--;money=money-C.price;prodlight=67;}
      total_amount=total_amount+C.price;
      display2();
      i++;}
    else if (choice==0) {
      printf("returning\n\n");
      display2();
      i++;}
    else {printf("\nInvalid\n");}
  }
}
