#include <iostream>

#include "DTO.h"

/*
 * Data Transfer Object (DTO) используется для передачи данных между слоями приложения или между системами. DTO обычно представляет
 * собой простой объект без бизнес-логики, содержащий только данные (поля) и, иногда, методы доступа (геттеры и сеттеры).
 *
 * Основная идея
 * - DTO служит контейнером для данных.
 * - Он не содержит бизнес-логики.
 * - Используется для передачи данных, например, между слоем данных и бизнес-слоем или по сети.
 */

int main()
{
    {
        SimpleUserDTO simpleUserDTO { .id_ = 0, .name_ = "Ivan Ivanov", .email_ = "ivanov@example.com" };
        std::cout << "id: " << simpleUserDTO.id_ << ", name = " << simpleUserDTO.name_ << ", email: " << simpleUserDTO.email_ << "\n";
    }

    {
        UserDTO userDTO(1, "Ivan Ivanov", "ivanov@example.com");

        std::cout << "id: " << userDTO.getId() << ", name = " << userDTO.getName() << ", email: " << userDTO.getEmail() << "\n";

        userDTO.setName("Ivan Petrov");
        std::cout << "New user name: " << userDTO.getName() << "\n";
    }

    return 0;
}
