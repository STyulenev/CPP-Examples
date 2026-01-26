#pragma once

#include <mutex>
#include <memory>

// Класс, реализующий паттерн Balking
class BalkingExample
{
private:
    std::mutex mtx;
    bool isProcessing;
    bool dataReady;
    int data;

public:
    BalkingExample();

    // Метод для установки данных (не блокирующий)
    bool setData(int newData);
    // Метод для запуска обработки (не блокирующий)
    bool process();
    // Метод для завершения обработки
    void finishProcessing();
    // Проверка состояния
    bool isBusy() const;

};

// Пример класса с отложенной инициализацией (ленивая инициализация)
class LazyInitializer
{
private:
    std::mutex mtx;
    std::unique_ptr<int> resource;
    bool initialized;

public:
    LazyInitializer();

    // Метод, который инициализирует ресурс только один раз
    int* getResource();
    bool isInitialized() const;

};

// Пример с автоматическим сохранением
class AutoSaveDocument
{
private:
    std::mutex mtx;
    bool changed;
    std::string content;

public:
    AutoSaveDocument();

    // Изменение документа
    void modify(const std::string& newContent);
    // Автосохранение (balking если не было изменений)
    bool autoSave();
    // Ручное сохранение (всегда выполняется)
    void manualSave();
    bool hasChanges() const;

};
