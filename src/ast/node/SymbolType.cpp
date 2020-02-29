#include "ast/node/SymbolType.h"
#include "ast/visitor/Visitor.h"

void tastr::ast::node::SymbolType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
