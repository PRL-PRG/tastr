#include "ast/S4TypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::S4TypeNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
