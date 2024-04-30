/*Syed Ashher Majid
  23i-007
  CS(A)
  Dr.Ali Zeeshan
  Mohammad Abdul Rafay
*/


#include<iostream>
#include<string>
#include<cstring>
#include "i23-0007_A.h"
using namespace std;


ALU::ALU()
    : NoOfAdders(0), NoOfSubtractor(0), NoOfRegisters(0), sizeOfRegisters() {}

ALU::ALU(int adders, int subtractors, int registers, int registerSize)
    : NoOfAdders(adders), NoOfSubtractor(subtractors), NoOfRegisters(registers), sizeOfRegisters(registerSize) {}

int ALU::getNoOfAdders() const {
    return NoOfAdders;
}

void ALU::setNoOfAdders(int adders) {
    NoOfAdders = adders;
}

int ALU::getNoOfSubtractor() const {
    return NoOfSubtractor;
}

void ALU::setNoOfSubtractor(int subtractors) {
    NoOfSubtractor = subtractors;
}

int ALU::getNoOfRegisters() const {
    return NoOfRegisters;
}

void ALU::setNoOfRegisters(int registers) {
    NoOfRegisters = registers;
}

int ALU::getSizeOfRegisters() const {
    return sizeOfRegisters;
}

void ALU::setSizeOfRegisters(int registerSize) {
    sizeOfRegisters = registerSize;
}

void ALU::insert() {
    cout << "Enter ALU details:" << endl;
    do {
        cout << "Number of Adders(1-100): ";
        if (!(cin >> NoOfAdders) || NoOfAdders <= 0 || NoOfAdders > 100 || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a non-negative integer for the number of adders." << endl;
            cin.clear();
            cin.ignore(numeric_limits  <streamsize>::max(), '\n');
        }
    } while (NoOfAdders <= 0 || NoOfAdders > 100  || cin.peek() != '\n');

    // Input validation for number of subtractors
    do {
        cout << "Number of Subtractors(1-100): ";
        if (!(cin >> NoOfSubtractor) || NoOfSubtractor <= 0 || NoOfSubtractor > 100 || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a non-negative integer for the number of subtractors." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (NoOfSubtractor <= 0 || NoOfSubtractor > 100  || cin.peek() != '\n');

    // Input validation for number of registers
    do {
        cout << "Number of Registers(1-100): ";
        if (!(cin >> NoOfRegisters) || NoOfRegisters <= 0 || NoOfRegisters > 100 || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a non-negative integer for the number of registers." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (NoOfRegisters <= 0 || NoOfRegisters > 100 || cin.peek() != '\n');

    // Input validation for size of registers
    do {
        cout << "Size of Registers(8/16/32/64 bit): ";
        if (!(cin >> sizeOfRegisters) || (sizeOfRegisters != 8 && sizeOfRegisters != 16 && sizeOfRegisters != 32 && sizeOfRegisters != 64) || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a non-negative integer for the size of registers(8/16/32/64 bit)." << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
    } while ( sizeOfRegisters != 8 &&  sizeOfRegisters != 16 && sizeOfRegisters != 32 && sizeOfRegisters != 64 || cin.peek() != '\n');
}
void ALU::display() const {
    cout << "ALU Details:" << endl;
    cout << "Number of Adders: " << NoOfAdders << endl;
    cout << "Number of Subtractors: " << NoOfSubtractor << endl;
    cout << "Number of Registers: " << NoOfRegisters << endl;
    cout << "Size of Registers: " << sizeOfRegisters << endl;
}

ControlUnit::ControlUnit()
    : clock(0.0f) {}

ControlUnit::ControlUnit(float clk)
    : clock(clk) {}

float ControlUnit::getClock() const {
    return clock;
}

void ControlUnit::setClock(float clk) {
    clock = clk;
}

void ControlUnit::insert() {
    cout << "Enter Control Unit details:" << endl;
    do {
        cout << "Clock (GHz)(1-6.5): ";
        if (!(cin >> clock) || clock <= 0 || clock > 6.5 || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a positive float value for the clock speed in GHz(1-6.5)." << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
    } while (clock <= 0 || clock > 6.5 || cin.peek() != '\n');
}

void ControlUnit::display() const {
    cout << "Control Unit Details:" << endl;
    cout << "Clock: " << clock << endl;
}


GraphicsCard::GraphicsCard()
    : brand(""), memorySize(0), price(0.0) {}

GraphicsCard::GraphicsCard(const string& br, int memSize, double pr)
    : brand(br), memorySize(memSize), price(pr) {}

string GraphicsCard::getBrand() const {
    return brand;
}

void GraphicsCard::setBrand(const string& br) {
    brand = br;
}

int GraphicsCard::getMemorySize() const {
    return memorySize;
}

void GraphicsCard::setMemorySize(int memSize) {
    memorySize = memSize;
}

double GraphicsCard::getPrice() const {
    return price;
}

void GraphicsCard::setPrice(double pr) {
    price = pr;
}

void GraphicsCard::insert() {
    cin.ignore();
    cout << "Enter the brand of the graphics card: ";
    getline(cin, brand);

    do {
        cout << "Enter the memory size (GB)(2/4/6/8): ";
        if (!(cin >> memorySize) || (memorySize != 2 && memorySize != 4 && memorySize != 6 && memorySize != 8) || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a positive integer value for memory size(2/4/6/8)." << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
    } while (memorySize != 2 && memorySize != 4 && memorySize != 6 && memorySize != 8 || cin.peek() != '\n');

    cin.ignore(); // Ignore the newline character in the input buffer
}

void GraphicsCard::display() const {
    cout << "Brand: " << brand << endl;
    cout << "Memory Size: " << memorySize << " GB" << endl;
}

NvidiaAmdGPU::NvidiaAmdGPU()
    : GraphicsCard("", 0, 0.0), gpuType("Nvidia/AMD") {}

NvidiaAmdGPU::NvidiaAmdGPU(const string& br, int memSize, double pr, const string& type)
    : GraphicsCard(br, memSize, pr), gpuType(type) {}

string NvidiaAmdGPU::getGPUType() const {
    return gpuType;
}

void NvidiaAmdGPU::insert() {
    GraphicsCard::insert(); // Call base class insert function

    cout << "Enter the GPU type (Nvidia/AMD): ";
    getline(cin, gpuType);
}

void NvidiaAmdGPU::display() const {
    GraphicsCard::display(); // Call base class display function

    cout << "GPU Type: " << gpuType << endl;
}

AppleGPU::AppleGPU()
    : GraphicsCard("", 0, 0.0), gpuType("AppleGPU") {}

AppleGPU::AppleGPU(const string& br, int memSize, double pr, const string& type)
    : GraphicsCard(br, memSize, pr), gpuType(type) {}

string AppleGPU::getGPUType() const {
    return gpuType;
}

void AppleGPU::insert() {
    GraphicsCard::insert(); // Call base class insert function

    cout << "Enter the GPU type (AppleGPU): ";
    getline(cin, gpuType);
}

void AppleGPU::display() const {
    GraphicsCard::display(); // Call base class display function

    cout << "GPU Type: " << gpuType << endl;
}

// CPU methods definition
CPU::CPU()
    : alu(nullptr), cu(nullptr) {}

CPU::CPU(ALU* alu, ControlUnit* cu)
    : alu(alu), cu(cu) {}

CPU::~CPU() {
    delete alu;
    delete cu;
}

ALU* CPU::getALU() const {
    return alu;
}

void CPU::setALU(ALU* alu) {
    this->alu = alu;
}

ControlUnit* CPU::getCU() const {
    return cu;
}

void CPU::setCU(ControlUnit* cu) {
    this->cu = cu;
}

// IntelAmdCPU methods definition
IntelAmdCPU::IntelAmdCPU()
    : CPU(nullptr, nullptr), gpu(nullptr), architecture("x86") {}

IntelAmdCPU::IntelAmdCPU(ALU* alu, ControlUnit* cu, GraphicsCard* gpu)
    : CPU(alu, cu), gpu(gpu), architecture("x86") {}

GraphicsCard* IntelAmdCPU::getGPU() const {
    return gpu;
}

void IntelAmdCPU::setGPU(GraphicsCard* graphics) {
    gpu = graphics;
}

string IntelAmdCPU::getArchitecture() const {
    return architecture;
}

void IntelAmdCPU::insert() {
    //cout << "Enter CPU details for Intel/AMD:" << endl;
    cout << "Enter CPU details for Intel/AMD:" << endl;
    // Insert ALU details
    alu = new ALU();
    alu->insert();
    // Insert ControlUnit details
    cu = new ControlUnit();
    cu->insert();

    if (gpu) {
        gpu = new GraphicsCard();
        gpu->insert();
    }
}

void IntelAmdCPU::display() const {
    cout << "CPU Details for Intel/AMD:" << endl;
    // Display ALU details
    alu->display();
    // Display ControlUnit details
    cu->display();
    // Display GPU details (if available)
    if (gpu) {
        gpu->display();
    }
}




// AppleCPU methods definition
AppleCPU::AppleCPU()
    : CPU(nullptr, nullptr), gpu(new AppleGPU()), architecture("ARM64") {}

AppleCPU::AppleCPU(const string& architecture, AppleGPU* gpu) : CPU(nullptr, nullptr), gpu(gpu), architecture(architecture) {

}

void AppleCPU::setArchitecture(const string& architecture) {
    this->architecture = architecture;
}

void AppleCPU::setGPU(AppleGPU* gpu) {
    this->gpu = gpu;
}

string AppleCPU::getArchitecture() const {
    return architecture;
}

AppleGPU* AppleCPU::getGPU() const {
    return gpu;
}

void AppleCPU::insert() {
    cout << "Enter CPU details for Apple:" << endl;
    // Insert ALU details
    alu = new ALU();
    alu->insert();
    // Insert ControlUnit details
    cu = new ControlUnit();
    cu->insert();
    // Insert GPU details
   /* gpu = new AppleGPU();
    gpu->insert();*/
}

void AppleCPU::display() const {
    cout << "CPU Details for Apple:" << endl;
    cout << "CPU Details for Apple:" << endl;
    // Display ALU details
    alu->display();
    // Display ControlUnit details
    cu->display();
    // Display GPU details
    gpu->display();
}

MainMemory::MainMemory()
    : capacity(0), technologyType("Semiconductor") {}

MainMemory::MainMemory(int cap, string techType)
    : capacity(cap), technologyType(techType) {}

int MainMemory::getCapacity() const {
    return capacity;
}

void MainMemory::setCapacity(int cap) {
    capacity = cap;
}

string MainMemory::getTechnologyType() const {
    return technologyType;
}

void MainMemory::setTechnologyType(string techType) {
    technologyType = techType;
}

void MainMemory::insert() {
    cout << "Enter Main Memory details:" << endl;
    // Input validation for capacity
    while (true) {
        cout << "Capacity (GB)(4/8/16/32/64/128): ";
        cin >> capacity;
        if (capacity == 2 || capacity == 4 || capacity == 8 || capacity == 16 || capacity == 32 || capacity == 64 || capacity == 128) {
            break;
        }
        else {
            cout << "Invalid input. Capacity must be a positive integer(4/8/16/32/64/128)." << endl;
            cin.clear();
            cin.ignore(numeric_limits  <streamsize>::max(), '\n');
        }
    }

    // Input validation for technology type
    cin.ignore(); // Clear input buffer before getline
    while (true) {
        cout << "Technology Type(Semiconductor/Silicon): ";
        getline(cin, technologyType);
        if (technologyType == "Semiconductor" || technologyType =="Silicon") {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid technology type(Semiconductor/Silicon)." << endl;
        }
    }
}

void MainMemory::display() const {
    cout << "Main Memory Details:" << endl;
    cout << "Capacity: " << capacity << " GB" << endl;
    cout << "Technology Type: " << technologyType << endl;
}

Port::Port()
    : type("VGI Port"), baud_rate(0) {}

Port::Port(const string& portType, int rate)
    : type(portType), baud_rate(rate) {}

string Port::getType() const {
    return type;
}

void Port::setType(const string& portType) {
    type = portType;
}

int Port::getBaudRate() const {
    return baud_rate;
}

void Port::setBaudRate(int rate) {
    baud_rate = rate;
}

void Port::insert() {
    cin.ignore();
    cout << "Enter Port details:" << endl;
    while (true) {
        cout << "Type(VGI, I/O, USB, HDMI): ";
       
        getline(cin, type);
        if (type == "VGI" || type == "I/O" || type == "USB" || type == "HDMI") {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid port type(VGI, I/O, USB, HDMI)." << endl;
        }
    }

    // Input validation for baud rate
    while (true) {
        cout << "Baud Rate(bps): ";
        if (cin >> baud_rate && baud_rate > 0) {
            break;
        }
        else {
            cout << "Invalid input. Baud rate must be a positive integer(bps)." << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
    }
}

void Port::display() const {
    cout << "Port Details:" << endl;
    cout << "Type: " << type << endl;
    cout << "Baud Rate: " << baud_rate << endl;
}

MotherBoard::MotherBoard()
    : mm(nullptr), ports(nullptr), numOfPorts(0) {}

MotherBoard::MotherBoard(MainMemory* memory, Port* prt, int numPorts)
    : mm(memory), ports(prt), numOfPorts(numPorts) {}

MotherBoard::~MotherBoard() {
    delete mm;
    delete[] ports;
}

MainMemory* MotherBoard::getMainMemory() const {
    return mm;
}

void MotherBoard::setMainMemory(MainMemory* memory) {
    mm = memory;
}

Port* MotherBoard::getPorts() const {
    return ports;
}

void MotherBoard::setPorts(Port* prt) {
    ports = prt;
}

int MotherBoard::getNumOfPorts() const {
    return numOfPorts;
}

void MotherBoard::setNumOfPorts(int numPorts) {
    numOfPorts = numPorts;
}

void MotherBoard::insert() {
    cout << "Enter MotherBoard details:" << endl;
    mm = new MainMemory();
    mm->insert();

    while (true) {
        cout << "Number of Ports: ";
        if (cin >> numOfPorts && numOfPorts > 0) {
            break;
        }
        else {
            cout << "Invalid input. Number of ports must be a positive integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits        <streamsize>::max(), '\n');
        }
    }

    ports = new Port[numOfPorts];
    for (int i = 0; i < numOfPorts; ++i) {
        cout << "Enter details for Port " << i + 1 << ":" << endl;
        ports[i].insert();
    }
}

void MotherBoard::display() const {
    cout << "MotherBoard Details:" << endl;
    mm->display();
    cout << "Number of Ports: " << numOfPorts << endl;
    for (int i = 0; i < numOfPorts; ++i) {
        cout << "Port " << i + 1 << " Details:" << endl;
        ports[i].display();
    }
}

PhysicalMemory::PhysicalMemory()
    : capacity(0) {}

PhysicalMemory::PhysicalMemory(int cap)
    : capacity(cap) {}

int PhysicalMemory::getCapacity() const {
    return capacity;
}

void PhysicalMemory::setCapacity(int cap) {
    capacity = cap;
}

void PhysicalMemory::insert() {
    while (true) {
        cout << "Enter Physical Memory Capacity (2/4/8/16/32/64 GB): ";
        cin >> capacity;
        if ( capacity == 2 || capacity == 4 || capacity == 8 || capacity == 16 || capacity == 32 || capacity == 64) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive integer for capacity(2/4/8/16/32/64 GB)." << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
        }
    }
}

void PhysicalMemory::display() const {
    cout << "Physical Memory Capacity: " << capacity << " GB" << endl;
}

DDRMemory::DDRMemory() : PhysicalMemory(0), memoryType("DDR") {}

DDRMemory::DDRMemory(int cap, const string& type) : PhysicalMemory(cap), memoryType(type) {}

string DDRMemory::getMemoryType() const {
    return memoryType;
}

void DDRMemory::insert() {
    PhysicalMemory::insert();
    cout << "Your PC Memory Type is: DDR" << endl;
    memoryType = "DDR4/5";
}

void DDRMemory::display() const {
    PhysicalMemory::display();
    cout << "DDR Memory Type: " << memoryType << endl;
}

LPDDRMemory::LPDDRMemory() : PhysicalMemory(0), memoryType("LPDDR") {}

LPDDRMemory::LPDDRMemory(int cap, const string& type) : PhysicalMemory(cap), memoryType(type) {}

string LPDDRMemory::getMemoryType() const {
    return memoryType;
}

void LPDDRMemory::insert() {
    PhysicalMemory::insert();
    cout << "Your Mac memory type is: LPDDR" << endl;
    memoryType = "LPDDR4/5";
}

void LPDDRMemory::display() const {
    PhysicalMemory::display();
    cout << "LPDDR Memory Type: " << memoryType << endl;
}

Computer::Computer() : pm(nullptr), mb(nullptr), cpu(nullptr) {}

Computer::Computer(PhysicalMemory* mem, MotherBoard* board, CPU* processor) : pm(mem), mb(board), cpu(processor) {}

Computer::~Computer() {
    delete pm;
    delete mb;
    delete cpu;
}

PhysicalMemory* Computer::getPhysicalMemory() const {
    return pm;
}

void Computer::setPhysicalMemory(PhysicalMemory* mem) {
    pm = mem;
}

MotherBoard* Computer::getMotherBoard() const {
    return mb;
}

void Computer::setMotherBoard(MotherBoard* board) {
    mb = board;
}

CPU* Computer::getCPU() const {
    return cpu;
}

void Computer::setCPU(CPU* processor) {
    cpu = processor;
}

void Computer::insertMotherBoard() {
    mb = new MotherBoard();
    mb->insert();
}

void Computer::insertCPU(const string& cpuType) {
    if (cpuType == "Apple") {
        cpu = new AppleCPU(); // Create apple CPU
    }
    else if (cpuType == "PC") {
        cpu = new IntelAmdCPU(); // Create Intel/AMD CPU
    }
    else {
        cout << "Invalid CPU type!" << endl;
    }
    cpu->insert();
}

void Computer::insertMemory(const string& cpuType) {
    if (cpuType == "Apple") {
        // Create apple CPU
        pm = new LPDDRMemory();
    }
    else if (cpuType == "PC") {
        // Create Intel/AMD CPU
        pm = new DDRMemory();
    }
    else {
        cout << "Invalid CPU type!" << endl;
    }

    pm->insert();
}

void Computer::display() const {
    pm->display();
    mb->display();
    cpu->display();
}

StorageDevice::StorageDevice() : type(""), capacity(0), price(55.5) {}

StorageDevice::StorageDevice(const string& t, int cap, double pr) : type(t), capacity(cap), price(pr) {}

string StorageDevice::getType() const {
    return type;
}

void StorageDevice::setType(const std::string& t) {
    type = t;
}

int StorageDevice::getCapacity() const {
    return capacity;
}

void StorageDevice::setCapacity(int cap) {
    capacity = cap;
}

double StorageDevice::getPrice() const {
    return price;
}

void StorageDevice::setPrice(double pr) {
    price = pr;
}

void StorageDevice::insert() {
    cin.ignore();
    
    while (true) {
        cout << "Enter the type of storage device(SDD/HDD): ";
       // cin.ignore();
        getline(cin, type);
        if (type == "SDD" || type == "HDD") {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid storage device(SDD/HDD)." << endl;
            //cout << "hello" << endl;
        }
    }

    while (true) {
        cout << "Enter the capacity (GB)(100/200/500/1000): ";
        cin >> capacity;
        if (capacity == 100 || capacity == 200 || capacity == 500 || capacity == 1000) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive integer for capacity(GB)(100/200/500/1000)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cin.ignore(); // Ignore the newline character in the input buffer
}

void StorageDevice::display() const {
    cout << "Type: " << type << endl;
    cout << "Capacity: " << capacity << " GB" << endl;
    //  cout << "Price: $" << price << endl;
}

NetworkCard::NetworkCard() : type(""), speed(0), price(70) {}

NetworkCard::NetworkCard(const string& t, int sp, double pr) : type(t), speed(sp), price(pr) {}

string NetworkCard::getType() const {
    return type;
}

void NetworkCard::setType(const string& t) {
    type = t;
}

int NetworkCard::getSpeed() const {
    return speed;
}

void NetworkCard::setSpeed(int sp) {
    speed = sp;
}

double NetworkCard::getPrice() const {
    return price;
}

void NetworkCard::setPrice(double pr) {
    price = pr;
}

void NetworkCard::insert() {
    cin.ignore();
    cout << "Enter details of network card: " << endl;

    while (true) {
        cout << "Enter the type of network card(Ethernet/Wifi): ";
       // cin.ignore();
        getline(cin, type);
        if (type == "Ethernet" || type == "Wifi" ) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid network card(Ethernet/Wifi)." << endl;
        }
    }

    while (true) {
        cout << "Enter the speed (Mbps)(1-100): ";
        cin >> speed;
        if ( speed > 0 && speed < 100) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive integer for speed(1-100 Mbps)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    cin.ignore(); // Ignore the newline character in the input buffer
}

void NetworkCard::display() const {
    cout << "Type: " << type << endl;
    cout << "Speed: " << speed << " Mbps" << endl;
    // cout << "Price: $" << price << endl;
}

PowerSupply::PowerSupply() : wattage(0), efficiencyRating(""), price(100) {}

PowerSupply::PowerSupply(int w, const string& rating, double pr) : wattage(w), efficiencyRating(rating), price(pr) {}

int PowerSupply::getWattage() const {
    return wattage;
}

void PowerSupply::setWattage(int w) {
    wattage = w;
}

string PowerSupply::getEfficiencyRating() const {
    return efficiencyRating;
}

void PowerSupply::setEfficiencyRating(const string& rating) {
    efficiencyRating = rating;
}

double PowerSupply::getPrice() const {
    return price;
}

void PowerSupply::setPrice(double pr) {
    price = pr;
}

void PowerSupply::insert() {
    cout << "Enter details of power supply" << endl;;
    while (true) {
        cout << "Enter the wattage(300-1000): ";
        cin >> wattage;
        if ( wattage >= 300 && wattage <= 1000) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive integer for wattage(300-1000)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    }

    cin.ignore(); // Ignore the newline character in the input buffer

    
   

    while (true) {
        cout << "Enter the efficiency rating(80 plus Bronze/ 80 plus Gold): ";
      //  cin.ignore();
        getline(cin, efficiencyRating);
        if (efficiencyRating == "80 plus Bronze" || efficiencyRating == "80 plus Gold") {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid efficiency rating(80 plus Bronze/ 80 plus Gold)." << endl;
        }
    }


    cin.ignore(); // Ignore the newline character in the input buffer
}

void PowerSupply::display() const {
    cout << "Wattage: " << wattage << "W" << endl;
    cout << "Efficiency Rating: " << efficiencyRating << endl;
    // cout << "Price: $" << price << endl;
}

Battery::Battery() : capacity(0) {}

Battery::Battery(int cap) : capacity(cap) {}

int Battery::getCapacity() const {
    return capacity;
}

void Battery::setCapacity(int cap) {
    capacity = cap;
}

void Battery::insert() {
    while (true) {
        cout << "Enter the capacity of the battery (mAh)(1000-10000): ";
        cin >> capacity;
        if ( capacity >= 1000 && capacity <=10000 ) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive integer for capacity." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    }
}

void Battery::display() const {
    cout << "Battery Capacity: " << capacity << " mAh" << endl;
}

Case::Case() : formFactor(""), color(""), price(110) {}

Case::Case(const string& form, const string& col, double pr) : formFactor(form), color(col), price(pr) {}

string Case::getFormFactor() const {
    return formFactor;
}

void Case::setFormFactor(const string& form) {
    formFactor = form;
}

string Case::getColor() const {
    return color;
}

void Case::setColor(const string& col) {
    color = col;
}

double Case::getPrice() const {
    return price;
}

void Case::setPrice(double pr) {
    price = pr;
}

void Case::insert() {
    cin.ignore();
    

   
    while (true) {
        cout << "Enter the form factor of the case(ATX/ Micro ATX): ";
      //  cin.ignore();
        getline(cin, formFactor);
        if (formFactor == "ATX" || formFactor == "Micro ATX") {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid formFactor(ATX/ Micro ATX)." << endl;
        }
    }

    cout << "Enter the color of the case: ";
    getline(cin, color);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
}

void Case::display() const {
    cout << "Case Form Factor: " << formFactor << endl;
    cout << "Case Color: " << color << endl;
    // cout << "Case Price: $" << price << endl;
}

ComputerAssembly::ComputerAssembly(StorageDevice* storageDevice,
    NetworkCard* netCard, PowerSupply* powerSupply,
    Battery* batt, Case* pcCase, double price)
    : storage(storageDevice), network(netCard),
    psu(powerSupply), battery(batt), computerCase(pcCase), totalPrice(price) {}

ComputerAssembly::~ComputerAssembly() {
    delete storage;
    delete network;
    delete psu;
    delete battery;
    delete computerCase;
}

StorageDevice* ComputerAssembly::getStorage() const { return storage; }
void ComputerAssembly::setStorage(StorageDevice* storageDevice) { storage = storageDevice; }

NetworkCard* ComputerAssembly::getNetwork() const { return network; }
void ComputerAssembly::setNetwork(NetworkCard* netCard) { network = netCard; }

PowerSupply* ComputerAssembly::getPSU() const { return psu; }
void ComputerAssembly::setPSU(PowerSupply* powerSupply) { psu = powerSupply; }

Battery* ComputerAssembly::getBattery() const { return battery; }
void ComputerAssembly::setBattery(Battery* batt) { battery = batt; }

Case* ComputerAssembly::getComputerCase() const { return computerCase; }
void ComputerAssembly::setComputerCase(Case* pcCase) { computerCase = pcCase; }

double ComputerAssembly::getTotalPrice() const { return totalPrice; }
void ComputerAssembly::setTotalPrice(double price) { totalPrice = price; }

void ComputerAssembly::insert() {
    cout << "Inserting components for Computer Assembly:" << endl;

    storage = new StorageDevice();
    storage->insert();

    network = new NetworkCard();
    network->insert();

    psu = new PowerSupply();
    psu->insert();

    battery = new Battery();
    battery->insert();

    computerCase = new Case();
    computerCase->insert();

    totalPrice =
        getStorage()->getPrice() +
        getNetwork()->getPrice() +
        getPSU()->getPrice() +
        getComputerCase()->getPrice();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
}

void ComputerAssembly::display() const {
    cout << "Displaying Computer Assembly Specifications:" << endl;

    storage->display();
    network->display();
    psu->display();
    battery->display();
    computerCase->display();
    cout << "Total Price: $" << totalPrice << endl;
}
AppleComputerAssembly::AppleComputerAssembly(StorageDevice* storageDevice,
    NetworkCard* netCard, PowerSupply* powerSupply,
    Battery* batt, Case* pcCase, double price,
    Computer* comp, AppleGPU* graphics)
    : ComputerAssembly(storageDevice, netCard, powerSupply, batt, pcCase, price),
    computer(comp), gpu(graphics) {}

AppleComputerAssembly::~AppleComputerAssembly() {
    delete computer;
    delete gpu;
}

Computer* AppleComputerAssembly::getComputer() const { return computer; }
void AppleComputerAssembly::setComputer(Computer* comp) { computer = comp; }

AppleGPU* AppleComputerAssembly::getGPU() const { return gpu; }
void AppleComputerAssembly::setGPU(AppleGPU* graphics) { gpu = graphics; }

void AppleComputerAssembly::insert() {
    ComputerAssembly::insert(); // Call base class insert function

    if (!computer) {
        computer = new Computer();
    }

    cout << "Inserting components for Apple Computer Assembly:" << endl;
    computer->insertMotherBoard();
    computer->insertMemory("Apple");
    computer->insertCPU("Apple");

    gpu = new AppleGPU();
    gpu->insert();
}

void AppleComputerAssembly::display() const {
    cout << endl << endl << endl;
    cout << "****************************************YOUR DEVICE IS READY*******************************************" << endl;
    cout << "***************************************HERE ARE THE SPECIFICATIONS***************************************" << endl;
    cout << "Displaying Apple Computer Assembly Specifications:" << endl;

    ComputerAssembly::display(); // Call base class display function

    computer->display();
    gpu->display();
}

PCComputerAssembly::PCComputerAssembly(StorageDevice* storageDevice,
    NetworkCard* netCard, PowerSupply* powerSupply,
    Battery* batt, Case* pcCase, double price,
    Computer* comp, NvidiaAmdGPU* graphics)
    : ComputerAssembly(storageDevice, netCard, powerSupply, batt, pcCase, price),
    computer(comp), gpu(graphics) {}

PCComputerAssembly::~PCComputerAssembly() {
    delete computer;
    delete gpu;
}

Computer* PCComputerAssembly::getComputer() const { return computer; }
void PCComputerAssembly::setComputer(Computer* comp) { computer = comp; }

NvidiaAmdGPU* PCComputerAssembly::getGPU() const { return gpu; }
void PCComputerAssembly::setGPU(NvidiaAmdGPU* graphics) { gpu = graphics; }

void PCComputerAssembly::insert() {
    ComputerAssembly::insert(); // Call base class insert function

    if (!computer) {
        computer = new Computer();
    }

    cout << "Inserting components for PC Computer Assembly:" << endl;
    computer->insertMotherBoard();
    computer->insertMemory("PC");
    computer->insertCPU("PC");

    gpu = new NvidiaAmdGPU();
    gpu->insert();
}

void PCComputerAssembly::display() const {
    cout << endl << endl << endl;
    cout << "****************************************YOUR DEVICE IS READY*******************************************" << endl;
    cout << "***************************************HERE ARE THE SPECIFICATIONS***************************************" << endl;
    cout << "Displaying PC Computer Assembly Specifications:" << endl;

    ComputerAssembly::display(); // Call base class display function

    computer->display();
    gpu->display();
}
