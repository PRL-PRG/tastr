#ifndef TASTR_AST_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_SCALAR_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class ScalarTypeNode
    : public TypeNode
    , public Name {
  public:
    explicit ScalarTypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    virtual ~ScalarTypeNode() = default;

    ScalarTypeNode(const ScalarTypeNode& node): TypeNode(node), Name(node) {
    }

    ScalarTypeNode(ScalarTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    ScalarTypeNode& operator=(const ScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    ScalarTypeNode& operator=(ScalarTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    virtual void
    accept(tastr::visitor::ConstNodeVisitor& visitor) const override = 0;

    virtual void
    accept(tastr::visitor::MutableNodeVisitor& visitor) override = 0;

    std::unique_ptr<ScalarTypeNode> clone() const {
        return std::unique_ptr<ScalarTypeNode>(this->clone_impl());
    }

    bool is_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual ScalarTypeNode* clone_impl() const override = 0;
};

using ScalarTypeNodePtr = ScalarTypeNode*;
using ScalarTypeNodeUPtr = std::unique_ptr<ScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SCALAR_TYPE_NODE_HPP */
