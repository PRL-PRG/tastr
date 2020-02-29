#include "ast/node/EnvironmentType.h"
#include "ast/visitor/Visitor.h"

void rtype::ast::node::EnvironmentType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
