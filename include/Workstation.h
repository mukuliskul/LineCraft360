#ifndef MYPROJECT_WORKSTATION_H
#define MYPROJECT_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace myproject
{
    extern std::deque<CustomerOrder> g_pending;    // holds the orders to be placed onto the assembly line at the first station.
    extern std::deque<CustomerOrder> g_completed;  // holds the orders that have been removed from the last station and have been completely filled
    extern std::deque<CustomerOrder> g_incomplete; // holds the orders that have been removed from the last station and could not be filled completely

    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation *m_pNextStation{};

    public:
        Workstation(const std::string &str);
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station = nullptr);
        Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);

        // deleted copy and move operations
        Workstation(const Workstation &ws) = delete;
        Workstation &operator=(const Workstation &ws) = delete;
        Workstation(Workstation &&ws) = delete;
        Workstation &operator=(Workstation &&ws) = delete;
    };
}

#endif