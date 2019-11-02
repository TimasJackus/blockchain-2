#include <sstream>
#include <chrono>
#include <iomanip>
#include <iostream>
#include "./hash.h"
#include "./user.h"

User::User(int id, std::string name, double balance) {
    this->id = id;
    this->name = name;
    this->balance = balance;
    this->publicKey = this->generatePublicKey(id, name);
}

std::string User::generatePublicKey(int id, std::string name) {
    unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::stringstream strm;
    strm << id << name << now;
    return hash(strm.str());
}

double User::getBalance() {
    return this->balance;
}

void User::increaseBalance(double amount) {
    this->balance = this->balance + amount;
}

void User::decreaseBalance(double amount) {
    this->balance = this->balance - amount;
}