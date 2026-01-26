#include "Example.h"

#include <iostream>

BalkingExample::BalkingExample() :
    isProcessing(false),
    dataReady(false),
    data(0)
{
    // ...
}

bool BalkingExample::setData(int newData)
{
    std::lock_guard<std::mutex> lock(mtx);

    // Balking: если уже обрабатывается, отказываемся от установки данных
    if (isProcessing) {
        std::cout << "Balking: Cannot set data while processing" << std::endl;
        return false;
    }

    data = newData;
    dataReady = true;
    std::cout << "Data set to: " << data << std::endl;

    return true;
}

bool BalkingExample::process()
{
    std::lock_guard<std::mutex> lock(mtx);

    // Balking: если уже обрабатывается или данные не готовы, отказываемся
    if (isProcessing) {
        std::cout << "Balking: Already processing" << std::endl;
        return false;
    }

    if (!dataReady) {
        std::cout << "Balking: Data not ready" << std::endl;
        return false;
    }

    // Начинаем обработку
    isProcessing = true;
    std::cout << "Starting processing of data: " << data << std::endl;

    return true;
}

void BalkingExample::finishProcessing()
{
    std::lock_guard<std::mutex> lock(mtx);

    if (isProcessing) {
        std::cout << "Finished processing data: " << data << std::endl;
        isProcessing = false;
        dataReady = false;
    }
}

bool BalkingExample::isBusy() const
{
    return isProcessing;
}

LazyInitializer::LazyInitializer() :
    initialized(false)
{
    // ...
}

int* LazyInitializer::getResource()
{
    // Balking: если уже инициализирован, просто возвращаем ресурс
    if (initialized) {
        return resource.get();
    }

    std::lock_guard<std::mutex> lock(mtx);

    // Двойная проверка (double-checked locking)
    if (!initialized) {
        std::cout << "Initializing resource..." << std::endl;
        resource = std::make_unique<int>(42); // Инициализация
        initialized = true;
    }

    return resource.get();
}

bool LazyInitializer::isInitialized() const
{
    return initialized;
}

AutoSaveDocument::AutoSaveDocument() :
    changed(false)
{
    // ...
}

void AutoSaveDocument::modify(const std::string &newContent)
{
    std::lock_guard<std::mutex> lock(mtx);
    content = newContent;
    changed = true;
    std::cout << "Document modified: " << content << std::endl;
}

bool AutoSaveDocument::autoSave()
{
    std::lock_guard<std::mutex> lock(mtx);

    // Balking: если нет изменений, не сохраняем
    if (!changed) {
        return false;
    }

    // Имитация сохранения
    std::cout << "Auto-saving document: " << content << std::endl;
    changed = false;

    return true;
}

void AutoSaveDocument::manualSave()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Manually saving document: " << content << std::endl;
    changed = false;
}

bool AutoSaveDocument::hasChanges() const
{
    return changed;
}
