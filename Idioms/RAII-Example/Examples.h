#pragma once

#include <iostream>
#include <filesystem>

/*
 * Примеры удобных RAII-обёрток
 */

// RAII класс для обязательного удаления файла, путь которого передан в конструктор
class FileGuard
{
public:
    FileGuard() = delete;
    FileGuard(const std::filesystem::path& filepath)
        : m_filepath(filepath)
    {}

    FileGuard(const FileGuard&) = delete;
    FileGuard& operator=(FileGuard&) = delete;

    FileGuard(FileGuard&& other) = default;
    FileGuard& operator=(FileGuard&& other) = default;

    ~FileGuard()
    {
        if (std::filesystem::exists(m_filepath))
        {
            std::filesystem::remove(m_filepath);
            std::cout << "remove " << m_filepath.string() << std::endl;
        }
    }

    const std::filesystem::path& get_path() const { return m_filepath; }

private:
    std::filesystem::path m_filepath;

};
