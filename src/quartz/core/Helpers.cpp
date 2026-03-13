#include <quartz/core/Helpers.hpp>
#include <cctype>

std::string quartz::camelToSnake(const std::string& camel)
{
    std::string snake;

    for (size_t i = 0; i < camel.size(); ++i)
    {
        char c = camel[i];

        if (std::isupper(static_cast<unsigned char>(c)))
        {
            if (i > 0 && std::islower(static_cast<unsigned char>(camel[i - 1])))
            {
                snake += '_';
            }
            else if (i > 0 && i + 1 < camel.size() && std::islower(static_cast<unsigned char>(camel[i + 1])))
            {
                snake += '_';
            }

            snake += std::tolower(static_cast<unsigned char>(c));
        }
        else
        {
            snake += c;
        }
    }

    return snake;
}