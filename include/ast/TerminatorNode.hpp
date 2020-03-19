#ifndef TASTR_AST_TERMINATOR_NODE_HPP
#define TASTR_AST_TERMINATOR_NODE_HPP

#include "ast/Node.hpp"

#include <string>

namespace tastr::ast {

class TerminatorNode final: public Node {
  public:
    explicit TerminatorNode(const std::string& value): Node(), value_(value) {
    }

    ~TerminatorNode() = default;

    TerminatorNode(const TerminatorNode& node)
        : Node(node), value_(node.value_) {
    }

    TerminatorNode(TerminatorNode&& node)
        : Node(std::move(node)), value_(std::move(node.value_)) {
    }

    TerminatorNode& operator=(const TerminatorNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        value_ = node.value_;
        return *this;
    }

    TerminatorNode& operator=(TerminatorNode&& node) {
        Node::operator=(std::move(node));
        value_ = std::move(node.value_);
        return *this;
    }

    std::unique_ptr<TerminatorNode> clone() const {
        return std::unique_ptr<TerminatorNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    Kind get_kind() const override final {
        return kind_;
    }

    bool is_terminator_node() const override final {
        return true;
    }

    const std::string& get_value() const {
        return value_;
    }

  private:
    virtual TerminatorNode* clone_impl() const override final {
        return new TerminatorNode(*this);
    }

    std::string value_;

    static const Kind kind_;
};

using TerminatorNodePtr = TerminatorNode*;
using TerminatorNodeUPtr = std::unique_ptr<TerminatorNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TERMINATOR_NODE_HPP */
