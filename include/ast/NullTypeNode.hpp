#ifndef TASTR_AST_NULL_TYPE_NODE_HPP
#define TASTR_AST_NULL_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class NullTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit NullTypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    ~NullTypeNode() = default;

    NullTypeNode(const NullTypeNode& node): TypeNode(node), Name(node) {
    }

    NullTypeNode(NullTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    NullTypeNode& operator=(const NullTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    NullTypeNode& operator=(NullTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<NullTypeNode> clone() const {
        return std::unique_ptr<NullTypeNode>(this->clone_impl());
    }

    bool is_null_type_node() const override final {
        return true;
    }

  private:
    virtual NullTypeNode* clone_impl() const override final {
        return new NullTypeNode(*this);
    };
};

using NullTypeNodePtr = NullTypeNode*;
using NullTypeNodeUPtr = std::unique_ptr<NullTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NULL_TYPE_NODE_HPP */
