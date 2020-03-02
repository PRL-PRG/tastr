#ifndef TASTR_AST_TYPE_DECLARATION_NODE_SEQUENCE_NODE_H
#define TASTR_AST_TYPE_DECLARATION_NODE_SEQUENCE_NODE_H

#include "Sequence.h"
#include "TypeDeclarationNode.h"

namespace tastr::ast {

class TypeDeclarationNodeSequenceNode final
    : public Node
    , public Sequence<TypeDeclarationNode> {
  public:
    TypeDeclarationNodeSequenceNode(): Node(), Sequence<TypeDeclarationNode>() {
    }

    ~TypeDeclarationNodeSequenceNode() = default;

    TypeDeclarationNodeSequenceNode(const TypeDeclarationNodeSequenceNode& node)
        : Node(node), Sequence<TypeDeclarationNode>(node) {
    }

    TypeDeclarationNodeSequenceNode(TypeDeclarationNodeSequenceNode&& node)
        : Node(std::move(node))
        , Sequence<TypeDeclarationNode>(std::move(node)) {
    }

    TypeDeclarationNodeSequenceNode&
    operator=(const TypeDeclarationNodeSequenceNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        Sequence<TypeDeclarationNode>::operator=(node);
        return *this;
    }

    TypeDeclarationNodeSequenceNode&
    operator=(TypeDeclarationNodeSequenceNode&& node) {
        Node::operator=(std::move(node));
        Sequence<TypeDeclarationNode>::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TypeDeclarationNodeSequenceNode> clone() const {
        return std::unique_ptr<TypeDeclarationNodeSequenceNode>(
            this->clone_impl());
    }

    bool is_type_declaration_node_sequence_node() const override final {
        return true;
    }

  private:
    virtual TypeDeclarationNodeSequenceNode* clone_impl() const override final {
        return new TypeDeclarationNodeSequenceNode(*this);
    };
};

using TypeDeclarationNodeSequenceNodePtr = TypeDeclarationNodeSequenceNode*;
using TypeDeclarationNodeSequenceNodeUPtr =
    std::unique_ptr<TypeDeclarationNodeSequenceNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_NODE_SEQUENCE_NODE_H */
