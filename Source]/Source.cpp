#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(const string& message, const string& key) {
    string encryptedMessage = message;
    for (char& c : encryptedMessage) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = key[c - base];
        }
    }
    return encryptedMessage;
}

string decrypt(const string& encryptedMessage, const string& key) {
    string decryptedMessage = encryptedMessage;
    for (char& c : decryptedMessage) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = 'A' + distance(key.begin(), find(key.begin(), key.end(), c));
        }
    }
    return decryptedMessage;
}

int main() {
    string key = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    char choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Encrypt a message" << endl;
        cout << "2. Decrypt a message" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string message;
        switch (choice) {
        case '1':
            cout << "Enter the message to encrypt: ";
            getline(cin, message);
            cout << "Encrypted message: " << encrypt(message, key) << endl;
            break;
        case '2':
            cout << "Enter the message to decrypt: ";
            getline(cin, message);
            cout << "Decrypted message: " << decrypt(message, key) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> choice;
        cin.ignore();
        system("cls");
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
