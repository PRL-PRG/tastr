#ifndef TASTR_AST_A_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_A_SCALAR_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/ScalarTypeNode.hpp"

namespace tastr::ast {

class AScalarTypeNode
    : public ScalarTypeNode
    , public Name {
  public:
    explicit AScalarTypeNode(const std::string& name)
        : ScalarTypeNode(), Name(name) {
    }

    virtual ~AScalarTypeNode() = default;

    AScalarTypeNode(const AScalarTypeNode& node)
        : ScalarTypeNode(node), Name(node) {
    }

    AScalarTypeNode(AScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)), Name(std::move(node)) {
    }

    AScalarTypeNode& operator=(const AScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    AScalarTypeNode& operator=(AScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    virtual void
    accept(tastr::visitor::ConstNodeVisitor& visitor) const override = 0;

    virtual void
    accept(tastr::visitor::MutableNodeVisitor& visitor) override = 0;

    std::unique_ptr<AScalarTypeNode> clone() const {
        return std::unique_ptr<AScalarTypeNode>(this->clone_impl());
    }

    bool is_a_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual AScalarTypeNode* clone_impl() const override = 0;
};

using AScalarTypeNodePtr = AScalarTypeNode*;
using AScalarTypeNodeUPtr = std::unique_ptr<AScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_A_SCALAR_TYPE_NODE_HPP */
