#pragma once

#include <string>

/*
 * DTO для класса User с минимальным количеством полей
 */
class UserDTO
{
public:
    // Конструкторы и деструктры для удобной и эффективной передачи объекта между слоями
    UserDTO();
    UserDTO(int id, const std::string& name, const std::string& email);
    UserDTO(int id, std::string&& name, std::string&& email);
    UserDTO(const UserDTO& other);
    UserDTO(UserDTO&& other) noexcept;
    UserDTO& operator=(const UserDTO& other);
    UserDTO& operator=(UserDTO&& other) noexcept;
    ~UserDTO();

    // Геттеры
    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;

    // Сеттеры
    void setId(int id);
    void setName(const std::string& name);
    void setEmail(const std::string& email);

    // Логики нет

private:
    int id_;
    std::string name_;
    std::string email_;

};
