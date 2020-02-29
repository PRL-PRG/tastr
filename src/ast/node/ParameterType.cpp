#include "ast/node/ParameterType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::ParameterType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
