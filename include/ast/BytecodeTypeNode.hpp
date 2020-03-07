#ifndef TASTR_AST_BYTECODE_TYPE_NODE_HPP
#define TASTR_AST_BYTECODE_TYPE_NODE_HPP

#include "TypeNode.hpp"

namespace tastr::ast {

class BytecodeTypeNode final: public TypeNode {
  public:
    explicit BytecodeTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~BytecodeTypeNode() = default;

    BytecodeTypeNode(const BytecodeTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    BytecodeTypeNode(BytecodeTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    BytecodeTypeNode& operator=(const BytecodeTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    BytecodeTypeNode& operator=(BytecodeTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<BytecodeTypeNode> clone() const {
        return std::unique_ptr<BytecodeTypeNode>(this->clone_impl());
    }

    bool is_bytecode_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual BytecodeTypeNode* clone_impl() const override final {
        return new BytecodeTypeNode(*this);
    };

    std::string identifier_;
};

using BytecodeTypeNodePtr = BytecodeTypeNode*;
using BytecodeTypeNodeUPtr = std::unique_ptr<BytecodeTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_BYTECODE_TYPE_NODE_HPP */
