#include <iostream>
#include <string.h>
#include <fstream>
#include <bitset>
#include <sstream>
#include <time.h>

const int HASH_LENGTH = 64;

long getCharsSum(std::string str) {
    long sum = 0;
    int x = 0;
    for(int i = 0; i < str.length(); i++) {
        sum += int(str[i]) * (i + 3);
        x = (i + 7) * int(str[i]);
    }
    sum = sum * 1337 * (64 % str.length() + int(str[0])) + x;
    return sum;
}

std::string bitsetToHex(std::bitset<HASH_LENGTH> bs[4]) {
    std::string hashStr = "";
    for(int i = 0; i < 4; i++) {
        std::string str;
        std::stringstream ss;
        ss << std::hex << bs[i].to_ulong();
        ss >> str;
        str = std::string((HASH_LENGTH / 4) - str.length(), '0').append(str);
        hashStr.append(str);
    }
    return hashStr;
}

std::string HexToBin(std::string hexdec)
{
    long int i = 0;
    std::string binStr = "";

    while (hexdec[i]) {
        switch (hexdec[i]) {
            case '0':
                binStr += "0000";
                break;
            case '1':
                binStr += "0001";
                break;
            case '2':
                binStr += "0010";
                break;
            case '3':
                binStr += "0011";
                break;
            case '4':
                binStr += "0100";
                break;
            case '5':
                binStr += "0101";
                break;
            case '6':
                binStr += "0110";
                break;
            case '7':
                binStr += "0111";
                break;
            case '8':
                binStr += "1000";
                break;
            case '9':
                binStr += "1001";
                break;
            case 'a':
                binStr += "1010";
                break;
            case 'b':
                binStr += "1011";
                break;
            case 'c':
                binStr += "1100";
                break;
            case 'd':
                binStr += "1101";
                break;
            case 'e':
                binStr += "1110";
                break;
            case 'f':
                binStr += "1111";
                break;
            default:
                break;
        }
        i++;
    }
    return binStr;
}

std::string hash(std::string input) {
    std::bitset<HASH_LENGTH> bs[4];
    for(int i = 0; i < 4; i++) {
        bs[i] = std::bitset<HASH_LENGTH>{}.set();
    }

    long charsSum = getCharsSum(input);
    for(int i = 0; i < 4; i++) {
        long val = charsSum * (i + 3);
        while (val >= HASH_LENGTH) {
            int index = val % HASH_LENGTH;
            val = val / 1.2;
            bs[i] = bs[i].test(index) == 1 ? bs[i].reset(index) : bs[i].set(index);
            if (index % 3 == 0) {
                bs[i].flip();
            }
        }
    }

    return bitsetToHex(bs);
}

double measureTime(std::string filename) {
    std::ifstream inFile;
    inFile.open(filename);
    std::string input;
    double timeElapsed = 0;

    while (getline(inFile, input)) {
        clock_t tStart = clock();
        hash(input);
        timeElapsed += (double)(clock() - tStart)/CLOCKS_PER_SEC;
    }
    inFile.close();
    return timeElapsed;
}