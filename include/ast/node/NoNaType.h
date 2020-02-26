#ifndef R_TYPE_AST_NODE_NO_NA_TYPE_H
#define R_TYPE_AST_NODE_NO_NA_TYPE_H

#include "CompositeType.h"
#include "VectorType.h"

#include <memory>

namespace rtype::ast::node {

class NoNaType: public CompositeType {
  public:
    NoNaType(std::unique_ptr<VectorType> inner_type)
        : CompositeType(), inner_type_(std::move(inner_type)) {
    }

    ~NoNaType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;

    const rtype::ast::node::VectorType& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<rtype::ast::node::VectorType> inner_type_;
};

using NoNaTypePtr = NoNaType*;
using NoNaTypeUPtr = std::unique_ptr<NoNaType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_NO_NA_TYPE_H */
