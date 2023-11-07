#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float money = 0;
int totalAmount = 0;
int password = 1234;
typedef struct Item {
    int stock;
    float price;
    char name[20];
} Item;

Item itemA = {10, 2.50, "Chips"};
Item itemB = {10, 3.00, "Candy"};
Item itemC = {10, 1.50, "Water"};


void displayProducts() {
    printf(" VENDING MACHINE\n\n");
    printf(" %s (DHS %.2f)\n", itemA.name, itemA.price);
    printf(" %s (DHS %.2f)\n", itemB.name, itemB.price);
    printf(" %s (DHS %.2f)\n", itemC.name, itemC.price);
    printf(" Total: DHS %2f  \n", money);
    printf(" Please insert coins before choosing product\n\n");
}

void insertMoney() {
    int choice;
    printf("\n How much money would you like to insert?\n");
    printf("1. DHS 1\n");
    printf("2. DHS 0.5\n");
    printf("3. DHS 0.25\n");
    printf("0. CANCEL\n");
    printf("Your choice:");
    scanf("%d", &choice);

    
    printf("You have selected DHS %.2f.\n\n", money);

   if (choice == 1) {
    money = money + 1;
    printf("You have inserted DHS %.2f.\n\n", money);
    displayProducts();
    insertMoney();
} else if (choice == 2) {
    money = money + 0.5;
    printf("You have inserted DHS %.2f.\n\n", money);
    displayProducts();
    insertMoney();
} else if (choice == 3) {
    money = money + 0.25;
    printf("You have inserted DHS %.2f.\n\n", money);
    displayProducts();
    insertMoney();
} else if (choice == 0) {
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
        printf("\n Which product  would you like to get?\n");
        printf("1. Chips\n");
        printf("2. Candy\n");
        printf("3. Water\n");
        printf("0. Cancel\n");
        printf("Your choice:");
        scanf("%d", &option);

      
        if (option == 1 && money < itemA.price) {
            printf("You do not have enough money to purchase Chips. Please insert more money.\n\n");
            continue;
        } else if (option == 2 && money < itemB.price) {
            printf("You do not have enough money to purchase Candy. Please insert more money.\n");
            continue;
        } else if (option == 3 && money < itemC.price) {
            printf("You do not have enough money to purchase Water. Please insert more money.\n");
            continue;
        }

        if (option == 1) {
            printf("You have bought Chips.\n\n");
            if ((itemA.stock != 0) && (money >= itemA.price)) {
                itemA.stock--;
                money = money - itemA.price;
            }
            totalAmount = totalAmount + itemA.price;
            displayProducts();
            i++;
        } else if (option == 2) {
            printf("You have bought Candy.\n\n");
            if ((itemB.stock != 0) && (money >= itemB.price)) {
                itemB.stock--;
                money = money - itemB.price;
            }
            totalAmount = totalAmount + itemB.price;
            displayProducts();
            i++;
        } else if (option == 3) {
            printf("You have bought Water.\n\n");
            if ((itemC.stock != 0) && (money >= itemC.price)) {
                itemC.stock--;
                money = money - itemC.price;
            }
            totalAmount = totalAmount + itemC.price;
            displayProducts();
            i++;
        } else if (option == 0) {
            printf("Returning\n\n");
            displayProducts();
            i++;
        } else {
            printf("\nInvalid option\n");
        }
    }
}

void displayMachineStatus() {
    printf("\n Current Machine Status\n");
    printf("Total Sales: DHS%d\n", totalAmount);
    printf("Product Information:\n");
    printf("A. %s (DHS%f) ", itemA.name, itemA.price);
    if (itemA.stock != 0) {
        printf("(%d left)\n", itemA.stock);
    } else {
        printf("(sold out)\n");
    }
    printf("B. %s (DHS%f) ", itemB.name, itemB.price);
    if (itemB.stock != 0) {
        printf("(%d left)\n", itemB.stock);
    } else {
        printf("(sold out)\n");
    }
    printf("C. %s (DHS%f) ", itemC.name, itemC.price);
    if (itemC.stock != 0) {
        printf("(%d left)\n", itemC.stock);
    } else {
        printf("(sold out)\n");
    }
}

void withdrawMoney() {
    printf("\n All money is being withdrawn.\n");
    printf("DHS%d is withdrawn.\n", totalAmount);
    totalAmount = 0;
}

void refillProducts() {
    int choice, i = 0;
    srand(time(NULL)); 

    while (i == 0) {
        printf("\nWhich product would you like to refill?\n");
        printf("1. Chips\n");
        printf("2. Candy\n");
        printf("3. Water\n");
        printf("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice == 1) {
            itemA.stock = (rand() % 20) + 1; 
            printf("You have refilled Chips to %d stocks\n", itemA.stock);
            i++;
        } else if (choice == 2) {
            itemB.stock = (rand() % 20) + 1; 
            printf("You have refilled Candy to %d stocks\n", itemB.stock);
            i++;
        } else if (choice == 3) {
            itemC.stock = (rand() % 20) + 1; 
            printf("You have refilled Water to %d stocks\n", itemC.stock);
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
            scanf("%f", &itemA.price);
            itemA.stock = 20;
            printf("Product A has been restocked to full.\n");
            i++;
        } else if (choice == 2) {
            printf("You have chosen to change Product B.\n");
            printf("\nEnter the new product name:");
            scanf("%s", itemB.name);
            printf("Enter the new product price:");
            scanf("%f", &itemB.price);
            itemB.stock = 20;
            printf("Product B has been restocked to full.\n");
            i++;
        } else if (choice == 3) {
            printf("You have chosen to change Product C.\n");
            printf("\nEnter the new product name:");
            scanf("%s", itemC.name);
            printf("Enter the new product price:");
            scanf("%f", &itemC.price);
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
        printf("1. INSERT MONEY\n");
        printf("2. SELECT PRODUCT\n");
        printf("3. RETURN MONEY\n");
        printf("4. ACCESS ADMIN\n");
        printf("0. BACK\n");
        printf("Your choice:");
        scanf("%d", &option);
        if (option == 1) {
            insertMoney();
        } else if (option == 2) {
            selectProduct();
        } else if (option == 3) {
            printf("\n Return button is pressed.\n");
            printf("DHS%f has been returned.\n\n", money);
            totalAmount -= money;
            money = 0;
            displayProducts();
        } else if (option == 4) {
            accessServiceMenu();
        } else if (option == 0) {
            i++;
        }
    }
    return 0;
}

