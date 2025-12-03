#include <stdio.h>

// Function to encrypt text
void encrypt(char text[], int key) {
    for(int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // For lowercase letters
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key) % 26 + 'a';
        }
        // For uppercase letters
        else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key) % 26 + 'A';
        }

        text[i] = ch; // store back
    }
}

// Function to decrypt text
void decrypt(char text[], int key) {
    for(int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // For lowercase letters
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        }
        // For uppercase letters
        else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        }

        text[i] = ch; // store back
    }
}

int main() {
    char text[100];
    int key, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        encrypt(text, key);
        printf("Encrypted text: %s\n", text);
    }
    else if(choice == 2) {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}