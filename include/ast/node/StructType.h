#ifndef TASTR_AST_NODE_STRUCT_TYPE_H
#define TASTR_AST_NODE_STRUCT_TYPE_H

#include "SequenceType.h"
#include "TaggedType.h"

namespace tastr::ast::node {

class StructType final: public SequenceType<TaggedType> {
  public:
    explicit StructType(
        std::unique_ptr<std::vector<std::unique_ptr<TaggedType>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~StructType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using StructTypePtr = StructType*;
using StructTypeUPtr = std::unique_ptr<StructType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_STRUCT_TYPE_H */
