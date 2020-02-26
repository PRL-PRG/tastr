#include "ast/node/StructType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::StructType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
