#ifndef R_TYPE_AST_NODE_NODE_H
#define R_TYPE_AST_NODE_NODE_H

#include <memory>

namespace rtype::ast::visitor {
class Visitor;
}

namespace rtype::ast::node {

class Node {
  public:
    Node() {
    }

    virtual ~Node() {
    }

    virtual void accept(rtype::ast::visitor::Visitor& visitor) const = 0;
};

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TYPE_H */
