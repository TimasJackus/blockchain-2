#include <chrono>
#include <sstream>
#include <iostream>
#include "block_header.h"
#include "hash.h"

const int DIFFICULTY_TARGET = 3;

BlockHeader::BlockHeader() {
    this->version = 1;
    this->nonce = 1;
    this->difficultyTarget = DIFFICULTY_TARGET;
    this->timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

BlockHeader::BlockHeader(std::string prevBlockHash, std::string merkleRoot, int version, int nonce) {
    this->prevBlockHash = prevBlockHash;
    this->merkleRoot = merkleRoot;
    this->version = version;
    this->nonce = nonce;
    this->difficultyTarget = DIFFICULTY_TARGET;
    this->timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

std::string BlockHeader::generateHash() {
    std::stringstream strm;
    strm << this->prevBlockHash << this->merkleRoot << this->version << this->difficultyTarget << this->timestamp << this->nonce;
    return hash(strm.str());
}

int BlockHeader::getDifficultyTarget() {
    return this->difficultyTarget;
}

void BlockHeader::updateNonce(int nonce) {
    this->nonce = nonce;
}