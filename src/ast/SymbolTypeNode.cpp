#include "ast/SymbolTypeNode.h"
#include "visitor/Visitor.h"

void tastr::ast::SymbolTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
