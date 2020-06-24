# ISO8583 Cipher
ISO 8583 is an international standard for financial transaction card. 
It consists of 128 fields in order to exchange electronic transactions initiated by cardholders using payment cards.

Field 52 is Personal Identification Number(PIN). A PIN is a numeric or alpha-numeric password used in the process of authenticating a user accessing a system. In common usage, PINs are used in ATM or POS transactions.

Field 64 and 128 are Message Authentication Code (MAC). A MAC sometimes known as a tag, is a short piece of information used to authenticate a message—in other words, to confirm that the message came from the stated sender (its authenticity) and has not been changed. 

## Getting Started
The code uses the Data Encryption Standard (DES) which is a symmetric-key algorithm for the encryption of digital data.

## Prerequisites
Google Test is a unit testing library for the C++ programming language, based on the xUnit architecture. The project use [Google Test framework](https://github.com/google/googletest).

## Test
The project contains many tests in the test directory, used to drive development and ensure correctness. The tests are written using the Google Test framework. 

## Build Requirements
These are the base requirements to build and use Google Test:

* C++17-standard-compliant compiler
* Google Test
* CMake version 3 and above

## Build
You can build The project using CMake as following:

$ cmake -Bbuild -H.  
$ cd build
$ make  

## Running the tests
After the project was completely build, then

$ ./test/iso8583_cipher_test
