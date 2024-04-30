
/*Syed Ashher Majid
  23i-007
  CS(A)
  Dr.Ali Zeeshan
  Mohammad Abdul Rafay
*/



#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

class ALU {
private:
    int NoOfAdders;
    int NoOfSubtractor;
    int NoOfRegisters;
    int sizeOfRegisters;

public:
    ALU();
    ALU(int adders, int subtractors, int registers, int registerSize);

    int getNoOfAdders() const;
    void setNoOfAdders(int adders);
    int getNoOfSubtractor() const;
    void setNoOfSubtractor(int subtractors);
    int getNoOfRegisters() const;
    void setNoOfRegisters(int registers);
    int getSizeOfRegisters() const;
    void setSizeOfRegisters(int registerSize);

    void insert();
    void display() const;
};

class ControlUnit {
private:
    float clock;

public:
    ControlUnit();
    ControlUnit(float clk);

    float getClock() const;
    void setClock(float clk);

    void insert();
    void display() const;
};

class GraphicsCard {
protected:
    string brand;
    int memorySize;
    double price;

public:
    GraphicsCard();
    GraphicsCard(const string& br, int memSize, double pr);

    string getBrand() const;
    void setBrand(const string& br);
    int getMemorySize() const;
    void setMemorySize(int memSize);
    double getPrice() const;
    void setPrice(double pr);
    virtual void insert();
    virtual void display() const;
};

class NvidiaAmdGPU : public GraphicsCard {
public:
    NvidiaAmdGPU();
    NvidiaAmdGPU(const string& br, int memSize, double pr, const string& type);

    string getGPUType() const;
    void insert() override;
    void display() const override;

private:
    string gpuType;
};

class AppleGPU : public GraphicsCard {
public:
    AppleGPU();
    AppleGPU(const string& br, int memSize, double pr, const string& type);

    string getGPUType() const;
    void insert() override;
    void display() const override;

private:
    string gpuType;
};

class CPU {
protected:
    ALU* alu;
    ControlUnit* cu;

public:
    CPU();
    CPU(ALU* alu, ControlUnit* cu);
    ~CPU();

    ALU* getALU() const;
    void setALU(ALU* alu);
    ControlUnit* getCU() const;
    void setCU(ControlUnit* cu);

    virtual void insert() = 0;
    virtual void display() const = 0;
};

class IntelAmdCPU : public CPU {
public:
    IntelAmdCPU();
    IntelAmdCPU(ALU* alu, ControlUnit* cu, GraphicsCard* gpu);

    GraphicsCard* getGPU() const;
    void setGPU(GraphicsCard* graphics);
    string getArchitecture() const;

    void insert() override;
    void display() const override;

private:
    GraphicsCard* gpu;
    string architecture;
};


class AppleCPU : public CPU {
public:
    AppleCPU();
    AppleCPU(const string& architecture, AppleGPU* gpu);

    void setArchitecture(const string& architecture);
    void setGPU(AppleGPU* gpu);

    string getArchitecture() const;
    AppleGPU* getGPU() const;

    void insert() override;
    void display() const override;

private:
    AppleGPU* gpu;
    string architecture;
};
class MainMemory {
private:
    int capacity;
    string technologyType;

public:
    MainMemory();
    MainMemory(int cap, string techType);

    int getCapacity() const;
    void setCapacity(int cap);
    string getTechnologyType() const;
    void setTechnologyType(string techType);

    void insert();
    void display() const;
};

class Port {
private:
    string type;
    int baud_rate;

public:
    Port();
    Port(const string& portType, int rate);

    string getType() const;
    void setType(const string& portType);
    int getBaudRate() const;
    void setBaudRate(int rate);

    void insert();
    void display() const;
};

class MotherBoard {
private:
    MainMemory* mm;
    Port* ports;
    int numOfPorts;

public:
    MotherBoard();
    MotherBoard(MainMemory* memory, Port* prt, int numPorts);
    ~MotherBoard();

    MainMemory* getMainMemory() const;
    void setMainMemory(MainMemory* memory);
    Port* getPorts() const;
    void setPorts(Port* prt);
    int getNumOfPorts() const;
    void setNumOfPorts(int numPorts);

    void insert();
    void display() const;
};

class PhysicalMemory {
protected:
    int capacity;

public:
    PhysicalMemory();
    PhysicalMemory(int cap);

    int getCapacity() const;
    void setCapacity(int cap);

    virtual void insert();
    virtual void display() const;
};

class DDRMemory : public PhysicalMemory {
public:
    DDRMemory();
    DDRMemory(int cap, const string& type);

    string getMemoryType() const;

    void insert() override;
    void display() const override;

private:
    string memoryType;
};

class LPDDRMemory : public PhysicalMemory {
public:
    LPDDRMemory();
    LPDDRMemory(int cap, const string& type);

    string getMemoryType() const;

    void insert() override;
    void display() const override;

private:
    string memoryType;
};

class Computer {
private:
    PhysicalMemory* pm;
    MotherBoard* mb;
    CPU* cpu;

public:
    Computer();
    Computer(PhysicalMemory* mem, MotherBoard* board, CPU* processor);
    ~Computer();

    PhysicalMemory* getPhysicalMemory() const;
    void setPhysicalMemory(PhysicalMemory* mem);
    MotherBoard* getMotherBoard() const;
    void setMotherBoard(MotherBoard* board);
    CPU* getCPU() const;
    void setCPU(CPU* processor);

    void insertMotherBoard();
    void insertCPU(const string& cpuType);
    void insertMemory(const string& cpuType);

    void display() const;
};

class StorageDevice {
private:
    string type;
    int capacity;
    double price;

public:
    StorageDevice();
    StorageDevice(const string& t, int cap, double pr);

    string getType() const;
    void setType(const std::string& t);
    int getCapacity() const;
    void setCapacity(int cap);
    double getPrice() const;
    void setPrice(double pr);

    void insert();
    void display() const;
};

class NetworkCard {
private:
    string type;
    int speed;
    double price;

public:
    NetworkCard();
    NetworkCard(const string& t, int sp, double pr);

    string getType() const;
    void setType(const string& t);
    int getSpeed() const;
    void setSpeed(int sp);
    double getPrice() const;
    void setPrice(double pr);

    void insert();
    void display() const;
};

class PowerSupply {
private:
    int wattage;
    string efficiencyRating;
    double price;

public:
    PowerSupply();
    PowerSupply(int w, const string& rating, double pr);

    int getWattage() const;
    void setWattage(int w);
    string getEfficiencyRating() const;
    void setEfficiencyRating(const string& rating);
    double getPrice() const;
    void setPrice(double pr);

    void insert();
    void display() const;
};

class Battery {
private:
    int capacity;

public:
    Battery();
    Battery(int cap);

    int getCapacity() const;
    void setCapacity(int cap);

    void insert();
    void display() const;
};

class Case {
private:
    string formFactor;
    string color;
    double price;

public:
    Case();
    Case(const string& form, const string& col, double pr);

    string getFormFactor() const;
    void setFormFactor(const string& form);
    string getColor() const;
    void setColor(const string& col);
    double getPrice() const;
    void setPrice(double pr);

    void insert();
    void display() const;
};

class ComputerAssembly {
protected:
    StorageDevice* storage;
    NetworkCard* network;
    PowerSupply* psu;
    Battery* battery;
    Case* computerCase;
    double totalPrice;

public:
    ComputerAssembly(StorageDevice* storageDevice = nullptr,
        NetworkCard* netCard = nullptr, PowerSupply* powerSupply = nullptr,
        Battery* batt = nullptr, Case* pcCase = nullptr, double price = 0.0);
        

    ~ComputerAssembly();

    StorageDevice* getStorage() const;
    void setStorage(StorageDevice* storageDevice);
    NetworkCard* getNetwork() const;
    void setNetwork(NetworkCard* netCard);
    PowerSupply* getPSU() const;
    void setPSU(PowerSupply* powerSupply);
    Battery* getBattery() const;
    void setBattery(Battery* batt);
    Case* getComputerCase() const;
    void setComputerCase(Case* pcCase);
    double getTotalPrice() const;
    void setTotalPrice(double price);

    void insert();
    void display() const;
};

class AppleComputerAssembly : public ComputerAssembly {
private:
    Computer* computer;
    AppleGPU* gpu;

public:
    AppleComputerAssembly(StorageDevice* storageDevice = nullptr,
        NetworkCard* netCard = nullptr, PowerSupply* powerSupply = nullptr,
        Battery* batt = nullptr, Case* pcCase = nullptr, double price = 0.0,
        Computer* comp = nullptr, AppleGPU* graphics = nullptr);

    ~AppleComputerAssembly();

    Computer* getComputer() const;
    void setComputer(Computer* comp);
    AppleGPU* getGPU() const;
    void setGPU(AppleGPU* graphics);

    void insert();
    void display() const;
};

class PCComputerAssembly : public ComputerAssembly {
private:
    Computer* computer;
    NvidiaAmdGPU* gpu;

public:
    PCComputerAssembly(StorageDevice* storageDevice = nullptr,
        NetworkCard* netCard = nullptr, PowerSupply* powerSupply = nullptr,
        Battery* batt = nullptr, Case* pcCase = nullptr, double price = 0.0,
        Computer* comp = nullptr, NvidiaAmdGPU* graphics = nullptr);

    ~PCComputerAssembly();

    Computer* getComputer() const;
    void setComputer(Computer* comp);
    NvidiaAmdGPU* getGPU() const;
    void setGPU(NvidiaAmdGPU* graphics);

    void insert();
    void display() const;
};