#include "ast/node/NoNaType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::NoNaType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
