  #include <stdio.h>
#include <windows.h>


#define MAXCARS 10
int numberOfCars = 10;
char carNames[MAXCARS][50] = {"Acura TLX 2023", "Audi A3 2023", "Audi A4 allroad 2023", "Audi Q3 2023", "Audi Q4 e-tron", "Audi Q8", "Audi R8", "Audi e-tron 2023", "BMW 3-Series 2023", "BMW 4-Series 2023"};
int price[] = {39650, 34900, 45900, 36800, 58200, 72800, 158600, 70800, 43800, 54900};
int stock[] = {3, 4, 2, 1, 3, 4, 1, 5, 3, 2};

typedef struct salesData{
    char carName[50];
    char customerName[50];
    int totalPrice;
    int discount;
    int buyingPrice;
}salesData;

int numberOfSales = 0;
#define capacityOfSales 50
salesData sales[capacityOfSales];

int getCarIndex(char names[][50], int nCars, const char* name) {
    int i;
    for(i=0; i<nCars; i++) {
        if (!strcmp(names[i], name))
            return i;

    }
    return -1;
}

void Show_menu() {

  printf("\n|==========================================================================|\n");
  printf("-------------------------------------MENU-----------------------------------\n");
  printf("|==========================================================================|\n");
  printf("|                                                                          |\n");
  printf("|\t1.Buy car \t\t\t\t\t\t\t   |\n|\t2.View Car Stocks \t\t\t\t\t\t   |\n|\t3.View Car Sales Data \t\t\t\t\t\t   |\n|\t4. Address and Info\t\t\t\t\t\t   |\n|\t0.Exit\t\t\t\t\t\t\t\t   |\n");
    printf("|                                                                          |\n");
  printf("|==========================================================================|\n");
}

void Menu_greet(){
  // welcomes user to website
  printf("---------------------WELCOME TO KISOMBE KARs'SALES!!!-----------------------");
}

void clearScreen(){
    //clears screen, this avoids disarrange
    system("cls");
}

void pauseScreen() {
    // pauses the screen
    system("pause");
}

salesData getUserDetails() {
    int isRunning = 1;
    int choiceCar, discount = 0, age, option;
    char name[50], email[50], phoneNumber[12], accountNumber[50];
    salesData s;

    printf("\nAvailable Cars in the Stock are:\n");
    for(int i=0; i<numberOfCars; i++) {
        printf("\t%d.  %s  ->  Price: $%d\n", i+1, carNames[i], price[i]);
    }

    do{
        printf("Enter the Car number you want to Buy: ");
        scanf("\n%d", &choiceCar);

        if(choiceCar > 0 && choiceCar <= numberOfCars) {
            isRunning = 0;
            choiceCar--;
            break;
        } else {
            printf("Invalid entry, try again:\n ");
        }
    } while (isRunning);

    printf("\nEnter your name: ");
    scanf("%s", name);

    isRunning = 1;
    while(isRunning) {
        printf("\nEnter your age: ");
        scanf("%d", &age);

        if(age < 18) {
            printf("Invalid entry, try again:\n ");
        } else {
            isRunning = 0;
        }
    }

    printf("\nSelected Car: %s\n", carNames[choiceCar]);
    printf("Price of Car: $%d\n", price[choiceCar]);

    if(age >= 18 && age <= 25)
        discount = price[choiceCar]*0.1;
    else if(age > 65)
        discount = price[choiceCar]*0.2;

    printf("Discount: $%d\n", discount);
    printf("-----------------------\n");
    printf("Total Amount: $%d\n\n", price[choiceCar]-discount);

    isRunning = 1;

    while(isRunning) {
        printf("Press 1. To continue \n");
        printf("Press 2.To Return to previous Menu\n\n");

        printf("Enter your choice: ");
        scanf("\n%d", &option);

        if(option != 1 && option != 2) {
            printf("Invalid entry, try again:\n ");
        } else {
            isRunning = 0;
        }
    }
    s.totalPrice = 0;
    if(option == 2)
        return s;

    strcpy(s.customerName, name);
    s.totalPrice = price[choiceCar];
    strcpy(s.carName,  carNames[choiceCar]);
    s.discount = discount;
    s.buyingPrice = price[choiceCar]-discount;

    printf("\nEnter your Email: ");
    scanf("%s", email);
    printf("\nEnter your Phone number: ");
    scanf("%s", phoneNumber);
    printf("\nEnter your Bank Account Number: ");
    scanf("%s", accountNumber);

    printf("\nCongratulations! You have successfully bought a New Car!\nEnjoy your Ride.\n\n");

    stock[choiceCar]--;

    if(stock[choiceCar] == 0) {
        for(int i=choiceCar; i<numberOfCars-1; i++)
        {
            strcpy(carNames[i], carNames[i+1]);
            stock[i] = stock[i+1];
            price[i] = price[i+1];
        }
        numberOfCars--;
    }

    return s;
}

void BuyCar(){
    int isRunning = 1; //true
    char buyUserChoice;
    salesData data;
    clearScreen();
    printf("\n|===========================================================|\n");
    printf("----------------------------BUY CAR-------------------------\n");
    printf("|===========================================================|\n\n");
    do {
        printf("Press 1. To continue: \n");
        printf("Press 2.To Reurn to Home Menu\n\n");
        scanf("\n%c", &buyUserChoice);
        switch(buyUserChoice){ 
            case '1':
                //add fuction to get user details
                data = getUserDetails();
                //add to totalSalesqq
                if(data.totalPrice == 0)
                    break;
                sales[numberOfSales] = data;
                numberOfSales++;
                pauseScreen();
                clearScreen();
                break;
            
            case '2':
                printf("2. To Return To Main Menu: \n");
                isRunning = 0; //false
                break;
                
            default:
               printf("Invaild entry, try again:\n ");
               break;
            }
    } while (isRunning);
}

void bubbleSortStock() {
    // loop to access each array element
    for (int step = 0; step < numberOfCars - 1; ++step) {

        // loop to compare array elements
        for (int i = 0; i < numberOfCars - step - 1; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (stock[i] < stock[i + 1]) {

                // swapping occurs if elements
                // are not in the intended order
                int temp = stock[i];
                stock[i] = stock[i + 1];
                stock[i + 1] = temp;

                temp = price[i];
                price[i] = price[i + 1];
                price[i + 1] = temp;

                char tempName[50];
                strcpy(tempName, carNames[i]);
                strcpy(carNames[i], carNames[i+1]);
                strcpy(carNames[i+1], tempName);

            }
        }
    }
}

void View_Car_Stocks(){
    int isRunning = 1; //true
    char buyUserChoice;
    bubbleSortStock();
    clearScreen();
  printf("\n|===========================================================|\n");
  printf("-------------------------VIEW CAR STOCKS-----------------------\n");
  printf("|===========================================================|\n\n");
     do {
        printf("Press 1. To continue: \n");
        printf("Press 2.To Reurn to Home Menu\n\n");
        scanf("\n%c", &buyUserChoice);
        switch(buyUserChoice){ 
            case '1':
                printf("\nAvailable Cars in the Stock are:\n");
                for(int i=0; i<numberOfCars; i++) {
                    printf("\t%d.  %s  ->  Price: $%d\tIn Stock: %d\n", i+1, carNames[i], price[i], stock[i]);
                }
                printf("\n");
                pauseScreen();
                clearScreen();
                break;
            
            case '2':
                printf("2. To Return To Main Menu: \n");
                isRunning = 0; //false
                break;
                
            default:
               printf("Invaild entry, try again:\n ");
               break;
            }
    } while (isRunning);
  
  
  }
void BubbleSortSold(char carName[][50], int nCars, int prices[]) {
    // loop to access each array element
    for (int step = 0; step < numberOfCars - 1; ++step) {

        // loop to compare array elements
        for (int i = 0; i < numberOfCars - step - 1; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (prices[i] < prices[i + 1]) {

                // swapping occurs if elements
                // are not in the intended order
                int temp = prices[i];
                prices[i] = prices[i + 1];
                prices[i + 1] = temp;

                char tempName[50];
                strcpy(tempName, carName[i]);
                strcpy(carName[i], carName[i+1]);
                strcpy(carName[i+1], tempName);

            }
        }
    }
}
void Car_SalesData(){
    int isRunning = 1; //true
    char buyUserChoice;
    char soldCars[MAXCARS][50], tempName[50];
    int nCars = 0, index;
    int totalPrice[MAXCARS];

    for(int i=0; i<MAXCARS; i++)
        totalPrice[i] = 0;
    clearScreen();
  printf("\n|===========================================================|\n");
  printf("--------------------------CAR DATA-------------------------\n");
  printf("|===========================================================|\n\n");
    do {
        printf("Press 1. To continue: \n");
        printf("Press 2.To Reurn to Home Menu\n\n");
        scanf("\n%c", &buyUserChoice);
        switch(buyUserChoice){ 
            case '1':
                for(int i=0; i<numberOfSales; i++) {
                    strcpy(tempName, sales[i].carName);
                    index = getCarIndex(soldCars, nCars, tempName);
                    if(index == -1)
                    {
                        index = nCars;
                        nCars++;

                    }

                    strcpy(soldCars[index], sales[i].carName);
                    totalPrice[index] += sales->buyingPrice;

                    printf("%d.  %s bought %s\n", i+1, sales[i].customerName, sales[i].carName);
                    printf("Original Price: $%d,  Discount: $%d\n", sales[i].totalPrice, sales[i].discount);
                    printf("Final Amount Paid: $%d\n\n", sales[i].buyingPrice);
                }

                printf("Cars Models Sold with total Sales.\n");
                BubbleSortSold(soldCars, nCars, totalPrice);
                for(int i=0; i<nCars; i++) {
                    printf("\t%s  -> Sales: $%d\n", soldCars[i], totalPrice[i]);
                }
                printf("\n");
                pauseScreen();
                clearScreen();
                break;
            
            case '2':
                printf("2. To Return To Main Menu:\n");
                isRunning = 0; //false
                break;
                
            default:
               printf("Invaild entry, try again:\n ");
               break;
            }
    } while (isRunning);
  }


void Address_And_Info(){
  printf("\n|===========================================================|\n");
  printf("----------------------ADDRESS AND INFO-------------------------\n");
  printf("|===========================================================|\n\n");
  //I have added the address of where my car sale is located
  printf("\n\n\nWe are located at CB5 8HB Newmarket Road\n\n");
  printf("Welcome to Kisombe Kars, your go-to destination for all your automotive needs. We offer an extensive inventory of new and used cars from top brands, as well as professional car maintenance and repair services. Our team of experienced professionals is dedicated to providing you with exceptional customer service and helping you find the perfect car that fits your needs and budget. We also offer hassle-free car buying and selling options, with competitive prices and flexible financing solutions.");
  printf("\n\nAt Kisombe Kars, we believe that everyone deserves to have a reliable and safe car. That's why we offer affordable prices and flexible financing options that make it easier for you to get the car you need.");
  printf("\n\nThank you for considering Kisombe Kars for your automotive needs. We look forward to serving you and helping you find your dream car.");
  }

void writeSalesToFile() {
    FILE* file;
    file = fopen("Sales.txt", "w");

    fprintf(file, "%d\n", numberOfSales);

    for(int i=0; i<numberOfSales; i++) {
        fprintf(file, "%s\n", sales[i].carName);
        fprintf(file, "%s\n", sales[i].customerName);
        fprintf(file, "%d %d %d\n", sales[i].totalPrice, sales[i].discount, sales[i].buyingPrice);
    }

    fclose(file);
}

void readSalesFromFile() {
    FILE* file;
    file = fopen("Sales.txt", "r");

    if(file == NULL)
        return;

    fscanf(file, "%d\n", &numberOfSales);

    for(int i=0; i<numberOfSales; i++) {
        fgets(sales[i].carName, 50, file);
        sales[i].carName[strcspn(sales[i].carName, "\n")] = 0;
        fgets(sales[i].customerName, 50, file);
        sales[i].customerName[strcspn(sales[i].customerName, "\n")] = 0;
        fscanf(file, "%d %d %d", &sales[i].totalPrice, &sales[i].discount, &sales[i].buyingPrice);
        while(fgetc(file) != '\n');
    }

    fclose(file);
}

int main(){

  char choice;
  int back;
    readSalesFromFile();
  do {
    Menu_greet();
    Show_menu();
    printf("\nEnter Your Choice: ");
    scanf("\n%c", &choice);

    switch(choice) {
      case '1':
        clearScreen();
        BuyCar();
        break;

      case '2':
        clearScreen();
        View_Car_Stocks(); //use this within the buycar function
        break;

      case '3':
        clearScreen();
        Car_SalesData();
        break;

      case '4':
        do {
            clearScreen();
            Address_And_Info();
            printf("\n\nPress 0. To return to menu:\n\n ");
            scanf("%d", &back);
        } while(back!=0);
        clearScreen();
         break;

      case '0':
       clearScreen();
       printf("\nThanks for visiting our website ;)\n ");
       choice = 0;
       break;

      default:
        clearScreen();
        printf("Invalid Entry, Try again:\n\n ");
        break;
        }

    } while (choice!=0);

  writeSalesToFile();

    return 0;
}


