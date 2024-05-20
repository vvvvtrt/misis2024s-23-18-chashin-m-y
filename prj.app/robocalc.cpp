#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


class Base {
public:
    virtual void operation(double& l, double& r) {}
};


class ADD : public Base {
    void operation(double& l, double& r) override{
        l = l + r;
    }
};

class MUL : public Base {
    void operation(double& l, double& r) override {
        l = l - r;
    }
};

class SUB : public Base {
    void operation(double& l, double& r) override {
        l = l * r;
    }
};

class DIV : public Base {
    void operation(double& l, double& r) override {
        if (r == 0) {
            throw "r value zero";
        }

        l = l / r;
    }
};



void Execute(std::vector<std::string> command) {

    std::istringstream iss(command);
    std::string _command;
    double _number;

    iss >> _command >> _number;

    Base* cmd;

    if (_command == "ADD") {
        cmd = new ADD();
    } else if (_command == "MUL") {
        cmd = new MUL();
    } else if (_command == "SUB") {
        cmd = new SUB();
    } else if (_command == "DIV") {
        cmd = new DIV();
    } else if (_command == "OUT") {
        std::cout << ans << std::endl;
        return;
    } else {
        return;
    }

    cmd->operation(ans, _number);
    delete cmd;
}


int main() {
    std::ifstream file("command.txt");

    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    std::string line;
    std::vector<std::string> command;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string _command;
        double _number;

        iss >> _command >> _number;

        if (_command == "OUT"){
            Execute(line, __number);
        }

    }

    file.close();

    return 0;
}
