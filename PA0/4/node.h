#pragma once

#include "abstract_node.h"
#include "leaf_node.h"
#include <memory>
#include <cmath>

class Node: public AbstractNode {
private:
    std::shared_ptr<AbstractNode> left;
    std::shared_ptr<AbstractNode> right;
    float val;
    float grad;
    char op;

public:
    Node(float value);  // 构造叶节点
    Node(const LeafNode& leaf);  // 从 LeafNode 构造
    Node(std::shared_ptr<AbstractNode> l, std::shared_ptr<AbstractNode> r, char operation);
    float get_val() override;
    void backward(float _grad) override;
    float get_grad() const { return grad; }
    void clear_grad() override;  // 修改为虚函数

    friend Node operator + (const Node &x, const Node &y);
    friend Node operator - (const Node &x, const Node &y);
    friend Node operator * (const Node &x, const Node &y);
    friend Node operator / (const Node &x, const Node &y);
    friend Node pow(const Node &x, const Node &y);
    friend Node exp(const Node &x);
    friend Node log(const Node &x);
};

Node operator + (const Node &x, const Node &y);
Node operator - (const Node &x, const Node &y);
Node operator * (const Node &x, const Node &y);
Node operator / (const Node &x, const Node &y);
Node pow(const Node &x, const Node &y);
Node exp(const Node &x);
Node log(const Node &x);
