#include "Employee.h"

// Employee基类实现
Employee::Employee(int id) : id(id), profile(nullptr) {}

Employee::~Employee() {
    delete profile;
}

// MDRSecurityProfile实现
MDRSecurityProfile::MDRSecurityProfile(int level) {
    this->level = level;
    this->department = MACRODATA_REFINEMENT;
}

bool MDRSecurityProfile::validate(Device *d) {
    // 检查部门权限
    if (d->getAllowedDepartment() != department) {
        std::cout << "No permission. ACCESS DENIED." << std::endl;
        return false;
    }
    
    // 检查安全等级
    bool isHighLevelDevice = dynamic_cast<DataTerminal *>(d) != nullptr;
    if (isHighLevelDevice && level < 2) {
        std::cout << "No permission. ACCESS DENIED." << std::endl;
        return false;
    }
    
    // 检查依赖链
    if (!d->isUnlocked(accessed)) {
        std::cout << "Dependency not met. ACCESS DENIED." << std::endl;
        return false;
    }
    
    return true;
}

void MDRSecurityProfile::upgradeLevel() {
    level = 2; // 升级到高级
}

SecurityProfile *MDRSecurityProfile::clone() {
    MDRSecurityProfile *newProfile = new MDRSecurityProfile(level);
    newProfile->accessed = accessed;
    return newProfile;
}

// OnDSecurityProfile实现
OnDSecurityProfile::OnDSecurityProfile(int level) {
    this->level = level;
    this->department = OPTICS_AND_DESIGN;
}

bool OnDSecurityProfile::validate(Device *d) {
    // 检查部门权限
    if (d->getAllowedDepartment() != department) {
        std::cout << "No permission. ACCESS DENIED." << std::endl;
        return false;
    }
    
    // 检查安全等级 - 对于O&D部门，OpticalTool是高级设备
    bool isHighLevelDevice = dynamic_cast<OpticalTool *>(d) != nullptr;
    if (isHighLevelDevice && level < 2) {
        std::cout << "No permission. ACCESS DENIED." << std::endl;
        return false;
    }
    
    // 检查依赖链
    if (!d->isUnlocked(accessed)) {
        std::cout << "Dependency not met. ACCESS DENIED." << std::endl;
        return false;
    }
    
    return true;
}

void OnDSecurityProfile::upgradeLevel() {
    level = 2; // 升级到高级
}

SecurityProfile *OnDSecurityProfile::clone() {
    OnDSecurityProfile *newProfile = new OnDSecurityProfile(level);
    newProfile->accessed = accessed;
    return newProfile;
}

// MDRJunior实现
MDRJunior::MDRJunior(int id) : Employee(id) {
    profile = new MDRSecurityProfile(1);
}

Employee *MDRJunior::promote() {
    return new MDRSenior(id);
}

bool MDRJunior::accessDevice(Device *d) {
    if (profile->validate(d)) {
        profile->accessed.push_back(d);
        d->execute();
        return true;
    }
    return false;
}

std::string MDRJunior::getType() const {
    return "MDR-Junior";
}

Department MDRJunior::getDepartment() const {
    return MACRODATA_REFINEMENT;
}

Employee *MDRJunior::clone() {
    MDRJunior *newEmp = new MDRJunior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}

// MDRSenior实现
MDRSenior::MDRSenior(int id) : Employee(id) {
    profile = new MDRSecurityProfile(2);
}

Employee *MDRSenior::promote() {
    return this; // 已经是最高级别
}

bool MDRSenior::accessDevice(Device *d) {
    if (profile->validate(d)) {
        profile->accessed.push_back(d);
        d->execute();
        return true;
    }
    return false;
}

std::string MDRSenior::getType() const {
    return "MDR-Senior";
}

Department MDRSenior::getDepartment() const {
    return MACRODATA_REFINEMENT;
}

Employee *MDRSenior::clone() {
    MDRSenior *newEmp = new MDRSenior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}

// OnDJunior实现
OnDJunior::OnDJunior(int id) : Employee(id) {
    profile = new OnDSecurityProfile(1);
}

Employee *OnDJunior::promote() {
    return new OnDSenior(id);
}

bool OnDJunior::accessDevice(Device *d) {
    if (profile->validate(d)) {
        profile->accessed.push_back(d);
        d->execute();
        return true;
    }
    return false;
}

std::string OnDJunior::getType() const {
    return "O&D-Junior";
}

Department OnDJunior::getDepartment() const {
    return OPTICS_AND_DESIGN;
}

Employee *OnDJunior::clone() {
    OnDJunior *newEmp = new OnDJunior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}

// OnDSenior实现
OnDSenior::OnDSenior(int id) : Employee(id) {
    profile = new OnDSecurityProfile(2);
}

Employee *OnDSenior::promote() {
    return this; // 已经是最高级别
}

bool OnDSenior::accessDevice(Device *d) {
    if (profile->validate(d)) {
        profile->accessed.push_back(d);
        d->execute();
        return true;
    }
    return false;
}

std::string OnDSenior::getType() const {
    return "O&D-Senior";
}

Department OnDSenior::getDepartment() const {
    return OPTICS_AND_DESIGN;
}

Employee *OnDSenior::clone() {
    OnDSenior *newEmp = new OnDSenior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}