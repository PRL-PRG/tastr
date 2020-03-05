#include "ast/NoNaTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NoNaTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NoNaTypeNode::accept(tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
