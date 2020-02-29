#include "ast/node/UnionType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::UnionType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
