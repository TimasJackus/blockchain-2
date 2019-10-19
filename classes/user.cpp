#include <sstream>
#include <chrono>
#include "./hash.h"
#include "./user.h"

User::User(std::string name, double balance) {
    this->name = name;
    this->balance = balance;
    this->publicKey = this->generatePublicKey(name);
}

std::string User::generatePublicKey(std::string name) {
    unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::stringstream strm;
    strm << name << now;
    return hash(strm.str());
}

std::ostream& operator<<(std::ostream& os, User const & user) {
    return os << "[" << user.publicKey << "] " << user.balance << " " << user.name << std::endl;
}

