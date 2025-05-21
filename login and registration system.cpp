#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;

public:
    void registerUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ofstream file(username + ".txt");
        if (file.is_open()) {
            file << username << endl;
            file << password << endl;
            file.close();
            cout << "Registration successful!" << endl;
        } else {
            cout << "Error creating file." << endl;
        }
    }

    void loginUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream file(username + ".txt");
        string storedUsername, storedPassword;
        if (file.is_open()) {
            getline(file, storedUsername);
            getline(file, storedPassword);
            file.close();

            if (storedUsername == username && storedPassword == password) {
                cout << "Login successful!" << endl;
            } else {
                cout << "Invalid credentials." << endl;
            }
        } else {
            cout << "No such user found." << endl;
        }
    }
};

int main() {
    User user;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user.registerUser();
                break;
            case 2:
                user.loginUser();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
