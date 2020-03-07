#ifndef TASTR_AST_CHARACTER_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_CHARACTER_SCALAR_TYPE_NODE_HPP

#include "ScalarTypeNode.hpp"

namespace tastr::ast {

class CharacterScalarTypeNode;
using CharacterScalarTypeNodePtr = CharacterScalarTypeNode*;
using CharacterScalarTypeNodeUPtr = std::unique_ptr<CharacterScalarTypeNode>;

class CharacterScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit CharacterScalarTypeNode(const std::string& name)
        : ScalarTypeNode(name) {
    }

    ~CharacterScalarTypeNode() = default;

    CharacterScalarTypeNode(const CharacterScalarTypeNode& node)
        : ScalarTypeNode(static_cast<const ScalarTypeNode&>(node)) {
    }

    CharacterScalarTypeNode(CharacterScalarTypeNode&& node)
        : ScalarTypeNode(std::move(static_cast<ScalarTypeNode&>(node))) {
    }

    CharacterScalarTypeNode& operator=(const CharacterScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(static_cast<const ScalarTypeNode&>(node));
        return *this;
    }

    CharacterScalarTypeNode& operator=(CharacterScalarTypeNode&& node) {
        ScalarTypeNode::operator=(
            std::move(static_cast<ScalarTypeNode&>(node)));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    CharacterScalarTypeNodeUPtr clone() const {
        return CharacterScalarTypeNodeUPtr(this->clone_impl());
    }

    bool is_character_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual CharacterScalarTypeNode* clone_impl() const override final {
        return new CharacterScalarTypeNode(*this);
    };
};

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_SCALAR_TYPE_NODE_HPP */
