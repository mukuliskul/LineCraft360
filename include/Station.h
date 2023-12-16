#ifndef MYPROJECT_STATION_H
#define MYPROJECT_STATION_H

#include <string>

namespace myproject
{
    class Station
    {
        int m_id;
        std::string m_name;
        std::string m_desc;
        size_t m_nextSerialNum;
        size_t m_stockCount;

        static size_t m_widthField;
        static int id_generator;

    public:
        Station();
        Station(const std::string &record);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &os, bool full) const;
    };
}

#endif