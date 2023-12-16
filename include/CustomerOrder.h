#ifndef MYPROJECT_CUSTOMERORDER_H
#define MYPROJECT_CUSTOMERORDER_H

#include <string>
#include "Station.h"

namespace myproject
{
    struct Item
    {
        std::string m_itemName{};
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };

    class CustomerOrder
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item **m_lstItem{};

        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const std::string &str);

        // copy not allowed
        CustomerOrder(const CustomerOrder &c); // throws exception if called
        CustomerOrder &operator=(const CustomerOrder &c) = delete;

        CustomerOrder(CustomerOrder &&c) noexcept;
        CustomerOrder &operator=(CustomerOrder &&c) noexcept;

        bool isOrderFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;

        ~CustomerOrder();
    };
}

#endif