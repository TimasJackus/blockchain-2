#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "transaction.h"
#include "./hash.h"

Transaction::Transaction(int senderId, int recipientId, double amount) {
    unsigned long int timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    this->id = this->generateHash(senderId, recipientId, amount, timestamp);
    this->senderId = senderId;
    this->recipientId = recipientId;
    this->amount = amount;
    this->timestamp = timestamp;
}

std::string Transaction::generateHash(int senderId, int recipientId, double amount, long int timestamp) {
    std::stringstream strm;
    strm << "S:" << senderId << "R:" << recipientId << "A:" << amount << "T:" << timestamp;
    return hash(strm.str());
}

std::string Transaction::generateHash() {
    std::stringstream strm;
    strm << "S:" << this->senderId << "R:" << this->recipientId << "A:" << this->amount << "T:" << this->timestamp;
    return hash(strm.str());
}

double Transaction::getAmount() {
    return this->amount;
}

int Transaction::getSenderId() {
    return this->senderId;
}

int Transaction::getRecipientId() {
    return this->recipientId;
}

std::string Transaction::getId() {
    return this->id;
}

void Transaction::setId(std::string id) {
    this->id = id;
}