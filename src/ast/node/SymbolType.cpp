#include "ast/node/SymbolType.h"
#include "ast/visitor/Visitor.h"

void rtype::ast::node::SymbolType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
