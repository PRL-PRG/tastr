#ifndef TASTR_AST_TYPE_NODE_SEQUENCE_NODE_H
#define TASTR_AST_TYPE_NODE_SEQUENCE_NODE_H

#include "Sequence.h"
#include "TagTypePairNode.h"

namespace tastr::ast {

class TypeNodeSequenceNode final
    : public Node
    , public Sequence<TypeNode> {
  public:
    TypeNodeSequenceNode(): Node(), Sequence<TypeNode>() {
    }

    TypeNodeSequenceNode(const TypeNodeSequenceNode& node)
        : Node(node), Sequence<TypeNode>(node) {
    }

    ~TypeNodeSequenceNode() {
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
