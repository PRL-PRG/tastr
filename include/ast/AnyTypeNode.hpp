#ifndef TASTR_AST_ANY_TYPE_NODE_HPP
#define TASTR_AST_ANY_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {
class AnyTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit AnyTypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    ~AnyTypeNode() = default;

    AnyTypeNode(const AnyTypeNode& node): TypeNode(node), Name(node) {
    }

    AnyTypeNode(AnyTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    AnyTypeNode& operator=(const AnyTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    AnyTypeNode& operator=(AnyTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<AnyTypeNode> clone() const {
        return std::unique_ptr<AnyTypeNode>(this->clone_impl());
    }

    bool is_any_type_node() const override final {
        return true;
    }

  private:
    virtual AnyTypeNode* clone_impl() const override final {
        return new AnyTypeNode(*this);
    };
};

using AnyTypeNodePtr = AnyTypeNode*;
using AnyTypeNodeUPtr = std::unique_ptr<AnyTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ANY_TYPE_NODE_HPP */
