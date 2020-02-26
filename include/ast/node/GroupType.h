#ifndef R_TYPE_AST_NODE_GROUP_TYPE_H
#define R_TYPE_AST_NODE_GROUP_TYPE_H

#include "CompositeType.h"
#include <memory>

namespace rtype::ast::node {

class GroupType: public CompositeType {
  public:
    explicit GroupType(std::unique_ptr<Type> inner_type)
        : CompositeType(), inner_type_(std::move(inner_type)) {
    }

    ~GroupType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;

    const rtype::ast::node::Type& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<Type> inner_type_;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_GROUP_TYPE_H */
