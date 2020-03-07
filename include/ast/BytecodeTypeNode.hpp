#ifndef TASTR_AST_BYTECODE_TYPE_NODE_HPP
#define TASTR_AST_BYTECODE_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class BytecodeTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit BytecodeTypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    ~BytecodeTypeNode() = default;

    BytecodeTypeNode(const BytecodeTypeNode& node): TypeNode(node), Name(node) {
    }

    BytecodeTypeNode(BytecodeTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    BytecodeTypeNode& operator=(const BytecodeTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    BytecodeTypeNode& operator=(BytecodeTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
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

  private:
    virtual BytecodeTypeNode* clone_impl() const override final {
        return new BytecodeTypeNode(*this);
    };
};

using BytecodeTypeNodePtr = BytecodeTypeNode*;
using BytecodeTypeNodeUPtr = std::unique_ptr<BytecodeTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_BYTECODE_TYPE_NODE_HPP */
