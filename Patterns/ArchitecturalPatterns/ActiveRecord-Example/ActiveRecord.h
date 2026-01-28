#pragma once

#include <optional>
#include <string>

/*
 * ActiveRecord для User. Вся логика для работы содержится внутри класса
 */
class UserActiveRecord
{
public:
    UserActiveRecord(int id, const std::string& name, const std::string& email);

    // Геттеры
    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;

    // Сеттеры
    void setId(int id);
    void setName(const std::string& name);
    void setEmail(const std::string& email);

    // CRUD логика
    bool save();
    bool remove();
    static std::optional<UserActiveRecord> findById(const int id);
    // static std::vector<UserActiveRecord> getAllUsers();
    // ...

private:
    int id_;
    std::string name_;
    std::string email_;

    bool isNew {false};

};
