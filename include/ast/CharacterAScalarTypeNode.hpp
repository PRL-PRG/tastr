#ifndef TASTR_AST_CHARACTER_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_CHARACTER_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr::ast {

class CharacterAScalarTypeNode;
using CharacterAScalarTypeNodePtr = CharacterAScalarTypeNode*;
using CharacterAScalarTypeNodeUPtr = std::unique_ptr<CharacterAScalarTypeNode>;

class CharacterAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit CharacterAScalarTypeNode(KeywordNodeUPtr keyword)
        : AScalarTypeNode(std::move(keyword)) {
    }

    ~CharacterAScalarTypeNode() = default;

    CharacterAScalarTypeNode(const CharacterAScalarTypeNode& node)
        : AScalarTypeNode(static_cast<const AScalarTypeNode&>(node)) {
    }

    CharacterAScalarTypeNode(CharacterAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(static_cast<AScalarTypeNode&>(node))) {
    }

    CharacterAScalarTypeNode& operator=(const CharacterAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(static_cast<const AScalarTypeNode&>(node));
        return *this;
    }

    CharacterAScalarTypeNode& operator=(CharacterAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(
            std::move(static_cast<AScalarTypeNode&>(node)));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    CharacterAScalarTypeNodeUPtr clone() const {
        return CharacterAScalarTypeNodeUPtr(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

  private:
    virtual CharacterAScalarTypeNode* clone_impl() const override final {
        return new CharacterAScalarTypeNode(*this);
    };

    static const Kind kind_;
};

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_SCALAR_TYPE_NODE_HPP */
