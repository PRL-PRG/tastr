#ifndef TASTR_AST_INTEGER_A_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_INTEGER_A_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr {
namespace ast {

class IntegerAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit IntegerAScalarTypeNode(KeywordNodeUPtr keyword)
        : AScalarTypeNode(std::move(keyword)) {
    }

    ~IntegerAScalarTypeNode() = default;

    IntegerAScalarTypeNode(const IntegerAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    IntegerAScalarTypeNode(const IntegerAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    IntegerAScalarTypeNode& operator=(const IntegerAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    IntegerAScalarTypeNode& operator=(IntegerAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<IntegerAScalarTypeNode> clone() const {
        return std::unique_ptr<IntegerAScalarTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

  private:
    virtual IntegerAScalarTypeNode* clone_impl() const override final {
        return new IntegerAScalarTypeNode(*this);
    }

    static const Kind kind_;
};

using IntegerAScalarTypeNodePtr = IntegerAScalarTypeNode*;
using IntegerAScalarTypeNodeUPtr = std::unique_ptr<IntegerAScalarTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_INTEGER_A_SCALAR_TYPE_NODE_HPP */
