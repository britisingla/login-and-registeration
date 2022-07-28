#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char regrec[] = "regrecord.txt";

class reg
{

public:
    int NewReg(char *regrec)
    {
        string username;
        string password;
        string name;

        cout << "\n\n";
        cout << "----- Registeration -----" << endl;
        cout << "\n";

        cout << "Enter new username: ";
        cin >> username;
        cout << "Set a password: ";
        cin >> password;
        cout << "Enter name: ";
        cin >> name;

        ofstream file1;

        file1.open("loginuser.txt");

        file1 << username << endl;
        file1.close();

        ofstream file2;

        file2.open("loginpass.txt");

        file2 << password << endl;
        file2.close();

        ofstream file3;

        file3.open("loginname.txt");

        file3 << name << endl;
        file3.close();

        cout << "\n";
        cout << "You have registered successfully!" << endl;
        cout << "\n\n";
    }

    int Login()
    {
        string un;
        string pw;
        string username;
        string password;
        string name;

        cout << "\n\n";
        cout << "----- Login -----" << endl;
        cout << "\n";
        cout << "Enter username: ";
        cin >> un;

        cout << "Enter password: ";
        cin >> pw;

        ifstream file1;

        file1.open("loginuser.txt");
        getline(file1, username);

        ifstream file2;

        file2.open("loginpass.txt");
        getline(file2, password);

        ifstream file3;

        file3.open("loginname.txt");
        getline(file3, name);

        if (username == un && password == pw)
        {

            cout << "You have logged in successfully!" << endl;
            cout << "Welcome " << name << "!!!";
            cout << "\n\n";

            return 1;
        }

        else if (username != un && password == pw)
        {
            cout << "The username is incorrect!" << endl;
        }

        else if (username == un && password != pw)
        {
            cout << "The password is incorrect!" << endl;
        }
        else
        {
            cout << "Both the username and password are incorrect!" << endl;
        }
    }
};

int main()
{
    reg Obj;

    int choice = -1;

    while (choice != 0)
    {

        cout << "\nLogin and Registration";
        cout << "\n";
        cout << "\n1 - Register";
        cout << "\n2 - Login";
        cout << "\n0 - Exit.";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Obj.NewReg(regrec);
            break;
        case 2:
            Obj.Login();
            break;
        case 0:
            cout << "\nYou have exited the program. Thankyou!! Good Bye.\n ";
            cout << "\n";
            break;
        default:
            cout << "\nInvalid choice!";
            getchar();
        }
    }

    return 0;
}