#include "DTO.h"

UserDTO::UserDTO()
{
    // ...
}

UserDTO::UserDTO(int id, const std::string& name, const std::string& email) :
    id_(id),
    name_(name),
    email_(email)
{
    // ...
}

UserDTO::UserDTO(int id, std::string&& name, std::string&& email) :
    id_(id),
    name_(std::move(name)),
    email_(std::move(email))
{
    // ...
}

UserDTO::UserDTO(const UserDTO &other) :
    id_(other.id_),
    name_(other.name_),
    email_(other.email_)
{
    // ...
}

UserDTO::UserDTO(UserDTO &&other) noexcept :
    id_(other.id_),
    name_(std::move(other.name_)),
    email_(std::move(other.email_))
{
    other.id_ = 0;
    // ...
}

UserDTO &UserDTO::operator=(UserDTO &&other) noexcept
{
    if (this != &other) // Проверка на самоприсваивание
    {
        id_ = other.id_;
        name_ = std::move(other.name_); // Перемещение строки
        email_ = std::move(other.email_); // Перемещение строки

        other.id_ = 0; // Обнуляем перемещенный объект
    }
    return *this;
}

UserDTO &UserDTO::operator=(const UserDTO &other)
{
    if (this != &other) // Проверка на самоприсваивание
    {
        id_ = other.id_;
        name_ = other.name_; // Копирование строки
        email_ = other.email_; // Копирование строки
    }

    return *this;
}

UserDTO::~UserDTO()
{
    // ...
}

int UserDTO::getId() const
{
    return id_;
}

const std::string& UserDTO::getName() const
{
    return name_;
}

const std::string& UserDTO::getEmail() const
{
    return email_;
}

void UserDTO::setId(int id)
{
    id_ = id;
}

void UserDTO::setName(const std::string &name)
{
    name_ = name;
}

void UserDTO::setEmail(const std::string &email)
{
    email_ = email;
}
