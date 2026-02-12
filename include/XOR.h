/*
 * @author Jorge Velazquez
 * @version 02/09/2026
 */

#pragma once
#include <iostream>
#include <map>
#include <vector>

/**
 * @class XOR
 * @brief Encrypts strings using a random key and bitwise XOR.
 */
class XOR {
private:
  /**
   * @brief Stores the encrypted string with its dedicated key.
   */
  std::map<unsigned char, std::vector<std::string>> stringStorage;

  /**
   * @brief Creates a character from 0-255.
   *
   * @return a random character
   */
  unsigned char keyGenerator();

  // Helper to convert raw bytes to Hex string
  std::string toHex(const std::string &text);

public:
  /**
   * @brief Takes in a string and encrypts it with a key.
   *
   * @param String to be encrypted
   * @param Character to used as encryption value
   * @return Returns the HEX representation of the encrypted string
   */
  std::string encryptString(std::string &text);

  /**
   * @brief Turns an encrypted string back to its original form.
   *
   * @param An encrypted string.
   * @param The key to decrypt it.
   * @return Returns the HEX representation of the found match (or "" if failed)
   */
  std::string decryptString(std::string &text);
};
