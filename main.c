#include <stdio.h>

int main() {
    printf("Welcome to Food Thingies!\n");


    int nrfoods = 3;
    char foods[][100] = {"Pizza","Pasta","Salad"};
    int notypes[] = {3,2,4};
    char types[20][20][20] = {
            {"Pizza Carbonara", "Pizaa Diavola", "Pizza Margherita"},
            {"Chicken Alfredo", "Mac&Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad","Cobb"}
    };
    double prices[4][4] = {
            {21, 23, 19},
            {23,21},
            {23, 22, 19,21}
    };
    int noAdditionalItems = 3;
    char additionalItems[][100] = {"Coca-cola","Lipton","Water"};
    double additionalItemsPrices[] = {5, 5, 4};


    char firstName[20];
    char lastName[20];
    char phoneNumber[10];
    char address[30];
    int choice, foodChoice, typeChoice;
    int noAddItemsChosen = 0;
    int chosenAdditionalItems[3];

    int state =0;
    int contractSigned = 0;
    while(!contractSigned){
        switch (state) {
            case 0: {

                printf("Please input your data\n");
                printf("---First name:\n");
                gets(firstName);
                printf("---Last name:\n");
                gets(lastName);
                printf("---Phone number\n");
                gets(phoneNumber);
                printf("---Address\n");
                gets(address);
                state++;
                break;
            }
            case 1: {

                printf("Please choose what food do you want to eat\n");
                for(int i=0;i<nrfoods;i++) {
                    putchar('a'+i);
                    printf(") %s\n",foods[i]);
                }
                printf("%c) Go back\n",'a'+nrfoods);
                choice = getchar();

                getchar();
                if(choice == 'a'+nrfoods) {
                    state--;
                    break;
                }
                foodChoice = choice - 'a';
                state++;
                break;
            }
            case 2: {

                printf("Please choose what type of food do you want %s\n",types[foodChoice]);
                for(int i=0;i<notypes[foodChoice];i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n",types[foodChoice][i], prices[foodChoice][i]);
                }
                printf("%c) Go back\n",'a'+notypes[foodChoice]);
                choice = getchar();

                getchar();
                if(choice == 'a'+notypes[foodChoice]) {
                    state--;
                    break;
                }
                typeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {

                printf("Choose additional drink (separated by comma)\n");
                for(int i=0;i<noAdditionalItems;i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n", additionalItems[i], additionalItemsPrices[i]);
                }
                printf("%c) Go back\n",'a'+noAdditionalItems);



                choice = getchar();
                if(choice == 'a'+noAdditionalItems) {
                    state--;

                    getchar();
                    break;
                }
                noAddItemsChosen = 0;
                while (choice !='\n') {

                    chosenAdditionalItems[noAddItemsChosen] = choice - 'a';
                    noAddItemsChosen++;

                    char comma = getchar();
                    if(comma=='\n'){

                        break;
                    }
                    choice = getchar();
                }
                state++;
                break;
            }
            case 4:{

                printf("Your order is:\n");
                printf("-------------\n");
                printf("Customer data:\n");
                printf("-name: %s %s\n", firstName, lastName);
                printf("-phone number: %s\n", phoneNumber);
                printf("-address: %s\n", address);
                printf("Order data:\n");
                printf("food: %s (%.2f)\n", types[foodChoice][typeChoice], prices[foodChoice][typeChoice]);
                double additionalItemsPrice = 0;
                for(int i=0;i<noAddItemsChosen;i++) {
                    additionalItemsPrice += additionalItemsPrices[chosenAdditionalItems[i]];
                }
                printf("-additional items (%.2f)\n", additionalItemsPrice);
                if(noAddItemsChosen!=0){
                    for(int i=0;i<noAddItemsChosen;i++) {
                        printf("--%s (%.2f)\n", additionalItems[chosenAdditionalItems[i]], additionalItemsPrices[chosenAdditionalItems[i]]);
                    }
                }
                printf("Total price: %.2f\n", prices[foodChoice][typeChoice] + additionalItemsPrice);
                printf("-------------\n");
                printf("a) Sign\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    contractSigned = 1;
                } else {
                    state--;
                }

                getchar();
                break;
            }
        }
    }
    return 0;
}