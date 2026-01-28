#include "ActiveRecord.h"

UserActiveRecord::UserActiveRecord(int id, const std::string& name, const std::string& email) :
    id_(id),
    name_(name),
    email_(email)
{
    // ...
}

int UserActiveRecord::getId() const
{
    return id_;
}

const std::string& UserActiveRecord::getName() const
{
    return name_;
}

const std::string& UserActiveRecord::getEmail() const
{
    return email_;
}

void UserActiveRecord::setId(int id)
{
    id_ = id;
    isNew = true;
}

void UserActiveRecord::setName(const std::string &name)
{
    name_ = name;
    isNew = true;
}

void UserActiveRecord::setEmail(const std::string &email)
{
    email_ = email;
    isNew = true;
}

bool UserActiveRecord::save()
{
    if (isNew)
    {
        // INSERT INTO ...
    }
    else
    {
        // UPDATE ...
    }

    isNew = false;

    return true; // Если нет ошибок, то возвращаем true
}

bool UserActiveRecord::remove()
{
    // DELETE FROM ...
    id_ = -1;
    name_ = "";
    email_ = "";

    return true; // Если нет ошибок, то возвращаем true
}

std::optional<UserActiveRecord> UserActiveRecord::findById(const int id)
{
    if (true)
    {
        return UserActiveRecord(id, "Alex", "alex@www.com");
    }
    else
    {
        return std::nullopt;
    }
}
