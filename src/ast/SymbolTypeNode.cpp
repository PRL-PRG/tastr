#include "ast/SymbolTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::SymbolTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::SymbolTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
