#pragma once
#include "_Device.h"

// BaseLock: 基础锁，没有依赖
class BaseLock : public Device
{
public:
    BaseLock();
    bool isUnlocked(const std::vector<Device *> &accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};

// SecurityPanel: 安全面板，依赖BaseLock
class SecurityPanel : public Device
{
public:
    SecurityPanel();
    bool isUnlocked(const std::vector<Device *> &accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};

// DataTerminal: 数据终端，依赖SecurityPanel
class DataTerminal : public Device
{
private:
    int capacity; // 数据容量，单位TB
public:
    DataTerminal(int capacity);
    bool isUnlocked(const std::vector<Device *> &accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};

// OpticalTool: 光学工具，没有依赖
class OpticalTool : public Device
{
public:
    OpticalTool();
    bool isUnlocked(const std::vector<Device *> &accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};