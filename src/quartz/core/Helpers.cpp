#include <quartz/core/SnakeCase.hpp>
#include <cctype>
#include <cstdint>

std::string quartz::camelToSnake(const std::string& camel)
{
    std::string snake;
    snake.reserve(camel.size() + camel.size() / 2);

    for (size_t i = 0; i < camel.size(); ++i)
    {
        char c = camel[i];

        if (std::isupper(static_cast<unsigned char>(c)))
        {
            bool insertUnderscore = i > 0 && (std::islower(static_cast<unsigned char>(camel[i - 1])) || (i + 1 < camel.size() && std::islower(static_cast<unsigned char>(camel[i + 1]))));

            if (insertUnderscore)
            {
                snake += '_';
            }

            snake += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        else
        {
            snake += c;
        }
    }

    return snake;
}