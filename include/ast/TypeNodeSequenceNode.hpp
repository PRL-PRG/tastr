#ifndef TASTR_AST_TYPE_NODE_SEQUENCE_NODE_H
#define TASTR_AST_TYPE_NODE_SEQUENCE_NODE_H

#include "Sequence.hpp"
#include "TagTypePairNode.hpp"

namespace tastr::ast {

class TypeNodeSequenceNode final
    : public Node
    , public Sequence<TypeNode> {
  public:
    TypeNodeSequenceNode(): Node(), Sequence<TypeNode>() {
    }

    ~TypeNodeSequenceNode() = default;

    TypeNodeSequenceNode(const TypeNodeSequenceNode& node)
        : Node(node), Sequence<TypeNode>(node) {
    }

    TypeNodeSequenceNode(TypeNodeSequenceNode&& node)
        : Node(std::move(node)), Sequence<TypeNode>(std::move(node)) {
    }

    TypeNodeSequenceNode& operator=(const TypeNodeSequenceNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        Sequence<TypeNode>::operator=(node);
        return *this;
    }

    TypeNodeSequenceNode& operator=(TypeNodeSequenceNode&& node) {
        Node::operator=(std::move(node));
        Sequence<TypeNode>::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TypeNodeSequenceNode> clone() const {
        return std::unique_ptr<TypeNodeSequenceNode>(this->clone_impl());
    }

    bool is_type_node_sequence_node() const override final {
        return true;
    }

  private:
    virtual TypeNodeSequenceNode* clone_impl() const override final {
        return new TypeNodeSequenceNode(*this);
    };
};

using TypeNodeSequenceNodePtr = TypeNodeSequenceNode*;
using TypeNodeSequenceNodeUPtr = std::unique_ptr<TypeNodeSequenceNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_NODE_SEQUENCE_NODE_H */
