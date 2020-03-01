#ifndef TASTR_AST_TYPE_DECLARATION_SEQUENCE_H
#define TASTR_AST_TYPE_DECLARATION_SEQUENCE_H

#include "CompositeTypeNode.h"
#include "Sequence.h"
#include "TypeDeclarationNode.h"

namespace tastr::ast {

class TypeDeclarationSequenceNode final
    : public CompositeTypeNode
    , public Sequence<TypeDeclarationNode> {
  public:
    explicit TypeDeclarationSequenceNode()
        : CompositeTypeNode(), Sequence<TypeDeclarationNode>() {
    }

    ////////////////////////////////////////////////////////////////////////////
    // explicit TypeDeclarationSequenceNode(                                  //
    //     std::unique_ptr<std::vector<std::unique_ptr<TypeDeclarationNode>>> //
    //         sequence)                                                      //
    //     : SequenceTypeNode(std::move(sequence)) {                          //
    // }                                                                      //
    ////////////////////////////////////////////////////////////////////////////

    ~TypeDeclarationSequenceNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using TypeDeclarationSequenceNodePtr = TypeDeclarationSequenceNode*;
using TypeDeclarationSequenceNodeUPtr =
    std::unique_ptr<TypeDeclarationSequenceNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_SEQUENCE_H */
