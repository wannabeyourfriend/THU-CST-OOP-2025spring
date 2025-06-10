#include "Device.h"

bool BaseLock::isUnlocked(const std::vector<Device*>& accessed) {
    return true; 
}

void BaseLock::execute() {
    std::cout << "BaseLock engaged." << std::endl;
}

std::string BaseLock::getName() const {
    return "BaseLock";
}

Department BaseLock::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT;
}

bool SecurityPanel::isUnlocked(const std::vector<Device*>& accessed) {
    for (auto device : accessed) {
        if (dynamic_cast<BaseLock*>(device)) {
            return true;
        }
    }
    return false;
}

void SecurityPanel::execute() {
    std::cout << "SecurityPanel activated." << std::endl;
}

std::string SecurityPanel::getName() const {
    return "SecurityPanel";
}

Department SecurityPanel::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT;
}

DataTerminal::DataTerminal(int capacity) : capacity(capacity) {}

bool DataTerminal::isUnlocked(const std::vector<Device*>& accessed) {
    for (auto device : accessed) {
        if (dynamic_cast<SecurityPanel*>(device)) {
            return true;
        }
    }
    return false;
}

void DataTerminal::execute() {
    std::cout << "Processed " << capacity << "TB data." << std::endl;
}

std::string DataTerminal::getName() const {
    return "DataTerminal";
}

Department DataTerminal::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT;
}

bool OpticalTool::isUnlocked(const std::vector<Device*>& accessed) {
    return true; 
}

void OpticalTool::execute() {
    std::cout << "OpticalTool adjusted." << std::endl;
}

std::string OpticalTool::getName() const {
    return "OpticalTool";
}

Department OpticalTool::getAllowedDepartment() const {
    return OPTICS_AND_DESIGN;
}