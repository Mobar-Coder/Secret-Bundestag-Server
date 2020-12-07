/**
 * @file Message.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "Message.hpp"

namespace messages {
    void Message::addProperty(const PropertySetter &setter, const PropertyGetter &getter, const std::string &name) {
        properties.emplace_back(setter, getter, name);
    }

    bool
    Message::addClass(const Message::Factory &factory, const Message::IsInstance &isInstance, const std::string &name) {
        for (const auto &[f, i, className] : Message::getClassesList()) {
            if (className == name) {
                return false;
            }
        }

        Message::getClassesList().emplace_back(factory, isInstance, name);
        return true;
    }

    auto Message::toJson() const -> nlohmann::json {
        nlohmann::json json;
        for (const auto &[_, getter, name] : properties) {
            json["body"][name] = getter();
        }

        for (const auto &[_, isInstance, name] : Message::getClassesList()) {
            if (isInstance(this)) {
                json["name"] = name;
                break;
            }
        }

        return json;
    }


    auto Message::fromJson(const nlohmann::json &j) -> std::shared_ptr<Message> {
        auto messageName = j.at("name").get<std::string>();
        std::shared_ptr<Message> message = nullptr;

        for (const auto &[factory, _, name] : Message::getClassesList()) {
            if (name == messageName) {
                message = factory();
                break;
            }
        }

        if (message == nullptr) {
            throw std::runtime_error{"Invalid type or format!"};
        }

        for (const auto &[setter, _, name] : message->properties) {
            setter(j["body"][name]);
        }

        return message;
    }

    auto Message::operator==(const Message &message) const -> bool {
        bool foundType = false;
        for (const auto &[f, isInstance, s]: Message::getClassesList()) {
            if (isInstance(this) != isInstance(&message)) {
                return false;
            } else if (isInstance(this) and isInstance(&message)) {
                foundType = true;
                break;
            }
        }

        if (!foundType) {
            return false;
        }

        assert(this->properties.size() == message.properties.size()); // Should always be the case

        for (auto c = 0U; c < this->properties.size(); ++c) {
            const auto &[ts, thisGetter, thisName] = this->properties[c];
            const auto &[ms, messageGetter, messageName] = message.properties[c];

            assert(thisName == messageName); // See above, assumes equal ordering

            if (thisGetter() != messageGetter()) {
                return false;
            }
        }
        return true;
    }

    auto Message::getClassesList() -> std::vector<ClassInfo> & {
        static std::vector<ClassInfo> classesList{};
        return classesList;
    }
}
