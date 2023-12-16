#include <stdexcept>
#include "../include/Utilities.h"

namespace myproject
{
    char Utilities::m_delimiter = '|';

    Utilities::Utilities()
    {
        m_widthField = 1;
    }

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
    {
        std::string result;
        more = true;
        if (more)
        {

            if (next_pos >= str.length())
            {
                more = false;
                throw "Invalid position for token extraction";
            }

            if (str[next_pos] == m_delimiter)
            {
                more = false;
                throw "Delimiter found at starting position";
            }

            size_t delimIndex = str.find(m_delimiter, next_pos);

            if (delimIndex == std::string::npos)
            {
                // This is the last token
                result = str.substr(next_pos);
                more = false;
            }
            else
            {
                // Extract the token and update next_pos
                result = str.substr(next_pos, delimIndex - next_pos);
                next_pos = delimIndex + 1;
                more = true;
            }

            result = result.erase(0, result.find_first_not_of(' ')); // remove leading whitespaces
            result = result.erase(result.find_last_not_of(' ') + 1); // remove trailing whitespaces

            if (result.length() > m_widthField)
            {
                m_widthField = result.length();
            }
        }
        return result;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}
