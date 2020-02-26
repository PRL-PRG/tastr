#ifndef R_TYPE_AST_NODE_UNION_TYPE_H
#define R_TYPE_AST_NODE_UNION_TYPE_H

#include "CompositeType.h"
#include <memory>

namespace rtype::ast::node {

class UnionType: public CompositeType {
  public:
    UnionType(std::unique_ptr<Type> first_type,
              std::unique_ptr<Type> second_type)
        : CompositeType()
        , first_type_(std::move(first_type))
        , second_type_(std::move(second_type)) {
    }

    ~UnionType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;

    const rtype::ast::node::Type& get_first_type() const {
        return *first_type_.get();
    }

    const rtype::ast::node::Type& get_second_type() const {
        return *second_type_.get();
    }

  private:
    std::unique_ptr<Type> first_type_;
    std::unique_ptr<Type> second_type_;
};

using UnionTypePtr = UnionType*;
using UnionTypeUPtr = std::unique_ptr<UnionType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_UNION_TYPE_H */
