/**
 * @file Message.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "Message.hpp"

namespace messages {
    std::vector<Message::ClassInfo> Message::classes{};

    void Message::addProperty(const PropertySetter &setter, const PropertyGetter &getter, const std::string &name) {
        properties.emplace_back(setter, getter, name);
    }

    void
    Message::addClass(const Message::Factory &factory, const Message::IsInstance &isInstance, const std::string &name) {
        for (const auto &[f, i, className] : classes) {
            if (className == name) {
                return;
            }
        }

        classes.emplace_back(factory, isInstance, name);
    }

    auto Message::toJson() const -> nlohmann::json {
        nlohmann::json json;
        for (const auto &[_, getter, name] : properties) {
            json["body"][name] = getter();
        }

        for (const auto &[_, isInstance, name] : classes) {
            if (isInstance(this)) {
                json["name"] = name;
            }
        }

        return json;
    }


    auto Message::fromJson(const nlohmann::json &j) -> std::shared_ptr<Message> {
        auto messageName = j.at("name").get<std::string>();
        std::shared_ptr<Message> message = nullptr;

        for (const auto &[factory, _, name] : classes) {
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
}
