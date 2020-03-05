#include "ast/TopLevelNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TopLevelNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TopLevelNode::accept(tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
