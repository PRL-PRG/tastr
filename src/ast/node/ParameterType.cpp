#include "ast/node/ParameterType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::ParameterType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
