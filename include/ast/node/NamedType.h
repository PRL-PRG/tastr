#ifndef R_TYPE_AST_NODE_NAMED_TYPE_H
#define R_TYPE_AST_NODE_NAMED_TYPE_H

#include "ast/node/CompositeType.h"

#include <string>
#include <memory>

namespace rtype::ast::node {

class NamedType: public CompositeType {
  public:
    explicit NamedType(const std::string& name, std::unique_ptr<Type> type)
        : CompositeType(), name_(name), type_(std::move(type)) {
    }

    ~NamedType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override;

    const std::string& get_name() const {
        return name_;
    }

    const rtype::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::string name_;
    std::unique_ptr<Type> type_;
};

using NamedTypePtr = NamedType*;
using NamedTypeUPtr = std::unique_ptr<NamedType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_NAMED_TYPE_H */
