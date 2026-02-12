#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::string;


double balance;

void displayBalance(double balance);
double depositMoney(double deposit, double balance);
double withdrawMoney(double withdraw, double balance);
double readPositiveAmount(const char* prompt, double balance);

int main() {
  int choice;
  double balance=0;
  double amount = 0;

  do {
    cout << "\nThis is a banking application. Choose your action:\n";
    cout << "1. Display your balance\n";
    cout << "2. Deposit money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Exit\n";
    cout << "Choice: ";

    cin >> choice;

    switch (choice) {
    case 1:
      displayBalance(balance);
      break;
    case 2:
      amount = readPositiveAmount("\nEnter the deposit amount: ", balance);
      balance = depositMoney(amount, balance);
      displayBalance(balance);
      break;
    case 3:
      amount=readPositiveAmount("\nEnter the deposit amount: ", balance);
      balance = withdrawMoney(amount, balance);
      displayBalance(balance);
      break;
    case 4:
      break;
    default:
      cout << "Invalid choice. Choice number 1 to 4 \n";
    }
  } while (choice != 4);

  return 0;
};

void displayBalance(double balance) {
  cout << std::fixed << std::setprecision(2);
  cout << "Your balance is $" << balance << "\n";
};

double depositMoney(double deposit, double balance) {
  balance += deposit;
  cout << std::fixed << std::setprecision(2);
  cout << "You have deposited $" << deposit << " to your account\n";
  return balance;
};

double withdrawMoney(double withdraw, double balance) {
  balance -= withdraw;
  cout << std::fixed << std::setprecision(2);
  cout << "You have withdrawed $" << withdraw << " from your account\n";
  return balance;
};

double readPositiveAmount(const char *prompt, double balance) {
  double amount;

  while (true) {
    std::cout << prompt;
    if (cin >> amount && amount > 0) {
      return amount;
    }

    cout << "Invalid input. Enter positive number.\n";
    std::cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
};