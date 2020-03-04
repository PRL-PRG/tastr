#include "ast/TypeNodeSequenceNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::TypeNodeSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
