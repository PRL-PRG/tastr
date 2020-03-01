#ifndef TASTR_AST_TYPE_DECLARATION_SEQUENCE_H
#define TASTR_AST_TYPE_DECLARATION_SEQUENCE_H

#include "TypeNode.h"
#include "Sequence.h"
#include "TypeDeclarationNode.h"

namespace tastr::ast {
// TODO: fix base class to Node
class TypeDeclarationSequenceNode final
    : public TypeNode
    , public Sequence<TypeDeclarationNode> {
  public:
    explicit TypeDeclarationSequenceNode()
        : TypeNode(), Sequence<TypeDeclarationNode>() {
    }

    TypeDeclarationSequenceNode(const TypeDeclarationSequenceNode& node)
        : TypeNode(node), Sequence<TypeDeclarationNode>(node) {
    }

    ~TypeDeclarationSequenceNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TypeDeclarationSequenceNode> clone() const {
        return std::unique_ptr<TypeDeclarationSequenceNode>(this->clone_impl());
    }

    bool is_type_declaration_sequence_node() const override final {
        return true;
    }

  private:
    virtual TypeDeclarationSequenceNode* clone_impl() const override final {
        return new TypeDeclarationSequenceNode(*this);
    }
};

using TypeDeclarationSequenceNodePtr = TypeDeclarationSequenceNode*;
using TypeDeclarationSequenceNodeUPtr =
    std::unique_ptr<TypeDeclarationSequenceNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_SEQUENCE_H */
