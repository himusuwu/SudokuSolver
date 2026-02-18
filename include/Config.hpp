#ifndef CONFIG
#define CONFIG

#include <cstddef>

enum class DifficultyLevel
{
    EASY,
    MEDIUM,
    HARD,
    EXPERT
};

struct DifficultyProfile
{
    size_t minEmpty;
    size_t maxEmpty;
    bool symetric;
    size_t solverAttempts;
};

#endif