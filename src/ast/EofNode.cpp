#include "ast/EofNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::EofNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::EofNode::accept(tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
