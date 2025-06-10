#include "node.h"

Node::Node(float value) : val(value), grad(0), op('v') {
    left = nullptr;
    right = nullptr;
}

Node::Node(const LeafNode& leaf) : val(const_cast<LeafNode&>(leaf).get_val()), grad(0), op('v') {
    // left = std::make_shared<LeafNode>(const_cast<LeafNode&>(leaf));
    // 需要使用shared_ptr指向原始的LeafNode对象
    left = std::shared_ptr<AbstractNode>(&const_cast<LeafNode&>(leaf), [](AbstractNode*) {});
    right = nullptr;
    val = left->get_val();
}

Node::Node(std::shared_ptr<AbstractNode> _left, std::shared_ptr<AbstractNode> _right, char _op)
    : left(_left), right(_right), grad(0), op(_op) {
    val = get_val();
}

float Node::get_val() {
    if (op == 'v') return val;
    
    float l_val = left->get_val();
    float r_val = right ? right->get_val() : 0;
    
    switch(op) {
        case '+': return l_val + r_val;
        case '-': return l_val - r_val;
        case '*': return l_val * r_val;
        case '/': return l_val / r_val;
        case 'p': return pow(l_val, r_val);
        case 'e': return exp(l_val);
        case 'l': return log(l_val);
        default: return 0;
    }
}

void Node::backward(float _grad) {
    grad += _grad;
    
    if (op == 'v') return;
    
    float l_val = left->get_val();
    float r_val = right ? right->get_val() : 0;
    
    switch(op) {
        case '+':
            left->backward(_grad);
            right->backward(_grad);
            break;
        case '-':
            left->backward(_grad);
            right->backward(-_grad);
            break;
        case '*':
            left->backward(_grad * r_val);
            right->backward(_grad * l_val);
            break;
        case '/':
            left->backward(_grad / r_val);
            right->backward(_grad * (-l_val / (r_val * r_val)));
            break;
        case 'p':
            left->backward(_grad * r_val * pow(l_val, r_val - 1));
            right->backward(_grad * log(l_val) * pow(l_val, r_val));
            break;
        case 'e':
            left->backward(_grad * exp(l_val));
            break;
        case 'l':
            left->backward(_grad / l_val);
            break;
    }
}

void Node::clear_grad() {
    grad = 0;
    if (left) left->clear_grad();
    if (right) right->clear_grad();
}

Node operator + (const Node &x, const Node &y) {
    return Node(std::make_shared<Node>(x), std::make_shared<Node>(y), '+');
}

Node operator - (const Node &x, const Node &y) {
    return Node(std::make_shared<Node>(x), std::make_shared<Node>(y), '-');
}

Node operator * (const Node &x, const Node &y) {
    return Node(std::make_shared<Node>(x), std::make_shared<Node>(y), '*');
}

Node operator / (const Node &x, const Node &y) {
    return Node(std::make_shared<Node>(x), std::make_shared<Node>(y), '/');
}

Node pow(const Node &x, const Node &y) {
    return Node(std::make_shared<Node>(x), std::make_shared<Node>(y), 'p');
}

Node exp(const Node &x) {
    return Node(std::make_shared<Node>(x), nullptr, 'e');
}

Node log(const Node &x) {
    return Node(std::make_shared<Node>(x), nullptr, 'l');
}
