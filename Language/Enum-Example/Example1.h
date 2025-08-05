#pragma once

#include <iostream>
#include <cstdint>
#include <unordered_map>

/*
 *
 * Примеры использования перечислений
 *
 */
namespace Example1
{

// Типизированный enum
void test1()
{
    enum class Color : uint32_t
    {
        Red = 0xFF0000,
        Green = 0x00FF00,
        Blue = 0x0000FF,
        Black = 0x000000,
        White = 0xFFFFFF
    };

    enum class CharDigital : char
    {
        Zero = '0',
        One = '1',
        Two = '2',
    };

    Color bg = Color::White;
    uint8_t value = static_cast<uint8_t>(bg);

    std::cout << "value = " << value << std::endl;
}

// Использование битовых флагов с enum
enum class Permissions : uint8_t
{
    Read    = 1 << 0,            // 00000001
    Write   = 1 << 1,            // 00000010
    Execute = 1 << 2,            // 00000100
    ReadWrite = Read | Write,    // 00000011
    // ...
    All = Read | Write | Execute // 00000111
};

Permissions operator|(Permissions a, Permissions b)
{
    return static_cast<Permissions>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

bool operator&(Permissions a, Permissions b)
{
    return (static_cast<uint8_t>(a) & static_cast<uint8_t>(b)) != 0;
}

void test2()
{
    Permissions perms = Permissions::Read | Permissions::Write;

    if (perms & Permissions::Write)
    {
        std::cout << "May be write" << std::endl;
    }

    if (perms & Permissions::Read)
    {
        std::cout << "May be read" << std::endl;
    }
}

// Enum с методами (используя namespace)

namespace Direction
{
enum Value
{
    North,
    South,
    East,
    West
};

const char* toString(Value dir)
{
    switch(dir) {
    case North: return "North";
    case South: return "South";
    case East:  return "East";
    case West:  return "West";
    default:    return "Unknown";
    }
}

Value opposite(Value dir)
{
    switch(dir) {
    case North: return South;
    case South: return North;
    case East:  return West;
    case West:  return East;
    default:    return dir;
    }
}

}

void test3()
{
    Direction::Value dir = Direction::North;
    std::cout << "Direction: " << Direction::toString(dir) << std::endl;
    std::cout << "Opposite: " << Direction::toString(Direction::opposite(dir)) << std::endl;
}

// Enum с unordered_map

enum class Planet
{
    Mercury,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};

static const std::unordered_map<Planet, double> planetMass = {
    { Planet::Mercury, 0.330  },
    { Planet::Venus,   4.87   },
    { Planet::Earth,   5.97   },
    { Planet::Mars,    0.642  },
    { Planet::Jupiter, 1898.0 },
    { Planet::Saturn,  568.0  },
    { Planet::Uranus,  86.8   },
    { Planet::Neptune, 102.0  }
};

void test4()
{
    Planet p = Planet::Earth;
    std::cout << "Mass of Earth: " << planetMass.at(p) << " x 10^24 kg" << std::endl;
}

} // namespace Example1
