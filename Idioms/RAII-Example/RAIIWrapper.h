#pragma once

template <typename Type>
class RAIIWrapper
{
private:
    Type* resource__;

public:
    RAIIWrapper() {
        try {
            resource__ = new Type();
        } catch (...) {
            delete resource__;
            throw;
        }
    }

    ~RAIIWrapper() {
        if (resource__)
            delete resource__;
    }

    RAIIWrapper(const RAIIWrapper& other) {
        resource__ = new Type(*other.resource__);
    }

    RAIIWrapper& operator=(const RAIIWrapper& other) {
        *resource__ = *other.resource__;
        return *this;
    }

    Type* get() {
        return resource__;
    }
};

