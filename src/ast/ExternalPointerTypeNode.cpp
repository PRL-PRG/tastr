#include "ast/ExternalPointerTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ExternalPointerTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ExternalPointerTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
