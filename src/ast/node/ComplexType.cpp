#include "ast/node/ComplexType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::ComplexType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
