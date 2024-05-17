#pragma once

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER_(number, macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER##number(macro            \
        __VA_OPT__(,) __VA_ARGS__)                                    \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER(number, macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER_(number, macro          \
        __VA_OPT__(,) __VA_ARGS__)                                   \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER1(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 1)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER2(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 2)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER1(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER3(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 3)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER2(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER4(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 4)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER3(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER5(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 5)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER4(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER6(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 6)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER5(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER7(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 7)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER6(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER8(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 8)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER7(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER9(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 9)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER8(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER10(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 10)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER9(macro            \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER11(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 11)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER10(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER12(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 12)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER11(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER13(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 13)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER12(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER14(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 14)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER13(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER15(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 15)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER14(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER16(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 16)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER15(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER17(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 17)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER16(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER18(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 18)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER17(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER19(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 19)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER18(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER20(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 20)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER19(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER21(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 21)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER20(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER22(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 22)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER21(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER23(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 23)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER22(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER24(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 24)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER23(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER25(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 25)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER24(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER26(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 26)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER25(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER27(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 27)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER26(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER28(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 28)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER27(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER29(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 29)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER28(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER30(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 30)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER29(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER31(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 31)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER30(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER32(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 32)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER31(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER33(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 33)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER32(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER34(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 34)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER33(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER35(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 35)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER34(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER36(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 36)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER35(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER37(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 37)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER36(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER38(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 38)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER37(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER39(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 39)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER38(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER40(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 40)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER39(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER41(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 41)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER40(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER42(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 42)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER41(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER43(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 43)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER42(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER44(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 44)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER43(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER45(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 45)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER44(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER46(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 46)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER45(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER47(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 47)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER46(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER48(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 48)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER47(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER49(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 49)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER48(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER50(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 50)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER49(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER51(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 51)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER50(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER52(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 52)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER51(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER53(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 53)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER52(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER54(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 54)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER53(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER55(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 55)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER54(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER56(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 56)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER55(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER57(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 57)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER56(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER58(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 58)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER57(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER59(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 59)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER58(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER60(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 60)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER59(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER61(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 61)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER60(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER62(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 62)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER61(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER63(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 63)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER62(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER64(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 64)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER63(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER65(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 65)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER64(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER66(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 66)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER65(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER67(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 67)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER66(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER68(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 68)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER67(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER69(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 69)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER68(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER70(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 70)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER69(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER71(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 71)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER70(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER72(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 72)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER71(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER73(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 73)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER72(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER74(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 74)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER73(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER75(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 75)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER74(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER76(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 76)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER75(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER77(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 77)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER76(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER78(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 78)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER77(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER79(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 79)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER78(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER80(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 80)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER79(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER81(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 81)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER80(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER82(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 82)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER81(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER83(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 83)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER82(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER84(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 84)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER83(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER85(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 85)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER84(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER86(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 86)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER85(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER87(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 87)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER86(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER88(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 88)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER87(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER89(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 89)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER88(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER90(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 90)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER89(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER91(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 91)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER90(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER92(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 92)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER91(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER93(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 93)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER92(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER94(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 94)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER93(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER95(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 95)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER94(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER96(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 96)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER95(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER97(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 97)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER96(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER98(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 98)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER97(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER99(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 99)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER98(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER100(macro, ...) \
    macro(__VA_ARGS__ __VA_OPT__(,) 100)                        \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER99(macro            \
        __VA_OPT__(,) __VA_ARGS__)                              \
