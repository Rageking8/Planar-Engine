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
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER1(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 2)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER3(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER2(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 3)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER4(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER3(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 4)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER5(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER4(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 5)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER6(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER5(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 6)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER7(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER6(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 7)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER8(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER7(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 8)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER9(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER8(macro           \
        __VA_OPT__(,) __VA_ARGS__)                            \
    macro(__VA_ARGS__ __VA_OPT__(,) 9)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER10(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER9(macro            \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 10)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER11(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER10(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 11)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER12(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER11(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 12)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER13(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER12(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 13)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER14(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER13(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 14)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER15(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER14(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 15)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER16(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER15(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 16)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER17(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER16(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 17)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER18(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER17(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 18)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER19(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER18(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 19)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER20(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER19(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 20)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER21(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER20(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 21)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER22(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER21(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 22)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER23(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER22(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 23)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER24(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER23(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 24)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER25(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER24(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 25)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER26(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER25(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 26)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER27(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER26(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 27)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER28(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER27(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 28)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER29(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER28(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 29)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER30(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER29(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 30)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER31(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER30(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 31)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER32(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER31(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 32)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER33(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER32(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 33)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER34(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER33(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 34)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER35(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER34(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 35)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER36(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER35(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 36)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER37(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER36(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 37)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER38(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER37(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 38)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER39(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER38(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 39)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER40(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER39(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 40)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER41(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER40(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 41)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER42(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER41(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 42)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER43(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER42(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 43)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER44(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER43(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 44)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER45(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER44(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 45)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER46(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER45(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 46)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER47(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER46(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 47)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER48(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER47(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 48)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER49(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER48(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 49)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER50(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER49(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 50)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER51(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER50(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 51)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER52(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER51(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 52)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER53(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER52(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 53)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER54(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER53(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 54)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER55(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER54(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 55)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER56(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER55(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 56)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER57(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER56(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 57)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER58(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER57(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 58)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER59(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER58(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 59)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER60(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER59(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 60)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER61(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER60(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 61)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER62(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER61(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 62)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER63(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER62(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 63)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER64(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER63(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 64)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER65(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER64(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 65)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER66(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER65(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 66)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER67(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER66(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 67)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER68(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER67(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 68)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER69(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER68(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 69)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER70(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER69(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 70)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER71(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER70(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 71)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER72(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER71(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 72)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER73(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER72(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 73)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER74(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER73(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 74)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER75(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER74(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 75)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER76(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER75(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 76)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER77(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER76(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 77)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER78(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER77(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 78)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER79(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER78(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 79)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER80(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER79(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 80)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER81(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER80(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 81)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER82(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER81(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 82)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER83(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER82(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 83)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER84(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER83(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 84)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER85(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER84(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 85)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER86(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER85(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 86)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER87(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER86(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 87)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER88(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER87(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 88)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER89(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER88(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 89)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER90(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER89(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 90)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER91(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER90(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 91)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER92(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER91(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 92)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER93(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER92(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 93)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER94(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER93(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 94)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER95(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER94(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 95)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER96(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER95(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 96)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER97(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER96(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 97)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER98(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER97(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 98)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER99(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER98(macro           \
        __VA_OPT__(,) __VA_ARGS__)                             \
    macro(__VA_ARGS__ __VA_OPT__(,) 99)                        \

#define PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER100(macro, ...) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER99(macro            \
        __VA_OPT__(,) __VA_ARGS__)                              \
    macro(__VA_ARGS__ __VA_OPT__(,) 100)                        \
