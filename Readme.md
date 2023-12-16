# Line Craft 360

## Project Overview

This project is a C++ Object-Oriented simulation of an assembly line with a customizable number of stations. It simulates a set of workstations, each holding specific stock items. A line manager moves customer orders along the line, filling orders at each station as required. The simulation processes queues of orders at each station and manages inventory, resulting in either completed or incomplete orders based on item availability.

## Skills

### C++ Programming

- **Object-Oriented Design:** Deep dive into OOP concepts such as classes, objects, inheritance, and polymorphism.
- **File Handling:** Experience in reading and writing files, crucial for setting up and configuring the assembly line simulation.
- **Memory Management:** Practical application of dynamic memory allocation and management, especially in the `CustomerOrder` module.

### System Design

- **Modular Development:** Understanding of designing modular systems, as shown by separate modules like `Utilities`, `Station`, `CustomerOrder`, `Workstation`, and `LineManager`.
- **Process Flow Management:** Insights into managing complex process flows, particularly evident in how customer orders are processed through different stations.

### Data Structures and Algorithms

- **Efficient Data Handling:** Use of data structures (e.g., queues in `Workstation`) for effective data management.
- **Algorithm Implementation:** Application of algorithms for order processing and station management.

## Experience Gained

### Real-world Application Development

- **Comprehensive Project Structure:** Experience in handling a project that mirrors real-world industrial simulations.
- **Complex Logic Implementation:** Dealing with complex business logic as seen in order management and processing.

### Software Engineering Practices

- **Debugging and Testing:** Gaining practical experience in debugging and thorough testing, supported by the `Tester` module.
- **Code Documentation and Readability:** Emphasis on writing well-documented and readable code, crucial for large-scale projects.

### Collaborative Development

- **Version Control and Management:** Experience with version control systems, essential for managing changes in a multi-module project.

## Features

### `Utilities` and `Station` Classes

- **Utilities Module:** Supports parsing of input files containing assembly line setup and configuration data.
- **Station Module:** Manages information about each station on the assembly line, handling specific items for customer orders.

### `CustomerOrder` Module

- Manages single orders on the assembly line, processing them as they move from station to station.

### `Workstation` and `LineManager` Modules

- **Workstation Module:** Represents an active station on the assembly line, managing order processing for items.
- **LineManager Module:** Configures the assembly line and moves orders along it, determining if orders are complete or incomplete based on station inventory.

## Usage (Compilation and Running)

To compile and run the Library Management System, follow these steps:

1. Ensure you have a C++ compiler installed, such as GCC or Clang.
2. Compile the source files. For example, using GCC:
   ```
   g++ -Wall -std=c++17 -o LineCraft src/*.cpp
   ```
3. Run the compiled application:
   ```
   ./LineCraft ./data/Stations1.txt ./data/Stations2.txt ./data/CustomerOrders.txt ./data/AssemblyLine.txt
   ```

## Contribution

Contributions to this project are welcome. Please fork the repository and submit a pull request for review.
