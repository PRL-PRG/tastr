#ifndef TASTR_AST_NODE_H
#define TASTR_AST_NODE_H

#include <memory>

namespace tastr::visitor {
class Visitor;
}

namespace tastr::ast {

class Node {
  public:
    Node() {
    }

    Node(const Node& node) {
    }

    virtual ~Node() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;

    std::unique_ptr<Node> clone() const {
        return std::unique_ptr<Node>(this->clone_impl());
    }

  private:
    virtual Node* clone_impl() const = 0;
};

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

} // namespace tastr::ast

#endif /* TASTR_AST_NODE_H */
