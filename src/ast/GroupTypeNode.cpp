#include "ast/GroupTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::GroupTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
