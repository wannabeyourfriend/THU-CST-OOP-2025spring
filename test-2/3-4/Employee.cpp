#include "Employee.h"

Employee::Employee(int id) : id(id) {}

Employee::~Employee() {
    delete profile;
}

MDRSecurityProfile::MDRSecurityProfile(int level) {
    this->level = level;
    this->department = MACRODATA_REFINEMENT;
}

// 修改 MDRSecurityProfile 的 validate 方法
bool MDRSecurityProfile::validate(Device* d) {
    // 检查部门权限
    if (d->getAllowedDepartment() != department) {
        return false;
    }
    
    // 检查安全等级
    if (level < 2 && (dynamic_cast<DataTerminal*>(d))) {
        return false;
    }
    
    // 检查依赖链
    if (!d->isUnlocked(accessed)) {
        return false;
    }
    
    return true;
}

void MDRSecurityProfile::upgradeLevel() {
    level = 2;
}

SecurityProfile* MDRSecurityProfile::clone() {
    MDRSecurityProfile* newProfile = new MDRSecurityProfile(level);
    newProfile->accessed = accessed;
    return newProfile;
}

OnDSecurityProfile::OnDSecurityProfile(int level) {
    this->level = level;
    this->department = OPTICS_AND_DESIGN;
}

bool OnDSecurityProfile::validate(Device* d) {
    if (d->getAllowedDepartment() != department) {
        return false;
    }
    
    if (level < 2 && (dynamic_cast<OpticalTool*>(d))) {
        return false;
    }
    
    if (!d->isUnlocked(accessed)) {
        return false;
    }
    
    return true;
}

void OnDSecurityProfile::upgradeLevel() {
    level = 2;
}

SecurityProfile* OnDSecurityProfile::clone() {
    OnDSecurityProfile* newProfile = new OnDSecurityProfile(level);
    newProfile->accessed = accessed;
    return newProfile;
}

MDRJunior::MDRJunior(int id) : Employee(id) {
    profile = new MDRSecurityProfile(1);
}

Employee* MDRJunior::promote() {
    MDRSenior* senior = new MDRSenior(id);
    senior->profile->accessed = profile->accessed;
    return senior;
}

// 需要修改 MDRJunior 的 accessDevice 方法
bool MDRJunior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        // 修改判断顺序，先检查部门权限和安全等级，再检查依赖
        if (d->getAllowedDepartment() != getDepartment() || 
            (dynamic_cast<DataTerminal*>(d) && profile->level < 2)) {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        } else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED." << std::endl;
        } else {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

// 同样需要修改其他三个员工类的 accessDevice 方法
// MDRSenior
bool MDRSenior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        if (d->getAllowedDepartment() != getDepartment()) {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        } else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED." << std::endl;
        } else {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

// OnDJunior
bool OnDJunior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        if (d->getAllowedDepartment() != getDepartment() || 
            (dynamic_cast<OpticalTool*>(d) && profile->level < 2)) {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        } else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED." << std::endl;
        } else {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

// OnDSenior
bool OnDSenior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        if (d->getAllowedDepartment() != getDepartment()) {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        } else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED." << std::endl;
        } else {
            std::cout << "No permission. ACCESS DENIED." << std::endl;
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

std::string MDRJunior::getType() const {
    return "MDR-Junior";
}

Department MDRJunior::getDepartment() const {
    return MACRODATA_REFINEMENT;
}

Employee* MDRJunior::clone() {
    MDRJunior* newEmp = new MDRJunior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}

MDRSenior::MDRSenior(int id) : Employee(id) {
    profile = new MDRSecurityProfile(2);
}

Employee* MDRSenior::promote() {
    return this; 
}

std::string MDRSenior::getType() const {
    return "MDR-Senior";
}

Department MDRSenior::getDepartment() const {
    return MACRODATA_REFINEMENT;
}

Employee* MDRSenior::clone() {
    MDRSenior* newEmp = new MDRSenior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}

OnDJunior::OnDJunior(int id) : Employee(id) {
    profile = new OnDSecurityProfile(1);
}

Employee* OnDJunior::promote() {
    OnDSenior* senior = new OnDSenior(id);
    senior->profile->accessed = profile->accessed;
    return senior;
}

std::string OnDJunior::getType() const {
    return "O&D-Junior";
}

Department OnDJunior::getDepartment() const {
    return OPTICS_AND_DESIGN;
}

Employee* OnDJunior::clone() {
    OnDJunior* newEmp = new OnDJunior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}

OnDSenior::OnDSenior(int id) : Employee(id) {
    profile = new OnDSecurityProfile(2);
}

Employee* OnDSenior::promote() {
    return this;
}

std::string OnDSenior::getType() const {
    return "O&D-Senior";
}

Department OnDSenior::getDepartment() const {
    return OPTICS_AND_DESIGN;
}

Employee* OnDSenior::clone() {
    OnDSenior* newEmp = new OnDSenior(id);
    delete newEmp->profile;
    newEmp->profile = profile->clone();
    return newEmp;
}