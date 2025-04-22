#pragma once
#include "_Employee.h"
#include "Device.h"

// 安全配置文件的具体实现
class MDRSecurityProfile : public SecurityProfile
{
public:
    MDRSecurityProfile(int level = 1);
    bool validate(Device *d) override;
    void upgradeLevel() override;
    SecurityProfile *clone() override;
};

class OnDSecurityProfile : public SecurityProfile
{
public:
    OnDSecurityProfile(int level = 1);
    bool validate(Device *d) override;
    void upgradeLevel() override;
    SecurityProfile *clone() override;
};

// 宏观数据精简部初级员工
class MDRJunior : public Employee
{
public:
    MDRJunior(int id);
    Employee *promote() override;
    bool accessDevice(Device *d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee *clone() override;
};

// 宏观数据精简部高级员工
class MDRSenior : public Employee
{
public:
    MDRSenior(int id);
    Employee *promote() override;
    bool accessDevice(Device *d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee *clone() override;
};

// 光学设计部初级员工
class OnDJunior : public Employee
{
public:
    OnDJunior(int id);
    Employee *promote() override;
    bool accessDevice(Device *d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee *clone() override;
};

// 光学设计部高级员工
class OnDSenior : public Employee
{
public:
    OnDSenior(int id);
    Employee *promote() override;
    bool accessDevice(Device *d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee *clone() override;
};