#ifndef TASTR_AST_NODE_TYPE_DECLARATION_SEQUENCE_H
#define TASTR_AST_NODE_TYPE_DECLARATION_SEQUENCE_H

#include "SequenceType.h"
#include "TypeDeclaration.h"

namespace tastr::ast::node {

class TypeDeclarationSequence final: public SequenceType<TypeDeclaration> {
  public:

    explicit TypeDeclarationSequence(): SequenceType() {
    }

    explicit TypeDeclarationSequence(
        std::unique_ptr<std::vector<std::unique_ptr<TypeDeclaration>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~TypeDeclarationSequence() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using TypeDeclarationSequencePtr = TypeDeclarationSequence*;
using TypeDeclarationSequenceUPtr = std::unique_ptr<TypeDeclarationSequence>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_TYPE_DECLARATION_SEQUENCE_H */
