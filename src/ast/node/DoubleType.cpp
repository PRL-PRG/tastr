#include "ast/node/DoubleType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::DoubleType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
