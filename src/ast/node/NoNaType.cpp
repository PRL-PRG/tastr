#include "ast/node/NoNaType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::NoNaType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
