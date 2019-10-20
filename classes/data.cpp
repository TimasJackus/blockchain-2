#include <random>
#include "user.h"
#include "transaction.h"

const int USERS_COUNT = 1000;
const int TRANSACTIONS_COUNT = 10000;
std::random_device rd;
std::mt19937 eng(rd());

double getRandomDouble(int a, int b) {
    std::uniform_real_distribution<double> between(a, b);
    return between(eng);
}

int getRandomInt(int a, int b) {
    std::uniform_int_distribution<int> between(a, b);
    return between(eng);
}

int getRandomIntNotEqualTo(int a, int b, int comparer) {
    std::uniform_int_distribution<int> between(a, b);
    int randomNumber = between(eng);
    if (randomNumber == comparer) {
        return getRandomIntNotEqualTo(a, b, comparer);
    }
    return randomNumber;
}

std::vector<User> generateUsers() {
    std::vector<User> users;
    for (int i = 0; i < USERS_COUNT; i++) {
        std::string name = "Name" + std::to_string(i);
        double balance = getRandomDouble(10, 1000000);
        User user = User(i, name, balance);
        users.push_back(user);
    }
    return users;
}

std::vector<Transaction> generateTransactions() {
    std::vector<Transaction> transactions;
    for (int i = 0; i < TRANSACTIONS_COUNT; i++) {
        double amount = getRandomDouble(0, 500);
        int senderId = getRandomInt(0, USERS_COUNT - 1);
        int recipientId = getRandomIntNotEqualTo(0, USERS_COUNT - 1, senderId);
        Transaction transaction = Transaction(senderId, recipientId, amount);
        transactions.push_back(transaction);
    }
    return transactions;
}