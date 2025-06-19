#include <iostream>
#include <Eigen/Core>

int main() {
    Eigen::Matrix3d m = Eigen::Matrix3d::Random();
    Eigen::Vector3d v = Eigen::Vector3d::Random();
    Eigen::Vector3d result = m * v;
    std::cout << "Matrix m:\n" << m << std::endl;
    std::cout << "Vector v:\n" << v << std::endl;
    std::cout << "Result of m*v:\n" << result << std::endl;
}