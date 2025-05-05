#pragma once

#include "IService.h"

/*
 * Реализация интерфейса, выполняющая реальное действие.
 */
class RealService : public IService
{
public:
    int performAction(int value) override {
        return value * 2; // Пример действия
    }
};

/*
 * Мок-объект или имитационный объект (макет, подделка, заглушка), который используется для тестирования.
 * Он возвращает предсказуемое значение.
 */
class MockService : public IService
{
public:
    int performAction(int value) override {
        return value + 1; // Мок-реализация для тестирования
    }
};

// Другие реальные сервисы и мок-сервисы ...
