
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
void createNewAccount(std::ofstream outputFile);
int main()
{
    int choice;
    startup();
    choice = selectionScreen();
    
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

    printSelection(choice);
    switch (choice)
    {
    case 1:
        createNewAccount(outputFile);
        break;
    case 2:
        //UpdateAccount();
        break;
    case 3:
        //Continue();
        break;
    case 4:
        return 1;
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


void createNewAccount(std::ofstream outputFile) {
    double hourlyRate = 0;
    double monthlyHours = 0;
    double taxRate = 0;
    double monthlyExpenses = 0;
    
    std::cout << '\n' << '\t' << "Enter the following information:" << '\n';
    std::cout << "Hourly income rate: ";
    std::cin >> hourlyRate;
    std::cout << "Hours worked per month: ";
    std::cin >> monthlyHours;
    std::cout << "Estimated tax rate: ";
    std::cin >> taxRate;
    std::cout << "Total Monthly expenses";
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
        std::cout << '\n' << "Error occurred in opening the file";
    }


}