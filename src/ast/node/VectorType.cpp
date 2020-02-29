#include "ast/node/VectorType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::VectorType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
