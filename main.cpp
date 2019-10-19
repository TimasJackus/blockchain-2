#include <vector>
#include "classes/user.h"
#include "classes/transaction.h"
#include "classes/data.h"


int main() {
    std::vector<User> users = generateUsers();
    std::vector<Transaction> transactions = generateTransactions();
    return 0;
}