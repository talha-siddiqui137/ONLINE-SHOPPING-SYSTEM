// ============================================================
//   ONLINE SHOPPING SYSTEM USING OBJECT-ORIENTED PROGRAMMING
//   Language  : C++
//   Author    : SE-25096
//   Concepts  : Inheritance, Polymorphism, Abstract Class,
//               Composition, Aggregation, Friend Function,
//               Struct, Constructors, Destructors, STL, Encap.
// ============================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ============================================================
// SECTION 1: STRUCT
// OOP Concept: Structure to store basic order information
// ============================================================
struct OrderDetails {
    int    orderID;  // Unique ID for each order
    string date;     // Date of order placement
};

// ============================================================
// SECTION 2: ABSTRACT BASE CLASS — Product
// OOP Concept: Abstract Class + Runtime Polymorphism
//              Pure virtual function forces derived classes
//              to provide their own displayProduct()
// ============================================================
class Product {
protected:
    int    productID;   // Encapsulation: protected data
    string name;
    double price;

public:
    // Parameterized Constructor
    Product(int id, string n, double p)
        : productID(id), name(n), price(p) {
        cout << "[Constructor] Product created: " << name << "\n";
    }

    // Pure Virtual Function — makes Product an Abstract Class
    // OOP Concept: Polymorphism (Runtime)
    virtual void displayProduct() = 0;

    // Getters — OOP Concept: Encapsulation
    int    getID()    const { return productID; }
    string getName()  const { return name; }
    double getPrice() const { return price; }

    // Virtual Destructor — important when using base class pointers
    virtual ~Product() {
        cout << "[Destructor] Product destroyed: " << name << "\n";
    }
};

// ============================================================
// SECTION 3: DERIVED CLASS — Electronics
// OOP Concept: Inheritance (from Product)
//              Polymorphism (displayProduct overridden)
// ============================================================
class Electronics : public Product {
private:
    string brand;

public:
    Electronics(int id, string n, double p, string b)
        : Product(id, n, p), brand(b) {
        cout << "[Constructor] Electronics created: " << name << "\n";
    }

    // OOP Concept: Polymorphism — overriding pure virtual function
    void displayProduct() override {
        cout << "  [Electronics] ID: " << productID
             << " | Name: "  << name
             << " | Brand: " << brand
             << " | Price: Rs." << price << "\n";
    }

    ~Electronics() {
        cout << "[Destructor] Electronics destroyed: " << name << "\n";
    }
};

// ============================================================
// SECTION 4: DERIVED CLASS — Clothing
// OOP Concept: Inheritance (from Product)
//              Polymorphism (displayProduct overridden)
// ============================================================
class Clothing : public Product {
private:
    string size;

public:
    Clothing(int id, string n, double p, string s)
        : Product(id, n, p), size(s) {
        cout << "[Constructor] Clothing created: " << name << "\n";
    }

    // OOP Concept: Polymorphism — overriding pure virtual function
    void displayProduct() override {
        cout << "  [Clothing]     ID: " << productID
             << " | Name: " << name
             << " | Size: " << size
             << " | Price: Rs." << price << "\n";
    }

    ~Clothing() {
        cout << "[Destructor] Clothing destroyed: " << name << "\n";
    }
};

// ============================================================
// SECTION 5: CLASS — Payment
// OOP Concept: Composition (used inside Order)
//              Friend Function (applyDiscount accesses private)
// ============================================================
class Payment {
private:
    double totalAmount;
    string method;

public:
    // OOP Concept: Frtalhaiend Function Declaration
    friend void applyDiscount(Payment& pay, double discountPercent);

    Payment(double amount, string m)
        : totalAmount(amount), method(m) {
        cout << "[Constructor] Payment object created.\n";
    }

    double getAmount() const { return totalAmount; }
    string getMethod() const { return method; }

    void displayPayment() const {
        cout << "  Payment Method : " << method << "\n";
        cout << "  Total Amount   : Rs." << totalAmount << "\n";
    }

    ~Payment() {
        cout << "[Destructor] Payment object destroyed.\n";
    }
};

// ============================================================
// SECTION 6: FRIEND FUNCTION — applyDiscount
// OOP Concept: Friend Function
//              Accesses private member 'totalAmount' of Payment
// ============================================================
void applyDiscount(Payment& pay, double discountPercent) {
    double discountAmount = (pay.totalAmount * discountPercent) / 100;
    pay.totalAmount -= discountAmount;
    cout << "  Discount of " << discountPercent
         << "% applied! New Total: Rs." << pay.totalAmount << "\n";
}

// ============================================================
// SECTION 7: CLASS — Order
// OOP Concept: Composition
//              Order HAS-A Payment object (lives inside Order)
// ============================================================
class Order {
private:
    OrderDetails   details;    // OOP Concept: Struct usage
    Payment        payment;    // OOP Concept: Composition
    vector<string> itemNames;

public:
    Order(int id, string date, double amount,
          string payMethod, vector<string> items)
        : payment(amount, payMethod), itemNames(items) {
        details.orderID = id;
        details.date    = date;
        cout << "[Constructor] Order #" << details.orderID << " created.\n";
    }

    void displayOrder() const {
        cout << "\n========== ORDER SUMMARY ==========\n";
        cout << "  Order ID  : " << details.orderID << "\n";
        cout << "  Date      : " << details.date    << "\n";
        cout << "  Items     :\n";
        for (const string& item : itemNames)
            cout << "    -> " << item << "\n";
        payment.displayPayment();
        cout << "====================================\n";
    }

    Payment& getPayment() { return payment; }

    ~Order() {
        cout << "[Destructor] Order #" << details.orderID << " destroyed.\n";
    }
};

// ============================================================
// SECTION 8: CLASS — Cart
// OOP Concept: Aggregation
//              Cart stores Product* pointers (does not own them)
// ============================================================
class Cart {
private:
    vector<Product*> items;   // OOP Concept: Aggregation + STL vector

public:
    Cart() { cout << "[Constructor] Cart created.\n"; }

    // OOP Concept: Function Overloading — Version 1 (by ID)
    void addToCart(int id, vector<Product*>& allProducts) {
        for (Product* p : allProducts) {
            if (p->getID() == id) {
                items.push_back(p);
                cout << "   Added to cart by ID: " << p->getName() << "\n";
                return;
            }
        }
        cout << "   Product with ID " << id << " not found.\n";
    }

    // OOP Concept: Function Overloading — Version 2 (by Name)
    void addToCart(string name, vector<Product*>& allProducts) {
        for (Product* p : allProducts) {
            if (p->getName() == name) {
                items.push_back(p);
                cout << "   Added to cart by Name: " << p->getName() << "\n";
                return;
            }
        }
        cout << "   Product \"" << name << "\" not found.\n";
    }

    void viewCart() const {
        if (items.empty()) { cout << "  Your cart is empty!\n"; return; }
        cout << "\n---------- YOUR CART ----------\n";
        double total = 0;
        for (Product* p : items) {
            p->displayProduct();   // OOP Concept: Runtime Polymorphism
            total += p->getPrice();
        }
        cout << "  --------------------------------\n";
        cout << "  Cart Total: Rs." << total << "\n";
        cout << "--------------------------------\n";
    }

    double getTotal() const {
        double total = 0;
        for (Product* p : items) total += p->getPrice();
        return total;
    }

    vector<string> getItemNames() const {
        vector<string> names;
        for (Product* p : items) names.push_back(p->getName());
        return names;
    }

    bool isEmpty() const { return items.empty(); }

    ~Cart() { cout << "[Destructor] Cart destroyed.\n"; }
};

// ============================================================
// SECTION 9: BASE CLASS — User
// OOP Concept: Inheritance (base class) + Encapsulation
// ============================================================
class User {
protected:
    string username;
    string email;

public:
    User(string u, string e) : username(u), email(e) {
        cout << "[Constructor] User created: " << username << "\n";
    }

    virtual void showProfile() const {
        cout << "  Username : " << username << "\n";
        cout << "  Email    : " << email    << "\n";
    }

    string getUsername() const { return username; }

    virtual ~User() {
        cout << "[Destructor] User destroyed: " << username << "\n";
    }
};

// ============================================================
// SECTION 10: DERIVED CLASS — Customer
// OOP Concept: Inheritance (from User)
// ============================================================
class Customer : public User {
private:
    string address;

public:
    Customer(string u, string e, string addr)
        : User(u, e), address(addr) {
        cout << "[Constructor] Customer profile created: " << username << "\n";
    }

    void showProfile() const override {
        cout << "\n--- Customer Profile ---\n";
        User::showProfile();
        cout << "  Address  : " << address << "\n";
    }

    ~Customer() {
        cout << "[Destructor] Customer destroyed: " << username << "\n";
    }
};

// ============================================================
// SECTION 11: DERIVED CLASS — Admin
// OOP Concept: Inheritance (from User)
// ============================================================
class Admin : public User {
private:
    string adminCode;

public:
    Admin(string u, string e, string code)
        : User(u, e), adminCode(code) {
        cout << "[Constructor] Admin created: " << username << "\n";
    }

    void showProfile() const override {
        cout << "\n--- Admin Profile ---\n";
        User::showProfile();
        cout << "  Admin Code: " << adminCode << "\n";
    }

    ~Admin() {
        cout << "[Destructor] Admin destroyed: " << username << "\n";
    }
};

// ============================================================
// HELPER FUNCTIONS
// These keep main() clean by moving each menu action here
// ============================================================

// Prints a styled separator header
void printHeader(const string& title) {
    cout << "\n============================================\n";
    cout << "   " << title << "\n";
    cout << "============================================\n";
}

// Loads all products into the catalogue using dynamic memory
// OOP Concept: Dynamic Memory (new), Abstract Class, Polymorphism
void loadProducts(vector<Product*>& allProducts) {
    cout << "\n[STEP 2] Creating Products...\n";
    allProducts.push_back(new Electronics(101, "Samsung Galaxy A55",    89999,  "Samsung"));
    allProducts.push_back(new Electronics(102, "HP Laptop 15s",         120000, "HP"));
    allProducts.push_back(new Electronics(103, "JBL Bluetooth Speaker",  8500,  "JBL"));
    allProducts.push_back(new Clothing   (201, "Linen Kurta",            2500,  "M"));
    allProducts.push_back(new Clothing   (202, "Denim Jeans",            4200,  "L"));
    allProducts.push_back(new Clothing   (203, "Winter Hoodie",          3800,  "XL"));
}

// Frees all heap-allocated products
// OOP Concept: Dynamic Memory (delete) + Virtual Destructor chain
void cleanupProducts(vector<Product*>& allProducts) {
    cout << "\n[CLEANUP] Deleting all products from memory...\n";
    for (Product* p : allProducts)
        delete p;
    allProducts.clear();
    cout << "\n[Program End] All objects destroyed. Goodbye!\n";
}

// Displays all products using runtime polymorphism
// OOP Concept: Runtime Polymorphism (Product* calls correct override)
void handleViewProducts(vector<Product*>& allProducts) {
    printHeader("AVAILABLE PRODUCTS");
    cout << "  Using Runtime Polymorphism (base class pointer):\n\n";
    for (Product* p : allProducts)
        p->displayProduct();
}

// Adds a product to cart by ID (overloaded version 1)
// OOP Concept: Function Overloading (Compile-Time Polymorphism)
void handleAddByID(Cart& cart, vector<Product*>& allProducts) {
    printHeader("ADD TO CART (by ID)");
    cout << "  Enter Product ID: ";
    int id;
    cin >> id;
    cart.addToCart(id, allProducts);
}

// Adds a product to cart by Name (overloaded version 2)
// OOP Concept: Function Overloading (Compile-Time Polymorphism)
void handleAddByName(Cart& cart, vector<Product*>& allProducts) {
    printHeader("ADD TO CART (by Name)");
    cin.ignore();
    cout << "  Enter Product Name: ";
    string name;
    getline(cin, name);
    cart.addToCart(name, allProducts);
}

// Places an order with Composition, Struct, and Friend Function
// OOP Concept: Composition (Order HAS-A Payment)
//              Struct (OrderDetails inside Order)
//              Friend Function (applyDiscount)
//              Dynamic Memory (new Order, delete order)
void handlePlaceOrder(Cart& cart, const string& customerName) {
    if (cart.isEmpty()) {
        cout << "\n   Cart is empty! Add products first.\n";
        return;
    }

    printHeader("PLACE ORDER");

    cout << "  Payment Methods:\n";
    cout << "  1. Cash on Delivery\n";
    cout << "  2. Card Payment\n";
    cout << "  Choose payment method: ";
    int pm;
    cin >> pm;
    string method = (pm == 2) ? "Card Payment" : "Cash on Delivery";

    // OOP Concept: Composition — Order is created with Payment inside it
    Order* order = new Order(1001, "14-04-2025",
                             cart.getTotal(), method,
                             cart.getItemNames());

    // OOP Concept: Friend Function — applyDiscount accesses private Payment data
    cout << "\n  Apply Discount? (1=Yes / 0=No): ";
    int applyD;
    cin >> applyD;
    if (applyD == 1) {
        cout << "  Enter discount %: ";
        double disc;
        cin >> disc;
        applyDiscount(order->getPayment(), disc);
    }

    order->displayOrder();
    cout << "\n   Order placed successfully! Thank you, " << customerName << "!\n";

    delete order;   // OOP Concept: Dynamic Memory (delete)
}

// Shows profiles of both Customer and Admin
// OOP Concept: Inheritance + Runtime Polymorphism (showProfile override)
void handleShowProfiles(const Customer& customer, const Admin& admin) {
    printHeader("USER PROFILES");
    customer.showProfile();
    admin.showProfile();
}

// Prints the main menu options
void printMenu(const string& username) {
    printHeader("MAIN MENU");
    cout << "  Logged in as: " << username << "\n\n";
    cout << "  1. View Products\n";
    cout << "  2. Add to Cart (by ID)\n";
    cout << "  3. Add to Cart (by Name)\n";
    cout << "  4. View Cart\n";
    cout << "  5. Place Order\n";
    cout << "  6. Show User Profiles\n";
    cout << "  7. Exit\n";
    cout << "\n  Enter your choice: ";
}

// ============================================================
// MAIN FUNCTION — Clean and simple
// All logic is delegated to helper functions above
// ============================================================
int main() {

    printHeader("ONLINE SHOPPING SYSTEM");

    // ── Create Customer (OOP: Inheritance) ──────────────────
    cout << "\n[STEP 1] Creating Users...\n";
    string name, email, city;
    cout << "Enter customer name         : "; cin >> name;
    cout << "Enter customer email        : "; cin >> email;
    cout << "Enter customer city/country : "; cin >> city;

    Customer customer(name, email, city);
    Admin    admin("admin_user", "admin@shop.pk", "ADM-2025");

    // ── Load Products (OOP: Dynamic Memory, Polymorphism) ───
    vector<Product*> allProducts;
    loadProducts(allProducts);

    // ── Create Cart (OOP: Aggregation) ──────────────────────
    Cart cart;

    // ── Menu Loop ────────────────────────────────────────────
    int  choice  = 0;
    bool running = true;

    while (running) {
        printMenu(customer.getUsername());
        cin >> choice;

        switch (choice) {
            case 1: handleViewProducts(allProducts);                         break;
            case 2: handleAddByID(cart, allProducts);                        break;
            case 3: handleAddByName(cart, allProducts);                      break;
            case 4: printHeader("VIEW CART"); cart.viewCart();               break;
            case 5: handlePlaceOrder(cart, customer.getUsername());          break;
            case 6: handleShowProfiles(customer, admin);                     break;
            case 7: running = false;
                    cout << "\n  Thank you for using Online Shopping System!\n";
                    cout << "  Exiting... (Watch destructors below)\n\n";    break;
            default: cout << "\n   Invalid choice! Please try again.\n";
        }
    }

    // ── Cleanup (OOP: Dynamic Memory delete) ────────────────
    cleanupProducts(allProducts);

    return 0;
}

// ============================================================
// OOP CONCEPTS SUMMARY (Quick Reference)
// ------------------------------------------------------------
// 1.  Inheritance        : User -> Customer, Admin
//                          Product -> Electronics, Clothing
// 2.  Polymorphism       : displayProduct() virtual, overridden
//                          showProfile() virtual, overridden
// 3.  Abstract Class     : Product (pure virtual displayProduct)
// 4.  Encapsulation      : private variables + getters/setters
// 5.  Composition        : Order HAS-A Payment (inside Order)
// 6.  Aggregation        : Cart stores Product* (external objs)
// 7.  Friend Function    : applyDiscount accesses Payment private
// 8.  Struct             : OrderDetails { orderID, date }
// 9.  Constructors       : All classes have constructors
// 10. Destructors        : All classes print on destruction
// 11. Function Overload  : addToCart(int) & addToCart(string)
// 12. STL vector         : vector<Product*>, vector<string>
// 13. Dynamic Memory     : new Product, delete p
// ============================================================