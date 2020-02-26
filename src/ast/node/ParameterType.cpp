#include "ast/node/ParameterType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::ParameterType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
