#include "Device.h"

// BaseLock 实现
BaseLock::BaseLock() {}

bool BaseLock::isUnlocked(const std::vector<Device *> &accessed) {
    // BaseLock没有依赖，始终可以解锁
    return true;
}

void BaseLock::execute() {
    std::cout << "BaseLock engaged." << std::endl;
}

std::string BaseLock::getName() const {
    return "BaseLock";
}

Department BaseLock::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT; // 只有MDR部门可以访问
}

// SecurityPanel 实现
SecurityPanel::SecurityPanel() {}

bool SecurityPanel::isUnlocked(const std::vector<Device *> &accessed) {
    // 检查是否已经访问过BaseLock
    for (auto device : accessed) {
        if (dynamic_cast<BaseLock *>(device)) {
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
    return MACRODATA_REFINEMENT; // 只有MDR部门可以访问
}

// DataTerminal 实现
DataTerminal::DataTerminal(int capacity) : capacity(capacity) {}

bool DataTerminal::isUnlocked(const std::vector<Device *> &accessed) {
    bool hasBaseLock = false;
    bool hasSecurityPanel = false;
    
    // 检查是否已经访问过BaseLock和SecurityPanel
    for (auto device : accessed) {
        if (dynamic_cast<BaseLock *>(device)) {
            hasBaseLock = true;
        }
        if (dynamic_cast<SecurityPanel *>(device)) {
            hasSecurityPanel = true;
        }
    }
    
    return hasBaseLock && hasSecurityPanel;
}

void DataTerminal::execute() {
    std::cout << "Processed " << capacity << "TB data." << std::endl;
}

std::string DataTerminal::getName() const {
    return "DataTerminal";
}

Department DataTerminal::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT; // 只有MDR部门可以访问
}

// OpticalTool 实现
OpticalTool::OpticalTool() {}

bool OpticalTool::isUnlocked(const std::vector<Device *> &accessed) {
    // OpticalTool没有依赖，始终可以解锁
    return true;
}

void OpticalTool::execute() {
    std::cout << "OpticalTool adjusted." << std::endl;
}

std::string OpticalTool::getName() const {
    return "OpticalTool";
}

Department OpticalTool::getAllowedDepartment() const {
    return OPTICS_AND_DESIGN; // 只有O&D部门可以访问
}