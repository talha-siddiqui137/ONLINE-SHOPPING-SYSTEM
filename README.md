# 🛒 Online Shopping System (C++)

A menu-driven **Online Shopping System** developed in **C++** to demonstrate the core principles of **Object-Oriented Programming (OOP)**. This project simulates the basic workflow of an e-commerce platform, allowing users to browse products, add items to a cart, place orders, choose payment methods, and apply discounts.

This project was developed as an **Object-Oriented Programming (OOP)** assignment for the **Software Engineering** program at **NED University of Engineering & Technology**.

---

## 📌 Features

- Browse available products
- Electronics and Clothing product categories
- Add products to cart by **ID** or **Name**
- View shopping cart and total amount
- Place an order
- Select payment method
- Apply discount using a friend function
- Customer and Admin profiles
- Constructor and destructor lifecycle demonstration
- Menu-driven console interface

---

## 🏗️ OOP Concepts Implemented

This project demonstrates the following Object-Oriented Programming concepts:

- ✅ Classes and Objects
- ✅ Encapsulation
- ✅ Inheritance
- ✅ Runtime Polymorphism (Virtual Functions)
- ✅ Compile-Time Polymorphism (Function Overloading)
- ✅ Abstract Class
- ✅ Composition
- ✅ Aggregation
- ✅ Friend Function
- ✅ Structures (`struct`)
- ✅ Constructors
- ✅ Destructors
- ✅ Dynamic Memory Allocation (`new` / `delete`)
- ✅ STL (`vector`, `string`)

---

## 📂 Class Structure

```
                   Product (Abstract)
                  /                  \
        Electronics              Clothing


                     User
                    /    \
             Customer    Admin


Order
 ├── OrderDetails (Struct)
 └── Payment

Cart
 └── Stores Product* (Aggregation)
```

---

## 🛍️ Workflow

```
Start
   │
   ▼
Create Customer
   │
   ▼
Load Products
   │
   ▼
Main Menu
   │
   ├── View Products
   ├── Add to Cart (ID)
   ├── Add to Cart (Name)
   ├── View Cart
   ├── Place Order
   │      ├── Select Payment Method
   │      ├── Apply Discount (Optional)
   │      └── Display Order Summary
   ├── Show User Profiles
   └── Exit
```

---

## 💻 Technologies Used

- C++
- Object-Oriented Programming
- Standard Template Library (STL)
- Console Application

---

## 📁 Project Structure

```
Online-Shopping-System/
│
├── main.cpp
├── README.md
└── Project_Report.pdf (optional)
```

---

## ▶️ How to Run

### Using g++

```bash
g++ main.cpp -o shopping
./shopping
```

### Using Visual Studio

1. Create a new C++ Console Project.
2. Replace the generated source file with `main.cpp`.
3. Build and Run.

### Using VS Code

Compile:

```bash
g++ main.cpp -o shopping
```

Run:

```bash
./shopping
```

---

## 📸 Sample Output

```
============================================
        ONLINE SHOPPING SYSTEM
============================================

1. View Products
2. Add to Cart (by ID)
3. Add to Cart (by Name)
4. View Cart
5. Place Order
6. Show User Profiles
7. Exit
```

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience with:

- Designing software using Object-Oriented Programming
- Building class hierarchies
- Implementing inheritance and polymorphism
- Applying composition and aggregation relationships
- Working with abstract classes and virtual functions
- Managing dynamic memory
- Using STL containers
- Organizing a medium-sized C++ application

---

## 🚀 Future Improvements

- Product inventory management
- User authentication
- Remove items from cart
- Product quantity support
- Order history
- File handling
- Database integration
- Graphical User Interface (GUI)
- Online payment gateway
- Product search and filtering

---

## 👨‍💻 Author

**Talha Siddiqui**

Software Engineering Student  
NED University of Engineering & Technology

GitHub: https://github.com/talha-siddiqui137

---

## ⭐ Support

If you found this project helpful, consider giving it a **⭐ Star** on GitHub.