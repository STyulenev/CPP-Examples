#include "Example1.h"
#include "Example2.h"
#include "Example3.h"
#include "Example4.h"
#include "Example6.h"
#include "Example7.h"
#include "Example8.h"

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
   }

   // Composite type categories
   {
       Example2::CTP1::test();
       Example2::CTP2::test();
       Example2::CTP3::test();
       Example2::CTP4::test();
       Example2::CTP5::test();
       Example2::CTP6::test();
   }

    // Type properties
    {
        Example3::TP1::test();
        Example3::TP2::test();
        Example3::TP3::test();
        Example3::TP5::test();
        Example3::TP9::test();
        Example3::TP10::test();
        Example3::TP11::test();
        Example3::TP12::test();
        Example3::TP13::test();
    }

    // Supported operations
    {
        Example4::SO1::test();
    }

   // Type relationships
   {
       Example6::TR1::test();
       Example6::TR2::test();
   }

    // Type transformations
    {
        Example7::TT1_1::test();
        Example7::TT1_4::test();
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
    }

    return 0;
}
