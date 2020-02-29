#include "ast/node/EnvironmentType.h"
#include "ast/visitor/Visitor.h"

void tastr::ast::node::EnvironmentType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
