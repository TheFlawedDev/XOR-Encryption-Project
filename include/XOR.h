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

  /**
   * @brief Takes in a string and turns it into Hex.
   *
   * @param string of encrypted values
   * @return a hex value
   */
  std::string printAsHex(const std::string &text);

public:
  /**
   * @brief Takes in a string and encrypts it with a key.
   *
   * @param string to be encrypted
   * @param character to used as encryption value
   * @return a string representation of the now encrypted string.
   */
  void encryptString(std::string &text);

  /**
   * @brief Turns an encrypted string back to its original form.
   *
   * @param an encrypted string.
   * @param the key to decrypt it.
   * @return the origninal strings form.
   */
  bool decryptString(std::string &text);
};
