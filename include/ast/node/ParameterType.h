#ifndef R_TYPE_AST_NODE_PARAMETER_TYPE_H
#define R_TYPE_AST_NODE_PARAMETER_TYPE_H

#include "SequenceType.h"

namespace rtype::ast::node {

class ParameterType: public SequenceType<Type> {
  public:
    explicit ParameterType(
        std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~ParameterType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

using ParameterTypePtr = ParameterType*;
using ParameterTypeUPtr = std::unique_ptr<ParameterType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_PARAMETER_TYPE_H */
