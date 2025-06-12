#pragma once
#include "_Device.h"

class BaseLock : public Device {
public:
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};

class SecurityPanel : public Device {
public:
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};

class DataTerminal : public Device {
private:
    int capacity;
public:
    DataTerminal(int capacity);
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};

class OpticalTool : public Device {
public:
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};