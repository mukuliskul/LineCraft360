#include <iomanip>
#include "../include/Station.h"
#include "../include/Utilities.h"

namespace myproject
{
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station()
    {
        m_id = {};
        m_name = {};
        m_desc = {};
        m_nextSerialNum = {};
        m_stockCount = {};
    }

    Station::Station(const std::string &record) : Station()
    {
        Utilities utils;
        bool more = true;
        size_t next_pos = 0;

        Station::id_generator++;

        m_id = id_generator;
        m_name = utils.extractToken(record, next_pos, more);
        if (more)
        {
            m_nextSerialNum = stoi(utils.extractToken(record, next_pos, more));
        }
        if (more)
        {
            m_stockCount = stoi(utils.extractToken(record, next_pos, more));
        }

        if (Station::m_widthField < utils.getFieldWidth())
        {
            Station::m_widthField = utils.getFieldWidth();
        }

        if (more)
        {
            m_desc = utils.extractToken(record, next_pos, more);
        }
    }

    const std::string &Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_nextSerialNum++;
    }
    size_t Station::getQuantity() const
    {
        return m_stockCount;
    }
    void Station::updateQuantity()
    {
        if (m_stockCount > 0)
            m_stockCount--;
    }

    void Station::display(std::ostream &os, bool full) const
    {
        os << std::setfill('0') << std::right << std::setw(3) << m_id << " | ";
        os << std::setfill(' ');

        os << std::left << std::setw(m_widthField) << m_name << " | ";
        os << std::setfill('0') << std::right << std::setw(6) << m_nextSerialNum << " | ";
        os << std::setfill(' ');

        if (full)
        {
            os << std::setw(4) << m_stockCount << " | ";
            os << std::left << m_desc << std::endl;
        }
        else
            os << std::endl;
    }
}