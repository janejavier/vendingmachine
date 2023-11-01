#include <stdio.h>
#include <stdlib.h>

int money = 0;
int totalAmount = 0;
int password = 1234;
typedef struct Item { //allows me to group together different data types under a single name
    int stock;
    int price;
    char name[20];// stores 20 characters only
} Item;

Item itemA = {10, 10, "Chips"};
Item itemB = {10, 15, "Candy"};
Item itemC = {10, 3, "Water"};

void displayProductInfo() {
    printf("VENDING MACHINE \n");
    printf("Menu:\n");
    printf("A. %s (DHS%d)\n", itemA.name, itemA.price);
    printf("B. %s (DHS%d)\n", itemB.name, itemB.price);
    printf("C. %s (DHS%d)\n", itemC.name, itemC.price);
}


void displayProducts() {
    printf("VENDING MACHINE\n");
    printf(" Chips=DHS%d  Candy=DHS%d  Water=DHS%d \n", itemA.price, itemB.price, itemC.price);
    printf("$%2d \n", money);
}

void insertMoney() {
    int choice;
    printf("\n(2) How much money would you like to insert?\n");
    printf("1. DHS 1\n");
    printf("2. DHS 2\n");
    printf("3. DHS 5\n");
    printf("4. DHS 10\n");
    printf("5. Go back\n");
    printf("Your choice:");
    scanf("%d", &choice);
    if (choice == 1) {
        money = money + 1;
        printf("You have inserted DHS 1.\n\n");
        displayProducts();
        insertMoney();
    } else if (choice == 2) {
        money = money + 2;
        printf("You have inserted DHS 2.\n\n");
        displayProducts();
        insertMoney();
    } else if (choice == 3) {
        money = money + 5;
        printf("You have inserted DHS 5.\n\n");
        displayProducts();
        insertMoney();
    } else if (choice == 4) {
        money = money + 10;
        printf("You have inserted DHS 10.\n\n");
        displayProducts();
        insertMoney();
    } else if (choice == 5) {
        printf("Returning\n\n");
        displayProducts();
    } else {
        printf("\nInvalid\n");
        insertMoney();
    }
}

void selectProduct() {
    int option, i = 0;
    while (i == 0) {
        printf("\n Which product would you like to choose?\n");
        printf("1. Chips\n");
        printf("2. Candy\n");
        printf("3. Water\n");
        printf("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &option);
        if (option == 1) {
            printf("You have pressed button 1.\n\n");
            if ((itemA.stock != 0) && (money >= itemA.price)) {
                itemA.stock--;
                money = money - itemA.price;
            }
            totalAmount = totalAmount + itemA.price;
            displayProductInfo();
            i++;
        } else if (option == 2) {
            printf("You have pressed button 2.\n\n");
            if ((itemB.stock != 0) && (money >= itemB.price)) {
                itemB.stock--;
                money = money - itemB.price;
            }
            totalAmount = totalAmount + itemB.price;
            displayProductInfo();
            i++;
        } else if (option == 3) {
            printf("You have pressed button 3.\n\n");
            if ((itemC.stock != 0) && (money >= itemC.price)) {
                itemC.stock--;
                money = money - itemC.price;
            }
            totalAmount = totalAmount + itemC.price;
            displayProductInfo();
            i++;
        } else if (option == 0) {
            printf("Returning\n\n");
            displayProductInfo();
            i++;
        } else {
            printf("\nInvalid\n");
        }
    }
}

void displayMachineStatus() {
    printf("\n Current Machine Status\n");
    printf("Total Sales: $%d\n", totalAmount);
    printf("Product Information:\n");
    printf("A. %s ($%d) ", itemA.name, itemA.price);
    if (itemA.stock != 0) {
        printf("(%d left)\n", itemA.stock);
    } else {
        printf("(sold out)\n");
    }
    printf("B. %s ($%d) ", itemB.name, itemB.price);
    if (itemB.stock != 0) {
        printf("(%d left)\n", itemB.stock);
    } else {
        printf("(sold out)\n");
    }
    printf("C. %s ($%d) ", itemC.name, itemC.price);
    if (itemC.stock != 0) {
        printf("(%d left)\n", itemC.stock);
    } else {
        printf("(sold out)\n");
    }
}

void withdrawMoney() {
    printf("\n All money is being withdrawn.\n");
    printf("$%d is withdrawn.\n", totalAmount);
    totalAmount = 0;
}

void refillProducts() {
    int choice, i = 0;
    int num= 0;
    while (i == 0) {
        printf("\nWhich product would you like to refill?\n");
        printf("1. Product A\n");
        printf("2. Product B\n");
        printf("3. Product C\n");
        printf("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice == 1) {
            num= rand() % 20 +1;
            printf("%d", "stock left is",num);
            printf("You have refilled Product A to full.\n");
            i++;
        } else if (choice == 2) {
            num= rand() % 20 +1;
            printf("%d", "stock left is",num);
            printf("You have refilled Product B to full.\n");
            i++;
        } else if (choice == 3) {
            num= rand() % 20 +1;
            printf("%d", "stock left is",num);
            printf("You have refilled Product C to full.\n");
            i++;
        } else if (choice == 0) {
            printf("Returning\n");
            i++;
        } else {
            printf("\nInvalid\n");
        }
    }
}

void changeProduct() {
    int choice, i = 0;
    while (i == 0) {
        printf("\n Which product would you like to change?\n");
        printf("1. Product A\n");
        printf("2. Product B\n");
        printf("3. Product C\n");
        printf("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You have chosen to change Product A.\n");
            printf("\nEnter the new product name:");
            scanf("%s", itemA.name);
            printf("Enter the new product price:");
            scanf("%d", &itemA.price);
            itemA.stock = 20;
            printf("Product A has been restocked to full.\n");
            i++;
        } else if (choice == 2) {
            printf("You have chosen to change Product B.\n");
            printf("\nEnter the new product name:");
            scanf("%s", itemB.name);
            printf("Enter the new product price:");
            scanf("%d", &itemB.price);
            itemB.stock = 20;
            printf("Product B has been restocked to full.\n");
            i++;
        } else if (choice == 3) {
            printf("You have chosen to change Product C.\n");
            printf("\nEnter the new product name:");
            scanf("%s", itemC.name);
            printf("Enter the new product price:");
            scanf("%d", &itemC.price);
            itemC.stock = 20;
            printf("Product C has been restocked to full.\n");
            i++;
        }
    }
}

void serviceMenu() {
    int choice, i = 0;
    while (i == 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Check machine status\n");
        printf("2. Withdraw all money\n");
        printf("3. Refill product\n");
        printf("4. Change product\n");
        printf("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice == 1) {
            displayMachineStatus();
        } else if (choice == 2) {
            withdrawMoney();
        } else if (choice == 3) {
            refillProducts();
        } else if (choice == 4) {
            changeProduct();
        } else if (choice == 0) {
            printf("Returning\n\n");
            displayProducts();
            i++;
        } else {
            printf("\nInvalid\n");
        }
    }
}

void accessServiceMenu() {
    int accessCode;
    printf("\nOpening service menu\n");
    printf("Enter access code:");
    scanf("%d", &accessCode);
    if (accessCode == password) {
        printf("\nCorrect\n");
        serviceMenu();
    } else {
        printf("\nIncorrect\n\n");
        displayProducts();
    }
}

int main(void) {
    int option, i = 0;
    displayProducts();
    while (i == 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. display product info\n");
        printf("2. insert money\n");
        printf("3. select a product\n");
        printf("4. return money\n");
        printf("5. access admin mode\n");
        printf("0. back\n");
        printf("Your choice:");
        scanf("%d", &option);
        if (option == 1) {
            displayProductInfo();
        } else if (option == 2) {
            insertMoney();
        } else if (option == 3) {
            selectProduct();
        } else if (option == 4) {
            printf("\n Return button is pressed.\n");
            printf("$%d has been returned.\n\n", money);
            totalAmount -= money;
            money = 0;
            displayProducts();
        } else if (option == 5) {
            accessServiceMenu();
        } else if (option == 0) {
            i++;
        }
    }
    return 0;
}
