#ifndef TASTR_AST_PARAMETER_TYPE_H
#define TASTR_AST_PARAMETER_TYPE_H

#include "SequenceType.h"

namespace tastr::ast {

class ParameterType final: public SequenceType<Type> {
  public:
    explicit ParameterType(
        std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~ParameterType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ParameterTypePtr = ParameterType*;
using ParameterTypeUPtr = std::unique_ptr<ParameterType>;

} // namespace tastr::ast

#endif /* TASTR_AST_PARAMETER_TYPE_H */
