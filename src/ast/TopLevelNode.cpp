#include "ast/TopLevelNode.hpp"
#include "visitor/Visitor.hpp"

void tastr::ast::TopLevelNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
