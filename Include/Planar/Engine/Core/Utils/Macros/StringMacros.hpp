#pragma once

#define PLANAR_STRINGIFY_(string) #string
#define PLANAR_STRINGIFY(string) PLANAR_STRINGIFY_(string)

#define PLANAR_LINE_STRING PLANAR_STRINGIFY(__LINE__)
