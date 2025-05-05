#pragma once

/*
 * Интерфейс, который определяет методы, в данном случае performAction
 */
class IService {
public:
    virtual ~IService() {}

    virtual int performAction(int value) = 0;
    // Другие методы

};
