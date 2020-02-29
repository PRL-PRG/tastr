#ifndef TASTR_AST_UNION_TYPE_H
#define TASTR_AST_UNION_TYPE_H

#include "CompositeType.h"
#include <memory>

namespace tastr::ast {

class UnionType final: public CompositeType {
  public:
    UnionType(std::unique_ptr<Type> first_type,
              std::unique_ptr<Type> second_type)
        : CompositeType()
        , first_type_(std::move(first_type))
        , second_type_(std::move(second_type)) {
    }

    ~UnionType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::Type& get_first_type() const {
        return *first_type_.get();
    }

    const tastr::ast::Type& get_second_type() const {
        return *second_type_.get();
    }

  private:
    std::unique_ptr<Type> first_type_;
    std::unique_ptr<Type> second_type_;
};

using UnionTypePtr = UnionType*;
using UnionTypeUPtr = std::unique_ptr<UnionType>;

} // namespace tastr::ast

#endif /* TASTR_AST_UNION_TYPE_H */
