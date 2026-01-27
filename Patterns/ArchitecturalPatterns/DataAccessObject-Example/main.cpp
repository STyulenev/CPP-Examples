#include <memory>
#include <iostream>

/*
 * В C++ паттерн Data Access Object (DAO) используется для абстрагирования доступа к данным (например, базе данных,
 * файлам или другим источникам). DAO инкапсулирует логику получения, сохранения и обновления данных, предоставляя простой
 * интерфейс для работы с ними. DAO может работать с DTO скрывая получение/вставку данных и добавляя логику.
 *
 */

#include "DAO.h"

int main()
{
    {
        std::unique_ptr<IUserDAO> userDAO = std::make_unique<UserMemoryDAO>();

        userDAO->saveUser(UserDTO {1, "Ivan Ivanov", "ivanov@example.com"});
        userDAO->saveUser(UserDTO {2, "Ivan Petrov", "petrov@example.com"});

        auto users = userDAO->getAllUsers();

        for (const auto& user : users)
        {
            std::cout << "id: " << user.getId() << ", name = " << user.getName() << ", email: " << user.getEmail() << "\n";
        }
    }

    {
        std::unique_ptr<IUserDAO> userDAO = std::make_unique<UserDataBaseDAO>();

        //userDAO->saveUser(UserDTO {1, "Ivan Ivanov", "ivanov@example.com"});
        //userDAO->saveUser(UserDTO {2, "Ivan Petrov", "petrov@example.com"});

        auto users = userDAO->getAllUsers();

        for (const auto& user : users)
        {
            std::cout << "id: " << user.getId() << ", name = " << user.getName() << ", email: " << user.getEmail() << "\n";
        }
    }

    return 0;
}
