# XOR-Cipher Text Encryption
>[!Warning]
> **Disclosure:**This program is part of an assignment project intended for educational use only, do not use this to secure your sensitive information.

## Installation & Usage
1. Clone this repository:
```bash
git clone https://github.com/TheFlawedDev/XOR-Encryption-Project.git
```

2. Navigate to the directory and build the project:
```bash
cd XOR-Encryption-Project
make mainTest
```

3. Run the program:
```bash
./mainTest
```

4. Clean up
To remove the executable and object file after you are done:
```bash
make clean
```

## Limitations
  The implementation of the XOR cipher in this tool uses a single unsigned char as a key. This introduces brute-force vulnerability, as the range of possible keys (0-255) can be tested fairly quickly to validate encrypted text. This is demonstrated in the program's *decryptString()* method, which iterates through every probable key to find a matching text. One other limitation is what is known as [Known Plaintext Attacks (KPA)](https://en.wikipedia.org/wiki/Known-plaintext_attack), where plaintext and the encrypted text can reveal the key, this allows attackers who have access to both to XOR them together and find the key.

## Ethical Implications & Utility
  My intention behind this project was to understand the functionality of XOR when used in encryption and to build a foundational, (weak) encryption tool. The tool uses a HEX format to show a visual representation of the encrypted text --this is because of the limitation in which binary can be represented as symbols in a terminal. This design choice brings up an ethical dilemma, it can give a sense of security --a non-technical user might assume the HEX output is not their original text and thus the text is "*secure*". But this is far from it, as stated in the "Limitations" section, the simplicity of the key allows attackers to easily brute-force the decryption.

## License

