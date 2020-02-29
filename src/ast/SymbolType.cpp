#include "ast/SymbolType.h"
#include "visitor/Visitor.h"

void tastr::ast::SymbolType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
