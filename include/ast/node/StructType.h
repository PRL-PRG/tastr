#ifndef R_TYPE_AST_NODE_STRUCT_TYPE_H
#define R_TYPE_AST_NODE_STRUCT_TYPE_H

#include "NamedType.h"
#include "SequenceType.h"

namespace rtype::ast::node {

class StructType final: public SequenceType<NamedType> {
  public:
    explicit StructType(
        std::unique_ptr<std::vector<std::unique_ptr<NamedType>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~StructType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using StructTypePtr = StructType*;
using StructTypeUPtr = std::unique_ptr<StructType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_STRUCT_TYPE_H */
