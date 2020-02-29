#include "ast/node/FunctionType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::FunctionType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
