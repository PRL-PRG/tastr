#include "ast/node/IntegerType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::IntegerType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
