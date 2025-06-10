#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cmath>

#include "node.h"
#include "leaf_node.h"

// Helper function to print test results
void print_test_results(const std::string& test_name, 
                        std::vector<LeafNode>& variables,
                        const std::vector<std::string>& var_names,
                        float result_val) {
    std::cout << "=== " << test_name << " ===" << std::endl;
    std::cout << "Forward pass result: " << result_val << std::endl;
    std::cout << "Gradients:" << std::endl;
    for (size_t i = 0; i < variables.size(); ++i) {
        std::cout << "  d(" << test_name << ")/d(" << var_names[i] 
                  << ") = " << variables[i].get_grad() << std::endl;
    }
    std::cout << std::endl;
    
    // Clear gradients for next test
    for (auto& var : variables) {
        var.clear_grad();
    }
}

// Test basic operations
void test_basic_operations() {
    // Create leaf nodes (input variables)
    LeafNode x(2.0), y(3.0), z(4.0);
    std::vector<LeafNode> vars = {x, y, z};
    std::vector<std::string> names = {"x", "y", "z"};
    
    // Test addition: f = x + y
    {
        Node f = x + y;
        std::cout << "f = x + y = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("x + y", vars, names, f.get_val());
    }
    
    // Test subtraction: f = x - y
    {
        Node f = x - y;
        std::cout << "f = x - y = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("x - y", vars, names, f.get_val());
    }
    
    // Test multiplication: f = x * y
    {
        Node f = x * y;
        std::cout << "f = x * y = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("x * y", vars, names, f.get_val());
    }
    
    // Test division: f = x / y
    {
        Node f = x / y;
        std::cout << "f = x / y = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("x / y", vars, names, f.get_val());
    }
}

// Test advanced operations
void test_advanced_operations() {
    // Create leaf nodes (input variables)
    LeafNode x(2.0), y(3.0);
    std::vector<LeafNode> vars = {x, y};
    std::vector<std::string> names = {"x", "y"};
    
    // Test power: f = x^y
    {
        Node f = pow(x, y);
        std::cout << "f = x^y = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("x^y", vars, names, f.get_val());
    }
    
    // Test exponential: f = e^x
    {
        Node f = exp(x);
        std::cout << "f = e^x = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("e^x", vars, names, f.get_val());
    }
    
    // Test logarithm: f = ln(x)
    {
        Node f = log(x);
        std::cout << "f = ln(x) = " << f.get_val() << std::endl;
        f.backward(1.0);
        print_test_results("ln(x)", vars, names, f.get_val());
    }
}

// Test complex computation graph
void test_complex_graph() {
    // Create leaf nodes (input variables)
    LeafNode x(2.0), y(3.0), z(4.0);
    std::vector<LeafNode> vars = {x, y, z};
    std::vector<std::string> names = {"x", "y", "z"};
    
    // Build a complex computation graph:
    // f = (x + y) * z + ln(x) - e^y + x^z
    Node term1 = (x + y) * z;
    Node term2 = log(x);
    Node term3 = exp(y);
    Node term4 = pow(x, z);
    Node f = term1 + term2 - term3 + term4;
    
    // Forward pass
    float result = f.get_val();
    std::cout << "Complex function f = (x + y) * z + ln(x) - e^y + x^z" << std::endl;
    std::cout << "With x = " << x.get_val() << ", y = " << y.get_val() 
              << ", z = " << z.get_val() << std::endl;
    std::cout << "Forward pass result: " << result << std::endl;
    
    // Backward pass
    f.backward(1.0);
    
    // Print gradients
    std::cout << "Gradients:" << std::endl;
    std::cout << "df/dx = " << x.get_grad() << std::endl;
    std::cout << "df/dy = " << y.get_grad() << std::endl;
    std::cout << "df/dz = " << z.get_grad() << std::endl;
    
    // Verify gradients with numerical approximation
    std::cout << "\nVerifying gradients with numerical approximation:" << std::endl;
    
    // Numerical approximation for df/dx
    float epsilon = 0.0001;
    x.set_val(x.get_val() + epsilon);
    float f_plus = ((x + y) * z + log(x) - exp(y) + pow(x, z)).get_val();
    x.set_val(x.get_val() - 2 * epsilon);
    float f_minus = ((x + y) * z + log(x) - exp(y) + pow(x, z)).get_val();
    x.set_val(x.get_val() + epsilon);  // Reset to original value
    float numerical_dx = (f_plus - f_minus) / (2 * epsilon);
    std::cout << "Numerical df/dx ≈ " << numerical_dx << std::endl;
    
    // Numerical approximation for df/dy
    y.set_val(y.get_val() + epsilon);
    f_plus = ((x + y) * z + log(x) - exp(y) + pow(x, z)).get_val();
    y.set_val(y.get_val() - 2 * epsilon);
    f_minus = ((x + y) * z + log(x) - exp(y) + pow(x, z)).get_val();
    y.set_val(y.get_val() + epsilon);  // Reset to original value
    float numerical_dy = (f_plus - f_minus) / (2 * epsilon);
    std::cout << "Numerical df/dy ≈ " << numerical_dy << std::endl;
    
    // Numerical approximation for df/dz
    z.set_val(z.get_val() + epsilon);
    f_plus = ((x + y) * z + log(x) - exp(y) + pow(x, z)).get_val();
    z.set_val(z.get_val() - 2 * epsilon);
    f_minus = ((x + y) * z + log(x) - exp(y) + pow(x, z)).get_val();
    z.set_val(z.get_val() + epsilon);  // Reset to original value
    float numerical_dz = (f_plus - f_minus) / (2 * epsilon);
    std::cout << "Numerical df/dz ≈ " << numerical_dz << std::endl;
}

// Test gradient accumulation
void test_gradient_accumulation() {
    LeafNode x(2.0);
    
    // Create a computation graph where x is used multiple times
    // f = x + x + x
    Node f = x + x + x;
    
    std::cout << "=== Gradient Accumulation Test ===" << std::endl;
    std::cout << "f = x + x + x = " << f.get_val() << std::endl;
    f.backward(1.0);
    std::cout << "df/dx = " << x.get_grad() << " (should be 3.0)" << std::endl;
    
    // Clear gradient and test another case
    x.clear_grad();
    
    // f = x * x
    Node g = x * x;
    std::cout << "g = x * x = " << g.get_val() << std::endl;
    g.backward(1.0);
    std::cout << "dg/dx = " << x.get_grad() << " (should be 4.0)" << std::endl;
}

int main() {
    // Set output formatting
    std::cout << std::fixed << std::setprecision(6);
    
    // Run tests
    test_basic_operations();
    test_advanced_operations();
    test_complex_graph();
    test_gradient_accumulation();
    
    // Print node count to check for memory leaks
    std::cout << "\nFinal AbstractNode count: " << AbstractNode::get_count() << std::endl;
    
    return 0;
}