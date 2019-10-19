#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "transaction.h"
#include "./hash.h"

Transaction::Transaction(int senderId, int recipientId, double amount) {
    this->hashValue = this->generateHash(senderId, recipientId, amount);
    this->senderId = senderId;
    this->recipientId = recipientId;
    this->amount = amount;
}

std::string Transaction::generateHash(int senderId, int recipientId, double amount) {
    unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::stringstream strm;
    strm << "S:" << senderId << "R:" << recipientId << "A:" << amount << "T:" << now;
    return hash(strm.str());
}

std::ostream& operator<<(std::ostream& os, Transaction const & transaction) {
    return os << "[" << transaction.hashValue << "] " << "S:" << transaction.senderId << " R:" << transaction.recipientId << " A:"  << std::fixed << std::setprecision(2) << transaction.amount << std::endl;
}