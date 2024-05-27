#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory> 

class Base {
public:
    Base(double r) : r_value(r) {}
    virtual ~Base() = default; 

    virtual void operation(double& l) {} 

protected:
    double r_value;
};

class ADD : public Base {
public:
    ADD(double r) : Base(r) {}
    void operation(double& l) override {
        l = l + r_value;
    }
};

class MUL : public Base {
public:
    MUL(double r) : Base(r) {}
    void operation(double& l) override {
        l = l * r_value;
    }
};

class SUB : public Base {
public:
    SUB(double r) : Base(r) {}
    void operation(double& l) override {
        l = l - r_value;
    }
};

class DIV : public Base {
public:
    DIV(double r) : Base(r) {}
    void operation(double& l) override {
        if (r_value == 0) {
            throw std::runtime_error("r value zero"); 
        }
        l = l / r_value;
    }
};

int main() {
    std::ifstream file("command.txt");

    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    std::string line;
    std::vector<std::unique_ptr<Base>> command2;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string _command;
        double _number;

        iss >> _command >> _number;

        if (_command == "OUT") {
            for (const auto& temp : command2) { 
                temp->operation(_number);
            }
            std::cout << _number << "\n";
        }
        else if (_command == "REV") {
            for (int i = 0; i < _number && command2.size() > 0; i++) {
                command2.pop_back();
            }
        }
        else {
            if (_command == "ADD") { 
                command2.push_back(std::make_unique<ADD>(_number)); 
            }
            else if (_command == "MUL") { 
                command2.push_back(std::make_unique<MUL>(_number)); 
            }
            else if (_command == "SUB") { 
                command2.push_back(std::make_unique<SUB>(_number)); 
            }
            else if (_command == "DIV") { 
                command2.push_back(std::make_unique<DIV>(_number)); 
            }
        }
    }

    file.close();

    return 0;
}
