#include "XOR.h"
#include <iostream>

int main() {
  XOR tool;
  char choice;
  std::string userInput;

  std::cout << "--- XOR ---" << std::endl;

  while (true) {
    std::cout << "\nMenu:\n 'y' to encrypt new text\n 'f' to find text\n 'e' "
                 "to exit\nSelection: ";
    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 'e') {
      break;
    } else if (choice == 'y') {
      std::cout << "Enter text to encrypt: ";
      std::getline(std::cin, userInput);

      // Encrypts in-place AND returns the hex string
      std::string hexOutput = tool.encryptString(userInput);

      std::cout << "Encrypted! Stored as Hex: " << hexOutput << std::endl;
    } else if (choice == 'f') {
      std::cout << "Enter original text to search for: ";
      std::getline(std::cin, userInput);

      // Attempt to find it
      std::string resultHex = tool.decryptString(userInput);

      if (resultHex != "") {
        std::cout << "Match Found! The encrypted version in the vault is: "
                  << resultHex << std::endl;
      } else {
        std::cout << "No match found in the vault." << std::endl;
      }
    }
  }

  std::cout << "Exiting vault..." << std::endl;
  return 0;
}
