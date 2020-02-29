#ifndef TASTR_AST_GROUP_TYPE_H
#define TASTR_AST_GROUP_TYPE_H

#include "CompositeType.h"
#include <memory>

namespace tastr::ast {

class GroupType final: public CompositeType {
  public:
    explicit GroupType(std::unique_ptr<Type> inner_type)
        : CompositeType(), inner_type_(std::move(inner_type)) {
    }

    ~GroupType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::Type& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<Type> inner_type_;
};

using GroupTypePtr = GroupType*;
using GroupTypeUPtr = std::unique_ptr<GroupType>;

} // namespace tastr::ast

#endif /* TASTR_AST_GROUP_TYPE_H */
