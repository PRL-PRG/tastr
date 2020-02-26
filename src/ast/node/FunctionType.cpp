#include "ast/node/FunctionType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::FunctionType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
