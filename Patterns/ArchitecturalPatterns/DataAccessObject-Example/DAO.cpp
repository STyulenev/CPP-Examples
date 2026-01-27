#include "DAO.h"

void UserMemoryDAO::saveUser(const UserDTO &user)
{
    users_.push_back(user);
}

std::vector<UserDTO> UserMemoryDAO::getAllUsers() const
{
    return users_;
}

void UserDataBaseDAO::saveUser(const UserDTO &user)
{
    // INSERT INTO ...
}

std::vector<UserDTO> UserDataBaseDAO::getAllUsers() const
{
    std::vector<UserDTO> users;

    // SELECT * FROM ...

    users.emplace_back(1, "Ivan Ivanov", "ivanov@example.com");
    users.emplace_back(2, "Ivan Ivanov", "ivanov@example.com");

    return users;
}
