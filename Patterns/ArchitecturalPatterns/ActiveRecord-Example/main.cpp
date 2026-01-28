#include <iostream>

#include "ActiveRecord.h"

/*
 *
 * Active Record — это архитектурный паттерн, при котором объект содержит как данные, так и методы для работы с ними (CRUD операции). Каждый
 * объект соответствует строке в таблице БД.
 *
 */

int main()
{
    {
        UserActiveRecord user(1, "Alex", "alex@www.com");
        user.setName("Erzhan");
        user.save();

        std::cout << "id: " << user.getId() << ", name = " << user.getName() << ", email: " << user.getEmail() << "\n";
    }

    return 0;
}
