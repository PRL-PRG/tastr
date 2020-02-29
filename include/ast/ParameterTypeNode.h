#ifndef TASTR_AST_PARAMETER_TYPE_H
#define TASTR_AST_PARAMETER_TYPE_H

#include "SequenceTypeNode.h"

namespace tastr::ast {

class ParameterTypeNode final: public SequenceTypeNode<TypeNode> {
  public:
    explicit ParameterTypeNode(
        std::unique_ptr<std::vector<std::unique_ptr<TypeNode>>> sequence)
        : SequenceTypeNode(std::move(sequence)) {
    }

    ~ParameterTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ParameterTypeNodePtr = ParameterTypeNode*;
using ParameterTypeNodeUPtr = std::unique_ptr<ParameterTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_PARAMETER_TYPE_H */
