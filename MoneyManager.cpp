
#include <iostream>
#include <string>
#include <fstream>

/*
Create a loading phase that allows for the selection of creating a new file, updating a file, or proceeding with the already written file
*/
void startup();
int selectionScreen();
void printSelection(int choice);
std::ofstream outputFile;
std::ifstream inputFile;
void createNewAccount();
void readAccount();
void printInfo();
void printOutro();
void updateAccount();
 

double hourlyRate = 0;
double monthlyHours = 0;
double taxRate = 0;
double monthlyExpenses = 0;

int main()
{
    int choice;
    startup();
    choice = selectionScreen();
    if (choice == 4) {
        return 0;
    }
    
    printOutro();
    return 0;
}

void startup() {
    std::cout << '\n' << "\t\t\t\t" << "Welcome to V O I D 's Money Manager!" << '\n';
    std::cout << '\n' << '\t' << "You will be able to calculate how much money you will have left over per month";
    std::cout << '\n';
}

int selectionScreen() {
    int choice;
    std::cout << '\n';
    std::cout << '\t' << "Please make a selection: " << '\n';
    std::cout << '\t' << "1: Create a new account" << '\n';
    std::cout << '\t' << "2: Update an account" << '\n';
    std::cout << '\t' << "3: Continue with previous account" << '\n';
    std::cout << '\t' << "4: Exit Program" << "\n";
    std::cout << '\t' << "Choice: ";
    std::cin >> choice;
    std::cout << '\n';
    std::cout << '\t';

    printSelection(choice);
    switch (choice)
    {
    case 1:
        createNewAccount();
        printInfo();
        break;
    case 2:
        updateAccount();
        printInfo();
        break;
    case 3:
        readAccount();
        printInfo();
        break;
    case 4:
        return 4;
    }
   



    return 0;
}

void printSelection(int choice) {
    switch (choice)
    {
    case 1:
        std::cout << "You have chosen to create a new account" << '\n';
        break;
    case 2:
        std::cout << "You have chosen to update an existing account" << '\n';
        break;
    case 3:
        std::cout << "You have chosen to proceed with a previously saved account " << '\n';
        break;

    case 4:
        std::cout << "You have chosen to Exit the program" << '\n';
        break;
    }

}


void createNewAccount() {
     hourlyRate = 0;
     monthlyHours = 0;
     taxRate = 0;
     monthlyExpenses = 0;
    
    std::cout << '\n' << '\t' << "Enter the following information:" << '\n';
    std::cout << "Hourly income rate: ";
    std::cin >> hourlyRate;
    std::cout << "Hours worked per month: ";
    std::cin >> monthlyHours;
    std::cout << "Estimated tax rate: ";
    std::cin >> taxRate;
    std::cout << "Total Monthly expenses: ";
    std::cin >> monthlyExpenses;
    outputFile.open("accountInfo.txt");
    

    
    if (outputFile.is_open()) {
        outputFile << hourlyRate << "\n";
        outputFile << monthlyHours << "\n";
        outputFile << taxRate << "\n";
        outputFile << monthlyExpenses << "\n";
        outputFile.close();
    }
    else {
        std::cout << '\n' << "!!!Error occurred in opening the file!!!";
    }


}

void readAccount() {
    inputFile.open("accountInfo.txt");
    std::string line;
    if (inputFile.is_open()) {
        std::getline(inputFile, line);
        hourlyRate = std::stod(line);
        std::getline(inputFile, line);
        monthlyHours = std::stod(line);
        std::getline(inputFile, line);
        taxRate = std::stod(line);
        std::getline(inputFile, line);
        monthlyExpenses = std::stod(line);


            
    }
    else {
        std::cout << '\n' << "!!!Error occurred in opening the file!!!";
    }
}

void printInfo() {
    std::cout << '\n' << '\t' << " Your hourly rate is: " << hourlyRate;
    std::cout << '\n' << '\t' << " Your total hours worked per month is: " << monthlyHours;
    std::cout << '\n' << '\t' << " Your tax rate is: " << taxRate;
    std::cout << '\n' << '\t' << " Your monthly expenses are: " << monthlyExpenses;
    std::cout << '\n' << '\t' << " Your total income for the month is: " << hourlyRate * monthlyHours * taxRate;
    std::cout << '\n' << '\t' << " After paying your monthly expenses, you will be left with: $" << (hourlyRate * monthlyHours * taxRate) - monthlyExpenses;
    std::cout << '\n';
}

void updateAccount() {
    readAccount();
    printInfo();
    std::cout << '\n' << '\t' << "Set your new hourly rate: ";
    std::cin >> hourlyRate;
    std::cout << '\n' << '\t' << "Set your new hours per month: ";
    std::cin >> monthlyHours;
    std::cout << '\n' << '\t' << "Set your new tax rate: ";
    std::cin >> taxRate;
    std::cout << '\n' << '\t' << "Set your new monthly expenses: ";
    std::cin >> monthlyExpenses;
    outputFile.open("accountInfo.txt");



    if (outputFile.is_open()) {
        outputFile << hourlyRate << "\n";
        outputFile << monthlyHours << "\n";
        outputFile << taxRate << "\n";
        outputFile << monthlyExpenses << "\n";
        outputFile.close();
    }
    else {
        std::cout << '\n' << "!!!Error occurred in opening the file!!!";
    }
}

void printOutro() {
    int temp;
    std::cout << "\n" << "\t\t\t\t" << "E N D  O F  P R O G R A M ";
    std::cin >> temp;
}