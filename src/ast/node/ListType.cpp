#include "ast/node/ListType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::ListType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
