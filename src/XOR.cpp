/*
 * @author Jorge Velazquez
 * @version 02/10/2026
 */
#include "../include/XOR.h"
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

std::string decryptString(std::string &text, unsigned char key);
