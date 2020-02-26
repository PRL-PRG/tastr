#include "ast/node/FunctionType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::FunctionType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
