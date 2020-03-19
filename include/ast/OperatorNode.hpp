#ifndef TASTR_AST_OPERATOR_NODE_HPP
#define TASTR_AST_OPERATOR_NODE_HPP

#include "ast/Node.hpp"

#include <string>

namespace tastr::ast {

class OperatorNode final: public Node {
  public:
    explicit OperatorNode(const std::string& value): Node(), value_(value) {
    }

    ~OperatorNode() = default;

    OperatorNode(const OperatorNode& node): Node(node), value_(node.value_) {
    }

    OperatorNode(OperatorNode&& node)
        : Node(std::move(node)), value_(std::move(node.value_)) {
    }

    OperatorNode& operator=(const OperatorNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        value_ = node.value_;
        return *this;
    }

    OperatorNode& operator=(OperatorNode&& node) {
        Node::operator=(std::move(node));
        value_ = std::move(node.value_);
        return *this;
    }

    std::unique_ptr<OperatorNode> clone() const {
        return std::unique_ptr<OperatorNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    Kind get_kind() const override final {
        return kind_;
    }

    bool is_operator_node() const override final {
        return true;
    }

    const std::string& get_value() const {
        return value_;
    }

  private:
    virtual OperatorNode* clone_impl() const override final {
        return new OperatorNode(*this);
    }

    std::string value_;

    static const Kind kind_;
};

using OperatorNodePtr = OperatorNode*;
using OperatorNodeUPtr = std::unique_ptr<OperatorNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_OPERATOR_NODE_HPP */
