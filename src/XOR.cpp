/*
 * @author Jorge Velazquez
 * @version 02/10/2026
 */
#include "../include/XOR.h"
#include <algorithm>
#include <map>
#include <random>
#include <vector>

unsigned char XOR::keyGenerator() {
  char character_val;
  std::random_device rd; // a seed for the random number engine
  std::mt19937 gen(
      rd()); // Seed the Mersenne Twister engine with the random_device, mt19937
             // is a high-quality pseudo-random number generator
  std::uniform_int_distribution<> distrib(
      0, 255); // Define the desired distribution, range from 0-255

  character_val = static_cast<unsigned char>(
      distrib(gen)); // Convert ASCII value to a character
  return character_val;
}

std::string printAsHex(const std::string &text);

void XOR::encryptString(std::string &text) {
  // call to generate a random key
  unsigned char cipherKey = keyGenerator();

  // apply XOR cipher using the randomly generated
  // this encrypts the text.
  for (char &e : text) {
    e = e ^ cipherKey;
  }

  // to later retreive the text we store it in a map with its key.
  auto &vec = stringStorage[cipherKey];
  if (std::find(vec.begin(), vec.end(), text) == vec.end()) {
    vec.push_back(text);
  }
}

bool XOR::decryptString(std::string &text) {

  // Loop through ALL possible keys (0-255)
  // We use int to avoid infinite loop issues with unsigned char
  for (int k = 0; k <= 255; ++k) {
    unsigned char currentKey = static_cast<unsigned char>(k);

    // Check if this key even exists in our map first
    auto mapIt = stringStorage.find(currentKey);
    if (mapIt == stringStorage.end()) {
      continue;
    }

    // Create a copy to test
    std::string tempString = text;

    // Encrypt the temporary string
    for (char &e : tempString) {
      e = e ^ currentKey;
    }

    // Check if this encrypted candidate is in the list
    const std::vector<std::string> &list = mapIt->second;
    auto vecIt = std::find(list.begin(), list.end(), tempString);

    if (vecIt != list.end()) {
      // Match found!
      return true;
    }
  }

  // No match found with any key

  return false;
}
