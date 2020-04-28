#ifndef TASTR_AST_TYPE_NODE_HPP
#define TASTR_AST_TYPE_NODE_HPP

#include "ast/Node.hpp"

namespace tastr {
namespace ast {

class TypeNode: public Node {
  public:
    TypeNode(): Node() {
    }

    virtual ~TypeNode() = default;

    TypeNode(const TypeNode& node): Node(node) {
    }

    TypeNode(TypeNode&& node): Node(std::move(node)) {
    }

    TypeNode& operator=(const TypeNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        return *this;
    }

    TypeNode& operator=(TypeNode&& node) {
        Node::operator=(std::move(node));
        return *this;
    }

    virtual void
    accept(tastr::visitor::ConstNodeVisitor& visitor) const override = 0;

    virtual void
    accept(tastr::visitor::MutableNodeVisitor& visitor) override = 0;

    std::unique_ptr<TypeNode> clone() const {
        return std::unique_ptr<TypeNode>(this->clone_impl());
    }

  private:
    virtual TypeNode* clone_impl() const override = 0;
};

using TypeNodePtr = TypeNode*;
using TypeNodeUPtr = std::unique_ptr<TypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_TYPE_NODE_HPP */
