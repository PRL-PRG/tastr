#include "ast/ExternalPointerTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::ExternalPointerTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
