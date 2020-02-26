#include "ast/node/StructType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::StructType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
