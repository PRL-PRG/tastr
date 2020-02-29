#include "ast/node/StructType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::StructType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
