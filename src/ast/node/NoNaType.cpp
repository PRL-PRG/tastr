#include "ast/node/NoNaType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::NoNaType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
