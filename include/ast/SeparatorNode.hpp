#ifndef TASTR_AST_SEPARATOR_NODE_HPP
#define TASTR_AST_SEPARATOR_NODE_HPP

#include "ast/Node.hpp"

#include <string>

namespace tastr::ast {

class SeparatorNode final: public Node {
  public:
    explicit SeparatorNode(const std::string& value): Node(), value_(value) {
    }

    ~SeparatorNode() = default;

    SeparatorNode(const SeparatorNode& node): Node(node), value_(node.value_) {
    }

    SeparatorNode(SeparatorNode&& node)
        : Node(std::move(node)), value_(std::move(node.value_)) {
    }

    SeparatorNode& operator=(const SeparatorNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        value_ = node.value_;
        return *this;
    }

    SeparatorNode& operator=(SeparatorNode&& node) {
        Node::operator=(std::move(node));
        value_ = std::move(node.value_);
        return *this;
    }

    std::unique_ptr<SeparatorNode> clone() const {
        return std::unique_ptr<SeparatorNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    Kind get_kind() const override final {
        return kind_;
    }

    const std::string& get_value() const {
        return value_;
    }

  private:
    virtual SeparatorNode* clone_impl() const override final {
        return new SeparatorNode(*this);
    }

    std::string value_;

    static const Kind kind_;
};

using SeparatorNodePtr = SeparatorNode*;
using SeparatorNodeUPtr = std::unique_ptr<SeparatorNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SEPARATOR_NODE_HPP */
