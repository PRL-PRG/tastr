#include "ast/SymbolTypeNode.hpp"
#include "visitor/Visitor.hpp"

void tastr::ast::SymbolTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
