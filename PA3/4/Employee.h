#pragma once
#include "_Employee.h"
#include "Device.h"

class MDRSecurityProfile : public SecurityProfile {
public:
    MDRSecurityProfile(int level);
    bool validate(Device* d) override;
    void upgradeLevel() override;
    SecurityProfile* clone() override;
};

class OnDSecurityProfile : public SecurityProfile {
public:
    OnDSecurityProfile(int level);
    bool validate(Device* d) override;
    void upgradeLevel() override;
    SecurityProfile* clone() override;
};

class MDRJunior : public Employee {
public:
    MDRJunior(int id);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};

class MDRSenior : public Employee {
public:
    MDRSenior(int id);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};

class OnDJunior : public Employee {
public:
    OnDJunior(int id);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};

class OnDSenior : public Employee {
public:
    OnDSenior(int id);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};