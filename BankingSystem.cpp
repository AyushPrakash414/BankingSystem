// Online C++ compiler to run C++ program online
// Functioning ATM that perform withdraw,deposite,transfer,blance
// check,search_account;
#include <iostream>
using namespace std;
int count = 0;
class atm {
public:
  int account_number;
  int adhaar_number;
  string name;
  int balance;
  long password;

  void make_account(void);
  int withdraw(atm arr[], int count);
  int deposite(atm arr[], int count);
  int search(atm arr[], int count);
  int transfer(atm arr[], int count);
  int balance_check(atm arr[], int count);
  void show_all_account(atm arr[], int count);
};

void atm::make_account(void) {
  count++;
  cout << "Enter your adhaar number:";
  cin >> adhaar_number;
  cout << "Enter your Name:";
  cin >> name;
  cout << "Enter your password:";
  cin >> password;
  cout << "Enter the Balance:";
  cin >> balance;
  account_number = rand() % 100000;
}

int atm::deposite(atm arr[], int count) {
  atm o;
  int x;
  cout << "Enter your account Number:";
  cin >> o.account_number;
  cout << "Enter your password:";
  cin >> o.password;
  cout << "Enter your Amount:";
  cin >> x;
  for (int i = 0; i < count; i++) {
    if (o.account_number == arr[i].account_number &&
        o.password == arr[i].password) {
      arr[i].balance += x;
      return (1);
    }
  }
  cout << "Either account number or password is wrong!!!";
  return (0);
}

int atm::withdraw(atm arr[], int count) {
  atm o;
  int x;
  cout << "Enter your account number:";
  cin >> o.account_number;
  cout << "Enter your password:";
  cin >> o.password;
  cout << "Enter the to withdraw:";
  cin >> x;
  for (int i = 0; i < count; i++) {
    if (o.account_number == arr[i].account_number &&
        o.password == arr[i].password) {
      arr[i].balance -= x;
      return (1);
    }
  }
  cout << "Either account number or password is wrong!!!";
  return (0);
}

int atm::balance_check(atm arr[], int count) {
  atm o;
  cout << "Enter your account number:";
  cin >> o.account_number;
  cout << "Enter your password:";
  cin >> o.password;
  for (int i = 0; i < count; i++) {
    if (o.account_number == arr[i].account_number &&
        o.password == arr[i].password) {
      cout << "----------------------------------" << endl;
      cout << "Your current Balance is:" << arr[i].balance << endl;
      cout << "----------------------------------";
      return (1);
    }
  }
  cout << "error--->try again!!";
  return 0;
}

int atm::transfer(atm arr[], int count) {
  atm o;
  int a, b;
  cout << "Enter your bank account number:";
  cin >> o.account_number;
  cout << "Enter the password:";
  cin >> o.password;
  cout << "Enter the bank account you want to transfer:";
  cin >> a;
  cout << "Enter your amount:";
  cin >> b;
  for (int i = 0; i < count; i++) {
    if (o.account_number == arr[i].account_number &&
        o.password == arr[i].password) {
      for (int j = 0; j < count; j++) {
        if (arr[j].account_number == a) {
          arr[j].balance += b;
          arr[i].balance -= b;
          return (1);
        }
      }
    }
  }
  cout << "!!!!Error!!!!----->Try Again.";
  return 0;
}

void atm::show_all_account(atm arr[], int count) {

  cout << "----------------------------------" << endl;
  cout << "Account number---Name---Balance" << endl;
  cout << "----------------------------------" << endl;
  for (int i = 0; i < count; i++) {
    cout << arr[i].account_number << "---" << arr[i].name << "---"
         << arr[i].balance << endl;
    cout << "----------------------------------" << endl;
  }
}

int atm::search(atm arr[], int count) {
  atm o;
  cout << "Enter the account number:";
  cin >> o.account_number;
  for (int i = 0; i < count; i++) {
    if (o.account_number == arr[i].account_number &&
        o.password == arr[i].password) {
      cout << "----------------------------------" << endl;
      cout << arr[i].account_number << "---" << arr[i].name << "---"
           << arr[i].balance << endl;
      cout << "----------------------------------" << endl;
      return 1;
    }
  }
  cout << "!!!!Error!!!!----->Try Again.";
  return 0;
}

int main() {
  atm arr[100];
  int x, i = 0;
  cout << "Ayush Prakash Banking System" << endl;
  cout << "----------------------------------" << endl;
  cout << "1.Make Account\n2.Show all Account\n3.Transfer Money\n4.Balance "
          "check\n5.Deposite\n6.withdraw\n7.serach account\n8.exit"
       << endl;
  cout << "----------------------------------" << endl;
  while (1) {
    cout << "Enter your choice:";
    cin >> x;
    if (x == 8) {
      exit(1);
    } else if (x == 1) {
      arr[i].make_account();
      i++;
    } else if (x == 2) {
      arr[i].show_all_account(arr, count);
    } else if (x == 3) {
      arr[i].transfer(arr, count);
    } else if (x == 4) {
      arr[i].balance_check(arr, count);
    } else if (x == 5) {
      arr[i].deposite(arr, count);
    } else if (x == 6) {
      arr[i].withdraw(arr, count);
    } else if (x == 7) {
      arr[i].search(arr, count);
    }
  }
  return 0;
}
