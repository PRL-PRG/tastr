#ifndef TASTR_AST_TYPE_DECLARATION_SEQUENCE_H
#define TASTR_AST_TYPE_DECLARATION_SEQUENCE_H

#include "SequenceTypeNode.h"
#include "TypeDeclarationNode.h"

namespace tastr::ast {

class TypeDeclarationSequenceNode final: public SequenceTypeNode<TypeDeclarationNode> {
  public:

    explicit TypeDeclarationSequenceNode(): SequenceTypeNode() {
    }

    explicit TypeDeclarationSequenceNode(
        std::unique_ptr<std::vector<std::unique_ptr<TypeDeclarationNode>>> sequence)
        : SequenceTypeNode(std::move(sequence)) {
    }

    ~TypeDeclarationSequenceNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using TypeDeclarationSequenceNodePtr = TypeDeclarationSequenceNode*;
using TypeDeclarationSequenceNodeUPtr = std::unique_ptr<TypeDeclarationSequenceNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_SEQUENCE_H */
