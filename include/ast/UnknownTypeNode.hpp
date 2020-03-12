#ifndef TASTR_AST_UNKNOWN_TYPE_NODE_HPP
#define TASTR_AST_UNKNOWN_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {
class UnknownTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit UnknownTypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    ~UnknownTypeNode() = default;

    UnknownTypeNode(const UnknownTypeNode& node): TypeNode(node), Name(node) {
    }

    UnknownTypeNode(UnknownTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    UnknownTypeNode& operator=(const UnknownTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    UnknownTypeNode& operator=(UnknownTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<UnknownTypeNode> clone() const {
        return std::unique_ptr<UnknownTypeNode>(this->clone_impl());
    }

    bool is_unknown_type_node() const override final {
        return true;
    }

  private:
    virtual UnknownTypeNode* clone_impl() const override final {
        return new UnknownTypeNode(*this);
    };
};

using UnknownTypeNodePtr = UnknownTypeNode*;
using UnknownTypeNodeUPtr = std::unique_ptr<UnknownTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_UNKNOWN_TYPE_NODE_HPP */
