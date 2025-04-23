#pragma once

template <typename FirstType, typename SecondType>
struct SomePair
{
    FirstType first{};
    SecondType second{};
};

// CTAD не работает с нестатической инициализацией членов

/*struct SomePair2
{
    std::pair first<1, 2>;
    std::pair second<bool, 'a';
};*/
