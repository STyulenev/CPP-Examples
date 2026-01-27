#pragma once

#include "DTO.h"

#include <vector>

/*
 * Абстрактный интерфейс DAO для пользователя
 */
class IUserDAO
{
public:
    virtual ~IUserDAO() = default;

    virtual void saveUser(const UserDTO& user) = 0;
    virtual std::vector<UserDTO> getAllUsers() const = 0;
};

/*
 * Реализация DAO для работы в памяти
 */
class UserMemoryDAO final : public IUserDAO
{
public:
    void saveUser(const UserDTO& user) override;
    std::vector<UserDTO> getAllUsers() const override;

private:
    std::vector<UserDTO> users_;

};

/*
 * Реализация DAO для работы с БД
 */
class UserDataBaseDAO final : public IUserDAO
{
public:
    void saveUser(const UserDTO& user) override;
    std::vector<UserDTO> getAllUsers() const override;

};
