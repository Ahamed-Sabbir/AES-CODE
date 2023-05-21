The implementation of the Advanced Encryption Standard - Encryption is coded in C++ language with vector data structure.. It takes plaintext from the user as a 4 x 4 state matrix and a key as a 4 x 4 matrix. Then it outputs the ciphertext as a 4 x 4 matrix. The values within the matrix are hexadecimal values.
It contains 4 Major functionalities. There are:
Add Round Key
Substitute Bytes
Shift Rows
Mix Columns
It also contains “Key Expansion” functionality to expand the key. 
There are some tables called “Recon Table”, “S-Box”, “Mix-Column Table”. They are implemented here with predefined values.
There are some supportive functions such as hexadecimal to decimal value converter, decimal to hexadecimal converter, hexadecimal value and a multiplication over the finite field GF(28).
