#include <iostream>
#include <vector>
#include <string.h>
#include "classes/hash.h"
#include "classes/user.h"

std::vector<User> generateUsers(int count) {
    std::vector<User> users;
    for (int i = 1; i <= count; i++) {
        std::string name = "Name";
        double balance = 10;
        User user = User(name, balance);
        users.push_back(user);
    }
    return users;
}

int main() {
    std::vector<User> users = generateUsers(1000);
    return 0;
}
