// Vincent Phillip Rodriguez CPSC120-19

#include <iostream>
#include <iomanip>
using namespace std;

//Declare const variable for maximum tries to enter PIN correctly
const int MAXIMUM_TRIES = 3;


int main (int argc, char* argv[]) {
  //Check the correct amount of arguments.
  if (argc != 3) {
    cout << "Usage: ./atm <Personal 4 Digit PIN> <AccountBalance>\n";
    return 1;
  }

  //Store the user's PIN and Account Balance.
  string personal_pin = argv[1];
  float account_balance = stoi(argv[2]);

  //Check that the user entered entered a 4 digit PIN.
  if (personal_pin.length() != 4) {
    cout << "ERROR!\nPlease enter a FOUR digit PIN.\n";
    return 1;
  }

  //Welcome Message
  cout << "Welcome to branch #120 at CPSC Bank!\n";

/******************************************************************************/
//PIN CHECK
/******************************************************************************/
  int attempts = 0,
      amount_of_tries_left = 2;

  do {
    string pin_input;

    //Prompt user to enter correct PIN.
    cout << "Please enter your PIN: ";
    cin >> pin_input;

    if (pin_input == personal_pin) {
      //Exits the do-while loop when the user enters the correct PIN.
      attempts = 3;

    } else if (attempts < 2) {
      //Prints out how many tries the user has left to enter the correct PIN.
      cout << "Sorry, that was the wrong pin. You have " << amount_of_tries_left << " tries left.\n";
      amount_of_tries_left = amount_of_tries_left - 1;
      attempts += 1;

    } else if (attempts >= 2) {
      //Exit the program when the user enters the wrong PIN THREE times.
      cout << "Sorry, that was the wrong pin.\n";
      cout << "You have reached the maximum amount of attempts. You may try again later.\n";
      return 1;
    }
  } while (attempts < MAXIMUM_TRIES);

/******************************************************************************/
//MAIN MENU
/******************************************************************************/
  int user_choice;

  float deposit_amount,
        withdraw_amount;

  string  new_withdrawal_amount_decision,
          new_pin,
          new_pin_check,
          pin_input;

  cout << "What would you like to do today?\n";

  do {
    /*Sets decimal precision to show account balance when there is a zero in the
    last decimal place. For example: $100.00, $5.90, $20.50, etc.*/
    cout << fixed << setprecision(2);

    //Menu interface------------------------------------------------------------
    cout << "1 - Check balance\n";
    cout << "2 - Deposit cash\n";
    cout << "3 - Withdraw cash\n";
    cout << "4 - Reset PIN\n";
    cout << "5 - Exit\n";
    cout << ": ";
    cin >> user_choice;

    /*CHECK ACCOUNT BALANCE---------------------------------------------------*/
    if (user_choice == 1) {
      //Output the user's account balance.
      cout << "Account Balance : $" << account_balance << endl;
      cout << "\nWhat would you like to do next?\n";

    /*MAKE A DEPOSIT----------------------------------------------------------*/
    } else if (user_choice == 2) {
      //Prompts user to enter the amount that they want to deposit.
      cout << "Enter amount to deposit: ";
      cin >> deposit_amount;

      //Add the amount they want to deposit to the account balance.
      account_balance = account_balance + deposit_amount;

      //Outputs the new account balance after the deposit has been made.
      cout << "Thank you! Your account now has a balance of $" << account_balance << endl;
      cout << "\nWhat would you like to do next?\n";

    /*MAKE A WITHDRAWAL-------------------------------------------------------*/
    } else if (user_choice == 3) {
      //Prompts user to enter the amount that they want to withdraw.
      cout << "Enter amount to withdraw: ";
      cin >> withdraw_amount;

      //Check that the user entered an appropriate withdrawal amount.
      if (withdraw_amount > account_balance) {
        //Lets the user know that they do not have enough money in the account
        //to complete the withdrawal.
        cout << "Insufficient funds.\n";

        //Provides the user the option to withdraw the balance instead.
        cout << "Would you like to withdraw $" << account_balance << " instead? (y/n): ";
        cin >> new_withdrawal_amount_decision;

        //Withdraws the account balance and prints the new account balance.
        if (new_withdrawal_amount_decision == "y") {
          account_balance = account_balance - account_balance;
          cout << "Thank you! Your account now has a balance of $" << account_balance << endl;
        }
      } else {
        //If the user entered an appropriate amount to withdraw, withdraws that
        //amount from the account balance and prints out the new account balance.
        account_balance = account_balance - withdraw_amount;
        cout << "Thank you! Your account now has a balance of $" << account_balance << endl;
      }
      cout << "\nWhat would you like to do next?\n";

    /*RESET PIN---------------------------------------------------------------*/
    } else if (user_choice == 4) {

      //For security purposes, prompts the user to enter the old PIN. Exits the
      //program when the user fails to input the correct PIN after three attempts.

      attempts = 0,
      amount_of_tries_left = 2;

      do {

        //Prompt user to enter correct PIN.
        cout << "Please enter your PIN: ";
        cin >> pin_input;

        if (pin_input == personal_pin) {
          //Exits the do-while loop when the user enters the correct PIN.
          attempts = 3;

        } else if (attempts < 2) {
          //Prints out how many tries the user has left to enter the correct PIN.
          cout << "Sorry, that was the wrong pin. You have " << amount_of_tries_left << " tries left.\n";
          amount_of_tries_left = amount_of_tries_left - 1;
          attempts += 1;

        } else if (attempts >= 2) {
          //Exit the program when the user enters the wrong PIN THREE times.
          cout << "Sorry, that was the wrong pin.\n";
          cout << "You have reached the maximum amount of attempts. You may try again later.\n";
          return 1;
        }
      } while (attempts < MAXIMUM_TRIES);

      //Prompt the user for their new PIN.
      cout << "Please enter your new PIN: ";
      cin >> new_pin;

      //Makes the user aware that a PIN change is being made. Prompts them to
      //re-enter their new PIN as a confirmation for the PIN change.
      attempts = 0,
      amount_of_tries_left = 2;

      do {
        //Prompt user to re-enter their new PIN.
        cout << "Re-enter your new PIN: ";
        cin >> new_pin_check;

        if (new_pin_check == new_pin) {
          //Exits the do-while loop when the user enters the new PIN correctly.
          attempts = 3;

        } else if (attempts < 2) {
          //Prints out how many tries the user has left to re-enter the new PIN.
          cout << "Sorry, that was the wrong pin. You have " << amount_of_tries_left << " tries left.\n";
          amount_of_tries_left = amount_of_tries_left - 1;
          attempts += 1;

        } else if (attempts >= 2) {
          //Exit the program when the user enters the new PIN incorrectly THREE
          //times.
          cout << "Sorry, that was the wrong pin.\n";
          cout << "You have reached the maximum amount of attempts. You may try again later.\n";
          return 1;
        }
      } while (attempts < MAXIMUM_TRIES);

      //Let's the user know that the PIN change was a success.
      cout << "\nYour PIN has been successfully changed!\n";

      cout << "\nWhat would you like to do next?\n";

    /*EXIT--------------------------------------------------------------------*/
    } else if (user_choice == 5) {
      cout << "Thank you for using CPSC Bank. Have a great day!\n";
    }

    //Allows the user to make multiple transactions until they decide to exit.
  } while (user_choice != 5);

  return 0;
}
