#include "Example1.h"
#include "Example2.h"
#include "Example3.h"
#include "Example4.h"
#include "Example5.h"
#include "Example6.h"
#include "Example7.h"
#include "Example8.h"
#include "Example9.h"

#include "Other.h"

int main()
{

    // Type traits: Type properties
    {
        Example1::TP1::test();
        Example1::TP2::test();
        Example1::TP3::test();
        Example1::TP4::test();
        Example1::TP5::test();
        Example1::TP6::test();
        Example1::TP7::test();
        Example1::TP8::test();
        Example1::TP9::test();
        Example1::TP10::test();
        Example1::TP11::test();
        Example1::TP12::test();
        Example1::TP13::test();
        Example1::TP14::test();
    }

    // Composite type categories
    {
        Example2::CTP1::test();
        Example2::CTP2::test();
        Example2::CTP3::test();
        Example2::CTP4::test();
        Example2::CTP5::test();
        Example2::CTP6::test();
        Example2::CTP7::test();
    }

    // Type properties
    {
        Example3::TP1::test();
        Example3::TP2::test();
        Example3::TP3::test();
        Example3::TP4::test();
        Example3::TP5::test();
        Example3::TP6::test();
        Example3::TP7::test();
        Example3::TP9::test();
        Example3::TP10::test();
        Example3::TP11::test();
        Example3::TP12::test();
        Example3::TP13::test();
        Example3::TP14::test();
        Example3::TP15::test();
        Example3::TP16::test();
        Example3::TP17::test();
        Example3::TP18::test();
    }

    // Supported operations
    {
        Example4::SO1::test();
    }

    // Property queries
    {
        Example5::PQ1::test();
        Example5::PQ2::test();
        Example5::PQ3::test();
    }

    // Type relationships
    {
        Example6::TR1::test();
        Example6::TR2::test();
        Example6::TR4::test();
        Example6::TR5::test();
        Example6::TR6::test();
        Example6::TR8::test();
    }

    // Type transformations
    {
        Example7::TT1_1::test();
        Example7::TT1_2::test();
        Example7::TT1_3::test();
        Example7::TT1_4::test();

        Example7::TT2_1::test();

        Example7::TT3_1::test();
        Example7::TT3_2::test();

        Example7::TT6_1::test();
        Example7::TT6_3::test();
        Example7::TT6_5::test();
        Example7::TT6_6::test();
    }

    // Logical operations
    {
        Example8::LO1::test();
        Example8::LO2::test();
        Example8::LO3::test();
    }

    // Other
    {
        Other::E1::test();
        Other::E2::test();
        Other::E3::test();
        Other::E4::test();
        Other::E5::test();
        Other::E6::test();
        Other::E7::test();
        Other::E8::test();
        Other::E9::test();
        Other::E10::test();
        Other::E11::test();
        Other::E12::test();
        Other::E13::test();
        Other::E14::test();
        Other::E15::test();
        Other::E16::test();
        Other::E17::test();
        Other::E18::test();
    }

    // Ratio
    /*{
        Example9::CTF_1::test();

        Example9::CTRA_1::test();
        Example9::CTRA_2::test();
        Example9::CTRA_3::test();
        Example9::CTRA_4::test();

        Example9::CTRC_1::test();
        Example9::CTRC_2::test();
        Example9::CTRC_3::test();
        Example9::CTRC_4::test();
        Example9::CTRC_5::test();
        Example9::CTRC_6::test();
    }*/

    return 0;
}
