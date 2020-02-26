#ifndef R_TYPE_AST_NODE_LIST_TYPE_H
#define R_TYPE_AST_NODE_LIST_TYPE_H

#include "SequenceType.h"

namespace rtype::ast::node {

class ListType: public SequenceType<Type> {
  public:
    explicit ListType(
        std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~ListType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_LIST_TYPE_H */
