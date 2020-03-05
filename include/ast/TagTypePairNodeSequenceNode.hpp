#ifndef TASTR_AST_TAG_TYPE_PAIR_NODE_SEQUENCE_NODE_HPP
#define TASTR_AST_TAG_TYPE_PAIR_NODE_SEQUENCE_NODE_HPP

#include "Sequence.hpp"
#include "TagTypePairNode.hpp"

namespace tastr::ast {

class TagTypePairNodeSequenceNode final
    : public Node
    , public Sequence<TagTypePairNode> {
  public:
    TagTypePairNodeSequenceNode(): Node(), Sequence<TagTypePairNode>() {
    }

    ~TagTypePairNodeSequenceNode() = default;

    TagTypePairNodeSequenceNode(const TagTypePairNodeSequenceNode& node)
        : Node(node), Sequence<TagTypePairNode>(node) {
    }

    TagTypePairNodeSequenceNode(TagTypePairNodeSequenceNode&& node)
        : Node(std::move(node)), Sequence<TagTypePairNode>(std::move(node)) {
    }

    TagTypePairNodeSequenceNode&
    operator=(const TagTypePairNodeSequenceNode& node) {
        Node::operator=(node);
        Sequence<TagTypePairNode>::operator=(node);
        return *this;
    }

    TagTypePairNodeSequenceNode& operator=(TagTypePairNodeSequenceNode&& node) {
        Node::operator=(std::move(node));
        Sequence<TagTypePairNode>::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableVisitor& visitor) override final;

    std::unique_ptr<TagTypePairNodeSequenceNode> clone() const {
        return std::unique_ptr<TagTypePairNodeSequenceNode>(this->clone_impl());
    }

    bool is_tag_type_pair_node_sequence_node() const override final {
        return true;
    }

  private:
    virtual TagTypePairNodeSequenceNode* clone_impl() const override final {
        return new TagTypePairNodeSequenceNode(*this);
    };
};

using TagTypePairNodeSequenceNodePtr = TagTypePairNodeSequenceNode*;
using TagTypePairNodeSequenceNodeUPtr =
    std::unique_ptr<TagTypePairNodeSequenceNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TAG_TYPE_PAIR_NODE_SEQUENCE_NODE_HPP */
